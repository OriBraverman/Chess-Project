#define _CRT_SECURE_NO_WARNINGS
#include "utility.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Q7.h"

void chessMenu()
{
	int userChoice = 1, pathRes;
	chessPos userPos;
	pathTree userPathTree;
	userPathTree.root = NULL;
	chessPosList* pathList = NULL;
	char* fileName;

	while (userChoice != 6)
	{
		printMenu();
		scanf("%d", &userChoice);
		getchar();
		system("cls");

		switch (userChoice)
		{
		case 1:
			userPos[0] = '\0';
			userPos[1] = '\0';
			unvalidInput(userPos);
			break;

		case 2:
			unvalidInput(userPos);
			userPathTree = findAllPossibleKnightPaths(&userPos);
			break;

		case 3:
			if (!(userPathTree.root))
			{
				unvalidInput(userPos);
				userPathTree = findAllPossibleKnightPaths(&userPos);
			}
			pathList = findKnightPathCoveringAllBoard(&userPathTree);
			if (!pathList)
				printf("There is not path from this position\n");
			break;

		case 4:
			if (!pathList)
			{
				if (!(userPathTree.root))
				{
					unvalidInput(userPos);
					userPathTree = findAllPossibleKnightPaths(&userPos);
				}
				pathList = findKnightPathCoveringAllBoard(&userPathTree);
				if (!pathList)
					printf("There isn't a path from this position\n");
			}
			fileName = getFileName();
			saveListToBinFile(fileName, pathList);
			free(fileName);
			break;

		case 5:
			fileName = getFileName();
			pathRes = checkAndDisplayPathFromFile(fileName);
			printRes(pathRes, fileName);
			free(fileName);
			break;

		case 6:
			if (pathList)
				freeList(pathList);
			freegTree(userPathTree);
			system("cls");
			printf("\nGood Bye ! \n");
			break;

		default:
			printf("Please choose number between 1-6\n");
			break;
		}
	}
}

void printRes(int pathRes, char* fileName)
{
	switch (pathRes)
	{
	case -1:
		printf("Could't open file: %s\n", fileName);
		break;
	case 1:
		printf("Not valid knight path\n");
		break;
	case 2:
		printf("Path covers all board\n");
		break;
	case 3:
		printf("Path do not cover all board\n");
		break;
	}
}
char* getFileName()
{
	int logSize = 0, phySize = 2;
	char c;
	char* res = (char*)malloc(sizeof(char) * phySize + 1);
	checkAlloc(res, "getFileName");

	printf("Please enter file name (press enter to end string) :");
	c = getchar();

	while (c != '\n')
	{
		res[logSize] = c;
		logSize++;
		if (logSize == phySize - 1)
		{
			phySize *= 2;
			res = (char*)realloc(res, sizeof(char) * phySize + 1);
			checkAlloc(res, "realloc, getFileName");
		}
		c = getchar();
	}
	res = (char*)realloc(res, sizeof(char) * logSize + 1);
	checkAlloc(res, "realloc, getFileName");

	res[logSize] = '\0';
	return res;
}

void unvalidInput(chessPos userPos)
{
	while (!isValidInput(userPos))
	{
		printf("Please enter valid coordinate: <A-H><1-8> :\n");
		userPos[0] = getchar();
		userPos[1] = getchar();
		getchar();
	} 
}

bool isValidInput(chessPos pos)
{
	return (pos[0] >= 'A' && pos[0] <= 'H' && pos[1] >= '1' && pos[1] <= '8');
}

void printMenu()
{
	printf(" \n\n");
	printf("***************************************************\n");
	printf("                                                   \n");
	printf("             Welcome To Knight Gambit              \n");
	printf("                                                   \n");
	printf("***************************************************\n\n");

	printf("Choose option from the following menu: \n");
	printf(" 1.\tEnter a knight's starting position. \n");
	printf(" 2.\tCreate all possible knight paths. \n");
	printf(" 3.\tFind a knight path covering all board. \n");
	printf(" 4.\tSave knight path covering all board to file.\n");
	printf(" 5.\tLoad and display path from file. \n");
	printf(" 6.\tExit.\n");
}