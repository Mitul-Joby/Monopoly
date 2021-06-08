// Accepts game mode choice from user 
// Returns the choice
int SelectGamemode();

// Reads location informations from file and stores them in structures.
// Returns EXIT_SUCCESS if read properly.
int ReadLocations();

// Reads a random card information from file based on card type and stores in a structure
// Returns EXIT_SUCCESS if read properly.
int ReadCards(int CardType);