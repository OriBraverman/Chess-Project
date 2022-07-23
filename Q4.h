#ifndef Q4_H
#define Q4_H

/*Q4 functions*/

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);

void findKnightPathCoveringAllBoardHelper(treeNode* root, chessPosList* lst, int* level);

void freeListCells(chessPosList* lst);

void freeList(chessPosList* lst);

#endif // !Q4_H

