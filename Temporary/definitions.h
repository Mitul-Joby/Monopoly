#define MAX_PLAYER 10
#define INTIAL_AMT 1200
#define PATH "locations.csv"

enum Boolean {False,True};
enum Type {FREE,CHEST,CHANCE,JAIL,UTILITY,TAX,RAIL,PROPERTY};

struct location
{   

    unsigned int ID:7, Type:3, isOwnable:1;
    char name[30];
    unsigned short int Cost;

    //Property Info
    char colour[20];    
    unsigned int SetID:3;
    unsigned short int intialRent, house[4], hotel, houseCost;
    unsigned int owner:4;
    unsigned int isSetComplete:1;
    unsigned int housesBuilt:3, hotelBuilt:1;
    int Rent;

}Location[40];

struct player
{
    char name[30];
    short int networth, cashInHand;
    unsigned int position:6, isBankrupt:1, inJail:1;
    struct location *currentLocation;    
    short unsigned int PropertyOwned[20],SetsOwned[10];
};