// Player rolls a die
// Returns a random value from 1-6
int PlayerRolls();

// Reads number of players and player names
// Returns EXIT_SUCCESS if read properly.
int ReadPlayers(int *numberOfPlayers, char (*Names)[30]);

// Each player rolls two dice and player order is set according to highest values
// Returns EXIT_SUCCESS if set properly.
int SetPlayerOrder(int numberOfPlayers, char (*Names)[30]);

// Accepts an integer input from the user within certain time
// Returns the integer or else returns the Default value given when time elapses
int TimedNumInput(int seconds,int Default);

// Accepts a character input from the user within certain time
// Returns the character or else returns the Default value given when time elapses
char TimedCharInput(int seconds,char Default);

int clearRightScreen(int startLine);

// Player Menu with timed input
// Returns player choice.
int PlayerMainMenu(struct player *CurrentPlayer);

int checkSet(struct player *currentPlayer ,struct location *currentLocation);

int RentCalc(struct player *owner ,struct location *currentLocation, int rolled);

int sellMenu(struct player *CurrentPlayer);

int buyHousesMenu(struct player *CurrentPlayer);

int buyMenu(struct player *CurrentPlayer,struct location *currentLocation);

// Checks if player is bankrupt 
int isPlayerBankrupt(int cashInHand);

int playerResults(struct player Player[],int PlayerCount);