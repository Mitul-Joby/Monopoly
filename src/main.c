#include "definitions.h"
#include "game.h"
#include "player.h"

int main()
{
    system("@cls||clear");

    //make infite loop perhaps

    //intro()
        //If doing map version,check if console size is enough, else resize it or ask player to resize
        //Name Heading
        //Options to choose:
        //  Play
        //  Read rules
    
    int GamemodeChoice = SelectGamemode();

    //Put cursor to bottom, maybe?
    printf("\nEnter any key to continue...");
    getch();
    system("@cls||clear");

    if (GamemodeChoice!=EXIT)
    {
        int PlayerCount;
        char Names[MAX_PLAYER][30];

        //Based on gamemode give choices to user 

        if (ReadPlayers(&PlayerCount,Names)!=EXIT_SUCCESS){
            printf("\nPlayers not read properly\n");
            return EXIT_FAILURE;
        }
        else if (SetPlayerOrder(PlayerCount,Names)!=EXIT_SUCCESS){
            printf("\nPlayers random order could not be set properly\n");
            return EXIT_FAILURE;
        }
        else if (ReadLocations()!=EXIT_SUCCESS){
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

        //Put cursor to bottom, maybe?
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
                    
                    //Ask wanna pay or stay in jail for 3 turns (Maybe roll doubles?)
                        //if yea  
                            //subtract money
                            //CurrentPlayer->JailTurn=0;
                            //CurrentPlayer->isInJail=False;
                            //say can play next turn
                        //if nah
                        printf("\n\n%s is in Jail, wait for %d turn(s) to play.",CurrentPlayer->name,CurrentPlayer->JailTurn+1);
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

                    //MAKE THIS A FUNCTION
                    // char Choice=0;
                    // for (int i=0;i<2;i++)
                    // {
                    //     system("@cls||clear");
                    //     printf("\nMENU FOR %s",CurrentPlayer->name);
                    //     printf("\nChoose an option:");
                    //     printf("\n  1-ROLL");
                    //     printf("\n  2-BUY HOUSES AND HOTELS");
                    //     printf("\n  3-SELL PROPERTIES");
                    //     printf("\n  X-GIVE UP");
                    //     printf("\n\nYou have 5 seconds or 1 will be chosen by default...");
                    //     Choice = TimedCharInput(5,0);
                    //     if(Choice ==0)
                    //     {
                    //         system("@cls||clear");
                    //         printf("\nYOU TOOK TOO LONG TO CHOOSE, ROLL WAS CHOSEN BY DEFAULT");
                    //         break;
                    //     }
                    //     else if(Choice =='1')
                    //     {
                    //         system("@cls||clear");
                    //         printf("\nYOU CHOSE TO ROLL");
                    //         break;
                    //     }    
                    //     else if(Choice =='2')
                    //     {
                    //         system("@cls||clear");
                    //         printf("\nYOU CHOSE TO BUY HOUSES AND HOTELS");
                    //         break;
                    //     }
                    //     else if(Choice =='3')
                    //     {
                    //         system("@cls||clear");
                    //         printf("\nYOU CHOSE TO SELL PROPERTIES");
                    //         break;
                    //     }
                    //     else if(Choice =='X'||Choice =='x')
                    //     {
                    //         system("@cls||clear");
                    //         printf("\nYOU CHOSE TO GIVE UP");
                    //         return 0;
                    //         break;
                    //     }
                    //     else
                    //     {
                    //         if(i==0)
                    //         {
                    //             printf("\nYOU CHOSE AN INVALID OPTION '%c'. YOU CAN TRY ONCE AGAIN.");
                    //             printf("\nPRESS ANY KEY TO CONTINUE...");
                    //             TimedCharInput(5,0);
                    //         }
                    //         else
                    //         {
                    //             system("@cls||clear");
                    //             printf("\nYOU CHOSE TO ROLL BY DEFAULT");
                    //             break;
                    //         }
                    //     }
                    // } 
                    // getch();

                    //IF ROLL CHOSEN/CERTAIN TIME PASSES
                        //playerMoves()
                            //If passed go/start, give player $----
                            //If doubles, player can roll again
                                //If 2/3 doubles, go to jail

                    
                    die1=PlayerRolls();die2=PlayerRolls();dieTotal=die1+die2;
                    printf("\n\n%s rolls a %d and %d with a total of %d.",CurrentPlayer->name,die1,die2,dieTotal);
                    if (die1==die2){
                        printf("\n%s got a double!",CurrentPlayer->name);
                        wasDouble+=1;
                    }
                    else
                        wasDouble=0;

                    if (wasDouble==2)    
                    {
                        CurrentPlayer->currentLocation=&Location[30];
                        printf("\nSince %s rolled a double again, they are sent to JAIL for overspeeding.",CurrentPlayer->name);
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
                            // if (ReadCards(CHEST)!=EXIT_SUCCESS){
                            //     printf("\nFile could not be opened\n");
                            //     return EXIT_FAILURE;
                            // }
                            //Something happens
                            break;
                        }    
                        case CHANCE:    
                        {
                            // if (ReadCards(CHANCE)!=EXIT_SUCCESS){
                            //     printf("\nFile could not be opened\n");
                            //     return EXIT_FAILURE;
                            // }
                            //Something happens
                            break;
                        }
                        case JAIL:     
                        {
                            CurrentPlayer->currentLocation=&Location[30];
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
                                    //
                            }
                            else
                            {
                                //Check if currrent player is owner or not
                                CurrentPlayer->cashInHand -= CurrentPlayer->currentLocation->Rent;
                                CurrentPlayer->networth   -= CurrentPlayer->currentLocation->Rent;
                                Player[CurrentPlayer->currentLocation->owner].cashInHand += CurrentPlayer->currentLocation->Rent;
                                Player[CurrentPlayer->currentLocation->owner].networth   += CurrentPlayer->currentLocation->Rent;
                            }
                            break;
                        }
                        default:   
                        {
                            printf("\nFile Value Error at Location Record %d",ID+1);
                            return EXIT_FAILURE;
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
            if (getch()=='x')
                GamemodeChoice=EXIT;
            //Do something based on gamemode
        }

        //Show player postions post game
    }
    
    //Thank you for playing message (perhaps)
    printf("\nThanks for playing");
    getch();
    system("@cls||clear");
    
    return EXIT_SUCCESS;
}