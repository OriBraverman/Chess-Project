#ifndef Q3_H
#define Q3_H

/*Q3 functions*/

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);

treeNode* findAllPossibleKnightPathsHelper(chessPos* pos, chessPosArray*** validArray, bool boolArray[][SIZE]);

void insertNodeToStart(treeNodeListCell* node, treeNode* tr);

bool hasNoChildren(chessPosArray* children, bool boolArray[][SIZE]);

treeNodeListCell* createNewNode(treeNode* tree, treeNodeListCell* next);

void printPath(pathTree path);

void printPathAux(treeNode* root);

void freegTree(pathTree gTr);

void freegTreeHelper(treeNode* root);

#endif // !Q3_H