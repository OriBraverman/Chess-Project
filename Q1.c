#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q1.h"

chessPosArray*** validKnightMoves()
{
	int i, j;
	chessPosArray*** knightArr = (chessPosArray***)malloc(SIZE * sizeof(chessPosArray**));
	checkAlloc(knightArr, "knightArr, validKnightMoves");

	for (i = 0; i < SIZE; i++)
	{
		knightArr[i] = (chessPosArray**)malloc(SIZE * sizeof(chessPosArray*));
		checkAlloc(knightArr[i], "knightArr[i], validKnightMoves");

		for (j = 0; j < SIZE; j++)
		{
			knightArr[i][j] = (chessPosArray*)malloc(sizeof(chessPosArray));
			checkAlloc(knightArr[i][j], "knightArr[i][j], validKnightMoves");
			knightArr[i][j]->size = validMoves(&(knightArr[i][j]->positions), i, j);
		}
	}
	return knightArr;
}

int validMoves(chessPos** positions, int row, int colom)
{
	int i, size = 0;

	POS around[8] = { {-2,-1},{-2,1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2} };
	chessPos* pos = (chessPos*)malloc(8 * sizeof(chessPos));
	checkAlloc(pos, "pos, validMoves");

	for (i = 0; i < 8; i++)
		if (isInBoard(row + around[i].xpos, colom + around[i].ypos))
		{
			pos[size][0] = 'A' + row + around[i].xpos;
			pos[size][1] = '1' + colom + around[i].ypos;
			size++;
		}

	pos = (chessPos*)realloc(pos, size * sizeof(chessPos));
	checkAlloc(pos, "Failed to realloc knightPosArr, validMoves");

	*positions = pos;
	return size;
}

void printKnightArrayMoves(chessPosArray**** knightArr)
{
	int i, j;
	chessPosArray*** printKArr = *knightArr;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%c%d--> ", 'A' + i, j + 1);
			printKnightArrayMovesHelper(printKArr[i][j]->positions, printKArr[i][j]->size);
		}
		printf("\n");
	}
}

void printKnightArrayMovesHelper(chessPos* positions, unsigned int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%c%c  ", positions[i][0], positions[i][1]);
}

void freeCPA(chessPosArray*** validArray)
{
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			free(validArray[i][j]->positions);
			free(validArray[i][j]);
		}
		free(validArray[i]);
	}
	free(validArray);
}