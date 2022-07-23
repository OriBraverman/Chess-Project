#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5

typedef char chessPos[2];
typedef unsigned char BYTE;

typedef struct _chessPosArray
{
	unsigned int size;
	chessPos* positions;
} chessPosArray;

typedef struct pos
{
	int xpos;
	int ypos;
} POS;

/*Q2 structs*/
typedef struct _chessPosCell
{
	chessPos position;
	struct _chessPosCell* next;
} chessPosCell;

typedef struct chessPosList
{
	chessPosCell* head;
	chessPosCell* tail;
} chessPosList;

/*Q3 structs*/
typedef struct _treeNode treeNode;
typedef struct _treeNodeListCell treeNodeListCell;

typedef struct _treeNode
{
	chessPos position;
	treeNodeListCell* next_possible_positions; /*List position*/
}treeNode;

typedef struct _treeNodeListCell
{
	treeNode* node;
	struct _treeNodeListCell* next;
}treeNodeListCell;

typedef struct _pathTree
{
	treeNode* root;
}pathTree;

/*General functions*/
void checkAlloc(void* ptr, char* msg);
void makeEmptyList(chessPosList* lst);
bool isEmptyList(chessPosList* lst);
bool isInBoard(int row, int col);
void insertDataToListHead(chessPosList* lst, chessPos pos);
chessPosCell* createNewListNode(chessPos pos, chessPosCell* next);
void insertNodeToStartList(chessPosList* lst, chessPosCell* head);
int chess_pos_to_num(chessPos pos);
void checkFileOpen(FILE* fp, char* msg);

#endif