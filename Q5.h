#ifndef Q5_H
#define Q5_H

void saveListToBinFile(char* fileName, chessPosList* pos_list);

BYTE* chessPosToBytes(chessPosCell* curr);

int listSize(chessPosCell* node);

unsigned char dictionary(char pos);

#endif // !Q5_H
