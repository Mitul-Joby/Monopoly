#define SCREENSIZE_X    172
#define SCREENSIZE_Y    40

//Can be changed according to user requirement
#define INTIAL_AMT      1200
#define BANKRUPT_VALUE  -500
#define MAX_DOUBLES     3

//Path location
#define LOCATION_PATH   "data/locations.csv"

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYER      8
#define MAX_LOCATIONS   40

#define clearScreen()   system("@cls||clear")
#define goto_XY(X,Y)    printf("%c[%d;%df",0x1B,Y,X)
#define hideCursor()    printf("\e[?25l")
#define showCursor()    printf("\e[?25h")
#define colour(C1,C2)   printf("\033[%d;%dm",C2,C1)

enum Boolean  {False,True};
enum colours  {RESET,INCREASED_INTENSITY,BLACK=30,RED,GREEN,YELLOW,BLUE,PURPLE,CYAN,WHITE,BLACK_BG=100,RED_BG,GREEN_BG,YELLOW_BG,BLUE_BG,PURPLE_BG,CYAN_BG,WHITE_BG}; 
enum GameMode {NETWORTH,TURNS,ENDLESS,EXIT};
enum csvHead  {ID_H,LocType_H,LocName_H,SetID_H,ColourName_H,Cost_H,Rent_H,H1_H,H2_H,H3_H,H4_H,Hotel_H,BuildCost_H};
enum LocType  {FREE,CHEST,CHANCE,JAIL,TAX,UTILITY,RAIL,PROPERTY};
enum CardType {BAD=-1,NEUTRAL,GOOD};
enum MainMenu {ROLL,BUY,SELL,GIVEUP};

//Structure of location information
struct location
{       
    unsigned int ID:7, Type:3, isOwnable:1;
    char name[30];
    unsigned short int Cost;
    unsigned int SetID:4;
    char colourName[20];    
    unsigned short int intialRent, house[4], hotel, buildCost;
    unsigned int ownerID:4;
    unsigned int isSetComplete:1;
    unsigned int housesBuilt:3, hotelBuilt:1;
    int Rent;

}Location[MAX_LOCATIONS];

//Structure of card information
struct card
{
    int Type:3;
    unsigned Money, LocationID;
}drawnCard;

//Structure of player information
struct player
{
    unsigned int ID:7;
    char name[30];
    unsigned int colour1,colour2;
    short int networth, cashInHand;
    unsigned int position:6, isOut:1, isBankrupt:1, isInJail:1, JailTurn:2;
    struct location *currentLocation;    
    short unsigned int PropertyOwnedCount,SetsOwnedCount;
    short unsigned int PropertyOwned[20],SetsOwned[10];
};