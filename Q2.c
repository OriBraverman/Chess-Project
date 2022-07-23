#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q2.h"

void display(chessPosList* lst)
{
	chessPosCell* curr = lst->head;
	chessPosCell* saver = NULL;
	bool exist[8][8] = { 0 };
	while (curr != NULL)
	{
		if (exist[curr->position[0] - 'A'][curr->position[1] - '0'] == 0)
		{
			exist[curr->position[0] - 'A'][curr->position[1] - '0'] = 1;
			curr = curr->next;
		}
		else
		{
			saver = curr->next;
			removeNodeFromList(lst, curr);
			curr = saver;
		}
	}
	print_board(lst);
}

void removeNodeFromList(chessPosList* lst, chessPosCell* node)
{
	chessPosCell* prev = lst->head;

	if (lst->head == lst->tail) /* if list have 1 node*/
	{
		lst->head = lst->tail = NULL;
	}
	else if (lst->head == node) /* if node in head list */
	{
		lst->head = node->next;
	}
	else if (lst->tail == node) /* if node in list tail */
	{
		while (prev->next != node)
		{
			prev = prev->next;
		}
		lst->tail = prev;
		prev->next = NULL;
	}
	else	/* if node is in the middle */
	{
		while (prev->next != node)
		{
			prev = prev->next;
		}
		prev->next = node->next;
	}

	free(node);
}

void print_board(chessPosList* lst)
{
	chessPosCell* curr = lst->head;
	int array[8][8] = { 0 };
	int row, col, count = 1;

	listToOrderArr(array, lst);
	for (row = 1; row < 20; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (row % 2 != 0)
				printf("+----");
			else
			{
				if (row == 2 && col >= 1)
					printf("| %2d ", col);
				else if (row >= 3 && col == 0)
					printf("| %2c ", row / 2 - 2 + 'A');
				else if (row >= 4 && row <= 18 && col >= 1 && col <= 8 && array[(row - 4) / 2][col - 1] != 0)
					printf("| %2d ", array[(row - 4) / 2][col - 1]);
				else
					printf("|    ");
			}
		}
		if (row % 2 != 0)
			printf("+\n");
		else
		{
			printf("|\n");
		}
	}
}

void listToOrderArr(int array[][8], chessPosList* lst)
{
	int count = 1;
	chessPosCell* curr = lst->head;
	while (curr != NULL)
	{
		array[curr->position[0] - 'A'][curr->position[1] - '1'] = count;
		count++;
		curr = curr->next;
	}
}

void printList(chessPosList* lst)
{
	chessPosCell* curr;

	if (lst)
	{
		curr = lst->head;

		while (curr)
		{
			printf("[%c%c]--> ", curr->position[0], curr->position[1]);
			curr = curr->next;
		}
		printf("\n");
	}
}