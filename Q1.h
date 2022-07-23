#ifndef Q1_H
#define Q1_H

/*Q1 functions*/

chessPosArray*** validKnightMoves();
int validMoves(chessPos* positions, int row, int colom);
chessPos* num_to_chess_pos(int row, int col);
bool isInBoard(int row, int col);
void printKnightArrayMoves(chessPosArray**** knightArr);
void printKnightArrayMovesHelper(chessPos* positions, unsigned int size);
void freeCPA(chessPosArray*** validArray);

#endif // !Q1_H
