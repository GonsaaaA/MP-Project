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
    int nDice;
    int aTile[TILE_MAX];
} Player;

void displayMenu(int position);
void displayInstructions();
void displaySettings(int position, int player, int tile, int *dice);
void displayGame(Player stPlayers, int nTile, int nCursor, int aSelectedTile[], int aDice[], int nRollTotal, bool bRoll);
void displayDice(int nRoll, int nPosition);

int getSelectedTotal(int aSelectedTile[], int nTile);
void modifySettings(int* nNum, int nMin, int nMax, int nStep, int nDirection);
void initializePlayers(Player stPlayers[], int nPlayer, int nDice, int nTile);
int rollDice(Player stPlayers, int aDice[]);
int modifyCursorPosition(Player stPlayers, int nTile, int nCursor, int nDirection);
void modifyPlayersTile(int nTile, int aSelectedTile[], Player stPlayers[]);
bool hasOpenTile(Player stPlayers, int nTile);
bool hasValidTile(Player stPlayers, int nTile, int nRollTotal);
void chooseDiceNumber(Player stPlayers[], int nDice);

void testAllTilesShut(Player* stPlayers, int nTile);
void testSinglePlayerGame(int* nPlayer);
#endif