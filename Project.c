#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#include "ProjectFunctions.c"

int main()
{	
	bool display = 1;
	int select;
	int position = 0;
	
	while(display)
	{	
		printf("\033[?25l");
		displayMenu(position);
		
		select = getch();
		if (select == 0 || select == 224)
		{
			select = getch();
			if (select == 72) // up
			{
				position = (position + 2) % 3;
			}
			else if (select == 80) // down
			{
				position = (position + 1) % 3;
			}
		}
		else if (select == 13)
		{
			switch (position)
			{
				case 0:
					display = 0;
					break;
					
				case 1:
					displayInstructions();
					break;
					
				case 2:
					printf(" "); // ending statement
					return 0;
			}
		}
		
		printf("\033[2J\033[H");
	}
	
	//------------------------------------------------//
	
	display = 1;
	position = 0;
	
	int player = 2, tile = 12, dice = 2; 
	
	while (display)
	{	
		printf("\033[2J\033[H");
		displaySettings(position, player, tile, dice);
		
		select = getch();
		if (select == 0 || select == 224)
		{
			select = getch();
			if (select == 72) // up
			{
				position = (position + 2) % 3;
			}
			else if (select == 80) // down
			{
				position = (position + 1) % 3;
			}
			else if (select == 75 || select == 77)
			{
				int direction = select == 75 ? -1 : 1;
				switch (position)
				{
					case 0:
						modifySettings(&player, PLAYER_MIN, PLAYER_MAX, 1, direction);
					case 1:
						modifySettings(&tile, TILE_MIN, TILE_MAX, 3, direction);
					case 2:
						modifySettings(&dice, DICE_MIN, DICE_MAX, 1, direction);
				}
			}
		}
		else if (select == 13)
		{
			display = 0;
		}
	}		
	
	//------------------------------------------------//
	return 0;
}