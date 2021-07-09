#include "definitions.h"
#include "game.h"
#include "player.h"

int mainGame()
{
    clearScreen();

    hideCursor();
    int GamemodeChoice = SelectGamemode(),maxNetworth,maxTurns;
    showCursor();

    if (GamemodeChoice == NETWORTH)
    {
        printf("\n\n\tEnter maximum networth after which game is to end: ");
        scanf("%d",&maxNetworth);
    }
    else if (GamemodeChoice == TURNS)
    {
        printf("\n\n\tEnter maximum turns after which game is to end: ");
        scanf("%d",&maxTurns);
    }
    clearScreen();
    
    if (GamemodeChoice!=EXIT)
    {
        int PlayerCount;
        char Names[MAX_PLAYER][30];

        if (ReadLocations()!=EXIT_SUCCESS){
            printf("\nFile could not be opened\n");
            return EXIT_FAILURE;
        }
        else if (ReadPlayers(&PlayerCount,Names)!=EXIT_SUCCESS){
            printf("\nPlayers not read properly\n");
            return EXIT_FAILURE;
        }
        else if (SetPlayerOrder(PlayerCount,Names)!=EXIT_SUCCESS){
            printf("\nPlayers random order could not be set properly\n");
            return EXIT_FAILURE;
        }    

        struct player Player[PlayerCount], *CurrentPlayer;

        //Intialising player values
        for(int i=0;i<PlayerCount;i++){                    
            strcpy(Player[i].name,Names[i]);
            Player[i].ID = i+1;
            Player[i].networth = Player[i].cashInHand = INTIAL_AMT;
            Player[i].JailTurn = Player[i].position = Player[i].PropertyOwnedCount = Player[i].SetsOwnedCount =  0;
            Player[i].isOut = Player[i].isBankrupt = Player[i].isInJail = False;
            Player[i].currentLocation = &Location[0];
            for(int j=0;j<20;j++)
            {
                Player[i].PropertyOwned[j]=0;
                Player[i].SetsOwned[j]=0;
            }
            switch(Player[i].ID)
            {
                case 1 : Player[i].colour1=RED;    Player[i].colour2=0;break;
                case 2 : Player[i].colour1=GREEN;  Player[i].colour2=0;break;
                case 3 : Player[i].colour1=BLUE;   Player[i].colour2=0;break;
                case 4 : Player[i].colour1=PURPLE; Player[i].colour2=0;break;
                case 5 : Player[i].colour1=CYAN;   Player[i].colour2=0;break;
                case 6 : Player[i].colour1=YELLOW; Player[i].colour2=0;break;
                case 7 : Player[i].colour1=PURPLE; Player[i].colour2=INCREASED_INTENSITY;break;
                case 8 : Player[i].colour1=CYAN;   Player[i].colour2=INCREASED_INTENSITY;break;
            }
        }

        goto_XY(95,SCREENSIZE_Y-1);
        printf("\n\n\tEnter any key to continue...");
        getch();    
        clearScreen();

        displayMap();
        for(int i=0;i<PlayerCount;i++){
            graphicalMove(&Player[i],1,1);
        }

        int currentTurns=0,PlayersOut=0;
        int ID=0,die1=0,die2=0,dieTotal=0,wasDouble=0;
        while (GamemodeChoice!=EXIT)
        {
            colour(GREEN,INCREASED_INTENSITY);
            goto_XY(0,2);printf("\tTURN: %d     ",currentTurns+1);
            colour(RESET,0);
            CurrentPlayer = &Player[ID];
            if (!CurrentPlayer->isOut)
            {
                if (CurrentPlayer->isInJail)
                {
                    clearRightScreen(0);
                    goto_XY(95,3); printf("PLAYER: %s CASH IN HAND: $%d NETWORTH: $%d                              ",CurrentPlayer->name,CurrentPlayer->cashInHand,CurrentPlayer->networth);   
                    int stay=True;
                    if (CurrentPlayer->JailTurn==2)
                    {
                        goto_XY(95,5);printf("%s, do you want to pay to get out of jail or stay for %d more turns?",CurrentPlayer->name,CurrentPlayer->JailTurn+1);
                        goto_XY(95,6);printf("     1: Pay to leave");
                        goto_XY(95,7);printf("     2: Stay in Jail");
                        hideCursor();
                        char JailOpt=getch();
                        showCursor();   
                        while(!(JailOpt=='1'||JailOpt=='2'))
                        {
                            goto_XY(95,8);printf("Invalid option!You entered: %c  ",JailOpt);
                            goto_XY(95,9);printf("Re-enter your choice!");
                            JailOpt=getch();
                        }
                        switch(JailOpt)
                        {
                            case'1':stay = False;
                                    CurrentPlayer->cashInHand-=100;
                                    CurrentPlayer->networth-=100;  //Pay to leave
                                    CurrentPlayer->JailTurn=0;
                                    CurrentPlayer->isInJail=False;
                                    goto_XY(95,11);printf("You can play next turn.");
                                    break;
                                    
                            default:stay = True;
                        }
                    }
                    if (stay==True)
                    {
                        goto_XY(95,13);printf(" %s is in Jail, wait for %d turn(s) to play.",CurrentPlayer->name,CurrentPlayer->JailTurn+1);
                        if(CurrentPlayer->JailTurn>0)
                            CurrentPlayer->JailTurn-=1;
                        else
                        {
                            CurrentPlayer->JailTurn=0;
                            CurrentPlayer->isInJail=False;
                        }
                    }
                }
                else
                {
                    goto_XY(95,3); printf("PLAYER: %s CASH IN HAND: $%d NETWORTH: $%d                              ",CurrentPlayer->name,CurrentPlayer->cashInHand,CurrentPlayer->networth);   
                    clearRightScreen(16);
                    int Choice=0;
                    if (wasDouble==0)
                        Choice=PlayerMainMenu(CurrentPlayer); 
                    
                    
                    if (Choice!=GIVEUP)
                    {
                        if (Choice==BUY)
                            buyHousesMenu(CurrentPlayer);
                        else if (Choice==SELL)
                            sellMenu(CurrentPlayer);

                        Choice=ROLL;
                        die1=PlayerRolls();die2=PlayerRolls();dieTotal=die1+die2;
                        goto_XY(95,20);printf("%s rolls a %d and %d with a total of %d.",CurrentPlayer->name,die1,die2,dieTotal);
                        if (die1==die2)
                        {
                            goto_XY(95,21);printf("%s got a double!",CurrentPlayer->name);
                            wasDouble+=1;
                        }
                        else
                            wasDouble=0;
                        int Teleported;
                        if (wasDouble==MAX_DOUBLES)    
                        {
                            //Sending player to jail for two sets of doubles in a row
                            int OldLocationID = CurrentPlayer->currentLocation->ID;
                            CurrentPlayer->currentLocation=&Location[30];
                            goto_XY(95,23);printf("Since %s rolled a double again, they are sent to JAIL for overspeeding.",CurrentPlayer->name);
                            graphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);                            
                            wasDouble=0;   
                        }
                        else
                        {
                            //Moving current players's current location and checking if they passed START

                            //Reaches here when player draws a NEUTRAL card
                            LocationTeleporter: ;
                            int OldLocationID = CurrentPlayer->currentLocation->ID;
                            if ((CurrentPlayer->currentLocation->ID)+dieTotal > MAX_LOCATIONS)
                            {
                                graphicalMove(CurrentPlayer,CurrentPlayer->currentLocation->ID,30);
                                goto_XY(95,23);printf("%s passed %s and collects $200!",CurrentPlayer->name,Location[0].name);
                                CurrentPlayer->cashInHand += 200;
                                CurrentPlayer->networth   += 200; 
                                CurrentPlayer->currentLocation=&Location[((CurrentPlayer->currentLocation->ID)+dieTotal)-MAX_LOCATIONS-1];
                            }
                            else
                            {
                                CurrentPlayer->currentLocation=&Location[(CurrentPlayer->currentLocation->ID)+dieTotal-1];
                            }
                            if (Teleported)
                                goto_XY(95,28);
                            else
                                goto_XY(95,24);
                            Teleported=False;
                            printf("%s landed on %s.                              ",CurrentPlayer->name,CurrentPlayer->currentLocation->name);    
                            graphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);                        
                        }

                        switch(CurrentPlayer->currentLocation->Type)
                        {
                            //Performing actions based on location type
                            case FREE:
                            {
                                break;
                            }
                            case CHEST: 
                            case CHANCE:
                            {
                                if (GenerateCard()!=EXIT_SUCCESS)
                                {
                                    goto_XY(95,SCREENSIZE_Y-1);
                                    printf("\nCard generation Error at Location Record %d",ID+1);
                                    return EXIT_FAILURE;
                                }
                                else
                                {
                                    goto_XY(95,25);printf("%s draws a card.",CurrentPlayer->name);
                                    switch(drawnCard.Type)
                                    {
                                        case BAD:
                                        {
                                            goto_XY(95,26);printf("OH NO! %s pays %d ",CurrentPlayer->name,drawnCard.Money);
                                            switch((rand()%(5)))
                                            {
                                                case 0 : printf("to the MAYOR!");break;
                                                case 1 : printf("for car insurance!");break;
                                                case 2 : printf("for health insurance!");break;
                                                case 3 : printf("Monopoly man!");break;
                                                default: printf("to the BANK!");break;
                                            }
                                            CurrentPlayer->cashInHand-=drawnCard.Money;                                        
                                            CurrentPlayer->networth  -=drawnCard.Money;
                                            break;
                                        }
                                        case NEUTRAL:
                                        {
                                            goto_XY(95,26);printf("%s teleports!",CurrentPlayer->name,Location[drawnCard.LocationID].name);
                                            CurrentPlayer->currentLocation = &Location[drawnCard.LocationID];
                                            Teleported=True;
                                            goto LocationTeleporter;
                                            break;
                                        }
                                        case GOOD:
                                        {
                                            goto_XY(95,26);printf("OOOH! %s gets %d ",CurrentPlayer->name,drawnCard.Money);
                                            switch((rand()%(5)))
                                            {
                                                case 0 : printf("from the MAYOR!");break;
                                                case 1 : printf("from the lottery!");break;
                                                case 2 : printf("for good luck!");break;
                                                case 3 : printf("from Monopoly man!");break;
                                                default: printf("from the BANK!");break;
                                            }
                                            CurrentPlayer->cashInHand+=drawnCard.Money;                                        
                                            CurrentPlayer->networth  +=drawnCard.Money;
                                            break;
                                        }
                                        default:
                                        {
                                            goto_XY(95,SCREENSIZE_Y-1);
                                            printf("\nCard generation Error at Location Record %d",ID+1);
                                            return EXIT_FAILURE;
                                        }
                                    }
                                }
                                break;
                            }
                            case JAIL:     
                            {
                                int OldLocationID = CurrentPlayer->currentLocation->ID;
                                goto_XY(95,25);printf("%s, have fun in Jail. :)",CurrentPlayer->name);
                                wasDouble=0;
                                CurrentPlayer->currentLocation=&Location[30];
                                CurrentPlayer->isInJail=True;
                                CurrentPlayer->JailTurn=2;
                                graphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);
                                break;
                            }
                            case TAX:    
                            {  
                                goto_XY(95,25);printf("%s pays %d as tax!",CurrentPlayer->name,CurrentPlayer->currentLocation->Rent);
                                CurrentPlayer->cashInHand -= CurrentPlayer->currentLocation->Rent;
                                CurrentPlayer->networth   -= CurrentPlayer->currentLocation->Rent; 
                                break;
                            }
                            case UTILITY:
                            case RAIL:  
                            case PROPERTY:      
                            {
                                goto_XY(95,37);printf("Press any key to continue...");getch();
                                if(CurrentPlayer->currentLocation->isOwnable)
                                {
                                    buyMenu(CurrentPlayer,CurrentPlayer->currentLocation);
                                }
                                else
                                {
                                    if(CurrentPlayer->currentLocation->ownerID==CurrentPlayer->ID){
                                        goto_XY(95,25);printf("%s landed on their own property!",CurrentPlayer->name);
                                    }
                                    else
                                    {
                                        goto_XY(95,25);printf("%s landed on %s's property!",CurrentPlayer->name,Player[ CurrentPlayer->currentLocation->ownerID-1 ].name);
                                        int Rent = RentCalc(&Player[ CurrentPlayer->currentLocation->ownerID-1 ],CurrentPlayer->currentLocation,dieTotal);

                                        goto_XY(95,26);printf("%s paid %s $%d!",CurrentPlayer->name,Player[CurrentPlayer->currentLocation->ownerID -1].name,Rent);
                                        
                                        CurrentPlayer->cashInHand -= Rent;
                                        CurrentPlayer->networth   -= Rent;
                                        Player[CurrentPlayer->currentLocation->ownerID -1].cashInHand += Rent;
                                        Player[CurrentPlayer->currentLocation->ownerID -1].networth   += Rent;
                                    }
                                }
                                break;
                            }
                            default:   
                            {
                                goto_XY(95,SCREENSIZE_Y-1);
                                printf("\nFile Value Error at Location Record %d",ID+1);
                                return EXIT_FAILURE;
                            }
                        }  
                        
                        CurrentPlayer->isBankrupt=isPlayerBankrupt(CurrentPlayer->cashInHand);
                        if(CurrentPlayer->isBankrupt)
                        {
                            goto_XY(95,30);printf("%s IS BANKRUPT !!!",CurrentPlayer->name);
                            CurrentPlayer->isOut=True;
                            CurrentPlayer->position=PlayerCount-PlayersOut;
                            PlayersOut++;
                            CurrentPlayer->PropertyOwnedCount=0;
                            CurrentPlayer->SetsOwnedCount=0;
                            for(int i=0;i<10;i++){
                                CurrentPlayer->SetsOwned[i]=0;
                            }
                            for(int i=0;i<20;i++){
                                CurrentPlayer->PropertyOwned[i]=0;
                            }
                            for(int i=0;i<MAX_LOCATIONS;i++){
                                if(Location[i].ownerID==CurrentPlayer->ID)
                                {
                                    Location[i].isOwnable=True;
                                    Location[i].ownerID=0;
                                    Location[i].housesBuilt=0;
                                    Location[i].hotelBuilt=False;
                                    Location[i].isSetComplete=False;
                                    Location[i].Rent=Location[i].intialRent;
                                }
                            }
                        }  
                    }                
                    else 
                    {                    
                        CurrentPlayer->isOut=True;
                        CurrentPlayer->position=PlayerCount-PlayersOut;
                        PlayersOut++;
                    }
                }

            }

            //Next player plays if current player did not get doubles
            if (wasDouble!=0){
                goto_XY(95,28);printf("%s plays again!",CurrentPlayer->name);
            }
            else if (ID+1>=PlayerCount){
                ID=0;
                currentTurns++;
            }
            else ID++;

            goto_XY(95,37);printf("Press any key to continue...");
            if (getch()=='x')
            {
                clearRightScreen(0);
                goto_XY(95,5);printf("Game interrupt");
                GamemodeChoice=EXIT;
            }

            if (GamemodeChoice==NETWORTH)
            {
                for(int i=0;i<PlayerCount;i++)
                {
                    if (Player[i].networth>=maxNetworth)
                    {
                        clearRightScreen(0);
                        goto_XY(95,5);printf("%s HAS ATTAINED A NETWORTH OF %d !",strupr(Player[i].name),Player[i].networth);
                        Player[i].position=1;
                        GamemodeChoice=EXIT;
                    }
                }
            }
            else if (GamemodeChoice==TURNS)
            {
                if (currentTurns>=maxTurns)
                {
                    clearRightScreen(0);
                    goto_XY(95,5);printf("%d TURNS HAVE PASSED!",maxTurns);
                    GamemodeChoice=EXIT;
                }
            }
            if(!(PlayerCount-PlayersOut>1))
            {
                clearRightScreen(0);
                for(int i=0;i<PlayerCount;i++)
                {
                    if(Player[i].position==0)
                    {
                        goto_XY(95,5);printf("ONLY %s REMAINS!",Player[i].name);
                        Player[i].position=1;
                        break;
                    }
                }
                GamemodeChoice=EXIT;
            }
        }
        
        goto_XY(95,SCREENSIZE_Y-1);
        printf("\n\n\tEnter any key to continue...");
        getch();    
        clearScreen();
        
        playerResults(Player,PlayerCount);
    }
    goto_XY(0,SCREENSIZE_Y-1);
    printf("\n\n\tEnter any key to continue...");
    getch();    
    clearScreen();   
    return EXIT_SUCCESS;
}


int main()
{
    
    if (intro()!=EXIT_SUCCESS){
        printf("\nIntro Error\n");
        return EXIT_FAILURE;
    }
        char Choice;
    while(True)
    {
        clearScreen();
        printf("\n                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P           "); 
        printf("\n                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P      ");       
        printf("\n                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P             "); 
        printf("\n                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P              "); 
        printf("\n                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888              ");  
        printf("\n                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888               "); 
        printf("\n                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888              ");  
        printf("\n                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888         ");       
        printf("\n\n\n\n\n");
        printf("\n\t  1-Play Monopoly");
        printf("\n\t  2-Read Rules");
        printf("\n\t  X-Exit\n\n");
        hideCursor();
        Choice = getch();
        showCursor();
        if (Choice == '1')
        {
            if (mainGame()!=EXIT_SUCCESS){
                printf("\nError in main Game\n");
                return EXIT_FAILURE;
            }
        }
        else if (Choice == '2'){
            if (showRules()!=EXIT_SUCCESS){
                printf("\nError in showRules\n");
                return EXIT_FAILURE;
            }    
        }
        else if (Choice == 'X'|| Choice == 'x')
        {
            clearScreen();
            if (thankYou()!=EXIT_SUCCESS){
                printf("\nError in thankYou\n");
                return EXIT_FAILURE;
            }  
            clearScreen();
            return EXIT_SUCCESS;
        }
        else
        {
            printf("\n\nYou entered an invalid choice \"%c\". Enter any key to try again.",Choice);
            getch();
        }
    }
    return EXIT_SUCCESS;
}