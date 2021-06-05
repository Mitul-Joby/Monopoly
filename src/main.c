#include "definitions.h"
#include "game.h"
#include "player.h"

int main()
{
    system("@cls||clear");

    //intro()
    
    int GamemodeChoice=0;char Choice;
    while(True)
    {
        system("@cls||clear");
        printf("\nChoose a game mode:");
        printf("\n  1-Networth : First player to reach a certain amount wins");
        printf("\n  2-Turns    : Game ends after ceratin number of turns/rounds are over");
        printf("\n  3-Endless  : Game goes on untill everyone except one player gets bankrupt");
        printf("\n  X-Exit\n\n");
        Choice = getch();
        if (Choice == '1')
        {
            printf("\nGAMEMODE NETWORTH CHOSEN");
            GamemodeChoice = NETWORTH;
            break;
        }
        else if (Choice == '2')
        {
            printf("\nGAMEMODE TURNS CHOSEN");
            GamemodeChoice = TURNS;
            break;
        }
        else if (Choice == '3')
        {
            printf("\nGAMEMODE ENDLESS CHOSEN");
            GamemodeChoice = ENDLESS;
            break;
        }
        else if (Choice == 'X'|| Choice == 'x')
        {
            printf("\nEXITING...");
            exit(0);
        }
        else
        {
            printf("\n\nYou entered an invalid choice \"%c\". Enter any key to try again.",Choice);
            getch();
        }
    }
    printf("\nEnter any key to continue...");
    getch();
    system("@cls||clear");

    int PlayerCount;
    char Names[MAX_PLAYER][30];

    ReadPlayers(&PlayerCount,Names);
    SetPlayerOrder(PlayerCount,Names);
    if (ReadLocations()!=EXIT_SUCCESS){
        printf("\nFile could not be opened\n");
        return EXIT_FAILURE;
    }
   
    struct player Player[PlayerCount], *CurrentPlayer;
    printf("\n\nPlaying order based on highest roll of the dice:");
    for(int i=0;i<PlayerCount;i++){    
        strcpy(Player[i].name,Names[i]);
        printf("\n%s",Player[i].name);
        Player[i].networth = Player[i].cashInHand = INTIAL_AMT;
        Player[i].position = 0;
        Player[i].isBankrupt = Player[i].isInJail = False;
        Player[i].currentLocation = &Location[0];
    }

    printf("\n\nEnter any key to continue...");
    getch();
    system("@cls||clear");

    int ID=0,die1=0,die2=0,dieTotal=0,wasDouble=0;
    while (GamemodeChoice!=EXIT)
    {
        CurrentPlayer = &Player[ID];
        if(CurrentPlayer->isBankrupt)
        {
            ;
        }
        else
        {
            
            if(CurrentPlayer->isInJail)
            {
                printf("\n%s is in Jail, wait for %d turn(s) to play.",CurrentPlayer->name,CurrentPlayer->JailTurn+1);
                if(CurrentPlayer->JailTurn>0)
                    CurrentPlayer->JailTurn-=1;
                else
                {
                    CurrentPlayer->JailTurn=0;
                    CurrentPlayer->isInJail=False;
                }
            }
            else
            {
                //MENU
                    //BUY HOUSES/HOTEL
                    //SELL PROPERIES
                    //ROLL
                    //GIVE UP 

                //IF ROLL CHOSEN/CERTAIN TIME PASSES
                    //playerMoves()
                        //If passed go/start, give player $----
                        //If doubles, player can roll again
                            //If 2/3 doubles, go to jail
                printf("\n");
                if ( getch() == 'x')
                    exit(0);

                die1=PlayerRolls();die2=PlayerRolls();dieTotal=die1+die2;
                printf("\n%s rolls a %d and %d with a total of %d.",CurrentPlayer->name,die1,die2,dieTotal);
                if (die1==die2){
                    printf("\n%s got a double!",CurrentPlayer->name);
                    wasDouble+=1;
                }
                else
                    wasDouble=0;

                if (wasDouble==2)    
                {
                    CurrentPlayer->currentLocation=&Location[30];
                    printf("\n%s rolled a double again and is sent to %s for overspeeding.",CurrentPlayer->name,CurrentPlayer->currentLocation->name);
                    wasDouble=0;
                }
                else
                {
                    if ((CurrentPlayer->currentLocation->ID)+dieTotal > MAX_LOCATIONS)
                    {
                        printf("\n%s passed %s and collects $200",CurrentPlayer->name,Location[0].name);
                        CurrentPlayer->cashInHand += 200;
                        CurrentPlayer->networth   += 200; 
                        CurrentPlayer->currentLocation=&Location[((CurrentPlayer->currentLocation->ID)+dieTotal)-MAX_LOCATIONS-1];
                    }
                    else
                        CurrentPlayer->currentLocation=&Location[(CurrentPlayer->currentLocation->ID)+dieTotal-1];
                    printf("\n%s landed on %s.",CurrentPlayer->name,CurrentPlayer->currentLocation->name);
                    
                }
                switch(CurrentPlayer->currentLocation->Type)
                {
                    case FREE:
                    {
                        break;
                    }      
                    case CHEST: 
                    {
                        //DrawChestCard();
                        break;
                    }    
                    case CHANCE:    
                    {
                        //DrawChanceCard();
                        break;
                    }
                    case JAIL:     
                    {
                        CurrentPlayer->currentLocation=&Location[30];
                        //Ask wanna pay or go to jail for 3 turns (Maybe roll doubles?)
                            //if yea  
                                //subtract money
                                //CurrentPlayer->JailTurn=0;
                                //CurrentPlayer->isInJail=True;
                            //if nah
                                CurrentPlayer->isInJail=True;
                                CurrentPlayer->JailTurn=2;
                            
                        break;
                    }   
                    case TAX:      
                    {
                        CurrentPlayer->cashInHand -= CurrentPlayer->currentLocation->Cost;
                        CurrentPlayer->networth   -= CurrentPlayer->currentLocation->Cost; 
                        break;
                    } 
                    case UTILITY:
                    case RAIL:  
                    case PROPERTY:      
                    {
                        if(CurrentPlayer->currentLocation->isOwnable)
                        {
                            //MENU
                                //BUY PROPERIES
                        }
                        else
                        {
                            CurrentPlayer->cashInHand -= CurrentPlayer->currentLocation->Rent;
                            CurrentPlayer->networth   -= CurrentPlayer->currentLocation->Rent;
                            Player[CurrentPlayer->currentLocation->owner].cashInHand += CurrentPlayer->currentLocation->Rent;
                            Player[CurrentPlayer->currentLocation->owner].networth   += CurrentPlayer->currentLocation->Rent;
                        }
                        break;
                    }
                    default:   
                    {
                        printf("\nFile Value Error at Locaion Record %d",ID+1);
                        exit(0);
                    }
                    CurrentPlayer->isBankrupt=isPlayerBankrupt(CurrentPlayer->cashInHand);

                }    
            }
        }
        if (wasDouble!=0)
            printf("\n\n%s plays again.",CurrentPlayer->name);
        else if (ID+1>=PlayerCount)
            ID=0;
        else 
            ID++;
    }

    return EXIT_SUCCESS;
}