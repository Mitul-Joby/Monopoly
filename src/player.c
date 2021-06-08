#include "definitions.h"

int PlayerRolls()
{
    return (rand()%6)+1;
}

int ReadPlayers(int *numberOfPlayers, char (*Names)[30])
{
    char inp[1];
    while (True){
        printf("\nEnter the number of players: ");
        scanf("%s",&inp);
        system("@cls||clear");
        if (atoi(inp) >= 1 && atoi(inp) <= MAX_PLAYER){
            *numberOfPlayers=atoi(inp);
            break;
        }
        else if ((inp[0] == 'X')||(inp[0] == 'x')){
            exit(0);
            break;
        }
        printf("Invalid Input (Enter a number from 1-%d or X to exit game) \nEntered: %s\n",MAX_PLAYER,inp);
    }
    for (int i=0;i<*numberOfPlayers;i++){
        printf("\nPlayer %d enter name: ",i+1);
        scanf("%s",&Names[i]);
        system("@cls||clear");
    } 
    return EXIT_SUCCESS;
}

int SetPlayerOrder(int numberOfPlayers, char (*Names)[30])
{
    srand(time(0));
    int die1, die2, order[numberOfPlayers], len=strlen(Names[0]);
    for (int i=0;i<numberOfPlayers;i++)
        if (len<strlen(Names[i]))
            len=strlen(Names[i]);

    for(int i=0;i<numberOfPlayers;i++){
        die1=PlayerRolls();
        die2=PlayerRolls();
        order[i]=die1+die2;
        printf("\n%*s rolled a %d and a %d thus has a total of %d.",len,Names[i],die1,die2,order[i]);
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

int PlayerMainMenu(char *name)
{
    char Choice;
    for (int i=0;i<2;i++)
    {
        system("@cls||clear");
        printf("\nMENU FOR %s",name);
        printf("\nChoose an option:");
        printf("\n  1-ROLL");
        printf("\n  2-BUY HOUSES AND HOTELS");
        printf("\n  3-SELL PROPERTIES");
        printf("\n  X-GIVE UP");
        printf("\n\nYou have 5 seconds or 1 will be chosen by default...");
        Choice = TimedCharInput(5,0);
        if(Choice == 0)
        {
            system("@cls||clear");
            printf("\nYOU TOOK TOO LONG TO CHOOSE, ROLL WAS CHOSEN BY DEFAULT");
            return ROLL;
        }
        else if(Choice =='1')
        {
            system("@cls||clear");
            printf("\nYOU CHOSE TO ROLL"); 
            return ROLL;
        }    
        else if(Choice =='2')
        {
            system("@cls||clear");
            printf("\nYOU CHOSE TO BUY HOUSES AND HOTELS"); 
            return BUY;
        }
        else if(Choice =='3')
        {
            system("@cls||clear");
            printf("\nYOU CHOSE TO SELL PROPERTIES");
            return SELL;
        }
        else if(Choice =='X'||Choice =='x')
        {
            system("@cls||clear");
            printf("\nYOU CHOSE TO GIVE UP");
            return GIVEUP;
        }
        else
        {
            if(i==0)
            {
                printf("\nYOU CHOSE AN INVALID OPTION '%c'. YOU CAN TRY ONCE AGAIN.");
                printf("\nPRESS ANY KEY TO CONTINUE...");
                TimedCharInput(5,0);
            }
            else
            {
                system("@cls||clear");
                printf("\nYOU CHOSE TO ROLL BY DEFAULT"); 
                return ROLL;
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
