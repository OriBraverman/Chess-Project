#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"

/*Function takes a position in chess board and make a generic tree*/
pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
	pathTree gTree;
	bool boolArray[SIZE][SIZE] = { 0 };
	chessPosArray*** validArray = validKnightMoves();
	
	gTree.root = (treeNode*)malloc(sizeof(treeNode));
	checkAlloc(gTree.root, "findAllPossibleKnightPaths");

	gTree.root = findAllPossibleKnightPathsHelper(startingPosition, validArray, boolArray);

	freeCPA(validArray); 
	return gTree;
}

treeNode* findAllPossibleKnightPathsHelper(chessPos* pos, chessPosArray*** validArray, bool boolArray[][SIZE])
{
	int i;
	chessPosArray* children = validArray[(*pos)[0] - 'A'][(*pos)[1] - '1'];
	treeNodeListCell* child;
	treeNode* res = (treeNode*)malloc(sizeof(treeNode));
	checkAlloc(res, "findAllPossibleKnightPathsHelper");

	res->next_possible_positions = NULL;
	res->position[0] = (*pos)[0];
	res->position[1] = (*pos)[1];
	
	if (hasNoChildren(children, boolArray))
		return res;

	boolArray[(*pos)[0] - 'A'][(*pos)[1] - '1'] = true;
	
	for (i = 0; i < children->size; i++)
		if (boolArray[(children->positions[i])[0] - 'A'][(children->positions[i])[1] - '1'] == false)
		{
			child = createNewNode(NULL, NULL);
			child->node = findAllPossibleKnightPathsHelper(children->positions[i], validArray, boolArray);
			if (child->node)
				insertNodeToStart(child, res);
		}

	boolArray[(*pos)[0] - 'A'][(*pos)[1] - '1'] = false;
	return res;
}

void insertNodeToStart(treeNodeListCell* node, treeNode* tr)
{
	node->next = tr->next_possible_positions;
	tr->next_possible_positions = node;
}

bool hasNoChildren(chessPosArray* children, bool boolAraay[][SIZE])
{
	int i;
	bool flag = true;

	for (i = 0; i < children->size; i++)
		if (boolAraay[(children->positions[i])[0] - 'A'][(children->positions[i])[1] - '1'] == false)
			flag = false;
	
	return flag;
}

treeNodeListCell* createNewNode(treeNode* tree, treeNodeListCell* next)
{
	treeNodeListCell* res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	checkAlloc(res, "createNewNode");

	res->node = tree;
	res->next = next;

	return res;
}

void printPath(pathTree path)
{
	printPathAux(path.root);
}

void printPathAux(treeNode* root)
{
	int counter = 0;
	chessPosCell* curr = root->next_possible_positions;

	if (!root)
		return;

	else
	{
		printf("[%c%c] -->", (root->position)[0], (root->position)[1]);

		while (curr)
		{
			printPathAux(root->next_possible_positions->node);
			curr = curr->next;
		}		
	}
}

void freegTree(pathTree gTr)
{
	freegTreeHelper(gTr.root);
}

void freegTreeHelper(treeNode* root)
{
	treeNodeListCell* curr, * saver;
	if (root != NULL)
	{
		curr = root->next_possible_positions;
		while (curr != NULL)
		{
			saver = curr->next;
			freegTreeHelper(curr->node);
			curr = saver;
		}
		free(root);
	}
}


