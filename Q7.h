#ifndef Q7_H
#define Q7_H

void chessMenu();

char* getFileName();

void unvalidInput(chessPos userPos);

bool isValidInput(chessPos pos);

void printMenu();

void printRes(int pathRes, char* fileName);

#endif // !Q7_H