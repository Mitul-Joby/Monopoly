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

int isPlayerBankrupt(int cashInHand)
{
    if(cashInHand>-500)
        return False;
    else
        return True;
}
