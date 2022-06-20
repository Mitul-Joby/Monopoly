#ifndef GAME_H_
#define GAME_H_

// Accepts game mode choice from user 
// Returns the choice NETWORTH/TURNS/ENDLESS/EXIT
int SelectGamemode();

// Reads location informations from file and stores them in structures
// Returns EXIT_SUCCESS if read properly
int ReadLocations();

// Generates random card information from locations file based on card type and stores it in a structure
// Returns EXIT_SUCCESS if read properly
int GenerateCard();

// Clears screen and displays monopoly map
// Returns EXIT_SUCCESS if displayed properly
int DisplayMap();

// Displays Property information graphically
// Returns EXIT_SUCCESS if displayed properly
int GraphicalPropertyInfo(struct player Players[],int playerCount);

#endif
