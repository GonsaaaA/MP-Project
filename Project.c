/*
	Description:     A console-based implementation of Shut the Box
               	 	 that allows 2 to 4 players to compete using
               	 	 configurable numbers of tiles and dice. Players
                	 aim to shut all tiles or achieve the lowest score.

	Programmed by:   Darwin Lu Lin
	Section:         S47B
	Last modified:   November 25, 2026
	Version:         1.0
	Acknowledgements:https://www.ascii-code.com/
					 https://www.ibm.com/docs/en/i/7.6.0?topic=extensions-standard-c-library-functions-table-by-name
					 https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
					 https://stackoverflow.com/questions/10463201/getch-and-arrow-codes
					 https://www.geeksforgeeks.org/dsa/subset-sum-problem-dp-25/
*/

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
	initializePlayers(stPlayers, nPlayer, nDice, nTile);
	
	// game page
	
	for (int i = 0; i < nPlayer; i++)
	{
		bool bRoll = true; // condition statement for roll or select
		bDisplay = true; // condition statement for game display
		int aSelectedTile[TILE_MAX] = {0}; // array storing the selection status of each tile 
										   // (0 for unselected and 1 for selected)
										   // initialize arrays to set of 0(unselected)
		int aDice[nDice]; // array storing value of dice
						  // for dice display
		int nCursor = 0; // stores current cursor position
		int nRollTotal = 0; // stores the total value of dice roll
		int nSelect; // recieves user input
		
		// initialize aDice
		for (int i = 0; i < nDice; i++)
		{
			aDice[i] = 1;
		}
		
		while (bDisplay)
		{
			displayGame(stPlayers[i], nTile, nCursor, aSelectedTile, aDice, nRollTotal, bRoll);
			
			nSelect = getch();
			if (nSelect == 27) // ESC
			{
				return 0;
			}
			else if (bRoll)
			{
				if (nSelect == 13) // ENTER
				{
					if (nDice == 2)
						chooseDiceNumber(&stPlayers[i], nDice);
					nRollTotal = rollDice(stPlayers[i], aDice);
					bRoll = false;
					
					if (!hasValidTile(stPlayers[i], nTile, nRollTotal))
					{
						displayGame(stPlayers[i], nTile, nCursor, aSelectedTile, aDice, nRollTotal, bRoll);
						stPlayers[i].nScore = getScore(stPlayers[i], nTile);
						bDisplay = false;
						
						printf("\033[26;45H\033[0J");
						printf("\033[26;57HYou Scored %d", stPlayers[i].nScore);
						printf("\033[28;50H== Press ENTER to continue == ");
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
						displayGame(stPlayers[i], nTile, nCursor, aSelectedTile, aDice, nRollTotal, bRoll);
						printf("\033[32;45HALL TILES SHUT! PLAYER %d WINS!\n", stPlayers[i].nPlayerNumber);
						bDisplay = false;
						system("pause");
						return 0;
					}
					else
					{
						// move cursor position to origin
						nCursor = 0;
						while (stPlayers[i].aTile[nCursor] == 1)
							nCursor++;
						bRoll = true;
					}
				}
			}
		}
	}
	
	// end game page
	
	
	return 0;
}