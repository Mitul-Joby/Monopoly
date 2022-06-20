#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

// System specific
#define SCREENSIZE_X    172
#define SCREENSIZE_Y    40

// Can be changed according to game requirement
#define INITIAL_AMT     1200                // Amount of money each player start with
#define BANKRUPT_VALUE -500                 // Min value of cash in hand to be not bankrupt
#define MAX_DOUBLES     3                   // Maximum die doubles a player can roll

// Path location of csv file
#define LOCATION_PATH   "data/locations.csv"

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sysSpecific.h"

#ifdef _WIN32
#include <conio.h>
#endif

#define clearScreen()   system("@cls||clear")
#define goto_XY(X,Y)    printf("%c[%d;%df",0x1B,Y,X)
#define hideCursor()    printf("\e[?25l")
#define showCursor()    printf("\e[?25h")
#define colour(C1,C2)   printf("\033[%d;%dm",C2,C1)

enum Boolean  {FALSE,TRUE};
enum colours  {RESET,INCREASED_INTENSITY,BLACK=30,RED,GREEN,YELLOW,BLUE,PURPLE,CYAN,WHITE,\
               RED_BG=41,GREEN_BG,YELLOW_BG,BLUE_BG,PURPLE_BG,CYAN_BG,WHITE_BG,\
               LIGHTBLACK_BG=100,LIGHTRED_BG,LIGHTGREEN_BG,LIGHTYELLOW_BG,LIGHTBLUE_BG,LIGHTPURPLE_BG,LIGHTCYAN_BG,PUREWHITE_BG}; 
enum GameMode {NETWORTH,TURNS,ENDLESS,EXIT};
enum csvHead  {ID_H,LocType_H,LocName_H,SetID_H,Cost_H,Rent_H,H1_H,H2_H,H3_H,H4_H,Hotel_H,BuildCost_H};
enum LocType  {FREE,CHEST,CHANCE,JAIL,TAX,UTILITY,RAIL,PROPERTY};
enum CardType {BAD=-1,NEUTRAL,GOOD};
enum MainMenu {ROLL,BUY,SELL,GIVEUP};

// Structure containing location information
extern struct location
{       
    unsigned int ID  :6;                    // Uniquely identify location (1-40)
    unsigned int type:3;                    // Type of location: FREE/CHEST/CHANCE/JAIL/TAX/UTILITY/RAIL/PROPERTY
    unsigned int isOwnable:1;               // If the location be owned currently by a player
    char name[30];                          // Name of the location
    unsigned short int cost:10;             // Cost to buy the location 
    unsigned int setID:4;                   // Identify properties by set ID
    int setColour:8;                        // Colour associated with set
    unsigned short int initialRent:10;      // Initial rent of the property
    unsigned short int house[4];            // Rents with 1-4 houses 
    unsigned short int  hotel:10;           // Rents with 1 hotel
    unsigned short int buildCost:10;        // Cost of building a house or hotel
    unsigned int ownerID:4;                 // If owned, current owner's ID else 0
    unsigned int isSetComplete:1;           // If the set is complete
    unsigned int housesBuilt:3;             // Amount of houses built on the property
    unsigned int hotelBuilt:1;              // If a hotel is built on the property 
    int rent;                               // Current rent of the property
}\
Location[40];                               // Locations read from csv file

// Structure containing card information
extern struct card
{
    int type:3;                             // Type of card: BAD/NEUTRAL/GOOD
    unsigned int money;                     // Money associated with the card
    unsigned int locationID:6;              // Location ID associated with card 
} drawnCard;

// Structure containing player information
struct player
{
    unsigned int ID:4;                      // Uniquely identify player
    char name[30];                          // Name of player
    unsigned int colour1:7,colour2:7;       // Colour of player on screen
    short int netWorth;                     // The net worth of the player
    short int cashInHand;                   // Amount of cash player currently has  
    unsigned int isOut:1;                   // If the player is out of the game
    unsigned int isBankrupt:1;              // If the player is bankrupt
    unsigned int isInJail:1;                // If the player is in jail
    unsigned int jailTurn:2;                // Number of turns player left to leave jail
    struct location *currentLocation;       // The current location of the player (structure)
    unsigned short int propertyOwnedCount:6;// Amount of properties the player owns
    unsigned short int propertyOwned[20];   // Lists of properties the player owns
    unsigned int position:4;                // Position of the player post-game
};

#endif
