//Can be changed according to user requirement
#define MAX_PLAYER      10
#define INTIAL_AMT      1200
#define BANKRUPT_VALUE  -500

//Set based on number of records in csv files
#define MAX_LOCATIONS   40
#define MAX_CHESTCARDS  1
#define MAX_CHANCECARDS 1

//Path locations of files
#define LOCATION_PATH "data/locations.csv"
#define CHEST_PATH    "data/chest.csv"
#define CHANCE_PATH   "data/chance.csv"

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

enum Boolean  {False,True};
enum GameMode {NETWORTH,TURNS,ENDLESS,EXIT};
enum Type     {FREE,CHEST,CHANCE,JAIL,TAX,UTILITY,RAIL,PROPERTY};
enum CardType {BAD=-1,NEUTRAL=0,GOOD=1};
enum MainMenu {ROLL,BUY,SELL,GIVEUP};

//Structure of location information
struct location
{       
    unsigned int ID:7, Type:3, isOwnable:1;
    char name[30];
    unsigned short int Cost;

    //Property Info
    unsigned int SetID:3;
    char colour[20];    
    unsigned short int intialRent, house[4], hotel, houseCost;
    unsigned int owner:4;
    unsigned int isSetComplete:1;
    unsigned int housesBuilt:3, hotelBuilt:1;
    int Rent;

}Location[MAX_LOCATIONS];

//Structure of card information
struct card
{
    unsigned int ID:8, Type:3, Money, LocationID;
    char Description[100];
}drawnCard;

//Structure of player information
struct player
{
    unsigned int ID:7;
    char name[30];
    short int networth, cashInHand;
    unsigned int position:6, isBankrupt:1, isInJail:1, JailTurn:2;
    struct location *currentLocation;    
    short unsigned int PropertyOwned[20],SetsOwned[10];
};