#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree)
{
	int level;
	chessPosList* resList = (chessPosList*)malloc(sizeof(chessPosList));
	checkAlloc(resList, "findKnightPathCoveringAllBoard");

	makeEmptyList(resList);
	findKnightPathCoveringAllBoardHelper(path_tree->root, resList, &level);

	if (level + 1 < SIZE - 1)
	{
		freeList(resList);
		return NULL;
	}
	return resList;
}


void findKnightPathCoveringAllBoardHelper(treeNode* root, chessPosList* lst, int* level)
{
	int maxLevel = -1, regularLevel;
	chessPosList maxList, regularList;
	treeNodeListCell* curr;
	makeEmptyList(&maxList);
	makeEmptyList(&regularList);

	if (!root)
	{
		*level = -1;
		makeEmptyList(lst);
	}
	else
	{
		curr = root->next_possible_positions;
		while (curr)
		{
			findKnightPathCoveringAllBoardHelper(curr->node, &regularList, &regularLevel);
			if (maxLevel < regularLevel)
			{
				maxLevel = regularLevel;
				if (!isEmptyList(&maxList))
					freeListCells(&maxList);
				maxList = regularList;
			}
			else
			{
				if (!isEmptyList(&regularList))
					freeListCells(&regularList);
			}
			curr = curr->next;
		}

		maxLevel++;
		insertDataToListHead(&maxList, root->position);
		*level = maxLevel;
		*lst = maxList;
	}
}

void freeListCells(chessPosList* lst)
{
	chessPosCell* curr = NULL, * saver = NULL;

	if (!isEmptyList(lst))
	{
		curr = lst->head;
		while (curr != NULL)
		{
			saver = curr->next;
			free(curr);
			curr = saver;
		}
		makeEmptyList(lst); /*what for ?*/
	}
}

void freeList(chessPosList* lst)
{
	freeListCells(lst);
	free(lst);
}
