#include "definitions.h"
#include "player.h"

int PlayerRolls()
{
    return (rand()%6)+1;
}

int ReadPlayers(int *numberOfPlayers, char (*Names)[30])
{
    char inp[1];
    while(TRUE) 
    {
        clearScreen();
        printf("\n              8888888b.  888             d8888 Y88b   d88P 8888888888 8888888b.       8888888b.  8888888888 88888888888     d8888 8888888 888      .d8888b.  ");
        printf("\n              888   Y88b 888            d88888  Y88b d88P  888        888   Y88b      888  \"Y88b 888            888        d88888   888   888     d88P  Y88b ");
        printf("\n              888    888 888           d88P888   Y88o88P   888        888    888      888    888 888            888       d88P888   888   888     Y88b.      ");
        printf("\n              888   d88P 888          d88P 888    Y888P    8888888    888   d88P      888    888 8888888        888      d88P 888   888   888      \"Y888b.   ");
        printf("\n              8888888P\"  888         d88P  888     888     888        8888888P\"       888    888 888            888     d88P  888   888   888         \"Y88b. ");
        printf("\n              888        888        d88P   888     888     888        888 T88b        888    888 888            888    d88P   888   888   888           \"888 ");
        printf("\n              888        888       d8888888888     888     888        888  T88b       888  .d88P 888            888   d8888888888   888   888     Y88b  d88P ");
        printf("\n              888        88888888 d88P     888     888     8888888888 888   T88b      8888888P\"  8888888888     888  d88P     888 8888888 88888888 \"Y8888P\"  ");
        printf("\n\n\n\n");
        showCursor();
        printf("\n\tEnter the number of players: ");
        scanf("%s",&inp);
        if (atoi(inp) >= 2 && atoi(inp) <= 8){
            *numberOfPlayers=atoi(inp);
            break;
        }
        else if ((inp[0] == 'X')||(inp[0] == 'x')){
            exit(0);
            break;
        }
        printf("\n\n\tInvalid Input (Enter a number from 2-8 or X to exit game) \n\tEntered: %s\n",inp);
        goto_XY(0,SCREENSIZE_Y);printf("\tEnter any key to retry...");
        getch();
    }
    for (int i=0;i<*numberOfPlayers;i++){
        printf("\n\tPlayer %d enter name: ",i+1);
        fflush(stdin);
        scanf("%s",&Names[i]);
    } 
    return EXIT_SUCCESS;
}

int SetPlayerOrder(int numberOfPlayers, char (*Names)[30])
{
    clearScreen();
    printf("\n                      8888888b.  888             d8888 Y88b   d88P 8888888888 8888888b.        .d88888b.  8888888b.  8888888b.  8888888888 8888888b.  ");
    printf("\n                      888   Y88b 888            d88888  Y88b d88P  888        888   Y88b      d88P\" \"Y88b 888   Y88b 888  \"Y88b 888        888   Y88b "); 
    printf("\n                      888    888 888           d88P888   Y88o88P   888        888    888      888     888 888    888 888    888 888        888    888 ");
    printf("\n                      888   d88P 888          d88P 888    Y888P    8888888    888   d88P      888     888 888   d88P 888    888 8888888    888   d88P ");
    printf("\n                      8888888P\"  888         d88P  888     888     888        8888888P\"       888     888 8888888P\"  888    888 888        8888888P\" ");
    printf("\n                      888        888        d88P   888     888     888        888 T88b        888     888 888 T88b   888    888 888        888 T88b   ");
    printf("\n                      888        888       d8888888888     888     888        888  T88b       Y88b. .d88P 888  T88b  888  .d88P 888        888  T88b  ");
    printf("\n                      888        88888888 d88P     888     888     8888888888 888   T88b       \"Y88888P\"  888   T88b 8888888P\"  8888888888 888   T88b ");
    printf("\n\n\n\n");
    srand(time(0));
    int die1, die2, order[10], len=strlen(Names[0]);
    for (int i=0;i<numberOfPlayers;i++){
        if (len<strlen(Names[i]))
            len=strlen(Names[i]);
    }
    for(int i=0;i<numberOfPlayers;i++){
        die1=PlayerRolls();
        die2=PlayerRolls();
        order[i]=die1+die2;
        printf("\n\t%-*s : Rolled a %d and a %d thus has a total of %d.",len,Names[i],die1,die2,order[i]);
    }

    int Temp;char TempName[30];
    for(int i=0;i<numberOfPlayers;i++){    
        for(int j=0;j<numberOfPlayers-1;j++){
            if(order[j]<order[j+1])
            {
                int Temp = order[j+1];
                order[j+1] = order[j];
                order[j] = Temp;

                strcpy(TempName  , Names[j+1]);
                strcpy(Names[j+1], Names[j]);
                strcpy(Names[j]  , TempName);
            }
        }           
    }

    printf("\n\n\tPlaying order based on highest roll of the dice:");
    for(int i=0;i<numberOfPlayers;i++){    
            printf("\n\t%s",Names[i]);
    }
    return EXIT_SUCCESS;
}

int InitialisePlayers(struct player Player[],int PlayerCount, char (*Names)[30])
{
    for(int i=0;i<PlayerCount;i++){  
        strcpy(Player[i].name,Names[i]);
        Player[i].ID = i+1;
        Player[i].netWorth = Player[i].cashInHand = INITIAL_AMT;
        Player[i].jailTurn = Player[i].position = Player[i].propertyOwnedCount =  0;
        Player[i].isOut = Player[i].isBankrupt = Player[i].isInJail = FALSE;
        Player[i].currentLocation = &Location[0];
        for(int j=0;j<20;j++)
        {
            Player[i].propertyOwned[j]=0;
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
    return EXIT_SUCCESS;
}

int GraphicalMove(struct player *currentPlayer,int OldLocationID,int NewLocationID)
{
    int map[40][2]={{ 9,36},{ 9,33},{ 9,30},{ 9,27},{ 9,24},{ 9,21},{ 9,18},{ 9,15},{ 9,12},{ 9, 9},\
                    { 9, 6},{16, 6},{23, 6},{30, 6},{37, 6},{44, 6},{51, 6},{58, 6},{65, 6},{72, 6},\
                    {79, 6},{79, 9},{79,12},{79,15},{79,18},{79,21},{79,24},{79,27},{79,30},{79,33},\
                    {79,36},{72,36},{65,36},{58,36},{51,36},{44,36},{37,36},{30,36},{23,36},{16,36}};
    
    int playerID = currentPlayer->ID;
    goto_XY(map[OldLocationID-1][0]+(playerID-1)%4,map[OldLocationID-1][1]+(playerID-1)/4);
    printf(" ");
    colour(currentPlayer->colour1,currentPlayer->colour2);
    goto_XY(map[NewLocationID-1][0]+(playerID-1)%4,map[NewLocationID-1][1]+(playerID-1)/4);
    printf("o");
    colour(RESET,RESET);
    return EXIT_SUCCESS;
}

int TimedNumInput(int seconds,int Default)
{
    int numInput;
    clock_t start = clock();
    while ( ! _kbhit() )
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= seconds) 
            return Default;
    scanf("%d",&numInput);
    return numInput;
}

char TimedCharInput(int seconds,char Default)
{
    int charInput;
    clock_t start = clock();
    while ( ! _kbhit() )
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= seconds) 
            return Default;
    charInput = getch();
    return charInput;
}

int ClearRightScreen(int startLine)
{
    for (int i=startLine;i<SCREENSIZE_Y;i++)
    {
        goto_XY(95,i);
        for(int j=0;j<(SCREENSIZE_X-95);j++)
            printf(" ");
    }
    return EXIT_SUCCESS;
}

int PlayerMainMenu(struct player *CurrentPlayer)
{
    char Choice;
    for (int i=0;i<2;i++)
    {
        ClearRightScreen(0);

        goto_XY(95,3);         
        printf("PLAYER: ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);
        printf("CASH IN HAND: $%d NET WORTH: $%d                              ",CurrentPlayer->cashInHand,CurrentPlayer->netWorth);   
        
        goto_XY(95,5); 
        printf("MENU FOR ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);
        
        goto_XY(95,6); printf("Choose an option:");
        goto_XY(95,7); printf("  1-ROLL");
        goto_XY(95,8); printf("  2-BUY HOUSES AND HOTELS");
        goto_XY(95,9); printf("  3-SELL PROPERTIES");
        goto_XY(95,10);printf("  X-GIVE UP");
        goto_XY(95,12);printf("PS: ROLL will be selected after selection of 2/3");
        goto_XY(95,13);printf("You have 10 seconds or 1 will be chosen by default...");
        Choice = TimedCharInput(10,0);
        if(Choice == 0)
        {
            goto_XY(95,15);printf("YOU TOOK TOO LONG TO CHOOSE, ROLL WAS CHOSEN BY DEFAULT");
            return ROLL;
        }
        else if(Choice =='1')
        {
            goto_XY(95,15);printf("YOU CHOSE TO ROLL"); 
            return ROLL;
        }
        else if(Choice =='2')
        {
            goto_XY(95,15);printf("YOU CHOSE TO BUY HOUSES AND HOTELS");
            return BUY;
        }
        else if(Choice =='3')
        {
            goto_XY(95,15);printf("YOU CHOSE TO SELL PROPERTIES");
            return SELL;
        }
        else if(Choice =='X'||Choice =='x')
        {
            goto_XY(95,15);printf("YOU CHOSE TO GIVE UP");
            return GIVEUP;
        }
        else
        {
            if(i==0)
            {
                goto_XY(95,15);printf("YOU CHOSE AN INVALID OPTION. YOU CAN TRY ONCE AGAIN.");
                goto_XY(95,16);printf("PRESS ANY KEY TO CONTINUE...");
                TimedCharInput(5,0);
            }
            else
            {
                goto_XY(95,15);printf("YOU CHOSE TO ROLL BY DEFAULT"); 
                return ROLL;
            }
        }
    } 
}

int RentCalc(struct player *owner ,struct location *currentLocation, int rolled)
{
    if(currentLocation->type==RAIL)
    {
        int RailsOwned;
        for(int i=0;i<40;i++){
            if(Location[i].type==RAIL && Location->ownerID==owner->ID){
                RailsOwned++;
            }
        }
        for(int i=0;i<40;i++){
            if(Location[i].type==RAIL && Location->ownerID==owner->ID){
                Location[i].rent=25*RailsOwned;
            }
        }
    }
    else if(currentLocation->type==UTILITY)
    {
        int UtilitiesOwned;
        for(int i=0;i<40;i++){
            if(Location[i].type==UTILITY && Location->ownerID==owner->ID){
                UtilitiesOwned++;
            }
        }
        for(int i=0;i<40;i++){
            if(Location[i].type==UTILITY && Location->ownerID==owner->ID){
                if (UtilitiesOwned==1)
                    Location[i].rent=4*rolled;
                else if (UtilitiesOwned==2)
                    Location[i].rent=10*rolled;
            }
        }
    }
    return currentLocation->rent;
}

int SellMenu(struct player *CurrentPlayer)
{
    int ChoiceInt;
    for (int i=0;i<2;i++)
    {
        int j=0;
        ClearRightScreen(0);

        goto_XY(95,3); 
        printf("PLAYER: ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);
        printf("CASH IN HAND: $%d NET WORTH: $%d                              ",CurrentPlayer->cashInHand,CurrentPlayer->netWorth);   

        goto_XY(95,5); printf("SELL MENU FOR ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);

        goto_XY(95,6); printf("Choose a property to sell:");
        if(CurrentPlayer->propertyOwnedCount>0)
        {
            for(j=0;j<CurrentPlayer->propertyOwnedCount;j++)
            {
                goto_XY(95,7+j); printf("  %2d-SELL %s",j+1,Location[ CurrentPlayer->propertyOwned[j]-1 ].name);
            }
        }
        else 
        {
            goto_XY(95,8); printf("YOU OWN NO PROPERTIES!");
            goto_XY(95,11);printf("ROLLING BY DEFAULT"); 
            return EXIT_SUCCESS;
        }
        goto_XY(95,7+j);printf("  %2d-CONTINUE AND ROLL",j+1);
        goto_XY(95,9+j);printf("You have 15 seconds or X will be chosen by default...");
        ChoiceInt = TimedNumInput(15,0);
        if(ChoiceInt == 0)
        {
            goto_XY(95,11+j);printf("YOU TOOK TOO LONG TO CHOOSE, CONTINUE AND ROLL WAS CHOSEN BY DEFAULT");
            return EXIT_SUCCESS;
        }
        else if(ChoiceInt == j+1)
        {
            goto_XY(95,11+j);printf("YOU CHOSE TO CONTINUE AND ROLL");
            return EXIT_SUCCESS;
        }
        else
        {
            if (1<=ChoiceInt && ChoiceInt<=CurrentPlayer->propertyOwnedCount)
            {
                int ID = CurrentPlayer->propertyOwned[ChoiceInt-1] -1;
                int cost;
                if (Location[ID].type==PROPERTY) 
                    cost=Location[ID].cost + (Location[ID].housesBuilt + Location[ID].hotelBuilt)*Location[ID].buildCost;
                else
                    cost=Location[ID].cost;
                goto_XY(95,11+j); printf("SOLD %s FOR $%d",Location[ID].name,cost);
                CurrentPlayer->cashInHand += cost;
                CurrentPlayer->propertyOwnedCount--;
                Location[ID].isOwnable=TRUE;
                Location[ID].ownerID=0;
                Location[ID].housesBuilt=0;
                Location[ID].hotelBuilt=FALSE;
                Location[ID].isSetComplete=FALSE;
                Location[ID].rent=Location[ID].initialRent;
                for(int s1=ChoiceInt-1; s1<19; s1++){
                    CurrentPlayer->propertyOwned[s1]=CurrentPlayer->propertyOwned[s1+1];
                }        
                CurrentPlayer->propertyOwned[19]=0;  
                for(int s2=0;s2<40;s2++){
                    if(Location[ID].setID==Location[s2].setID)
                        Location[s2].isSetComplete=FALSE;
                }

                return EXIT_SUCCESS;
            }
            else 
            {
                if(i==0)
                {
                    goto_XY(95,11+j);printf("YOU CHOSE AN INVALID OPTION. YOU CAN TRY ONCE AGAIN.");
                    goto_XY(95,12+j);printf("PRESS ANY KEY TO CONTINUE...");
                    TimedCharInput(5,0);
                }
                else
                {
                    goto_XY(95,11+j);printf("YOU CHOSE TO CONTINUE AND ROLL BY DEFAULT"); 
                    return EXIT_SUCCESS;
                }
            }
        }
    } 
}

int BuyHousesMenu(struct player *CurrentPlayer)
{
    int ChoiceInt;
    for (int i=0;i<2;i++)
    {
        int j=0;
        ClearRightScreen(0);
        
        goto_XY(95,3); 
        printf("PLAYER: ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);
        printf("CASH IN HAND: $%d NET WORTH: $%d                              ",CurrentPlayer->cashInHand,CurrentPlayer->netWorth);   

        goto_XY(95,5); 
        printf("BUY HOUSES AND HOTELS MENU FOR ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);
        
        goto_XY(95,6); printf("Choose an option for your properties:");
        if(CurrentPlayer->propertyOwnedCount>0)
        {
            for(j=0;j<CurrentPlayer->propertyOwnedCount;j++)
            {
                goto_XY(95,7+j); 
                printf("  %2d-BUY HOUSES/HOTEL FOR %s",j+1,Location[ CurrentPlayer->propertyOwned[j]-1 ].name);
            }
        }
        else 
        {
            goto_XY(95,8); printf("YOU OWN NO PROPERTIES!");
            goto_XY(95,11);printf("YOU CHOSE TO CONTINUE AND ROLL BY DEFAULT"); 
            return EXIT_SUCCESS;
        }
        goto_XY(95,7+j);printf("  %2d-CONTINUE AND ROLL",j+1);
        goto_XY(95,9+j);printf("You have 15 seconds or X will be chosen by default...");
        ChoiceInt = TimedNumInput(15,0);
        if(ChoiceInt == 0)
        {
            goto_XY(95,11+j);printf("YOU TOOK TOO LONG TO CHOOSE, CONTINUE AND ROLL WAS CHOSEN BY DEFAULT");
            return EXIT_SUCCESS;
        }
        else if(ChoiceInt ==j+1)
        {
            goto_XY(95,11+j);printf("YOU CHOSE TO CONTINUE AND ROLL");
            return EXIT_SUCCESS;
        }
        else
        {
            if (1<=ChoiceInt && ChoiceInt<=CurrentPlayer->propertyOwnedCount)
            {
                int ID = CurrentPlayer->propertyOwned[ChoiceInt-1]-1;
                if(Location[ID].type==PROPERTY)
                {       
                    int flag=TRUE;                 
                    for(int id=0;id<40;id++)
                    {
                        if(Location[id].setID!=0 && Location[id].type==PROPERTY && Location[ID].setID==Location[id].setID)
                        {
                            if(Location[id].ownerID!=CurrentPlayer->ID)
                            {
                                flag=FALSE;
                            }
                        }
                    }
                    for(int id=0;id<40;id++){
                        if(Location[ID].setID!=0 && Location[ID].setID==Location[id].setID && Location[ID].ownerID==Location[id].ownerID){
                            Location[id].isSetComplete=flag;
                        }
                    } 
                    if (Location[ID].isSetComplete)
                    {
                        char buildChoice;
                        goto_XY(95,11+j); printf("Do you want to build houses or a hotel?");
                        goto_XY(95,12+j); printf(" 1-HOUSES");
                        goto_XY(95,13+j); printf(" 2-HOTELS");
                        goto_XY(95,14+j); printf(" X-NONE");
                        hideCursor();
                        buildChoice=getch();
                        showCursor();
                        if (buildChoice=='1')
                        {
                            int count;
                            goto_XY(95,15+j); printf("HOW MANY HOUSES WOULD YOU LIKE TO BUILD (1-4):");
                            scanf("%d",&count);
                            if((count+Location[ID].housesBuilt)>4)
                            {
                                goto_XY(95,16+j); 
                                printf("CANNOT BUILD %d MORE HOUSES! %d HOUSES ALREADY PRESENT!",count,Location[ID].housesBuilt);
                            }
                            else
                            {
                                if(CurrentPlayer->cashInHand>=(count*Location[ID].buildCost))
                                {
                                    CurrentPlayer->cashInHand-=count*Location[ID].buildCost;
                                    Location[ID].housesBuilt+=count;
                                    Location[ID].rent=Location[ID].house[Location[ID].housesBuilt];
                                    goto_XY(95,16+j); 
                                    printf("PROPERTY \"%s\" NOW HAS %d HOUSES!",Location[ID].name,Location[ID].housesBuilt);
                                }
                                else
                                {
                                    goto_XY(95,16+j); 
                                    printf("INSUFFICIENT BALANCE!");
                                }
                            }
                            return EXIT_SUCCESS;
                        }
                        else if (buildChoice=='2')
                        { 
                            if(Location[ID].housesBuilt==TRUE)
                            {
                                goto_XY(95,15+j); 
                                printf("PROPERTY ALREADY HAS A HOTEL!");
                            }
                            else
                            {   if(Location[ID].housesBuilt<4)
                                {
                                    goto_XY(95,15+j); 
                                    printf("PROPERTY NEEDS %d MORE HOUSES TO BUILD A HOTEL ",4-Location[ID].housesBuilt);
                                }
                                else if(CurrentPlayer->cashInHand>=(Location[ID].buildCost))
                                {
                                    CurrentPlayer->cashInHand-=Location[ID].buildCost;
                                    Location[ID].hotelBuilt=TRUE;
                                    Location[ID].rent=Location[ID].hotel;
                                    goto_XY(95,15+j); 
                                    printf("PROPERTY \"%s\" NOW HAS A HOTEL!",Location[ID].name);
                                }
                                else
                                {
                                    goto_XY(95,16+j); 
                                    printf("INSUFFICIENT BALANCE!");
                                }
                                return EXIT_SUCCESS;
                            }
                        }
                        else 
                            return EXIT_SUCCESS;

                    }
                    else
                    {
                        goto_XY(95,11+j); 
                        printf("SET NOT COMPLETED!");
                    }
                    goto_XY(95,12+j);printf("PRESS ANY KEY TO CONTINUE...");
                    TimedCharInput(2,0);
                }
                else
                {
                    goto_XY(95,11+j); 
                    printf("HOUSES AND HOTELS CANNOT BE BUILT AT THIS LOCATION!");
                    goto_XY(95,12+j);printf("PRESS ANY KEY TO CONTINUE...");
                    TimedCharInput(2,0);
                }
            }
            else 
            {
                if(i==0)
                {
                    goto_XY(95,11+j);printf("YOU CHOSE AN INVALID OPTION . YOU CAN TRY ONCE AGAIN.");
                    goto_XY(95,12+j);printf("PRESS ANY KEY TO CONTINUE...");
                    TimedCharInput(5,0);
                }
                else
                {
                    goto_XY(95,11+j);printf("YOU CHOSE TO CONTINUE AND ROLL BY DEFAULT"); 
                    return EXIT_SUCCESS;
                }
            }
        }
    } 
}

int BuyMenu(struct player *CurrentPlayer,struct location *currentLocation)
{
    char Choice;
    for (int i=0;i<2;i++)
    {
        ClearRightScreen(0);

        goto_XY(95,3); 
        printf("PLAYER: ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);
        printf("CASH IN HAND: $%d NET WORTH: $%d                              ",CurrentPlayer->cashInHand,CurrentPlayer->netWorth);   

        goto_XY(95,5); printf("MENU FOR ");
        colour(CurrentPlayer->colour1,CurrentPlayer->colour2);
        printf("%s ",CurrentPlayer->name);
        colour(RESET,RESET);
        
        goto_XY(95,6); printf("Would you like to buy %s for $%d ?",currentLocation->name,currentLocation->cost);
        goto_XY(95,7); printf("  1-YES");
        goto_XY(95,8); printf("  2-NO");
        goto_XY(95,10);printf("You have 10 seconds or 2 will be chosen by default...");
        Choice = TimedCharInput(10,0);
        if(Choice == 0)
        {
            goto_XY(95,15);printf("YOU TOOK TOO LONG TO CHOOSE, NO WAS CHOSEN BY DEFAULT");
            return EXIT_SUCCESS;
        }
        else if(Choice =='1')
        {
            if(currentLocation->isOwnable)
            {
                if (currentLocation->cost>CurrentPlayer->cashInHand)
                {
                    goto_XY(95,15);
                    printf("INSUFFICIENT BALANCE");
                }
                else
                {
                    goto_XY(95,15);printf("BOUGHT %s!",currentLocation->name);
                    currentLocation->isOwnable=FALSE;
                    currentLocation->ownerID=CurrentPlayer->ID;
                    CurrentPlayer->cashInHand -= currentLocation->cost;
                    CurrentPlayer->propertyOwned[CurrentPlayer->propertyOwnedCount]=currentLocation->ID;
                    CurrentPlayer->propertyOwnedCount++;
                }
            }
            else
            {
                goto_XY(95,15);
                printf("THIS PROPERTY CANNOT BE BOUGHT!");
            }
            return EXIT_SUCCESS;
        }
        else if(Choice =='2')
        {
            goto_XY(95,15);printf("YOU CHOSE NO"); 
            return EXIT_SUCCESS;
        }
        else
        {
            if(i==0)
            {
                goto_XY(95,15);printf("YOU CHOSE AN INVALID OPTION. YOU CAN TRY ONCE AGAIN.");
                goto_XY(95,16);printf("PRESS ANY KEY TO CONTINUE...");
                TimedCharInput(5,0);
            }
            else
            {
                goto_XY(95,15);printf("YOU CHOSE TO ROLL BY DEFAULT"); 
                return EXIT_SUCCESS;
            }
        }
    } 
}

int IsPlayerBankrupt(int cashInHand)
{
    if(cashInHand>BANKRUPT_VALUE)
        return FALSE;
    else
        return TRUE;
}

int PlayerResults(struct player Player[],int PlayerCount)
{       
    printf("\n");         
    printf("\n                                                 8888888b.  8888888888 .d8888b.  888     888 888    88888888888 .d8888b.  ");
    printf("\n                                                 888   Y88b 888       d88P  Y88b 888     888 888        888    d88P  Y88b ");
    printf("\n                                                 888    888 888       Y88b.      888     888 888        888    Y88b.      ");
    printf("\n                                                 888   d88P 8888888    \"Y888b.   888     888 888        888     \"Y888b.   ");
    printf("\n                                                 8888888P\"  888           \"Y88b. 888     888 888        888        \"Y88b. ");
    printf("\n                                                 888 T88b   888             \"888 888     888 888        888          \"888 ");
    printf("\n                                                 888  T88b  888       Y88b  d88P Y88b. .d88P 888        888    Y88b  d88P ");
    printf("\n                                                 888   T88b 8888888888 \"Y8888P\"   \"Y88888P\"  88888888   888     \"Y8888P\"  ");
    printf("\n\n\n\n\n");
    int len=12,array[10];
    for (int i=0;i<PlayerCount;i++)
        array[i]=0;
    for (int i=0;i<PlayerCount;i++)
    {
        if (len<strlen(Player[i].name))
            len=strlen(Player[i].name);
        if (Player[i].position!=0)
            array[Player[i].position-1]=Player[i].ID;
    }
    for (int i=0;i<PlayerCount;i++)
    {
        if (array[i]==0)
        {
            int HighestNetworth=0;
            for (int j=0;j<PlayerCount;j++)
            {   
                if(Player[j].position==0)
                {
                    if(Player[j].netWorth>HighestNetworth)
                    {
                        HighestNetworth=Player[j].netWorth;
                        array[i]=j+1;
                    }
                    else if(Player[j].netWorth==HighestNetworth)
                    {
                        int HighestCashInHand=0;
                        for (int j=0;j<PlayerCount;j++)
                        {   
                            if(Player[j].position==0)
                            {
                                if(Player[j].cashInHand>HighestCashInHand)
                                {
                                    HighestCashInHand=Player[j].cashInHand;
                                    array[i]=j+1;
                                }
                            }
                        }
                    }
                }
            }
            Player[array[i]-1].position=i+1;
        }
    }
    printf("\n\t\t%9s     %*s     %13s     %9s","POSITION",len,"PLAYER NAME","CASH IN HAND","NET WORTH");
    for (int i=0; i<PlayerCount; i++){
        printf("\n\t\t%9d     %*s     %13d     %9d",Player[array[i]-1].position,len,Player[array[i]-1].name,Player[array[i]-1].cashInHand,Player[array[i]-1].netWorth);
    }
    return EXIT_SUCCESS;
}
