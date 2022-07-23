/************************************
Program name : Knight Gambit

Ori Braverman -- ID: 318917010 -- Class: Hadar Binsky
Sagi Goldfarb -- ID: 316496173 -- Class: Alon Schklar

9th June 2021
*************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Q7.h"

/*Q7 main*/
void main()
{
	chessMenu();
}




/*mains for debugging each question down below*/

/*Q6 main*/
//void main()
//{
//	printf("%d", checkAndDisplayPathFromFile("FullList.bin"));
//}

/*Q5 main*/
//void main()
//{
//	chessPosList lst;
//	chessPosCell y5 = { { 'E','3' } ,NULL };
//	chessPosCell y4 = { { 'A','1' },&y5 };
//	chessPosCell y3 = { { 'B','3' },&y4 };
//	chessPosCell y2 = { { 'A','4' },&y3 };
//	chessPosCell y1 = { { 'C','5' },&y2 };
//	lst.head = &y1;
//	lst.tail = &y5;
//
//	saveListToBinFile("Q5binaryList.bin", &lst);
//}

/*Q4 main*/
//void main()
//{
//	chessPos pos;
//	chessPosList* lst;
//	pathTree gTree;
//	pos[0] = 'A';
//	pos[1] = '1';
//	gTree = findAllPossibleKnightPaths(&pos);
//	lst = findKnightPathCoveringAllBoard(&gTree);
//	printList(lst);
//	//saveListToBinFile("FullList.bin", lst);
//}

/*Q3 main*/
//void main()
//{
//	chessPos pos;
//	pathTree gTree;
//	pos[0] = 'A';
//	pos[1] = '1';
//	gTree = findAllPossibleKnightPaths(&pos);
//	printPath(gTree);
//}

/*Q2 main*/
//void main()
//{
//	chessPosList lst;
//	chessPosCell a1, a2, a3, a4, a5;
//
//	a1.position[0] = 'B';
//	a1.position[1] = '5';
//
//	a2.position[0] = 'C';
//	a2.position[1] = '4';
//
//	a3.position[0] = 'B';
//	a3.position[1] = '5';
//
//	a4.position[0] = 'F';
//	a4.position[1] = '2';
//
//	a5.position[0] = 'B';
//	a5.position[1] = '4';
//
//	a1.next = &a2;
//	a2.next = &a3;
//	a3.next = &a4;
//	a4.next = &a5;
//	a5.next = NULL;
//
//	lst.head = &a1;
//	lst.tail = &a5;
//
//	printf("\nbefore: \n\n ");
//	printList(&lst);
//
//	printf("\display : \n \n");
//	display(&lst);
//}

/*Q1 main*/
//void main()
//{
//	chessPosArray*** knightArray = validKnightMoves();
//	printKnightArrayMoves(&knightArray);
//}