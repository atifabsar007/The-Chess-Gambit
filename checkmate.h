#ifndef CHECKMATE_H
#define CHECKMATE_H

#include "chess.h"

int isKingInCheck(Piece board[8][8], int color);
int isCheckmate(Piece board[8][8], int color);

#endif
