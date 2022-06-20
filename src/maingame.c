#include "maingame.h"

int Intro()
{
    clearScreen();
    printf("\n\n");
    printf("\n                                   888       888 8888888888 888      .d8888b.   .d88888b.  888b     d888 8888888888      88888888888 .d88888b.       ");
    printf("\n                                   888   o   888 888        888     d88P  Y88b d88P\" \"Y88b 8888b   d8888 888                 888    d88P\" \"Y88b  ");     
    printf("\n                                   888  d8b  888 888        888     888    888 888     888 88888b.d88888 888                 888    888     888      ");
    printf("\n                                   888 d888b 888 8888888    888     888        888     888 888Y88888P888 8888888             888    888     888      ");
    printf("\n                                   888d88888b888 888        888     888        888     888 888 Y888P 888 888                 888    888     888      ");
    printf("\n                                   88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888                 888    888     888      ");
    printf("\n                                   8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888                 888    Y88b. .d88P     "); 
    printf("\n                                   888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888          888     \"Y88888P\" ");                                                                                              
    printf("\n\n\n\n");                                                                                                                                                                                                  
    printf("\n                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P           "); 
    printf("\n                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P      ");       
    printf("\n                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P             "); 
    printf("\n                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P              "); 
    printf("\n                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888              ");  
    printf("\n                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888               "); 
    printf("\n                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888              ");  
    printf("\n                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888         ");       
    goto_XY(130,40);
    printf("Press any key to continue...");
    getch();
    return EXIT_SUCCESS;
}

int ShowRules()
{
    for (int i=0; i<2; i++)
    {
        clearScreen();
        printf("\n          888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P      8888888b.  888     888 888      8888888888 .d8888b.  ");
        printf("\n          8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P       888   Y88b 888     888 888      888       d88P  Y88b ");
        printf("\n          88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P        888    888 888     888 888      888       Y88b.      ");
        printf("\n          888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P         888   d88P 888     888 888      8888888    \"Y888b.   ");
        printf("\n          888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888          8888888P\"  888     888 888      888           \"Y88b. ");
        printf("\n          888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888          888 T88b   888     888 888      888             \"888 ");
        printf("\n          888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888          888  T88b  Y88b. .d88P 888      888       Y88b  d88P ");
        printf("\n          888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888          888   T88b  \"Y88888P\"  88888888 8888888888 \"Y8888P\"  ");
        printf("\n");  
        if (i==0) 
        {  
            printf("\n\tOBJECTIVE OF THE GAME");
            printf("\n\tBecome the wealthiest player through buying, renting and selling of property and force other players into bankruptcy.");
            printf("\n\n\tGAMEPLAY");
            printf("\n\tAt the start, each player throws the dice. The player with the highest total starts the play.");
            printf("\n\tAll players start at \"START\" and are given the opportunity roll the two dice.");
            printf("\n\tBased on the total of the two, the player moves to a location and can buy the property, or pay rent/tax, draw a Chance/Community Chest card, Go To Jail, or etc...");
            printf("\n\tIf the player throws doubles, they move their token and are subject to any privileges or penalties pertaining to the space on which they land.");
            printf("\n\tThen they can throw again and move their token as before. However, if the player ever throws doubles three times in succession, they are immediately sent to jail.");
            goto_XY(130,40);
            printf("Press any key to continue to next page...");
            getch();
        }
        else
        {
            printf("\n\tSTART");
            printf("\n\tEach time a player passes over START the player is paid a $200 salary.");
            printf("\n\n\tBUYING PROPERTY");
            printf("\n\tWhen a player lands on an unowned property they can buy that property at its printed price.");
            printf("\n\n\tPAYING RENT");
            printf("\n\tWhen a player lands on a property owned by another player, the owner collects rent in accordance with factors like no. of houses, hotels, etc.");
            printf("\n\n\tCHANCE AND COMMUNITY CHEST");
            printf("\n\tWhen a player lands here, they can recieve a certain amount, have to pay a certain amount, or teleport to a random location.");
            printf("\n\n\tJAIL");
            printf("\n\tA player can be sent to jail when they land on \"GO TO JAIL\" or roll a certain number of doubles.");
            printf("\n\tThe player is given the option to pay a certain amount to get out or can stay for a certain number of turns.");
            printf("\n\tIf the player stays, at each turn, the number of turns to wait is displayed. The player cannot sell properties or buy houses/hotels when in jail.");
            printf("\n\n\tFREE PARKING");
            printf("\n\tJust a free location with no reward or pentaly.");
            printf("\n\n\tHOUSES AND HOTELS");
            printf("\n\tIf the player has completed a set, they are now allowed to buy a max of 4 Houses or a hotel if they have a sufficient balance.");
            printf("\n\tThe player can build houses in only property type locations whose sets are completed.");
            printf("\n\tThe player can only build a hotel if 4 houses have been built.");
            printf("\n\n\tBANKRUPTCY");
            printf("\n\tWhen the player has an amount lesser than -500 in hand, they are bankrupt and out. Players can sell properties to avoid so.");                                                                                                                                                                     
            goto_XY(130,40);
            printf("Press any key to continue...");
            getch();
        }
    }
    return EXIT_SUCCESS;
}

int mainGame()
{
    clearScreen();

    hideCursor();
    int GamemodeChoice = SelectGamemode(),maxNetworth,maxTurns;
    showCursor();

    while (GamemodeChoice == NETWORTH)
    {
        char inp[1];
        printf("\n\n\tEnter maximum net worth after which game is to end: ");
        scanf("%s",&inp);
        if (atoi(inp) >= 1400){
            maxNetworth=atoi(inp);
            break;
        }
        printf("\n\n\tInvalid Input (Enter a number from greater than 1400) \n\tEntered: %s\n",inp);
    }
    while (GamemodeChoice == TURNS)
    {
        char inp[1];
        printf("\n\n\tEnter maximum turns after which game is to end: ");
        scanf("%s",&inp);
        if (atoi(inp) >= 1){
            maxTurns=atoi(inp);
            break;
        }
        printf("\n\n\tInvalid Input (Enter a number greater than 0) \n\tEntered: %s\n",inp);
    }
    clearScreen();
    
    if (GamemodeChoice!=EXIT)
    {
        int PlayerCount;
        char Names[9][30];
        struct player Players[9], *CurrentPlayer;
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
        else if (InitialisePlayers(Players,PlayerCount,Names)!=EXIT_SUCCESS){
            printf("\nPlayer values could not be set properly\n");
            return EXIT_FAILURE;
        }
        goto_XY(95,SCREENSIZE_Y-1);
        printf("\n\n\tEnter any key to continue...");
        getch();    
        clearScreen();

        DisplayMap();
        for(int i=0;i<PlayerCount;i++){
            if ( GraphicalMove(&Players[i],1,1)!=EXIT_SUCCESS ){
                printf("\nPlayer %d: %s could not be displayed\n",i+1,Players[i].name);
                return EXIT_FAILURE;
            }
        }

        int currentTurns=0,PlayersOut=0;
        int ID=0,die1=0,die2=0,dieTotal=0,wasDouble=0;
        while (GamemodeChoice!=EXIT)
        {
            colour(GREEN,INCREASED_INTENSITY);
            goto_XY(0,2);printf("\tTURN: %d     ",currentTurns+1);
            colour(RESET,0);
            GraphicalPropertyInfo(Players,PlayerCount);
            CurrentPlayer = &Players[ID];
            if (!CurrentPlayer->isOut)  
            {
                if (CurrentPlayer->isInJail)
                {
                    ClearRightScreen(0);
                    goto_XY(95,3); printf("PLAYER: %s CASH IN HAND: $%d NET WORTH: $%d                              ",CurrentPlayer->name,CurrentPlayer->cashInHand,CurrentPlayer->netWorth);   
                    int stay=TRUE;
                    if (CurrentPlayer->jailTurn==2)
                    {
                        goto_XY(95,5);printf("%s, do you want to pay to get out of jail or stay for %d more turns?",CurrentPlayer->name,CurrentPlayer->jailTurn+1);
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
                            case'1':stay = FALSE;
                                    CurrentPlayer->cashInHand-=100;
                                    CurrentPlayer->netWorth-=100;  //Pay to leave
                                    CurrentPlayer->jailTurn=0;
                                    CurrentPlayer->isInJail=FALSE;
                                    goto_XY(95,11);printf("You can play next turn.");
                                    break;
                                    
                            default:stay = TRUE;
                        }
                    }
                    if (stay==TRUE)
                    {
                        goto_XY(95,13);printf(" %s is in Jail, wait for %d turn(s) to play.",CurrentPlayer->name,CurrentPlayer->jailTurn+1);
                        if(CurrentPlayer->jailTurn>0)
                            CurrentPlayer->jailTurn-=1;
                        else
                        {
                            CurrentPlayer->jailTurn=0;
                            CurrentPlayer->isInJail=FALSE;
                        }
                    }
                }
                else
                {
                    
                    goto_XY(95,3); 
                    printf("PLAYER: ");
                    colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
                    printf("%s ",CurrentPlayer->name);
                    colour(RESET,RESET);
                    printf("CASH IN HAND: $%d NET WORTH: $%d                              ",CurrentPlayer->cashInHand,CurrentPlayer->netWorth);   
                    
                    ClearRightScreen(16);
                    int Choice=0;
                    if (wasDouble==0)
                        Choice=PlayerMainMenu(CurrentPlayer); 
                    
                    if (Choice!=GIVEUP)
                    {
                        if (Choice==BUY)
                            BuyHousesMenu(CurrentPlayer);
                        else if (Choice==SELL)
                            SellMenu(CurrentPlayer);

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
                            //Sending player to jail for MAX_DOUBLES sets of doubles in a row
                            int OldLocationID = CurrentPlayer->currentLocation->ID;
                            CurrentPlayer->currentLocation=&Location[30];
                            goto_XY(95,23);printf("Since %s rolled a double again, they are sent to JAIL for overspeeding.",CurrentPlayer->name);
                            GraphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);                            
                            wasDouble=0;   
                        }
                        else
                        {
                            //Moving current players's current location and checking if they passed START

                            //Reaches here when player draws a NEUTRAL card
                            LocationTeleporter: ;
                            int OldLocationID = CurrentPlayer->currentLocation->ID;
                            if ((CurrentPlayer->currentLocation->ID)+dieTotal > 40)
                            {
                                goto_XY(95,23);printf("%s passed %s and collects $200!",CurrentPlayer->name,Location[0].name);
                                CurrentPlayer->cashInHand += 200;
                                CurrentPlayer->netWorth   += 200; 
                                CurrentPlayer->currentLocation=&Location[((CurrentPlayer->currentLocation->ID)+dieTotal)-39];
                                GraphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);      
                            }
                            else
                            {
                                CurrentPlayer->currentLocation=&Location[(CurrentPlayer->currentLocation->ID)+dieTotal-1];
                            }
                            if (Teleported)
                                goto_XY(95,28);
                            else
                                goto_XY(95,24);
                            Teleported=FALSE;
                            printf("%s landed on %s.                              ",CurrentPlayer->name,CurrentPlayer->currentLocation->name);    
                            GraphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);                        
                        }

                        switch(CurrentPlayer->currentLocation->type)
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
                                    switch(drawnCard.type)
                                    {
                                        case BAD:
                                        {
                                            goto_XY(95,26);printf("OH NO! %s pays %d ",CurrentPlayer->name,drawnCard.money);
                                            switch((rand()%(5)))
                                            {
                                                case 0 : printf("to the MAYOR!");break;
                                                case 1 : printf("for car insurance!");break;
                                                case 2 : printf("for health insurance!");break;
                                                case 3 : printf("to Monopoly man!");break;
                                                default: printf("to the BANK!");break;
                                            }
                                            CurrentPlayer->cashInHand-=drawnCard.money;                                        
                                            CurrentPlayer->netWorth  -=drawnCard.money;
                                            break;
                                        }
                                        case NEUTRAL:
                                        {
                                            int OldLocationID = CurrentPlayer->currentLocation->ID;
                                            goto_XY(95,26);printf("%s teleports!",CurrentPlayer->name,Location[drawnCard.locationID].name);
                                            CurrentPlayer->currentLocation = &Location[drawnCard.locationID];
                                            GraphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);
                                            Teleported=TRUE;
                                            goto LocationTeleporter;
                                            break;
                                        }
                                        case GOOD:
                                        {
                                            goto_XY(95,26);printf("OOOH! %s gets %d ",CurrentPlayer->name,drawnCard.money);
                                            switch((rand()%(5)))
                                            {
                                                case 0 : printf("from the MAYOR!");break;
                                                case 1 : printf("from the lottery!");break;
                                                case 2 : printf("for good luck!");break;
                                                case 3 : printf("from Monopoly man!");break;
                                                default: printf("from the BANK!");break;
                                            }
                                            CurrentPlayer->cashInHand+=drawnCard.money;                                        
                                            CurrentPlayer->netWorth  +=drawnCard.money;
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
                                CurrentPlayer->currentLocation=&Location[10];
                                CurrentPlayer->isInJail=TRUE;
                                CurrentPlayer->jailTurn=2;
                                GraphicalMove(CurrentPlayer,OldLocationID,CurrentPlayer->currentLocation->ID);
                                break;
                            }
                            case TAX:    
                            {  
                                goto_XY(95,25);printf("%s pays %d as tax!",CurrentPlayer->name,CurrentPlayer->currentLocation->rent);
                                CurrentPlayer->cashInHand -= CurrentPlayer->currentLocation->rent;
                                CurrentPlayer->netWorth   -= CurrentPlayer->currentLocation->rent; 
                                break;
                            }
                            case UTILITY:
                            case RAIL:  
                            case PROPERTY:      
                            {
                                goto_XY(95,37);printf("Press any key to continue...");getch();
                                if(CurrentPlayer->currentLocation->isOwnable)
                                {
                                    BuyMenu(CurrentPlayer,CurrentPlayer->currentLocation);
                                }
                                else
                                {
                                    if(CurrentPlayer->currentLocation->ownerID==CurrentPlayer->ID){
                                        goto_XY(95,25);printf("%s landed on their own property!",CurrentPlayer->name);
                                    }
                                    else
                                    {
                                        goto_XY(95,25);printf("%s landed on %s's property!",CurrentPlayer->name,Players[ CurrentPlayer->currentLocation->ownerID-1 ].name);
                                        int Rent = RentCalc(&Players[ CurrentPlayer->currentLocation->ownerID-1 ],CurrentPlayer->currentLocation,dieTotal);

                                        goto_XY(95,26);printf("%s paid %s $%d!",CurrentPlayer->name,Players[CurrentPlayer->currentLocation->ownerID -1].name,Rent);
                                        
                                        CurrentPlayer->cashInHand -= Rent;
                                        CurrentPlayer->netWorth   -= Rent;
                                        Players[CurrentPlayer->currentLocation->ownerID -1].cashInHand += Rent;
                                        Players[CurrentPlayer->currentLocation->ownerID -1].netWorth   += Rent;
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
                        
                        CurrentPlayer->isBankrupt=IsPlayerBankrupt(CurrentPlayer->cashInHand);
                        if(CurrentPlayer->isBankrupt)
                        {
                            goto_XY(95,30);printf("%s IS BANKRUPT !!!",CurrentPlayer->name);
                            CurrentPlayer->isOut=TRUE;
                            CurrentPlayer->position=PlayerCount-PlayersOut;
                            PlayersOut++;
                            CurrentPlayer->propertyOwnedCount=0;
                            for(int i=0;i<20;i++){
                                CurrentPlayer->propertyOwned[i]=0;
                            }
                            for(int i=0;i<40;i++){
                                if(Location[i].ownerID==CurrentPlayer->ID)
                                {
                                    Location[i].isOwnable=TRUE;
                                    Location[i].ownerID=0;
                                    Location[i].housesBuilt=0;
                                    Location[i].hotelBuilt=FALSE;
                                    Location[i].isSetComplete=FALSE;
                                    Location[i].rent=Location[i].initialRent;
                                }
                            }
                        }  
                    }                
                    else 
                    {                    
                        CurrentPlayer->isOut=TRUE;
                        CurrentPlayer->position=PlayerCount-PlayersOut;
                        PlayersOut++;
                        CurrentPlayer->propertyOwnedCount=0;
                        for(int i=0;i<20;i++){
                            CurrentPlayer->propertyOwned[i]=0;
                        }
                        for(int i=0;i<40;i++){
                            if(Location[i].ownerID==CurrentPlayer->ID)
                            {
                                Location[i].isOwnable=TRUE;
                                Location[i].ownerID=0;
                                Location[i].housesBuilt=0;
                                Location[i].hotelBuilt=FALSE;
                                Location[i].isSetComplete=FALSE;
                                Location[i].rent=Location[i].initialRent;
                            }
                        }
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
                ClearRightScreen(0);
                goto_XY(95,5);printf("Game interrupt");
                GamemodeChoice=EXIT;
            }

            if (GamemodeChoice==NETWORTH)
            {
                for(int i=0;i<PlayerCount;i++)
                {
                    if (Players[i].netWorth>=maxNetworth)
                    {
                        ClearRightScreen(0);
                        goto_XY(95,5);printf("%s HAS ATTAINED A NET WORTH OF %d !", Players[i].name, Players[i].netWorth);
                        Players[i].position=1;
                        GamemodeChoice=EXIT;
                    }
                }
            }
            else if (GamemodeChoice==TURNS)
            {
                if (currentTurns>=maxTurns)
                {
                    ClearRightScreen(0);
                    goto_XY(95,5);printf("%d TURNS HAVE PASSED!",maxTurns);
                    GamemodeChoice=EXIT;
                }
            }
            if(!(PlayerCount-PlayersOut>1))
            {
                ClearRightScreen(0);
                for(int i=0;i<PlayerCount;i++)
                {
                    if(Players[i].position==0)
                    {
                        goto_XY(95,5);printf("ONLY %s REMAINS!",Players[i].name);
                        Players[i].position=1;
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
        
        PlayerResults(Players,PlayerCount);
    }
    goto_XY(0,SCREENSIZE_Y-1);
    printf("\n\n\tEnter any key to continue...");
    getch();    
    clearScreen();   
    return EXIT_SUCCESS;
}

int ThankYou()
{
    clearScreen();
    printf("\n\n");
    printf("\n                              88888888888 888    888        d8888 888b    888 888    d8P   .d8888b.       8888888888 .d88888b.  8888888b.  ");
    printf("\n                                  888     888    888       d88888 8888b   888 888   d8P   d88P  Y88b      888       d88P\" \"Y88b 888   Y88b ");
    printf("\n                                  888     888    888      d88P888 88888b  888 888  d8P    Y88b.           888       888     888 888    888 ");
    printf("\n                                  888     8888888888     d88P 888 888Y88b 888 888d88K      \"Y888b.        8888888   888     888 888   d88P ");
    printf("\n                                  888     888    888    d88P  888 888 Y88b888 8888888b        \"Y88b.      888       888     888 8888888P\"  ");
    printf("\n                                  888     888    888   d88P   888 888  Y88888 888  Y88b         \"888      888       888     888 888 T88b   ");
    printf("\n                                  888     888    888  d8888888888 888   Y8888 888   Y88b  Y88b  d88P      888       Y88b. .d88P 888  T88b  ");
    printf("\n                                  888     888    888 d88P     888 888    Y888 888    Y88b  \"Y8888P\"       888        \"Y88888P\"  888   T88b ");
    printf("\n\n\n\n");                                                                                                                                           
    printf("\n                                              8888888b.  888             d8888 Y88b   d88P 8888888 888b    888  .d8888b.  888              ");
    printf("\n                                              888   Y88b 888            d88888  Y88b d88P    888   8888b   888 d88P  Y88b 888              ");
    printf("\n                                              888    888 888           d88P888   Y88o88P     888   88888b  888 888    888 888              ");
    printf("\n                                              888   d88P 888          d88P 888    Y888P      888   888Y88b 888 888        888              ");
    printf("\n                                              8888888P\"  888         d88P  888     888       888   888 Y88b888 888  88888 888              ");
    printf("\n                                              888        888        d88P   888     888       888   888  Y88888 888    888 Y8P              ");
    printf("\n                                              888        888       d8888888888     888       888   888   Y8888 Y88b  d88P  \"               ");
    printf("\n                                              888        88888888 d88P     888     888     8888888 888    Y888  \"Y8888P88 888              ");
    printf("\n\n\n\n");                                                                                                                                                                                                  
    goto_XY(130,40);
    printf("Press any key to continue...");
    getch();
    return EXIT_SUCCESS;
}
    