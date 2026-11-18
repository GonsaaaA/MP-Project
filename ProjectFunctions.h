#ifndef PROJECTFUNCTIONS_H
#define PROJECTFUNCTIONS_H

#define PLAYER_MAX 4
#define PLAYER_MIN 2
#define DICE_MAX 3
#define DICE_MIN 2
#define TILE_MAX 18
#define TILE_MIN 12

typedef struct
{
    int nPlayerNumber;
    int nScore;
    int aTile[TILE_MAX];
} Player;

void displayMenu(int position);
void displayInstructions();
void displaySettings(int position, int player, int tile, int dice);
void modifySettings(int* nNum, int nMin, int nMax, int nStep, int nDirection);
void initializePlayers(Player stPlayer[], int nPlayer, int nTile);
void displayTile(Player stPlayer, int nTile, int nCursor, int aSelectedTile[]);
int displaySelectedTile(int nTile, int aSelectedTile[], int nRollTotal);

int displayGame(Player stPlayer, int nTile, int nCursor, int aSelectedTile[], int aDice[], int nRollTotal, int bRoll, int nDice);

void displayDice(int nRoll, int nPosition);

int modifyCursorPosition(Player stPlayer, int nTile, int nCursor, int nDirection);
int validatingSelectedTile(int nTileTotal, int nRollTotal, int nTile, int aSelectedTile[], Player stPlayer);


#endif