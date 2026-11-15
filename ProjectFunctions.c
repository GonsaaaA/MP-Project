#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "ProjectFunctions.h"

void displayMenu(int nPosition)
{
	printf("\033[36m");
	printf("\033[10;45H+-------------------------------+\n");
	printf("\033[11;45H|                               |\n");
	printf("\033[12;45H|    ____  _   _ _   _ _____    |\n");
	printf("\033[13;45H|   / ___|| | | | | | |_   _|   |\n");
	printf("\033[14;45H|   \\___ \\| |_| | | | | | |     |\n");
	printf("\033[15;45H|    ___) |  _  | |_| | | |     |\n");
	printf("\033[16;45H|   |____/|_| |_|\\___/  |_|     |\n");
	printf("\033[17;45H|                               |\n");
	printf("\033[18;45H+-------------------------------+\n");
	printf("\033[0m");
	
	// START DISPLAY
	if (nPosition == 0)
    	printf("\033[23;56H\033[33m> START\033[0m\n");
	else
		printf("\033[23;56HSTART\n");
	
	// INSTRUCTION DISPLAY
	if (nPosition == 1)
		printf("\033[24;56H\033[33m> INSTRUCTIONS\033[0m\n");
	else
		printf("\033[24;56HINSTRUCTIONS\n");
	
	// EXIT DISPLAY
	if (nPosition == 2)
		printf("\033[25;56H\033[33m> EXIT\033[0m\n");
    else
		printf("\033[25;56HEXIT\n");
}

void displayInstructions()
{
	system("cls");
	printf("==================HOW TO PLAY==================\n");
	printf("1. Objective: Shut as many tiles numbered 1 to 12 as possible. The player with the lowest score wins.\n");
	printf("2. Roll the Dice: Players take turns rolling two dice and adding their values. Once tiles 7, 8, and 9 are all shut, the player may choose to roll one or two dice.\n");
	printf("3. Shut the Tiles: Select available tiles whose numbers add up to the dice total. For example, if you roll a total of 5, you can shut 5, 1 and 4, or 2 and 3.\n");
	printf("4. Continue Playing: Keep rolling and shutting tiles until no valid combination is available for the current roll.\n");
	printf("5. Scoring: Your score is the sum of all remaining open tiles. After both players finish, the player with the lowest score wins.\n");
	printf("6. Instant Win: If a player shuts all 12 tiles, they win immediately!\n");
	system("pause");
}

void displaySettings(int nPosition, int nPlayer, int nTile, int nDice)
{
    printf("\033[36m");
    printf("\033[5;45H+------------------------------------------+");
    printf("\033[6;45H|              GAME SETTINGS               |");
    printf("\033[7;45H+------------------------------------------+");
    printf("\033[0m\n");
    
    // PLAYERS
    if (nPosition == 0)
    	printf("\033[10;50H\033[33mPLAYERS\033[0m");
	else
		printf("\033[10;50HPLAYERS\n");
	printf("\033[11;49H\t %s2%s \t %s3%s \t %s4%s", nPlayer == 2 ? "[" : " ",
													nPlayer == 2 ? "]" : " ",
													nPlayer == 3 ? "[" : " ",
													nPlayer == 3 ? "]" : " ",
													nPlayer == 4 ? "[" : " ",
													nPlayer == 4 ? "]" : " ");
	
	// TILES
	if (nPosition == 1)
		printf("\033[13;50H\033[33mTILES\033[0m");
	else
		printf("\033[13;50HTILES");
	printf("\033[14;49H\t %s12%s \t %s15%s \t %s18%s",  nTile == 12 ? "[" : " ",
														nTile == 12 ? "]" : " ",
														nTile == 15 ? "[" : " ",
														nTile == 15 ? "]" : " ",
														nTile == 18 ? "[" : " ",
														nTile == 18 ? "]" : " ");
	
	// DICES
	if (nPosition == 2)
		printf("\033[16;50H\033[33mDICES\033[0m");
    else
		printf("\033[16;50HDICES");
	printf("\033[17;49H\t %s2%s \t %s3%s",  nDice == 2 ? "[" : " ",
											nDice == 2 ? "]" : " ",
											nDice == 3 ? "[" : " ",
											nDice == 3 ? "]" : " ");
	
	printf("\033[20;45H\033[36m+------------------------------------------+\033[0m");
	printf("\033[21;49H%d PLAYERS  |  %d TILES  | %d DICES", nPlayer, nTile, nDice);
	printf("\033[22;45H\033[36m+------------------------------------------+\033[0m");
	printf("\033[24;53H== PRESS ENTER TO START ==");
}

void modifySettings(int* nNum, int nMin, int nMax, int nStep, int nDirection)
{
	*nNum += nStep * nDirection;
	if (*nNum > nMax)
	{
		*nNum = nMin;
	}
	else if (*nNum < nMin)
	{
		*nNum = nMax;
	}
}

void initializePlayers(Player stPlayer[], int nPlayer, int nTile)
{
	for (int i = 0; i < nPlayer; i++)
	{
		stPlayer[i].nPlayerNumber = i + 1;
		stPlayer[i].nScore = 0;
		
		for (int j = 0; j < nTile; j++)
		{
			stPlayer[i].nTile[j] = 1; // 1 - open; 0 - shut
		}
	}
}

void displayGame(Player stPlayer, int nTile)
{
	system("cls");
	printf("\033[36m");
    printf("\033[5;45H========================================");
    printf("\033[6;45H|             SHUT THE BOX             |");
    printf("\033[7;45H|           PLAYER %d'S TURN           |", stPlayer.nPlayerNumber);
    printf("\033[8;45H========================================");
    printf("\033[0m");
    
    for (int i = 0; i < nTile; i++)
	{
    if (stPlayer.nTile[i] == 1)
        printf("\033[32m[%2d]\033[0m ", i + 1);
    else
        printf("\033[31m[ X]\033[0m ");

    if ((i + 1) % 6 == 0)
        printf("\n");
	}
}

int rollDice(int nDice)
{
	int nRoll, nTotal;
	
	for (int i = 0; i < nDice; i++)
	{
		nRoll = rand() % 6 + 1;
		nTotal += nRoll;
	}
	
	return nTotal;
}

void displayPlayerTileTest(Player stPlayer[], int nPlayer, int nTile){
	
	system("cls");
	
	for (int i = 0; i < nPlayer; i++)
	{
		printf("%d\n", stPlayer[i].nPlayerNumber);
		for (int j = 0; j < nTile; j++)
		{
			printf("%d ", stPlayer[i].nTile[j]);
		}
		printf("\n");
	}
}
	