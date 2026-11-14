#define PLAYER_MAX 4
#define PLAYER_MIN 2
#define DICE_MAX 3
#define DICE_MIN 2
#define TILE_MAX 18
#define TILE_MIN 12

void displayMenu(int position);
void displayInstructions();
void displaySettings(int position, int player, int tile, int dice);
void modifySettings(int* num, int min, int max, int step, int direction);