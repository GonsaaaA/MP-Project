#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ProjectFunctions.h"


/* 	
	This function displays the main menu and highlights the currently selected option.
	Precondition: nPosition must be an integer from 0 to 2.
	
	@param nPosition is the current position of the menu cursor.
	@return None.
*/
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


/* 
	This function displays the game instructions, including the game
    mechanics, scoring system, and winning conditions.
    
	Precondition: None.
	@return None.
*/
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


/* 
	This function displays the game settings and highlights the currently
    selected option. It also sets the number of dice to 3 when the
    number of tiles exceeds 12.
    
	Precondition: nPosition is between 0 and 2, nPlayer is between 2 and 4,
             	  nTile is either 12, 15, or 18, and nDice points to a
              	  integer containing either 2 or 3.
	@param nPosition is the current position of the settings cursor.
	@param nPlayer is the configured number of players.
	@param nTile is the configured number of tiles.
	@param nDice is the address of the configured number of dice.
	@return None.
*/
void displaySettings(int nPosition, int nPlayer, int nTile, int *nDice)
{
	printf("\033[1J");
	
    printf("\033[36m"); // blue
    printf("\033[5;40H+------------------------------------------+");
    printf("\033[6;40H|              GAME SETTINGS               |");
    printf("\033[7;40H+------------------------------------------+");
    printf("\033[0m\n");
    
    // PLAYERS
    if (nPosition == 0)
    	printf("\033[10;46H\033[33mPLAYERS\033[0m"); // yellow
	else
		printf("\033[10;46HPLAYERS\n");
	printf("\033[11;55H %s2%s %6s3%s %6s4%s", nPlayer == 2 ? "[" : " ",
													nPlayer == 2 ? "]" : " ",
													nPlayer == 3 ? "[" : " ",
													nPlayer == 3 ? "]" : " ",
													nPlayer == 4 ? "[" : " ",
													nPlayer == 4 ? "]" : " ");
	
	// TILES
	if (nPosition == 1)
		printf("\033[13;46H\033[33mTILES\033[0m"); // yellow
	else
		printf("\033[13;46HTILES");
	printf("\033[14;55H %s12%s %5s15%s %5s18%s",  nTile == 12 ? "[" : " ",
														nTile == 12 ? "]" : " ",
														nTile == 15 ? "[" : " ",
														nTile == 15 ? "]" : " ",
														nTile == 18 ? "[" : " ",
														nTile == 18 ? "]" : " ");
	
	// DICE
	if (nTile > 12)
		*nDice = 3;
	if (nPosition == 2)
		printf("\033[16;46H\033[33mDICE\033[0m"); // yellow
    else
		printf("\033[16;46HDICE");
	printf("\033[17;55H %s2%s %7s3%s",  *nDice == 2 ? "[" : " ",
										*nDice == 2 ? "]" : " ",
										*nDice == 3 ? "[" : " ",
										*nDice == 3 ? "]" : " ");
	
	printf("\033[20;40H\033[36m+------------------------------------------+\033[0m");
	printf("\033[21;44H%d PLAYERS  |  %d TILES  | %d DICES", nPlayer, nTile, *nDice);
	printf("\033[22;40H\033[36m+------------------------------------------+\033[0m");
	printf("\033[25;48H== PRESS ENTER TO START ==");
}


/* 
	This function displays the current player's game interface, including
    the open and shut tiles, selected tiles, dice, and controls.
    
	Precondition: stPlayers is initialized, nTile is either 12, 15, or 18,
          		  nCursor is between 0 and nTile - 1, and both arrays
              	  contain valid initialized values.
	@param stPlayers contains the current player's information.
	@param nTile is the total number of tiles.
	@param nCursor is the current position of the tile cursor.
	@param aSelectedTile is the array storing the selection status of each tile.
	@param aDice is the array storing the current values of the dice.
	@param nRollTotal is the total value of the dice roll.
	@param bRoll indicates whether the player is in the rolling phase (true)
  	       or the tile selection phase (false).
	@return None.
*/
void displayGame(Player stPlayers, int nTile, int nCursor, int aSelectedTile[], int aDice[], int nRollTotal, bool bRoll)
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
	
	// display tiles add-up total
	int nSelectedTotal = getSelectedTotal(aSelectedTile, nTile);
	printf("\033[18;45HTotal: \033[%dm%d\033[0m", !bRoll ? nSelectedTotal > nRollTotal ? 31 : nSelectedTotal == nRollTotal ? 32 : 0 : 0, nSelectedTotal); // green - equals to nRollTotal; red - exceed nRollTotal
	
	// display dice
	for (int i = 0; i < stPlayers.nDice; i++)
	{
		displayDice(aDice[i], i);
	}
	
	// display roll / arrow hint
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


/* 
	This function displays a visual representation of a die based on
    its rolled value and display position.
    
	Precondition: nRoll is between 1 and 6, and nPosition is between 0 and 2.
	@param nRoll is the rolled value of the die.
	@param nPosition is the index determining the display position of the die.
	@return None.
*/
void displayDice(int nRoll, int nPosition)
{
	char aDice[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // 2D array for displaying die;
	
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
	
	int nCol = 47 + nPosition * 12; // starting col + index * width
	printf("\033[20;%dH+-------+", nCol);
	for (int i = 0; i < 3; i++)
	{
		printf("\033[%d;%dH| %c %c %c |", 21 + i, nCol,aDice[i][0], aDice[i][1], aDice[i][2]); // starting row + i
	}
	printf("\033[24;%dH+-------+", nCol);
}


void displayResult(Player stPlayers[])
{
	printf("\033[1J");
	
	printf("\033[4;45H\033[36mGAME OVER\033[0m");
	
}


/* 
	This function initializes each player's information by assigning
    a player number, setting the initial score to 0, assigning the
    configured number of dice, and set all tiles to open.
    
	Precondition: nPlayer is between 2 and 4, nDice is either 2 or 3,
	              nTile is either 12, 15, or 18, and stPlayers has
	              sufficient space to store players.
	@param stPlayers is the array of Player structures to be initialized.
	@param nPlayer is the total number of players.
	@param nDice is the number of dice assigned to each player.
	@param nTile is the total number of tiles assigned to each player.
	@return None.
*/
void initializePlayers(Player stPlayers[], int nPlayer, int nDice, int nTile)
{
	for (int i = 0; i < nPlayer; i++)
	{
		stPlayers[i].nPlayerNumber = i + 1;
		stPlayers[i].nScore = 0;
		stPlayers[i].nDice = nDice;
		
		for (int j = 0; j < nTile; j++)
		{
			stPlayers[i].aTile[j] = 0; // 0 - open; 1 - shut
		}
	}
}


/* 
	This function calculates the sum of the values of all selected tiles.
	
	Precondition: nTile is either 12, 15, or 18, and aSelectedTile contains
	              at least nTile elements initialized to either 0 or 1.
	@param aSelectedTile is the array storing the selection status of each
	       tile (0 for unselected and 1 for selected).
	@param nTile is the total number of tiles.
	@return the sum of the values of all selected tiles.
*/
int getSelectedTotal(int aSelectedTile[], int nTile)
{
	int nTileTotal = 0; // stores the total value of selected tiles
	
	for (int i = 0; i < nTile; i++)
    {
    	if (aSelectedTile[i] == 1)
    		nTileTotal += i + 1;
	}
	
	return nTileTotal;
}


/* 
	This function modifies the value of a setting by increasing or
    decreasing it by a specified step. The value wraps around when
    it exceeds the maximum or falls below the minimum.
    
	Precondition: nNum points to a integer within the specified range,
	              nMin is less than or equal to nMax, nStep is positive,
	              and nDirection is either -1 or 1.
	@param nNum is the address of the variable to be modified.
	@param nMin is the minimum allowed value.
	@param nMax is the maximum allowed value.
	@param nStep is the amount by which the value changes.
	@param nDirection determines whether to decrease (-1) or increase (1)
	       the value.
	@return None.
*/
void modifySettings(int* nNum, int nMin, int nMax, int nStep, int nDirection)
{
	*nNum += nStep * nDirection;
	if (*nNum > nMax)
		*nNum = nMin;
	else if (*nNum < nMin)
		*nNum = nMax;
}


/* 
	This function generates a random value range from 1 to 6 for each
				  die and calculates the total roll value.
    
	Precondition: stPlayers is initialized, stPlayers.nDice is between
	              1 and 3, aDice has sufficient space to store the dice
	              values, and the random number generator has been seeded.
	@param stPlayers contains the current player's information,
	       including the number of dice to roll.
	@param aDice is the array used to store the generated dice values.
	@return the sum of all rolled dice values.
*/
int rollDice(Player stPlayers, int aDice[])
{
	int nRoll;
	int nRollTotal = 0;
	
	for (int i = 0; i < stPlayers.nDice; i++)
	{
		nRoll = rand() % 6 + 1;
		aDice[i] = nRoll;
		nRollTotal += nRoll;
	}
	
	return nRollTotal;
}


/* 
	This function modifies the cursor position while skipping shut tiles.
	If no open tile is available in that direction, the original cursor
	position is retained.
    
	Precondition: stPlayers is initialized, nTile is either 12, 15, or 18,
	              nCursor is between 0 and nTile - 1, and nDirection
	              is either -6, 6, -1, or 1.
	@param stPlayers contains the current player's information.
	@param nTile is the total number of tiles.
	@param nCursor is the current position of the tile cursor.
	@param nDirection determines the direction of cursor movement
	       (-6 for up, 6 for down, -1 for left, and 1 for right).
	@return the new cursor position if valid, otherwise the original
	        cursor position.
*/
int modifyCursorPosition(Player stPlayers, int nTile, int nCursor, int nDirection)
{
	int nNewCursor = nCursor + nDirection;
	
	while (nNewCursor < nTile && nNewCursor >= 0 && stPlayers.aTile[nNewCursor] == 1)
	{
		nNewCursor += nDirection;
	}
	
	if (nNewCursor < nTile && nNewCursor >= 0)
		return nNewCursor;
	
	return nCursor;
}


/*
	This function shuts the selected tiles of the current player
    and resets their selection status to 0.
    
	Precondition: stPlayers points to an initialized Player structure,
	              nTile is either 12, 15, or 18, aSelectedTile contains
	              at least nTile elements with values of 0 or 1, and
	              the selected tiles contains nTile elements with values
				  of 0 or 1.
	@param nTile is the total number of tiles.
	@param aSelectedTile is the array storing the selection status of each tile.
	@param stPlayers points to the current player's structure whose tiles
	       are to be modified.
	@return None.
*/
void modifyPlayersTile(int nTile, int aSelectedTile[], Player stPlayers[])
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


/* 
	This function checks whether current player has at least one
	remaining open tile.
    
	Precondition: stPlayers is initialized, nTile is either 12, 15, or 18,
	              and each tile has a value of 0 or 1.
	@param stPlayers contains the current player's information.
	@param nTile is the total number of tiles.
	@return true if at least one tile is open, otherwise false.
*/
bool hasOpenTile(Player stPlayers, int nTile)
{
	for (int i = 0; i < nTile; i++)
	{
		if (stPlayers.aTile[i] == 0)
			return true;
	}
	return false;
}


/* 
	This function checks whether any combination of the remaining open
	tiles can sum up to the dice roll total using recursion
	
	Precondition: stPlayers is initialized, nTile is between 0 and TILE_MAX,
	              and nRollTotal is a non-negative integer.
	@param stPlayers contains the current player's information.
	@param nTile is the number of tiles remaining to be checked.
	@param nRollTotal is the target sum to be achieved.
	@return true if a valid combination of open tiles exists,
	        otherwise false.
*/
bool hasValidTile(Player stPlayers, int nTile, int nRollTotal)
{
	if (nRollTotal == 0)
		return true;
		
	if (nTile == 0)
		return false;
		
	if (stPlayers.aTile[nTile - 1] == 1)
		return hasValidTile(stPlayers, nTile - 1, nRollTotal);
		
	if (nTile > nRollTotal)
		return hasValidTile(stPlayers, nTile - 1, nRollTotal);
		
	return hasValidTile(stPlayers, nTile - 1, nRollTotal) || hasValidTile(stPlayers, nTile - 1, nRollTotal - nTile);
}


/* 
	This function allows the current player to choose between 1 or
	2 dice when tiles 7, 8, and 9 have all been shut.
    
	Precondition: stPlayers points to an initialized Player structure,
	              and nDice is 2.
	@param stPlayers points to the current player's structure whose
	       number of dice may be modified.
	@param nDice is the maximum number of dice allowed, based on
	       the original game settings.
	@return None.
*/
void chooseDiceNumber(Player stPlayers[], int nDice)
{
	if (stPlayers->aTile[6] == 1 && stPlayers->aTile[7] == 1 && stPlayers->aTile[8] == 1) // 7, 8, 9
	{
		int nSelect;
		
		do
		{
			printf("\033[26;45H\033[0J");
			printf("\033[26;47HSelect Number of Dice for Next Roll");
			printf("\033[28;59H%s1%s   %s2%s", stPlayers->nDice == 1 ? "[" : " ",
											   stPlayers->nDice == 1 ? "]" : " ",
											   stPlayers->nDice == 2 ? "[" : " ",
											   stPlayers->nDice == 2 ? "]" : " ");
															  
			nSelect = getch();
			if (nSelect == 0 || nSelect == 224)
			{
				nSelect = getch();
				if (nSelect == 75 || nSelect == 77)
				{
					int nDirection = nSelect == 75 ? -1 : 1;
					modifySettings(&stPlayers->nDice, 1, nDice, 1, nDirection);
				}
			}
		} while (nSelect != 13);
	}
}


/*
	This function calculates the current player's score by summing
    the values of all remaining open tiles.
    
	Precondition: stPlayers is initialized, nTile is either 12, 15, or 18,
	              and each tile has a value of 0 or 1.
	@param stPlayers contains the current player's information.
	@param nTile is the total number of tiles.
	@return the sum of all remaining open tile values.
*/
int getScore(Player stPlayers, int nTile)
{
	int nScore = 0;
	
	for (int i = 0; i < nTile; i++)
	{
		if (stPlayers.aTile[i] == 0)
			nScore += i + 1;
	}
	
	return nScore;
}


// -------------------------- testing functions --------------------------
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