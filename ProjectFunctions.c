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
	
	// SHUT THE BOX
	printf("\033[36m"); // blue
	printf("\033[6;48H ____  _   _ _   _ _____");
    printf("\033[7;48H/ ___|| | | | | | |_   _|");
    printf("\033[8;48H\\___ \\| |_| | | | | | |");
    printf("\033[9;48H ___) |  _  | |_| | | |");
    printf("\033[10;48H|____/|_| |_|\\___/  |_|");
    printf("\033[12;54HT H E   B O X");
    
    // Left die
    printf("\033[7;34H+-------+");
    printf("\033[8;34H| o     |");
    printf("\033[9;34H|       |");
    printf("\033[10;34H|     o |");
    printf("\033[11;34H+-------+");

    // Right die
    printf("\033[7;79H+-------+");
    printf("\033[8;79H| o   o |");
    printf("\033[9;79H|   o   |");
    printf("\033[10;79H| o   o |");
    printf("\033[11;79H+-------+");
    
	printf("\033[0m");
	
	// START DISPLAY
	if (nPosition == 0)
		printf("\033[43;30m"); // yellow back; black fore
    printf("\033[19;51H    START GAME    \033[0m");
	
	// INSTRUCTION DISPLAY
	if (nPosition == 1)
		printf("\033[43;30m"); // yellow back; black fore
	printf("\033[22;51H   INSTRUCTIONS   \033[0m");
	
	// EXIT DISPLAY
	if (nPosition == 2)
		printf("\033[43;30m"); // yellow back; black fore
	printf("\033[25;51H    EXIT GAME     \033[0m");
}


/* 
	This function displays the game instructions, including the game
    mechanics, scoring system, and winning conditions.
    
	Precondition: None.
	@return None.
*/
void displayInstructions()
{
	printf("\033[1J");
	
	// HOW TO PLAY
    printf("\033[36m\033[3;51HH O W   T O   P L A Y\033[0m"); // blue
    
    // OBJECTIVE
    printf("\033[6;27H\033[33mOBJECTIVE\033[0m");
    printf("\033[7;27HShut as many tiles as possible, the player with the lowest score wins.");

    // ROLL THE DICE
    printf("\033[9;27H\033[33m01 / ROLL THE DICE\033[0m"); // yellow
    printf("\033[10;27HRoll the dice and add their values together.");
    
    printf("\033[36m"); // blue
    printf("\033[12;30H+-------+   +-------+");
    printf("\033[13;30H| o     |   | o     |");
    printf("\033[14;30H|       | + |   o   |  =  5");
    printf("\033[15;30H|     o |   |     o |");
    printf("\033[16;30H+-------+   +-------+");
    printf("\033[0m");

    // SHUT THE TILES
    printf("\033[18;27H\033[33m02 / SHUT THE TILES\033[0m"); // yellow
    printf("\033[19;27HSelect open tiles whose values add up to the dice total.");

    printf("\033[21;30H");
    printf("\033[36m[ 1] + [ 4]\033[0m"); // blue
    printf("    OR    ");
    printf("\033[36m[ 2] + [ 3]\033[0m"); // blue
    printf("    OR    ");
    printf("\033[36m[ 5]\033[0m"); // blue

    // SCORING AND WINNING
    printf("\033[23;27H\033[33mSCORING & WINNING\033[0m"); // yellow

    printf("\033[24;27HYour turn ends when no valid combination remains.");
    printf("\033[25;27HYour score is the sum of all remaining open tiles.");
    printf("\033[26;27HThe player with the lowest score wins.");

    printf("\033[27;27H\033[32mShut every tile to win immediately!\033[0m");
	printf("\n\n");
	
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
	printf("\033[21;44H%d PLAYERS  |  %d TILES  | %d DICE", nPlayer, nTile, *nDice);
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
    printf("\033[26;45HARROWS - Move");
    printf("\033[27;45HSPACE - Select");
    printf("\033[28;45HENTER - Confirm");
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
		aDice[0][0] = 'o';
		aDice[2][2] = 'o';
	}
	
	if (nRoll >= 4)
	{
		aDice[0][2] = 'o';
		aDice[2][0] = 'o';
	}
	
	if (nRoll == 1 || nRoll == 3 || nRoll == 5)
		aDice[1][1] = 'o';
		
	if (nRoll == 6)
	{
		aDice[1][0] = 'o';
		aDice[1][2] = 'o';
	}
	
	int nCol = 47 + nPosition * 12; // starting col + index * width
	printf("\033[20;%dH+-------+", nCol);
	for (int i = 0; i < 3; i++)
	{
		printf("\033[%d;%dH| %c %c %c |", 21 + i, nCol,aDice[i][0], aDice[i][1], aDice[i][2]); // starting row + i
	}
	printf("\033[24;%dH+-------+", nCol);
}


/* 
	This function displays GAME OVER using ASCII art
	
	Precondition: The positions are correct
	@return None.
*/
void displayGameOver()
{
	printf("\033[1J");
	
	printf("\033[36m"); // blue
    printf("\033[5;37H  ____    _    __  __ _____");
    printf("\033[6;37H / ___|  / \\  |  \\/  | ____|");
    printf("\033[7;37H| |  _  / _ \\ | |\\/| |  _|");
    printf("\033[8;37H| |_| |/ ___ \\| |  | | |___");
    printf("\033[9;37H \\____/_/   \\_\\_|  |_|_____|");
    
    printf("\033[5;67H  _____     _______ ____");
    printf("\033[6;67H / _ \\ \\   / / ____|  _ \\");
    printf("\033[7;67H| | | \\ \\ / /|  _| | |_) |");
    printf("\033[8;67H| |_| |\\ V / |___|  _ <");
    printf("\033[9;67H \\___/  \\_/  |_____|_| \\_\\");
    printf("\033[0m");
}


/* 
	This function displays the winner announcement and scoreboard
    according to player rankings.
    
	Precondition: stPlayers is sorted in ascending order of scores, nPlayer
				  is between 2 and 4, and nPosition is either 0 or 1.
	@param stPlayers is the array containing the ranked players' information.
	@param nPlayer is the total number of players.
	@param nPosition determines the highlighted menu option
	       (0 for Play Again and 1 for Main Menu).
	@return None.
*/
void displayRankV1(Player stPlayers[], int nPlayer, int nPosition)
{
    // WINNER ANNOUNCEMENT
    printf("\033[12;57H\033[32m"); // green
    if (stPlayers[0].nScore == stPlayers[1].nScore)
    {
    	printf("DRAW BETWEEN: ");
    	for (int i = 0; i < nPlayer; i++)
    	{
    		if (stPlayers[i].nScore == stPlayers[0].nScore)
    			printf("Player %d  ", stPlayers[i].nPlayerNumber);
		}
	}
	else
		printf("PLAYER %d WINS", stPlayers[0].nPlayerNumber);
	printf("\033[0m");
    
    // SCOREBOARD
    printf("\033[14;43H------------------------------------------");
    printf("\033[15;43H%-17s%-17s%s", "PLAYER", "SCORE", "RANK");
    printf("\033[16;43H------------------------------------------");
    
    int nRank = 1;
    for (int i = 0; i < nPlayer; i++)
    {
    	if (i > 0 && stPlayers[i].nScore != stPlayers[i - 1].nScore)
    		nRank = i + 1;
    	
    	printf("\033[%d;43HPlayer %-14d%-14d%d", 18 + i, stPlayers[i].nPlayerNumber, stPlayers[i].nScore, nRank);
	}
	
	printf("\033[23;43H------------------------------------------");
	
	// PLAY AGAIN
	printf("\033[25;57H");
	if (nPosition == 0)
        printf("\033[46;30m");
    printf("  PLAY AGAIN  \033[0m");
    
    // MAIN MENU
    printf("\033[27;57H");
    if (nPosition == 1)
        printf("\033[46;30m");
    printf("  MAIN MENU    \033[0m");
}



/* 
	This function displays the winner announcement and scoreboard
    according to player ID.
    
	Precondition: stPlayers is initialized, nPlayer is between 2 and 4,
	nWinner is the index of the player with the lowest score, and nPosition
	is either 0 or 1.
	@param stPlayers is the array containing players' information.
	@param nPlayer is the total number of players.
	@param nPosition determines the highlighted menu option
	       (0 for Play Again and 1 for Main Menu).
	@param nWinner is the index of the player with the lowest score.
	@return None.
*/
void displayRankV2(Player stPlayers[], int nPlayer, int nWinner, int nPosition)
{
    // WINNER ANNOUNCEMENT
    printf("\033[12;57H\033[32m"); // green
    int nDraw = 0;
    
    for (int i = 0; i < nPlayer; i++)
    {
    	if (stPlayers[i].nScore == stPlayers[nWinner].nScore)
    		nDraw++;
	}
	
    if (nDraw > 1)
    {
    	printf("DRAW BETWEEN: ");
    	for (int i = 0; i < nPlayer; i++)
    	{
    		if (stPlayers[i].nScore == stPlayers[nWinner].nScore)
    			printf("Player %d  ", stPlayers[i].nPlayerNumber);
		}
	}
	else
		printf("PLAYER %d WINS", stPlayers[nWinner].nPlayerNumber);
	printf("\033[0m");
    
    // SCOREBOARD
    printf("\033[14;43H------------------------------------------");
    printf("\033[15;43H%-17s%-17s%s", "PLAYER", "SCORE", "RESULT");
    printf("\033[16;43H------------------------------------------");
    
	for (int i = 0; i < nPlayer; i++)
    {   		
    	if (stPlayers[i].nScore == stPlayers[nWinner].nScore)
            printf("\033[32m"); // green
    	
    	printf("\033[%d;43HPlayer %-11d%-16d%s", 18 + i, stPlayers[i].nPlayerNumber, stPlayers[i].nScore, stPlayers[i].nScore == stPlayers[nWinner].nScore ? "WINNER" : "  --");
    	printf("\033[0m");
	}
	
	printf("\033[23;43H------------------------------------------");
	
	// PLAY AGAIN
	printf("\033[25;57H");
	if (nPosition == 0)
        printf("\033[46;30m");
    printf("  PLAY AGAIN  \033[0m");
    
    // MAIN MENU
    printf("\033[27;57H");
    if (nPosition == 1)
        printf("\033[46;30m");
    printf("  MAIN MENU   \033[0m");
}


/* 
	This function initializes each player's information by assigning
    a player number, setting the initial score to 0, assigning the
    configured number of dice, and setting all tiles to open.
    
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
	This function generates a random value ranging from 1 to 6 for each
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
	              at least nTile elements with values of 0 or 1.
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


/*
	This function sorts the players in ascending order of scores
    by comparing and swapping their structures
    
	Precondition: stPlayers is initialized, all player scores are calculated,
              	  and nPlayer is between 2 and 4.
	@param stPlayers is the array containing all players' information.
	@param nPlayer is the total number of players.
	@return None.
*/
void sortRank(Player stPlayers[], int nPlayer)
{
	for (int i = 0; i < nPlayer - 1; i++)
	{
		for (int j = i + 1; j < nPlayer; j++)
		{
			if (stPlayers[i].nScore > stPlayers[j].nScore)
			{
				Player stTemp = stPlayers[i];
				stPlayers[i] = stPlayers[j];
				stPlayers[j] = stTemp;
			}
		}
	}
}


/*
	This function determines the winner by comparing the scores
    of all players.
    
	Precondition: stPlayers is initialized, all player scores are
				  calculated, and nPlayer is between 2 and 4.
	@param stPlayers is the array containing all players' information.
	@param nPlayer is the total number of players.
	@return The array index of the player with the lowest score.
*/
int getWinner(Player stPlayers[], int nPlayer)
{
	int nWinner = 0;
	for (int i = 1; i < nPlayer; i++)
	{
		if (stPlayers[i].nScore < stPlayers[nWinner].nScore)
			nWinner = i;
	}
	
	return nWinner;
}


void testAllTilesShut(Player* stPlayers, int nTile)
{
	for (int i = 0; i < nTile; i++)
	{
		stPlayers->aTile[i] = 1;
	}
}


// -------------------------- testing functions --------------------------
void testSinglePlayerGame(int* nPlayer)
{
	*nPlayer = 1;
}

void testDisplayPlayers(Player stPlayers[], int nPlayer)
{
	for (int i = 0; i < nPlayer; i++)
	{
		printf("Player %d\n", stPlayers[i].nPlayerNumber);
		printf("Score %d\n\n", stPlayers[i].nScore);
	}
}