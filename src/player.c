#include "definitions.h"

int PlayerRolls()
{
    return (rand()%6)+1;
}

int ReadPlayers(int *numberOfPlayers, char (*Names)[30])
{
    char inp[1];
    while (True){
        clearScreen();
        //goto_XY((SCREENSIZE_X-(145))/2,2);
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
        if (atoi(inp) >= 2 && atoi(inp) <= MAX_PLAYER){
            *numberOfPlayers=atoi(inp);
            break;
        }
        else if ((inp[0] == 'X')||(inp[0] == 'x')){
            exit(0);
            break;
        }
        printf("\n\n\tInvalid Input (Enter a number from 2-%d or X to exit game) \n\tEntered: %s\n",MAX_PLAYER,inp);
        goto_XY(0,SCREENSIZE_Y);printf("\tEnter any key to retry...");
        getch();
    }
    for (int i=0;i<*numberOfPlayers;i++){
        printf("\n\tPlayer %d enter name: ",i+1);
        fflush(stdin);
        scanf("%[^\n]s",&Names[i]);
    } 
    return EXIT_SUCCESS;
}

int SetPlayerOrder(int numberOfPlayers, char (*Names)[30])
{
    clearScreen();
    //goto_XY((SCREENSIZE_X-(130))/2,2);
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
    int die1, die2, order[numberOfPlayers], len=strlen(Names[0]);
    for (int i=0;i<numberOfPlayers;i++)
        if (len<strlen(Names[i]))
            len=strlen(Names[i]);

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

int clearRightScreen(int startLine)
{
    for (int i=startLine;i<SCREENSIZE_Y;i++)
    {
        goto_XY(95,i);
        for(int j=0;j<(SCREENSIZE_X-95);j++)
            printf(" ");
    }
}

int PlayerMainMenu(struct player *CurrentPlayer)
{
    char Choice;
    for (int i=0;i<2;i++)
    {
        clearRightScreen(0);
        goto_XY(95,3); printf("PLAYER: %s CASH IN HAND: $%d NETWORTH: $%d                              ",CurrentPlayer->name,CurrentPlayer->cashInHand,CurrentPlayer->networth);          
        goto_XY(95,5); printf("MENU FOR %s",CurrentPlayer->name);
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
                goto_XY(95,15);printf("YOU CHOSE AN INVALID OPTION '%c'. YOU CAN TRY ONCE AGAIN.",Choice);
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

int checkSet(struct player *currentPlayer ,struct location *currentLocation)
{
    for(int i;i<MAX_LOCATIONS;i++)
    {
        if(Location->isOwnable && currentLocation->SetID==Location[i].SetID && Location[i].SetID!=0)
        {
            if(currentPlayer->ID!=Location[i].ownerID)
            {
                for(int i;i<MAX_LOCATIONS;i++){
                    if(currentLocation->SetID==Location[i].SetID && currentPlayer->ID==Location[i].ownerID){
                        currentLocation->isSetComplete=False;
                    }
                }
                for(int i;i<10;i++){
                    if(currentPlayer->SetsOwned[i]==currentLocation->SetID){
                        currentPlayer->SetsOwned[i]=0;
                        currentPlayer->SetsOwnedCount--;
                    }
                }
                return EXIT_SUCCESS;
            }
        }
    }
    for(int i;i<MAX_LOCATIONS;i++){
        if(currentLocation->SetID==Location[i].SetID && currentPlayer->ID==Location[i].ownerID){
            currentLocation->isSetComplete=True;
        }
    }
    for(int i;i<10;i++){
        if(currentPlayer->SetsOwned[i]==0){
            currentPlayer->SetsOwned[i]=currentLocation->SetID;
            currentPlayer->SetsOwnedCount++;
        }
    }
    return EXIT_SUCCESS;
}

int RentCalc(struct player *owner ,struct location *currentLocation, int rolled)
{
    if(currentLocation->Type==RAIL)
    {
        int RailsOwned;
        for(int i=0;i<MAX_LOCATIONS;i++){
            if(Location[i].Type==RAIL && Location->ownerID==owner->ID){
                RailsOwned++;
            }
        }
        for(int i=0;i<MAX_LOCATIONS;i++){
            if(Location[i].Type==RAIL && Location->ownerID==owner->ID){
                Location[i].Rent=25*RailsOwned;
            }
        }
    }
    else if(currentLocation->Type==UTILITY)
    {
        int UtilitiesOwned;
        for(int i=0;i<MAX_LOCATIONS;i++){
            if(Location[i].Type==UTILITY && Location->ownerID==owner->ID){
                UtilitiesOwned++;
            }
        }
        for(int i=0;i<MAX_LOCATIONS;i++){
            if(Location[i].Type==UTILITY && Location->ownerID==owner->ID){
                if (UtilitiesOwned==1)
                    Location[i].Rent=4*rolled;
                else if (UtilitiesOwned==2)
                    Location[i].Rent=10*rolled;
            }
        }
    }
    return currentLocation->Rent;
}

int sellMenu(struct player *CurrentPlayer)
{
    char Choice;
    for (int i=0;i<2;i++)
    {
        int j=0;
        clearRightScreen(0);
        goto_XY(95,3); printf("PLAYER: %s CASH IN HAND: $%d NETWORTH: $%d                              ",CurrentPlayer->name,CurrentPlayer->cashInHand,CurrentPlayer->networth);          
        goto_XY(95,5); printf("SELL MENU FOR %s",CurrentPlayer->name);
        goto_XY(95,6); printf("Choose a property to sell:");
        if(CurrentPlayer->PropertyOwnedCount>0)
        {
            for(j=0;j<CurrentPlayer->PropertyOwnedCount;j++)
            {
                goto_XY(95,7+j); printf("  %2d-SELL %s",j+1,Location[ CurrentPlayer->PropertyOwned[j]-1 ].name);
            }
        }
        else 
        {
            goto_XY(95,8); printf("YOU OWN NO PROPERTIES!");
            goto_XY(95,11);printf("ROLLING BY DEFAULT"); 
            return EXIT_SUCCESS;
        }
        goto_XY(95,7+j);printf("   X-CONTINUE AND ROLL");
        goto_XY(95,9+j);printf("You have 10 seconds or X will be chosen by default...");
        Choice = TimedCharInput(10,0);
        if(Choice == 0)
        {
            goto_XY(95,11+j);printf("YOU TOOK TOO LONG TO CHOOSE, CONTINUE AND ROLL WAS CHOSEN BY DEFAULT");
            return EXIT_SUCCESS;
        }
        else if(Choice =='X'||Choice =='x')
        {
            goto_XY(95,11+j);printf("YOU CHOSE TO CONTINUE AND ROLL");
            return EXIT_SUCCESS;
        }
        else
        {
            int ChoiceInt = Choice-'0';
            if (1<=ChoiceInt && ChoiceInt<=CurrentPlayer->PropertyOwnedCount)
            {
                int ID = CurrentPlayer->PropertyOwned[ChoiceInt-1] -1;
                int cost;
                if (Location[ID].Type==PROPERTY) 
                    cost=Location[ID].Cost + (Location[ID].housesBuilt + Location[ID].hotelBuilt)*Location[ID].buildCost;
                else
                    cost=Location[ID].Cost;
                goto_XY(95,11+j); printf("SOLD %s FOR $%d",Location[ID].name,cost);
                CurrentPlayer->cashInHand += cost;
                CurrentPlayer->networth   += cost;
                CurrentPlayer->PropertyOwnedCount--;
                Location[ID].isOwnable=True;
                Location[ID].ownerID=0;
                Location[ID].housesBuilt=0;
                Location[ID].hotelBuilt=False;
                Location[ID].isSetComplete=False;
                Location[ID].Rent=Location[ID].intialRent;
                for(int s1=ChoiceInt-1; s1<19; s1++){
                    CurrentPlayer->PropertyOwned[s1]=CurrentPlayer->PropertyOwned[s1+1];
                }        
                CurrentPlayer->PropertyOwned[19]=0;  
                if(checkSet(CurrentPlayer,&Location[ID])!=EXIT_SUCCESS)
                {
                    goto_XY(0,SCREENSIZE_Y-2);
                    printf("\nSet Check Error at Location Record: %d",ID);
                    return EXIT_FAILURE;
                }
                return EXIT_SUCCESS;
            }
            else 
            {
                if(i==0)
                {
                    goto_XY(95,11+j);printf("YOU CHOSE AN INVALID OPTION '%c'. YOU CAN TRY ONCE AGAIN.",Choice);
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

int buyHousesMenu(struct player *CurrentPlayer)
{
    char Choice;
    for (int i=0;i<2;i++)
    {
        int j=0;
        clearRightScreen(0);
        goto_XY(95,3); printf("PLAYER: %s CASH IN HAND: $%d NETWORTH: $%d                              ",CurrentPlayer->name,CurrentPlayer->cashInHand,CurrentPlayer->networth);          
        goto_XY(95,5); printf("BUY HOUSES AND HOTELS MENU FOR %s",CurrentPlayer->name);
        goto_XY(95,6); printf("Choose an option for your properties:");
        if(CurrentPlayer->PropertyOwnedCount>0)
        {
            for(j=0;j<CurrentPlayer->PropertyOwnedCount;j++)
            {
                goto_XY(95,7+j); 
                printf("  %2d-BUY HOUSES/HOTEL FOR %s",j+1,Location[ CurrentPlayer->PropertyOwned[j]-1 ].name);
            }
        }
        else 
        {
            goto_XY(95,8); printf("YOU OWN NO PROPERTIES!");
            goto_XY(95,11);printf("YOU CHOSE TO CONTINUE AND ROLL BY DEFAULT"); 
            return EXIT_SUCCESS;
        }
        goto_XY(95,7+j);printf("   X-CONTINUE AND ROLL");
        goto_XY(95,9+j);printf("You have 10 seconds or X will be chosen by default...");
        Choice = TimedCharInput(10,0);
        if(Choice == 0)
        {
            goto_XY(95,11+j);printf("YOU TOOK TOO LONG TO CHOOSE, CONTINUE AND ROLL WAS CHOSEN BY DEFAULT");
            return EXIT_SUCCESS;
        }
        else if(Choice =='X'||Choice =='x')
        {
            goto_XY(95,11+j);printf("YOU CHOSE TO CONTINUE AND ROLL");
            return EXIT_SUCCESS;
        }
        else
        {
            int ChoiceInt = Choice-'0';
            if (1<=ChoiceInt && ChoiceInt<=CurrentPlayer->PropertyOwnedCount)
            {
                int ID = CurrentPlayer->PropertyOwned[ChoiceInt-1];
                if(Location[ID].Type==PROPERTY)
                {
                    if (Location[ID].isSetComplete)
                    {
                        char buildChoice;
                        goto_XY(95,11+j); printf("Do you want to build houses or a hotel?:");
                        goto_XY(95,12+j); printf(" 1-HOUSES");
                        goto_XY(95,13+j); printf(" 2-HOTELS");
                        goto_XY(95,14+j); printf(" X-NONE");
                        buildChoice=getch();
                        if (buildChoice=='1')
                        {
                            int count;
                            goto_XY(95,15+j); printf("HOW MANY HOUSES WOULD YOU LIKE TO BUILD (1-4):");
                            scanf("%d",&count);
                            if( 0>(count+Location[ID].housesBuilt) && (count+Location[ID].housesBuilt)>4)
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
                                    Location[ID].Rent=Location[ID].house[Location[ID].housesBuilt];
                                    goto_XY(95,16+j); 
                                    printf("PROPERTY \"%s\" NOW HAS %d HOUSES!",Location[ID].name,Location[ID].housesBuilt);
                                    if(checkSet(CurrentPlayer,&Location[ID])!=EXIT_SUCCESS)
                                    {
                                        goto_XY(0,SCREENSIZE_Y-2);
                                        printf("\nSet Check Error at Location Record: %d",ID);
                                        return EXIT_FAILURE;
                                    }
                                }
                                else
                                {
                                    goto_XY(95,16+j); 
                                    printf("INSUFFICIENT BALANCE!");
                                }
                            }
                        }
                        else if (buildChoice=='2')
                        { 
                            if(Location[ID].housesBuilt==True)
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
                                    Location[ID].hotelBuilt=True;
                                    Location[ID].Rent=Location[ID].hotel;
                                    goto_XY(95,15+j); 
                                    printf("PROPERTY \"%s\" NOW HAS A HOTEL!",Location[ID].name);
                                    if(checkSet(CurrentPlayer,&Location[ID])!=EXIT_SUCCESS)
                                    {
                                        goto_XY(0,SCREENSIZE_Y-2);
                                        printf("\nSet Check Error at Location Record: %d",ID);
                                        return EXIT_FAILURE;
                                    }
                                }
                                else
                                {
                                    goto_XY(95,16+j); 
                                    printf("INSUFFICIENT BALANCE!");
                                }
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
                    goto_XY(95,11+j);printf("YOU CHOSE AN INVALID OPTION '%c'. YOU CAN TRY ONCE AGAIN.",Choice);
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

int buyMenu(struct player *CurrentPlayer,struct location *currentLocation)
{
    char Choice;
    for (int i=0;i<2;i++)
    {
        clearRightScreen(0);
        goto_XY(95,3); printf("PLAYER: %s CASH IN HAND: $%d NETWORTH: $%d                              ",CurrentPlayer->name,CurrentPlayer->cashInHand,CurrentPlayer->networth);   
           
        goto_XY(95,5); printf("MENU FOR %s",CurrentPlayer->name);
        goto_XY(95,6); printf("Would you like to buy %s for $%d ?:",currentLocation->name,currentLocation->Cost);
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
                if (currentLocation->Cost>CurrentPlayer->cashInHand)
                {
                    goto_XY(95,15);
                    printf("INSUFFICIENT BALANCE");
                }
                else
                {
                    goto_XY(95,15);printf("BOUGHT %s!",currentLocation->name);
                    currentLocation->isOwnable=False;
                    currentLocation->ownerID=CurrentPlayer->ID;
                    CurrentPlayer->cashInHand -= currentLocation->Cost;
                    CurrentPlayer->PropertyOwned[CurrentPlayer->PropertyOwnedCount]=currentLocation->ID;
                    CurrentPlayer->PropertyOwnedCount++;

                    if(checkSet(CurrentPlayer,currentLocation)!=EXIT_SUCCESS)
                    {
                        goto_XY(0,SCREENSIZE_Y-2);
                        printf("\nSet Check Error at Location Record: %d",currentLocation->ID);
                        return EXIT_FAILURE;
                    }
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
                goto_XY(95,15);printf("YOU CHOSE AN INVALID OPTION '%c'. YOU CAN TRY ONCE AGAIN.",Choice);
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

int isPlayerBankrupt(int cashInHand)
{
    if(cashInHand>BANKRUPT_VALUE)
        return False;
    else
        return True;
}

int playerResults(struct player Player[],int PlayerCount)
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
    int len=12,array[PlayerCount];
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
                    if(Player[j].networth>HighestNetworth)
                    {
                        HighestNetworth=Player[j].networth;
                        array[i]=j+1;
                    }
                    else if(Player[j].networth==HighestNetworth)
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
    printf("\n\t\t%9s     %*s     %13s     %9s","POSITION",len,"PLAYER NAME","CASH IN HAND","NETWORTH");
    for (int i=0; i<PlayerCount; i++){
        printf("\n\t\t%9d     %*s     %13d     %9d",Player[array[i]-1].position,len,Player[array[i]-1].name,Player[array[i]-1].cashInHand,Player[array[i]-1].networth);
    }
    return EXIT_SUCCESS;
}