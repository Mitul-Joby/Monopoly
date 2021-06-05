#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define LOCATION_PATH "data/locations.csv"
#define CHEST_PATH    "data/chest.csv"
#define CHANCE_PATH   "data/chance.csv"

#define MAX_LOCATIONS   40
#define MAX_CHESTCARDS  1
#define MAX_CHANCECARDS 1
#define MAX_PLAYER      10

#define INTIAL_AMT    1200

enum Boolean  {False,True};
enum GameMode {NETWORTH,TURNS,ENDLESS,EXIT};
enum Type     {FREE,CHEST,CHANCE,JAIL,UTILITY,TAX,RAIL,PROPERTY};

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

struct card
{
    unsigned int ID:8, Type:3;
    char Description[100];
}drawnCard;

struct player
{
    unsigned int ID:7;
    char name[30];
    short int networth, cashInHand;
    unsigned int position:6, isBankrupt:1, isInJail:1, JailTurn:2;
    struct location *currentLocation;    
    short unsigned int PropertyOwned[20],SetsOwned[10];
};