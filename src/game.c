#include "definitions.h"
#include "game.h"

int SelectGamemode()
{
    char choice;
    while(TRUE)
    {
        clearScreen();
        printf("\n     .d8888b.  8888888888 888      8888888888 .d8888b. 88888888888       .d8888b.         d8888 888b     d888 8888888888 888b     d888  .d88888b.  8888888b.  8888888888 ");
        printf("\n    d88P  Y88b 888        888      888       d88P  Y88b    888          d88P  Y88b       d88888 8888b   d8888 888        8888b   d8888 d88P\" \"Y88b 888  \"Y88b 888        ");
        printf("\n    Y88b.      888        888      888       888    888    888          888    888      d88P888 88888b.d88888 888        88888b.d88888 888     888 888    888 888        ");
        printf("\n     \"Y888b.   8888888    888      8888888   888           888          888            d88P 888 888Y88888P888 8888888    888Y88888P888 888     888 888    888 8888888    ");
        printf("\n        \"Y88b. 888        888      888       888           888          888  88888    d88P  888 888 Y888P 888 888        888 Y888P 888 888     888 888    888 888        ");
        printf("\n          \"888 888        888      888       888    888    888          888    888   d88P   888 888  Y8P  888 888        888  Y8P  888 888     888 888    888 888        ");
        printf("\n    Y88b  d88P 888        888      888       Y88b  d88P    888          Y88b  d88P  d8888888888 888   \"   888 888        888   \"   888 Y88b. .d88P 888  .d88P 888        ");
        printf("\n     \"Y8888P\"  8888888888 88888888 8888888888 \"Y8888P\"     888           \"Y8888P88 d88P     888 888       888 8888888888 888       888  \"Y88888P\"  8888888P\"  8888888888 ");
        printf("\n\n\n\n\n");
        printf("\n\tChoose a game mode:");
        printf("\n\t  1-Net Worth : First player to reach a certain amount wins");
        printf("\n\t  2-Turns     : Game ends after ceratin number of turns/rounds are over");
        printf("\n\t  3-Endless   : Game goes on untill everyone except one player gets bankrupt");
        printf("\n\t  X-Exit\n\n");
        choice = getch();
        if (choice == '1')
            return NETWORTH;
        else if (choice == '2')
            return TURNS;
        else if (choice == '3')
            return ENDLESS;
        else if (choice == 'X'|| choice == 'x')
            return EXIT;
        else
        {
            printf("\n\n\tYou entered an invalid choice \"%c\". Enter any key to try again.",choice);
            getch();
        }
    }
}    

int ReadLocations()
{
	FILE *file = fopen(LOCATION_PATH, "r");
	if (!file)
        return EXIT_FAILURE;
	else
    {
		char buffer[1024];
		int row = 0, column = 0;
		while (fgets(buffer,1024, file)) {
			column = 0; 
			char* value = strtok(buffer, ",");
            while (value) {
                if (row == 0)
				    break;
                if (strcmp(value,"-")!=0){    
                    switch(column){
                        case ID_H: 
                                Location[row-1].ID = atoi(value);
                                break;
                        case LocType_H: 
                                if (strcmp(value,"FREE")==0){
                                    Location[row-1].type = FREE;
                                    Location[row-1].isOwnable = FALSE;
                                }
                                else if (strcmp(value,"CHEST")==0){
                                    Location[row-1].type = CHEST;
                                    Location[row-1].isOwnable = FALSE;
                                }
                                else if (strcmp(value,"CHANCE")==0){
                                    Location[row-1].type = CHANCE; 
                                    Location[row-1].isOwnable = FALSE;
                                }
                                else if (strcmp(value,"JAIL")==0){
                                    Location[row-1].type = JAIL;   
                                    Location[row-1].isOwnable = FALSE;
                                }
                                else if (strcmp(value,"TAX")==0){
                                    Location[row-1].type = TAX;
                                    Location[row-1].isOwnable = FALSE;
                                }
                                else if (strcmp(value,"UTILITY")==0){
                                    Location[row-1].type = UTILITY;
                                    Location[row-1].isOwnable = TRUE;
                                }
                                else if (strcmp(value,"RAIL")==0){
                                    Location[row-1].type = RAIL;
                                    Location[row-1].isOwnable = TRUE;
                                }
                                else if (strcmp(value,"PROPERTY")==0){
                                    Location[row-1].type = PROPERTY;   
                                    Location[row-1].isOwnable = TRUE;
                                    Location[row-1].isSetComplete = FALSE;
                                    Location[row-1].housesBuilt = 0;
                                    Location[row-1].hotelBuilt  = 0;
                                }   
                                break;
                        case LocName_H:
                                strcpy(Location[row-1].name,value);          
                                break;    
                    }
                    if (column==Cost_H && Location[row-1].type >= 5){
                        Location[row-1].cost = atoi(value);
                    }
                    if (column==Rent_H && Location[row-1].type >= 4){
                        Location[row-1].initialRent = atoi(value);
                        Location[row-1].rent = atoi(value);
                    }
                    if (Location[row-1].type == PROPERTY){
                        switch(column){
                            case SetID_H: 
                                    Location[row-1].setID=atoi(value);
                                    switch(Location[row-1].setID)
                                    {
                                        case 1 : Location[row-1].setColour=LIGHTBLACK_BG; break;
                                        case 2 : Location[row-1].setColour=LIGHTCYAN_BG;  break;
                                        case 3 : Location[row-1].setColour=LIGHTPURPLE_BG;break;
                                        case 4 : Location[row-1].setColour=YELLOW_BG;     break;
                                        case 5 : Location[row-1].setColour=LIGHTRED_BG;   break;
                                        case 6 : Location[row-1].setColour=LIGHTYELLOW_BG;break;
                                        case 7 : Location[row-1].setColour=LIGHTGREEN_BG; break;
                                        case 8 : Location[row-1].setColour=LIGHTBLUE_BG;  break;
                                    }
                                    break;
                            case H1_H: 
                                    Location[row-1].house[0]=atoi(value);
                                    break;
                            case H2_H: 
                                    Location[row-1].house[1]=atoi(value);
                                    break;
                            case H3_H: 
                                    Location[row-1].house[2]=atoi(value);
                                    break;
                            case H4_H:
                                    Location[row-1].house[3]=atoi(value);
                                    break;
                            case Hotel_H:
                                    Location[row-1].hotel=atoi(value);
                                    break;
                            case BuildCost_H:
                                    Location[row-1].buildCost=atoi(value);
                                    break;
                        }
                    }
                }
				value = strtok(NULL, ",");
				column++;
			}
            row++;
		}
		fclose(file);
	}
    return EXIT_SUCCESS;
}

int GenerateCard()
{
    srand(time(0));
    switch((rand()%(3))-1)
    {
        case -1:
                drawnCard.type =BAD;
                drawnCard.money=((rand()%(20))+1)*10;
                break;
        case  0:
                drawnCard.type=NEUTRAL;
                drawnCard.locationID=rand()%(40);
                break;
        case  1:
                drawnCard.type=GOOD;
                drawnCard.money=((rand()%(30))+1)*10;
                break;
        default:return EXIT_FAILURE;
    } 
    return EXIT_SUCCESS;
}

int DisplayMap()
{
    colour(BLACK,INCREASED_INTENSITY);
    clearScreen();
    printf("\n");
    printf("\n                ST.CH  ELCT  STATES VRGNIA PNSLVA  ST.JA   COM    TEN    NY    FREE         ");
    printf("\n                 AVE   COMP    AVE    AVE   RAIL    AVE   CHEST   AVE   AVE    PARK         ");
    printf("\n        ____________________________________________________________________________        ");
    printf("\n VISIT |      |      |      |      |      |      |      |      |      |      |      |       ");
    printf("\n  JAIL |      |      |      |      |      |      |      |      |      |      |      |       ");
    printf("\n       |______|______|______|______|______|______|______|______|______|______|______|       ");
    printf("\n CNNCT |      |                                                              |      | KNTCY ");
    printf("\n  AVE  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n VERMNT|      |                                                              |      |       ");
    printf("\n  AVE  |      |                                                              |      |CHANCE ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n       |      |                                                              |      |  IND  ");
    printf("\n CHANCE|      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n ORNTL |      |                                                              |      |  ILL  ");
    printf("\n  AVE  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n  READ |      |                                                              |      | B&O.  ");
    printf("\n  RAIL |      |                                                              |      | RAIL  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n       |      |                                                              |      |ATLNTC ");
    printf("\n  TAX  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n BALTIC|      |                                                              |      | VNTNR ");
    printf("\n  AVE  |      |                                                              |      |  AVE  ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n  COM  |      |                                                              |      | WATER ");
    printf("\n CHEST |      |                                                              |      | WORKS ");
    printf("\n       |______|                                                              |______|       ");
    printf("\n MEDTRN|      |                                                              |      | MRVN  ");
    printf("\n  AVE  |      |                                                              |      | GRDNS ");
    printf("\n       |______|______________________________________________________________|______|       ");
    printf("\n       |      |      |      |      |      |      |      |      |      |      |      | GO TO ");
    printf("\n START |      |      |      |      |      |      |      |      |      |      |      |  JAIL ");
    printf("\n       |______|______|______|______|______|______|______|______|______|______|______|       ");
    printf("\n                BRDWK LUXURY  PARK  CHANCE  SHORT PNSLVA   COM    NC    PCFC                ");
    printf("\n                       TAX    PLACE         LINE    AVE   CHEST   AVE   AVE                 ");
    colour(RESET,0);
    return EXIT_SUCCESS;
}

int GraphicalPropertyInfo(struct player Players[],int playerCount)
{
    int map[40][2]={{ 9,36},{ 9,33},{ 9,30},{ 9,27},{ 9,24},{ 9,21},{ 9,18},{ 9,15},{ 9,12},{ 9, 9},\
                    { 9, 6},{16, 6},{23, 6},{30, 6},{37, 6},{44, 6},{51, 6},{58, 6},{65, 6},{72, 6},\
                    {79, 6},{79, 9},{79,12},{79,15},{79,18},{79,21},{79,24},{79,27},{79,30},{79,33},\
                    {79,36},{72,36},{65,36},{58,36},{51,36},{44,36},{37,36},{30,36},{23,36},{16,36}};
    
    for (int i=0;i<40;i++)
    {
        int ID = Location[i].ID;
        if (Location[i].type==PROPERTY||Location[i].type==RAIL||Location[i].type==UTILITY)
        {
            if (Location[i].type==PROPERTY)
            {
                goto_XY(map[ID-1][0]+5,map[ID-1][1]);
                colour(Location[i].setColour,0);
                printf(" ");
                colour(RESET,RESET);
            }        
            if(Location[i].isOwnable)
            {
                colour(RESET,RESET);
                goto_XY(map[ID-1][0]+4,map[ID-1][1]+1);
                printf("  ");
            }
            else
            {
                for(int j=0;j<playerCount;j++)
                {
                    if (Location[i].ownerID==Players[j].ID)
                    {
                        goto_XY(map[ID-1][0]+4,map[ID-1][1]+1);
                        colour(Players[j].colour1,Players[j].colour2);
                        if (Location[i].hotelBuilt)
                            printf("HL");
                        else if (Location[i].housesBuilt>0)
                            printf("%dH",Location[i].housesBuilt);
                        else
                            printf(" X");
                        colour(RESET,RESET);
                    }
                }
            }
            
        }
    }
    colour(RESET,RESET);
    return EXIT_SUCCESS;
}
