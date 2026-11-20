#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ProjectFunctions.h"


// ------------------display functions------------------
void displayMenu(int nPosition)
{
	printf("\033[1J");
	
	printf("\033[36m"); // blue
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
    	printf("\033[23;56H\033[33m> START\033[0m\n"); // yellow
	else
		printf("\033[23;56HSTART\n");
	
	// INSTRUCTION DISPLAY
	if (nPosition == 1)
		printf("\033[24;56H\033[33m> INSTRUCTIONS\033[0m\n"); // yellow
	else
		printf("\033[24;56HINSTRUCTIONS\n");
	
	// EXIT DISPLAY
	if (nPosition == 2)
		printf("\033[25;56H\033[33m> EXIT\033[0m\n"); // yellow
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
	printf("\033[1J");
	
    printf("\033[36m"); // blue
    printf("\033[5;45H+------------------------------------------+");
    printf("\033[6;45H|              GAME SETTINGS               |");
    printf("\033[7;45H+------------------------------------------+");
    printf("\033[0m\n");
    
    // PLAYERS
    if (nPosition == 0)
    	printf("\033[10;50H\033[33mPLAYERS\033[0m"); // yellow
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
		printf("\033[13;50H\033[33mTILES\033[0m"); // yellow
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
		printf("\033[16;50H\033[33mDICES\033[0m"); // yellow
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

void displayGame(Player stPlayers, int nTile, int nCursor, int aSelectedTile[], int aDice[], int nRollTotal, bool bRoll, int nDice)
{	
	printf("\033[1J");
	
	// display SHUT THE BOX and PLAYER ID
	printf("\033[36m"); // blue
    printf("\033[4;45H========================================");
    printf("\033[5;45H|             SHUT THE BOX             |");
    printf("\033[6;45H|           PLAYER %d'S TURN            |", stPlayers.nPlayerNumber);
    printf("\033[7;45H========================================");
    printf("\033[0m");
    
    // display tiles
    printf("\033[9;45HOPEN TILES:");
    printf("\033[11;45H");
    for (int i = 0; i < nTile; i++)
	{
	if (i % 6 == 0)
		printf("\033[%d;45H", 11 + 2 * (i / 6));
    if (stPlayers.aTile[i] == 1)
   		printf("\033[31m[ X]\033[0m   "); // red; shut tiles
    else if (!bRoll && i == nCursor)
        printf("\033[36m[%2d]\033[0m   ", i + 1); // blue; cursor pointed tile
    else if (aSelectedTile[i] == 1)
    	printf("\033[33m[%2d]\033[0m   ", i + 1); // yellow; selected tile
    else
    	printf("[%2d]   ", i + 1);
    }

	// display selected tiles
	printf("\033[17;45HSelected Tiles: ");
    for (int i = 0; i < nTile; i++)
    {
    	if (aSelectedTile[i] == 1)
    	{
    		printf("%d   ", i + 1);
		}
	}
	
	int nSelectedTotal = getSelectedTotal(aSelectedTile, nTile);
	
	printf("\033[18;45HTotal: \033[%dm%d\033[0m", !bRoll ? nSelectedTotal > nRollTotal ? 31 : nSelectedTotal == nRollTotal ? 32 : 0 : 0, nSelectedTotal); // green - equals to nRollTotal; red - exceed nRollTotal
	
	// display dices
	for (int i = 0; i < nDice; i++)
	{
		displayDice(aDice[i], i);
	}
	
	if (bRoll)
	{
    printf("\033[26;45H----------------------------------------");
    printf("\033[27;45H          Press ENTER to roll");
    printf("\033[28;45H----------------------------------------");
	}
	else
	{
    printf("\033[26;45HARROWS - Move | SPACE - Select");
    printf("\033[27;45HENTER - Confirm");
	}
}

void displayDice(int nRoll, int nPosition)
{
	char aDice[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	
	if (nRoll >= 2)
	{
		aDice[0][0] = '*';
		aDice[2][2] = '*';
	}
	
	if (nRoll >= 4)
	{
		aDice[0][2] = '*';
		aDice[2][0] = '*';
	}
	
	if (nRoll == 1 || nRoll == 3 || nRoll == 5)
		aDice[1][1] = '*';
		
	if (nRoll == 6)
	{
		aDice[1][0] = '*';
		aDice[1][2] = '*';
	}
	
	int nCol = 47 + nPosition * 12;
	printf("\033[20;%dH+-------+", nCol);
	for (int i = 0; i < 3; i++)
	{
		printf("\033[%d;%dH| %c %c %c |", 21 + i, nCol,aDice[i][0], aDice[i][1], aDice[i][2]); // starting row + i
	}
	printf("\033[24;%dH+-------+", nCol);
}


// ------------------ ------------------
int getSelectedTotal(int aSelectedTile[], int nTile)
{
	int nTileTotal = 0;
	
	for (int i = 0; i < nTile; i++)
    {
    	if (aSelectedTile[i] == 1)
    	{
    		nTileTotal += i + 1;
		}
	}
	
	return nTileTotal;
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

void initializePlayers(Player stPlayers[], int nPlayer, int nTile)
{
	for (int i = 0; i < nPlayer; i++)
	{
		stPlayers[i].nPlayerNumber = i + 1;
		stPlayers[i].nScore = 0;
		
		for (int j = 0; j < nTile; j++)
		{
			stPlayers[i].aTile[j] = 0; // 0 - open; 1 - shut
		}
	}
}

int rollDice(int nDice, int aDice[])
{
	int nRoll;
	int nRollTotal = 0;
	
	for (int i = 0; i < nDice; i++)
	{
		nRoll = rand() % 6 + 1;
		aDice[i] = nRoll;
		nRollTotal += nRoll;
	}
	
	return nRollTotal;
}

int modifyCursorPosition(Player stPlayers, int nTile, int nCursor, int nDirection)
{
	int nNewCursor = nCursor + nDirection;
	
	while (stPlayers.aTile[nNewCursor] == 1 && nNewCursor < nTile && nNewCursor >= 0)
	{
		nNewCursor += nDirection;
	}
	
	if (nNewCursor < nTile && nNewCursor >= 0)
		return nNewCursor;
	
	return nCursor;
}

void modifyPlayersTile(int nTile, int aSelectedTile[], Player* stPlayers)
{
	for (int i = 0; i < nTile; i++)
	{
		if (stPlayers->aTile[i] != 1)
		{
			stPlayers->aTile[i] = aSelectedTile[i];
			aSelectedTile[i] = 0; // set to default
		}	
	}
}

bool hasOpenTile(Player stPlayers, int nTile)
{
	for (int i = 0; i < nTile; i++)
	{
		if (stPlayers.aTile[i] == 0)
			return true;
	}
	return false;
}


int getScore(Player stPlayers, int nTile)
{
	int nScore = 0;
	for (int i = 0; i < nTile, i++)
	{
		if (stPlayers.aTile[i] == 0);
		{
			nScore += i + 1;
		}
	}
}
// testing functions
void testAllTilesShut(Player* stPlayers, int nTile)
{
	for (int i = 0; i < nTile; i++)
	{
		stPlayers->aTile[i] = 1;
	}
}

void testSinglePlayerGame(int* nPlayer)
{
	*nPlayer = 1;
}