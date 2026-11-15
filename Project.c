#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

#include "ProjectFunctions.c"

int main()
{	
	srand(time(NULL));
	
	bool bDisplay = 1; // condition for loop display
	int nSelect; // recieve getch() from user
	int nPosition = 0; // position of current cursor
	
	while(bDisplay)
	{	
		printf("\033[?25l");
		printf("\033[3J\033[2J");
		
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
					bDisplay = 0;
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
	bDisplay = 1;
	nPosition = 0;
	
	int nPlayer = 2, nTile = 12, nDice = 2; // initialize player, tile, dice
	
	while (bDisplay)
	{	
		printf("\033[3J\033[2J");
		displaySettings(nPosition, nPlayer, nTile, nDice);
		
		nSelect = getch();
		if (nSelect == 0 || nSelect == 224)
		{
			nSelect = getch();
			if (nSelect == 72) // up
				nPosition = (nPosition + 2) % 3;
			else if (nSelect == 80) // down
				nPosition = (nPosition + 1) % 3;
			else if (nSelect == 75 || nSelect == 77) // left, right
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
			bDisplay = 0;
	}	
	
	//------------------------------------------------//
	
	
	// initialize players
	Player stPlayers[nPlayer];
	initializePlayers(stPlayers, nPlayer, nTile);
	displayGame(stPlayers[0], nTile);
	
	
	
	return 0;
}