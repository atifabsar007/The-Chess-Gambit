#include "chess.h"     // For core chess definitions (Piece, isValidMove, etc.)
#include "board.h"     // For board functions (initializeBoard, printBoard)
#include "checkmate.h" //(isCheckmate,isKingInCheck)
#include <ctype.h>     // For tolower()
#include <stdio.h>     // For input/output
#include <string.h>    // For string functions

void displayMoveHelp()
{

    printf("\nMove Rules:\n");

    printf("- Pawn: Forward 1 square (or 2 on first move), capture diagonally\n");

    printf("- Knight: L-shape (2 squares one way, 1 square perpendicular)\n");

    printf("- Bishop: Any number of squares diagonally\n");

    printf("- Rook: Any number of squares horizontally or vertically\n");

    printf("- Queen: Any number of squares in any direction\n");

    printf("- King: One square in any direction\n");

    printf("\nCommands:\n");

    printf("- Enter moves in format 'e2 e4'\n");

    printf("- Type 'save' to save the game\n");

    printf("- Type 'help' for this message\n");

    printf("- Type 'quit' to exit\n\n");
}

int main()
{
    Piece board[8][8];
    int currentPlayer = WHITE;
    int gameMode;
    char input[20];

    printf("Welcome to Two-Player Chess!\n");
    printf("1. New Game\n");
    printf("2. Load Saved Game\n");
    printf("Choose option: ");
    scanf("%d", &gameMode);
    while (getchar() != '\n')
        ; // Clear input buffer

    if (gameMode == 2)
    {
        char filename[100];
        printf("Enter save file name (without .chess extension): ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = 0;
        if (!loadGame(board, filename, &currentPlayer))
        {
            printf("Starting new game instead.\n");
            initializeBoard(board); // Initialize if loading fails
        }
    }
    else
    {
        initializeBoard(board); // Initialize the board at the start of a new game
        displayMoveHelp();
    }

    while (1)
    {
        printBoard(board); // Print the board in each loop iteration
        printf("\nCurrent player: %s\n", currentPlayer == WHITE ? "White" : "Black");
        if (isCheckmate(board, currentPlayer))
        {
            printf("Checkmate! %s wins!\n", (currentPlayer == WHITE) ? "Black" : "White");
            break; // End the game
        }
        if (isKingInCheck(board, currentPlayer))
        {
            printf("Check! %s king is in check.\n", (currentPlayer == WHITE) ? "White" : "Black");
        }

        printf("\nEnter command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        for (int i = 0; input[i]; i++)
        {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, "quit") == 0)
        {
            break;
        }
        else if (strcmp(input, "help") == 0)
        {
            displayMoveHelp();
            continue;
        }
        else if (strcmp(input, "save") == 0)
        {
            char filename[100];
            printf("Enter save file name (without .chess extension): ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0;
            saveGame(board, filename, currentPlayer);
            continue;
        }
        else if (strlen(input) == 5 && input[2] == ' ')
        {
            char fromStr[3], toStr[3];
            sscanf(input, "%2s %2s", fromStr, toStr);

            int fromY = fromStr[0] - 'a';
            int fromX = 8 - (fromStr[1] - '0');
            int toY = toStr[0] - 'a';
            int toX = 8 - (toStr[1] - '0');

            if (fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7 ||
                toX < 0 || toX > 7 || toY < 0 || toY > 7)
            {
                printf("Invalid move format or coordinates. Use format 'e2 e4'.\n");
                continue;
            }

            if (board[fromX][fromY].color != currentPlayer)
            {
                printf("Invalid move: You can only move your own pieces!\n");
                continue;
            }

            if (!isValidMove(board, fromX, fromY, toX, toY))
            {
                printf("Invalid move! Check the movement rules and try again.\n");
                continue;
            }
            Piece tempBoard[8][8];                        // Create a temporary board
            memcpy(tempBoard, board, sizeof(Piece) * 64); // Copy the current board

            movePiece(tempBoard, fromX, fromY, toX, toY); // Make the move on the temp board
            if (isKingInCheck(tempBoard, currentPlayer))
            {
                printf("Invalid move! You must get out of check.\n");
                continue;
            }

            movePiece(board, fromX, fromY, toX, toY);
            currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
        }
        else
        {
            printf("Invalid command or move format. Use 'help' for instructions.\n");
        }
    }
    return 0;
}
