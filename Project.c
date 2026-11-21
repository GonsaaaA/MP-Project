#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

#include "ProjectFunctions.c"

int main()
{	
	srand(time(NULL));
	bool bDisplay = true; // condition for loop display
	int nSelect; // recieve getch() from user
	int nPosition = 0; // position of current cursor
	int nPlayer = PLAYER_MIN, nTile = TILE_MIN, nDice = DICE_MIN; // initialize player, tile, dice
	
	// start page
	
	while(bDisplay)
	{	
		printf("\033[?25l");
		
		displayMenu(nPosition);
		
		nSelect = getch();
		if (nSelect == 0 || nSelect == 224)
		{
			nSelect = getch();
			if (nSelect == 72) // up
				nPosition = (nPosition + 2) % 3;
			else if (nSelect == 80) // down
				nPosition = (nPosition + 1) % 3;
		}
		else if (nSelect == 13)
		{
			switch (nPosition)
			{
				case 0: // START
					bDisplay = false;
					break;
					
				case 1: // INSTRUCTIONS
					displayInstructions();
					break;
					
				case 2: // EXIT
					printf(" "); // ending statement
					return 0;
			}
		}
	}
	
	//------------------------------------------------//
	
	// set to default
	bDisplay = true;
	nPosition = 0;
	
	// setting page
	
	while (bDisplay)
	{	
		displaySettings(nPosition, nPlayer, nTile, &nDice);
		
		nSelect = getch();
		if (nSelect == 0 || nSelect == 224)
		{
			nSelect = getch();
			if (nSelect == 72) // UP
				nPosition = (nPosition + 2) % 3;
			else if (nSelect == 80) // DOWN
				nPosition = (nPosition + 1) % 3;
			else if (nSelect == 75 || nSelect == 77) // LEFT, RIGHT
			{
				int direction = nSelect == 75 ? -1 : 1;
				switch (nPosition)
				{
					case 0:
						modifySettings(&nPlayer, PLAYER_MIN, PLAYER_MAX, 1, direction);
						break;
					case 1:
						modifySettings(&nTile, TILE_MIN, TILE_MAX, 3, direction);
						break;
					case 2:
						modifySettings(&nDice, DICE_MIN, DICE_MAX, 1, direction);
						break;
				}
			}
		}
		else if (nSelect == 13) // game start
			bDisplay = !bDisplay;
		else if (nSelect == 27) // ESC
			return 0;
	}	
	
	//------------------------------------------------//
	
	
	// initialize players
	// testSinglePlayerGame(&nPlayer);
	Player stPlayers[nPlayer];
	initializePlayers(stPlayers, nPlayer, nTile);
	
	// game page
	
	for (int i = 0; i < nPlayer; i++)
	{
		bool bRoll = true; // condition statement for determining roll or select
		bDisplay = true; // condition statement for game display
		int aSelectedTile[TILE_MAX] = {0}; // initialize arrays to set of 0(open)
		int aDice[nDice]; // array stores value of dice
		int nCursor = 0; // records current cursor position
		int nRollTotal = 0; // records the total value of dice roll
		int nSelect; // recieves user input
		
		// initialize aDice
		for (int i = 0; i < nDice; i++)
		{
			aDice[i] = 1;
		}
		
		while (bDisplay)
		{
			displayGame(stPlayers[i], nTile, nCursor, aSelectedTile, aDice, nRollTotal, bRoll, nDice);
			
			nSelect = getch();
			if (nSelect == 27) // ESC
			{
				return 0;
			}
			else if (bRoll)
			{
				if (nSelect == 13) // ENTER
				{
					nRollTotal = rollDice(nDice, aDice);
					bRoll = false;
					
					if (!hasValidTile(stPlayers[i], nTile, nRollTotal))
					{
						displayGame(stPlayers[i], nTile, nCursor, aSelectedTile, aDice, nRollTotal, bRoll, nDice);
						stPlayers[i].nScore = getScore(stPlayers[i], nTile);
						bDisplay = false;
						
						printf("\033[26;45H\033[0J");
						printf("\033[26;57HYou Scored %d", stPlayers[i].nScore);
						printf("\033[28;53H== Press ENTER to continue == ");
						do
						{
							nSelect = getch();
						} while (nSelect != 13);
					}
				}
			}
			else if (nSelect == 0 || nSelect == 224) // special keys
			{
				nSelect = getch();
				
				switch (nSelect)
				{
					case 72: // UP
						nCursor = modifyCursorPosition(stPlayers[i], nTile, nCursor, -6);
						break;
					case 80: // DOWN
						nCursor = modifyCursorPosition(stPlayers[i], nTile, nCursor, 6);
						break;
					case 75: // LEFT
						nCursor = modifyCursorPosition(stPlayers[i], nTile, nCursor, -1);
						break;
					case 77: // RIGHT
						nCursor = modifyCursorPosition(stPlayers[i], nTile, nCursor, 1);
						break;
				}
			}
			else if (nSelect == 32) // SPACE
				aSelectedTile[nCursor] = !aSelectedTile[nCursor];
			else if (nSelect == 13) // ENTER
			{
			    // testAllTilesShut(&stPlayers[i], nTile);				
				if (getSelectedTotal(aSelectedTile, nTile) == nRollTotal)
				{
					modifyPlayersTile(nTile, aSelectedTile, &stPlayers[i]);
					if (!hasOpenTile(stPlayers[i], nTile))
					{
						displayGame(stPlayers[i], nTile, nCursor, aSelectedTile, aDice, nRollTotal, bRoll, nDice);
						printf("\033[32;45HALL TILES SHUT! PLAYER %d WINS!\n", i = 1);
						bDisplay = false;
						system("pause");
						return 0;
					}
					else
					{
						// move cursor position to origin
						for (int j = 0; j < nTile; j++)
						{
							if (stPlayers[i].aTile[j] == 0)
							{
								nCursor = j;
								break;
							}
						}
						bRoll = true;
					}
				}
			}
		}
	}
	
	// end game page
	
	
	return 0;
}