#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "definitions.h"
#include "read.h"

int main(){
    system("@cls||clear");
    char inp[1];
    short int numberOfPlayers;
    while (True){
        printf("\nEnter the number of players: ");
        scanf("%s",&inp);
        system("@cls||clear");
        if (atoi(inp) >= 1 && atoi(inp) <= MAX_PLAYER){
            numberOfPlayers=atoi(inp);
            break;
        }
        else if ((inp[0] == 88)||(inp[0] == 120)){
            exit(0);
            break;
        }
        printf("Invalid Input (Enter a number from 1-%d or X to exit game) \nEntered: %s\n",MAX_PLAYER,inp);
    }

    char Names[MAX_PLAYER][30];
    for (int i=0;i<numberOfPlayers;i++){
        printf("\nPlayer %d enter name: ",i+1);
        scanf("%s",&Names[i]);
        system("@cls||clear");
    }

    int die1, die2, order[numberOfPlayers];
    srand(time(0)); //seed for random dice

    for(int i=0;i<numberOfPlayers;i++){
        die1=(rand()%6)+1;
        die2=(rand()%6)+1;
        order[i]=die1+die2;
        printf("\nPlayer %s rolled a %d and a %d thus has a total of %d.",Names[i],die1,die2,order[i]);
        
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
    if (Readfile()==1)
        exit(0);
    struct player Player[numberOfPlayers];
    printf("\n\nPlaying order based on highest roll of the dice: \n");
    for(int i=0;i<numberOfPlayers;i++){    
        strcpy(Player[i].name,Names[i]);
        printf("Player %s\n",Player[i].name);
        Player[i].currentLocation = &Location[0];
        Player[i].position = 1;
        Player[i].networth = Player[i].cashInHand = INTIAL_AMT;
        Player[i].isBankrupt = Player[i].inJail = False;
    }
    
    //For testing:
        int num;
        printf("\nEnter number 1-40 to check record: ");
        scanf("%d",&num);
        num = num-1;
        printf("\nName: %s",Location[num].name);
        printf("\tIs ownable?: ");
        if (Location[num].isOwnable)
            printf("True");
        else 
            printf("False");
        
    return 0;
}