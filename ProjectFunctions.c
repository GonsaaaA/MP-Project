#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "ProjectFunctions.h"

void displayMenu(int position)
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
	
	printf("\033[23;54H%s START", position == 0 ? ">" : " ");
	printf("\033[24;54H%s INSTRUCTIONS", position == 1 ? ">" : " ");
	printf("\033[25;54H%s EXIT", position == 2 ? ">" : " ");
}

void displayInstructions()
{
	system("cls");
	printf("HOW TO PLAY\n");
	printf("1. Objective: Shut as many tiles numbered 1 to 12 as possible. The player with the lowest score wins.\n");
	printf("2. Roll the Dice: Players take turns rolling two dice and adding their values. Once tiles 7, 8, and 9 are all shut, the player may choose to roll one or two dice.\n");
	printf("3. Shut the Tiles: Select available tiles whose numbers add up to the dice total. For example, if you roll a total of 5, you can shut 5, 1 and 4, or 2 and 3.\n");
	printf("4. Continue Playing: Keep rolling and shutting tiles until no valid combination is available for the current roll.\n");
	printf("5. Scoring: Your score is the sum of all remaining open tiles. After both players finish, the player with the lowest score wins.\n");
	printf("6. Instant Win: If a player shuts all 12 tiles, they win immediately!\n");
	system("pause");
}

void displaySettings(int position, int player, int tile, int dice)
{
    printf("\033[36m");
    printf("\033[10;45H+------------------------------------------+\n");
    printf("\033[11;45H|              GAME SETTINGS               |\n");
    printf("\033[12;45H+------------------------------------------+\n");
    printf("\033[0m\n");
    
    if (position == 0)
    {
    	printf("\033[33m  > PLAYERS\033[0m\n");
	}
    
	
}

void modifySettings(int* num, int min, int max, int step, int direction)
{
	*num += step * direction;
	if (*num > max)
	{
		*num = min;
	}
	else if (*num < min)
	{
		*num = max;
	}
}