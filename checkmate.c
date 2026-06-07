#include "checkmate.h"

int isKingInCheck(Piece board[8][8], int color)
{
    // Find king position
    int kingX = -1, kingY = -1;
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (board[x][y].type == KING && board[x][y].color == color)
            {
                kingX = x;
                kingY = y;
                break;
            }
        }
        if (kingX != -1)
            break;
    }

    // Check if any opponent piece can attack king
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (board[x][y].type != EMPTY && board[x][y].color != color)
            {
                if (isValidMove(board, x, y, kingX, kingY))
                {
                    return 1; // King is in check
                }
            }
        }
    }
    return 0;
}

int isCheckmate(Piece board[8][8], int color)
{
    if (!isKingInCheck(board, color))
    {
        return 0; // Not checkmate if king isn't in check
    }

    // Try all possible moves to see if any resolve the check
    for (int fromX = 0; fromX < 8; fromX++)
    {
        for (int fromY = 0; fromY < 8; fromY++)
        {
            if (board[fromX][fromY].type != EMPTY && board[fromX][fromY].color == color)
            {
                for (int toX = 0; toX < 8; toX++)
                {
                    for (int toY = 0; toY < 8; toY++)
                    {
                        Piece tempBoard[8][8];
                        memcpy(tempBoard, board, sizeof(Piece) * 64);

                        if (isValidMove(tempBoard, fromX, fromY, toX, toY))
                        {
                            movePiece(tempBoard, fromX, fromY, toX, toY);

                            if (!isKingInCheck(tempBoard, color))
                            {
                                return 0; // Found a move that gets out of check
                            }
                        }
                    }
                }
            }
        }
    }

    return 1; // No move can get out of check
}
