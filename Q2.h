#ifndef Q2_H
#define Q2_H

/*Q2 functions*/

void display(chessPosList* lst);

void removeNodeFromList(chessPosList* lst, chessPosCell* node);

void print_board(chessPosList* lst);

void listToOrderArr(int array[][8], chessPosList* lst);

void printList(chessPosList* lst);

#endif // !Q2_H