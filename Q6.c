#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q6.h"

int checkAndDisplayPathFromFile(char* file_name)
{
	int lSize, res;
    chessPosList* fileList = (chessPosList*)malloc(sizeof(chessPosList));
    checkAlloc(fileList, "readToList");

	FILE* fp = fopen(file_name, "rb");

    if (!fp) /*instead of checkFileOpen(fp, file_name) , according to question 6*/
    {
        return -1;
        free(fileList);
    }

    readToList(fileList, fp, &lSize);
	fclose(fp);

    /*printList(fileList);*/ /*for debugging*/
	if (isValidKnightList(fileList) == false)
		res = 1;

    else
    {
        display(fileList);
        if (lSize == SIZE * SIZE)
            res = 2;
        else
            res = 3;
    }

	freeList(fileList);
	return res;
}

/* function read binary file into fileList */
void readToList(chessPosList* fileList, FILE* fp, int* listSize)
{
    makeEmptyList(fileList);
    readListHelper(fileList, fp, listSize);
}

void readListHelper(chessPosList* fileList, FILE* fp, int* listSizeRes)
{
	int  byteSize, fileLen, physListSize;
    short int numOfCells;
	chessPosCell* tmpCell;
	BYTE byteArr[3];

	fseek(fp, 0, SEEK_END);
	fileLen = ftell(fp);
	rewind(fp);
    fread(&numOfCells, sizeof(short int), 1, fp);

    while (ftell(fp) < fileLen) 
    {
        if (fileLen - ftell(fp) > sizeof(BYTE) * 3)
            byteSize = 3;
        else if (fileLen - ftell(fp) <= sizeof(BYTE))
            byteSize = 1;
        else
            byteSize = 2;

        fread(byteArr, sizeof(BYTE), byteSize, fp);
        tmpCell = bytesToChessPos(byteArr); /* tmpCell is 4 chained nodes of chessPosCell*/
        addToTail(fileList, tmpCell);
    }

    rewind(fp);
	physListSize = listSize(fileList->head);

	while (physListSize > (int)numOfCells) /*  it is possible that 1-3 nodes that 
                                               shouldn't be in the list have been added   */
	{
		removeNodeFromList(fileList, fileList->tail);
		physListSize--;
	}
	*listSizeRes = (int)numOfCells;
}

/* add 4 chained nodes to list->tail */
void addToTail(chessPosList* list, chessPosCell* cell) 
{
    chessPosCell* temp = cell;

    while (temp->next != NULL)
        temp = temp->next;

    if (isEmptyList(list) == true)
    {
        list->head = cell;
        list->tail = temp;
    }

    else
    {
        list->tail->next = cell;
        list->tail = temp;
    }
}

/*function gets 3 BYTE and translate to 4 chained chess-pos*/
chessPosCell* bytesToChessPos(BYTE* data)
{
    int i, res_size;
    chessPosCell* res;
    chessPos temp;
    chessPosList* lst = (chessPosList*)malloc(sizeof(chessPosList));

    checkAlloc(lst, "bytesToChessPos");
    makeEmptyList(lst);

    for (i = 4; i >= 1; i--)
    {
        getChessPos(data, i, temp);
        insertDataToListHead(lst, temp);
    }
    res = lst->head;
    free(lst);
    return res;
}

void getChessPos(BYTE* data, int number, chessPos temp)
{
    BYTE mask = 0x07;
    switch (number)
    {
    case 1:
    {
        temp[0] = decode_pos_0(data[0] >> 5);
        temp[1] = decode_pos_1((data[0] >> 2) & mask);
        break;
    }
    case 2:
    {
        temp[0] = decode_pos_0(((data[0] << 1) & mask) | ((data[1] >> 7) & mask));
        temp[1] = decode_pos_1((data[1] >> 4) & mask);
        break;
    }
    case 3:
    {
        temp[0] = decode_pos_0((data[1] >> 1) & mask);
        temp[1] = decode_pos_1(((data[1] << 2) & mask) | (data[2] >> 6));
        break;
    }
    case 4:
    {
        temp[0] = decode_pos_0((data[2] >> 3) & mask);
        temp[1] = decode_pos_1(data[2] & mask);
        break;
    }
    }
}

int decode_dictionary(BYTE data)
{
    switch (data)
    {
    case 0x00:
        return 0;
    case 0x01:
        return 1;
    case 0x02:
        return 2;
    case 0x03:
        return 3;
    case 0x04:
        return 4;
    case 0x05:
        return 5;
    case 0x06:
        return 6;
    case 0x07:
        return 7;
    }
}

char decode_pos_0(BYTE data)
{
    return decode_dictionary(data) + 'A';
}

char decode_pos_1(BYTE data)
{
    return decode_dictionary(data) + '1';
}

/*check if there is an unvalid knight move in the list*/
bool isValidKnightList(chessPosList* fileList)
{
    int i;
    chessPosArray*** arr = validKnightMoves();
    chessPosCell* curr = fileList->head;
    chessPosArray* childs;
    chessPos temp, tempNext;
    bool found, res;

    found = false;
    res = true;

    if (!curr) 
        return false;

    while (curr->next)
    {
        found = false;

        temp[0] = (curr->position)[0];
        temp[1] = (curr->position)[1];
        childs = arr[temp[0] - 'A'][temp[1] - '1'];
        tempNext[0] = (curr->next->position)[0];
        tempNext[1] = (curr->next->position)[1];

        for (i = 0; i < childs->size && !found ; i++)
            if ((childs->positions)[i][0] == tempNext[0] && (childs->positions)[i][1] == tempNext[1])
                found = true;

        if (found == false)
            res = false;

        curr = curr->next;
    }

    freeCPA(arr);
    return res;
}
