#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"

void checkAlloc(void* ptr, char* msg)
{
	if (!ptr)
	{
		printf("Allocation failed: %s", msg);
		exit(1);
	}
}
void checkFileOpen(FILE* fp, char* msg)
{
	if (!fp)
	{
		fprintf(stderr, "File opening failure: %s\n", msg);
		exit(1);
	}
}

void makeEmptyList(chessPosList* lst)
{
	lst->head = lst->tail = NULL;
}

bool isEmptyList(chessPosList* lst)
{
	if (lst->head == NULL)
		return true;
	return false;
}

bool isInBoard(int row, int col)
{
	return (row >= 0 && row < SIZE) && (col >= 0 && col < SIZE);
}

void insertDataToListHead(chessPosList* lst, chessPos pos)
{
	chessPosCell* newHead = createNewListNode(pos, NULL);
	checkAlloc(newHead, "insertDataToListHead");
	insertNodeToStartList(lst, newHead);
}

chessPosCell* createNewListNode(chessPos pos, chessPosCell* next)
{
	chessPosCell* res = (chessPosCell*)malloc(sizeof(chessPosCell));
	checkAlloc(res, "createNewListNode");

	res->position[0] = pos[0];
	res->position[1] = pos[1];
	res->next = next;
	return res;
}

void insertNodeToStartList(chessPosList* lst, chessPosCell* head)
{
	if (isEmptyList(lst))
	{
		head->next = NULL;
		lst->head = lst->tail = head;
	}
	else
	{
		head->next = lst->head;
		lst->head = head;
	}
}

int chess_pos_to_num(chessPos pos)
{
	return (pos[0] - 'A') * 8 + (pos[1] - '0');
}