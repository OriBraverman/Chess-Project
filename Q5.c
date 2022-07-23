#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q5.h"

void saveListToBinFile(char* fileName, chessPosList* pos_list)
{
    BYTE* tmpData;
    chessPosCell* curr = pos_list->head;
    short int lstSize = listSize(curr);
    FILE* fpList = fopen(fileName, "wb");
    checkFileOpen(fpList, fileName);

    fwrite(&lstSize, sizeof(short int), 1, fpList);

    while (curr && (lstSize > 0))
    {
        tmpData = chessPosToBytes(curr);

        if (lstSize >= 4)
        {
            lstSize -= 4;                        /* push curr in place x to chessPosCell in place x+4 */
            curr = curr->next->next->next->next; /* won't get to NULL because lstSize >= 4            */
            fwrite(tmpData, sizeof(BYTE), 3, fpList);
        }
        else if (lstSize == 3)
        {
            fwrite(tmpData, sizeof(BYTE), 3, fpList);
            lstSize -= 3;
        }
        else if (lstSize == 2)
        {
            fwrite(tmpData, sizeof(BYTE), 2, fpList);
            lstSize -= 2;
        }
        else if (lstSize == 1)
        {
            fwrite(tmpData, sizeof(BYTE), 1, fpList);
            lstSize -= 1;
        }
        free(tmpData);
    }
    fclose(fpList);
}

//the function gets a list pointer and the 3 BYTE compress
BYTE* chessPosToBytes(chessPosCell* curr)
{
    int i;
    chessPos data[4] = { { 'A','1' }, { 'A','1' } ,{ 'A','1' } ,{ 'A','1' } };
    BYTE* res = (BYTE*)malloc(3 * sizeof(BYTE));
    checkAlloc(res, "chessPosToBytes");

    for (i = 0; curr && (i < 4); i++)
    {
        data[i][0] = curr->position[0];
        data[i][1] = curr->position[1];
        curr = curr->next;
    }

    res[0] = (dictionary(data[0][0]) << 5) | (dictionary(data[0][1]) << 2) | (dictionary(data[1][0]) >> 1);
    // 11100000 | 00011100 | 00000011
    res[1] = (dictionary(data[1][0]) << 7) | (dictionary(data[1][1]) << 4) | (dictionary(data[2][0]) << 1) | (dictionary(data[2][1]) >> 2);
    // 10000000 | 01110000 | 00001110 | 00000001
    res[2] = (dictionary(data[2][1]) << 6) | (dictionary(data[3][0]) << 3) | (dictionary(data[3][1]));
    // 11000000 | 00111000 | 00000111

    return res;
}

int listSize(chessPosCell* node)
{
    int res = 0;

    while (node)
    {
        node = node->next;
        res++;
    }

    return res;
}

unsigned char dictionary(char pos)
{
    switch (pos)
    {
    case '1':
        return 0x00;
    case '2':
        return 0x01;
    case '3':
        return 0x02;
    case '4':
        return 0x03;
    case '5':
        return 0x04;
    case '6':
        return 0x05;
    case '7':
        return 0x06;
    case '8':
        return 0x07;
    case 'A':
        return 0x00;
    case 'B':
        return 0x01;
    case 'C':
        return 0x02;
    case 'D':
        return 0x03;
    case 'E':
        return 0x04;
    case 'F':
        return 0x05;
    case 'G':
        return 0x06;
    case 'H':
        return 0x07;
    }
}
