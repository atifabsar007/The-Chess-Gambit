
// moves.c
#include "chess.h"

void movePiece(Piece board[8][8], int fromX, int fromY, int toX, int toY)
{
    board[toX][toY] = board[fromX][fromY]; // Copy the piece
    board[fromX][fromY].type = EMPTY;      // Set the original square to empty
    board[fromX][fromY].color = EMPTY;
}

int isPathClear(Piece board[8][8], int fromX, int fromY, int toX, int toY)
{
    int dx = (toX > fromX) ? 1 : ((toX < fromX) ? -1 : 0);
    int dy = (toY > fromY) ? 1 : ((toY < fromY) ? -1 : 0);
    int x = fromX + dx;
    int y = fromY + dy;

    while (x != toX || y != toY)
    {
        if (board[x][y].type != EMPTY)
        {
            return 0;
        }
        x += dx;
        y += dy;
    }
    return 1;
}

int isPieceMove(Piece board[8][8], int fromX, int fromY, int toX, int toY)
{
    Piece piece = board[fromX][fromY];
    int dx = abs(toX - fromX);
    int dy = abs(toY - fromY);

    switch (piece.type)
    {
    case PAWN:
        // Check for initial two-square move
        if (piece.color == WHITE)
        {
            if (fromX == 6 && toX == 4 && fromY == toY && board[5][toY].type == EMPTY && board[4][toY].type == EMPTY)
            {
                return 1;
            }
            // Normal move
            if (toX == fromX - 1 && fromY == toY && board[toX][toY].type == EMPTY)
            {
                return 1;
            }
            // Capture
            if (toX == fromX - 1 && abs(toY - fromY) == 1 && board[toX][toY].type != EMPTY)
            {
                return 1;
            }
        }
        else
        { // BLACK
            if (fromX == 1 && toX == 3 && fromY == toY && board[2][toY].type == EMPTY && board[3][toY].type == EMPTY)
            {
                return 1;
            }
            if (toX == fromX + 1 && fromY == toY && board[toX][toY].type == EMPTY)
            {
                return 1;
            }
            if (toX == fromX + 1 && abs(toY - fromY) == 1 && board[toX][toY].type != EMPTY)
            {
                return 1;
            }
        }
        return 0;

    case KNIGHT:
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);

    case BISHOP:
        return dx == dy && isPathClear(board, fromX, fromY, toX, toY);

    case ROOK:
        return ((dx == 0 && dy > 0) || (dx > 0 && dy == 0)) &&
               isPathClear(board, fromX, fromY, toX, toY);

    case QUEEN:
        return ((dx == dy) || (dx == 0 && dy > 0) || (dx > 0 && dy == 0)) &&
               isPathClear(board, fromX, fromY, toX, toY);

    case KING:
        return dx <= 1 && dy <= 1;

    default:
        return 0;
    }
}

int isValidMove(Piece board[8][8], int fromX, int fromY, int toX, int toY)
{
    // Check if coordinates are within bounds
    if (fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7 ||
        toX < 0 || toX > 7 || toY < 0 || toY > 7)
    {
        return 0;
    }

    // Check if source square has a piece
    if (board[fromX][fromY].type == EMPTY)
    {
        return 0;
    }

    // Check if destination has a piece of the same color
    if (board[toX][toY].type != EMPTY &&
        board[toX][toY].color == board[fromX][fromY].color)
    {
        return 0;
    }

    // Check piece-specific movement rules
    return isPieceMove(board, fromX, fromY, toX, toY);
}

//
