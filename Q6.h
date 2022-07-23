#ifndef Q6_H
#define Q6_H

int checkAndDisplayPathFromFile(char* file_name);

void readToList(chessPosList* fileList, FILE* fp, int* listSize);

void readListHelper(chessPosList* fileList, FILE* fp, int* listSizeRes);

void addToTail(chessPosList* list, chessPosCell* cell);

chessPosCell* bytesToChessPos(BYTE* data);

void getChessPos(BYTE* data, int number, chessPos temp);

int decode_dictionary(BYTE data);

char decode_pos_0(BYTE data);

char decode_pos_1(BYTE data);

bool isValidKnightList(chessPosList* fileList);

#endif // !Q6_H
