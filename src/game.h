
int intro();

int showRules();

// Accepts game mode choice from user 
// Returns the choice
int SelectGamemode();

// Reads location informations from file and stores them in structures
// Returns EXIT_SUCCESS if read properly
int ReadLocations();

// Generates random card information from locations file based on card type and stores it in a structure
// Returns EXIT_SUCCESS if read properly
int GenerateCard();

int displayMap();

int graphicalMove(struct player *currentPlayer,int OldLocationID,int NewLocationID);

int thankYou();