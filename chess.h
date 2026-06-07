// chess.h
#ifndef CHESS_H
#define CHESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

#define WHITE 0
#define BLACK 1

typedef struct
{
    int type;
    int color;
} Piece;

// Function declarations
// void initializeBoard(Piece board[8][8]);
// void printBoard(Piece board[8][8]);
int isValidMove(Piece board[8][8], int fromX, int fromY, int toX, int toY);
void movePiece(Piece board[8][8], int fromX, int fromY, int toX, int toY);
void saveGame(Piece board[8][8], const char *filename, int currentPlayer);
int loadGame(Piece board[8][8], const char *filename, int *currentPlayer);
int isPieceMove(Piece board[8][8], int fromX, int fromY, int toX, int toY);
int isPathClear(Piece board[8][8], int fromX, int fromY, int toX, int toY);
#endif
