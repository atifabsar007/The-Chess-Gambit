#include "chess.h"

void saveGame(Piece board[8][8], const char *filename, int currentPlayer)
{
    char fullPath[150];
    sprintf(fullPath, "%s.chess", filename); // Add .chess extension

    FILE *file = fopen(fullPath, "wb"); // Open in binary mode
    if (!file)
    {
        printf("Error: Could not save game\n");
        return;
    }

    // Write format version
    int version = 1;
    fwrite(&version, sizeof(int), 1, file);

    // Write current player
    fwrite(&currentPlayer, sizeof(int), 1, file);

    // Write board state
    fwrite(board, sizeof(Piece), 64, file);

    fclose(file);
    printf("Game saved successfully to %s\n", fullPath);
}

int loadGame(Piece board[8][8], const char *filename, int *currentPlayer)
{
    char fullPath[150];
    sprintf(fullPath, "%s.chess", filename);

    FILE *file = fopen(fullPath, "rb"); // Open in binary mode
    if (!file)
    {
        printf("Error: Could not load game\n");
        return 0;
    }

    // Read and verify format version
    int version;
    if (fread(&version, sizeof(int), 1, file) != 1 || version != 1)
    {
        printf("Error: Invalid or corrupted save file\n");
        fclose(file);
        return 0;
    }

    // Read current player
    if (fread(currentPlayer, sizeof(int), 1, file) != 1)
    {
        printf("Error: Failed to read game state\n");
        fclose(file);
        return 0;
    }

    // Read board state
    if (fread(board, sizeof(Piece), 64, file) != 64)
    {
        printf("Error: Failed to read board state\n");
        fclose(file);
        return 0;
    }

    fclose(file);
    printf("Game loaded successfully from %s\n", fullPath);
    return 1;
}
