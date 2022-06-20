#ifndef PLAYER_H_
#define PLAYER_H_

// Emulates player rolling a die
// Returns a random integer from 1-6
int PlayerRolls();

// Reads number of players and player names
// Returns EXIT_SUCCESS if read properly
int ReadPlayers(int *numberOfPlayers, char (*Names)[30]);

// Each player rolls two dice and player order is set according to highest values
// Returns EXIT_SUCCESS if set properly
int SetPlayerOrder(int numberOfPlayers, char (*Names)[30]);

// Initialise Player structure values
// Returns EXIT_SUCCESS if set properly
int InitialisePlayers(struct player Player[],int PlayerCount, char (*Names)[30]);

// Places the player on the screen according to their current position and clears the previous one
// Returns EXIT_SUCCESS if set properly
int GraphicalMove(struct player *currentPlayer,int OldLocationID,int NewLocationID);

// Accepts an integer input from the user within certain time
// Returns the integer or else returns the Default value given when time elapses
int TimedNumInput(int seconds,int Default);

// Accepts a character input from the user within certain time
// Returns the character or else returns the Default value given when time elapses
char TimedCharInput(int seconds,char Default);

// Clears right part of the screen form line given
// Returns EXIT_SUCCESS if cleared properly
int ClearRightScreen(int startLine);

// Player Menu with timed input
// Returns player choice: ROLL/BUY/SELL/GIVEUP
int PlayerMainMenu(struct player *CurrentPlayer);

// Calculates rent of location the player is currently on based on location type
// Returns rent of the location
int RentCalc(struct player *owner ,struct location *currentLocation, int rolled);

// Sell Menu for current player based on locations they own
// Returns EXIT_SUCCESS on success
int SellMenu(struct player *CurrentPlayer);

// Buy houses and hotels Menu for current player based on locations they own
// Returns EXIT_SUCCESS on success
int BuyHousesMenu(struct player *CurrentPlayer);

// Buy Property Menu for location player lands on
// Returns EXIT_SUCCESS on success
int BuyMenu(struct player *CurrentPlayer,struct location *currentLocation);

// Checks if player is bankrupt 
// Returns TRUE/FALSE
int IsPlayerBankrupt(int cashInHand);

// Shows leaderboards post game
// Returns EXIT_SUCCESS on successful display
int PlayerResults(struct player Player[],int PlayerCount);

#endif
