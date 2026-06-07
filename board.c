#include "board.h"

void initializeBoard(Piece board[8][8])
{
    // Initialize empty squares
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j].type = EMPTY;
        }
    }

    // Set up pawns
    for (int i = 0; i < 8; i++)
    {
        board[1][i].type = PAWN;
        board[1][i].color = BLACK;
        board[6][i].type = PAWN;
        board[6][i].color = WHITE;
    }

    // Set up other pieces for both colors
    int backRow[8] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int i = 0; i < 8; i++)
    {
        board[0][i].type = backRow[i];
        board[0][i].color = BLACK;
        board[7][i].type = backRow[i];
        board[7][i].color = WHITE;
    }
}
void printBoard(Piece board[8][8])
{
    printf("   a b c d e f g h\n");
    printf(" +-----------------+\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d| ", 8 - i);
        for (int j = 0; j < 8; j++)
        {
            char *pieceChar = " ";
            if ((i + j) % 2 == 0)
            {
                printf("\033[47m"); // Light gray background
            }
            else
            {
                printf("\033[40m"); // Black background
            }

            if (board[i][j].type == EMPTY)
            { // Check for empty squares FIRST
                printf(". ");
                continue; // VERY IMPORTANT: Skip to the next square
            }
            switch (board[i][j].type)
            {
            case PAWN:
                pieceChar = (board[i][j].color == WHITE) ? "♟" : "♙";
                break;
            case KNIGHT:
                pieceChar = (board[i][j].color == WHITE) ? "♞" : "♘";
                break;
            case BISHOP:
                pieceChar = (board[i][j].color == WHITE) ? "♝" : "♗";
                break;
            case ROOK:
                pieceChar = (board[i][j].color == WHITE) ? "♜" : "♖";
                break;
            case QUEEN:
                pieceChar = (board[i][j].color == WHITE) ? "♛" : "♕";
                break;
            case KING:
                pieceChar = (board[i][j].color == WHITE) ? "♚" : "♔";
                break;
            }
            if (board[i][j].color == BLACK)
            {
                printf("\033[1;31m%s \033[0m", pieceChar);
            }
            else
            {
                printf("%s ", pieceChar);
            }
        }
        printf("\033[0m|\n");
    }
    printf(" +-----------------+\n");
}
