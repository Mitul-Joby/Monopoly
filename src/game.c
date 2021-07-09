#include "definitions.h"

int intro()
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
    goto_XY(130,40);printf("Press any key to continue...");getch();
    return EXIT_SUCCESS;
}

int showRules()
{
    clearScreen();
    printf("\n\n");
    printf("\n          888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P      8888888b.  888     888 888      8888888888 .d8888b.  ");
    printf("\n          8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P       888   Y88b 888     888 888      888       d88P  Y88b ");
    printf("\n          88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P        888    888 888     888 888      888       Y88b.      ");
    printf("\n          888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P         888   d88P 888     888 888      8888888    \"Y888b.   ");
    printf("\n          888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888          8888888P\"  888     888 888      888           \"Y88b. ");
    printf("\n          888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888          888 T88b   888     888 888      888             \"888 ");
    printf("\n          888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888          888  T88b  Y88b. .d88P 888      888       Y88b  d88P ");
    printf("\n          888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888          888   T88b  \"Y88888P\"  88888888 8888888888 \"Y8888P\"  ");
    printf("\n\n\n\n");                                                                                                                                                                                                  

    goto_XY(130,40);printf("Press any key to continue...");getch();
    return EXIT_SUCCESS;
}


int SelectGamemode()
{
    char Choice;
    while(True)
    {
        clearScreen();
        //int bannerlength=166;goto_XY((SCREENSIZE_X-(bannerlength))/2,2);
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
        printf("\n\t  1-Networth : First player to reach a certain amount wins");
        printf("\n\t  2-Turns    : Game ends after ceratin number of turns/rounds are over");
        printf("\n\t  3-Endless  : Game goes on untill everyone except one player gets bankrupt");
        printf("\n\t  X-Exit\n\n");
        Choice = getch();
        if (Choice == '1')
            return NETWORTH;
        else if (Choice == '2')
            return TURNS;
        else if (Choice == '3')
            return ENDLESS;
        else if (Choice == 'X'|| Choice == 'x')
            return EXIT;
        else
        {
            printf("\n\nYou entered an invalid choice \"%c\". Enter any key to try again.",Choice);
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
                if (strcmpi(value,"-")!=0){    
                    switch(column){
                        case ID_H: 
                                Location[row-1].ID = atoi(value);
                                break;
                        case LocType_H: 
                                if (strcmpi(value,"FREE")==0){
                                    Location[row-1].Type = FREE;
                                    Location[row-1].isOwnable = False;
                                }
                                else if (strcmpi(value,"CHEST")==0){
                                    Location[row-1].Type = CHEST;
                                    Location[row-1].isOwnable = False;
                                }
                                else if (strcmpi(value,"CHANCE")==0){
                                    Location[row-1].Type = CHANCE; 
                                    Location[row-1].isOwnable = False;
                                }
                                else if (strcmpi(value,"JAIL")==0){
                                    Location[row-1].Type = JAIL;   
                                    Location[row-1].isOwnable = False;
                                }
                                else if (strcmpi(value,"TAX")==0){
                                    Location[row-1].Type = TAX;
                                    Location[row-1].isOwnable = False;
                                }
                                else if (strcmpi(value,"UTILITY")==0){
                                    Location[row-1].Type = UTILITY;
                                    Location[row-1].isOwnable = True;
                                }
                                else if (strcmpi(value,"RAIL")==0){
                                    Location[row-1].Type = RAIL;
                                    Location[row-1].isOwnable = True;
                                }
                                else if (strcmpi(value,"PROPERTY")==0){
                                    Location[row-1].Type = PROPERTY;   
                                    Location[row-1].isOwnable = True;
                                    Location[row-1].isSetComplete = False;
                                    Location[row-1].housesBuilt = 0;
                                    Location[row-1].hotelBuilt  = 0;
                                }   
                                break;
                        case LocName_H:
                                strcpy(Location[row-1].name,value);          
                                break;    
                    }
                    if (column==Cost_H && Location[row-1].Type >= 5){
                        Location[row-1].Cost = atoi(value);
                    }
                    if (column==Rent_H && Location[row-1].Type >= 4){
                        Location[row-1].intialRent = atoi(value);
                        Location[row-1].Rent = atoi(value);
                    }
                    if (Location[row-1].Type == PROPERTY){
                        switch(column){
                            case SetID_H: 
                                    Location[row-1].SetID=atoi(value);
                                    break;
                            case ColourName_H: 
                                    strcpy(Location[row-1].colourName,value);
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
                drawnCard.Type =BAD;
                drawnCard.Money=((rand()%(20))+1)*10;
                break;
        case  0:
                drawnCard.Type=NEUTRAL;
                drawnCard.LocationID=rand()%(MAX_LOCATIONS);

                break;
        case  1:
                drawnCard.Type=GOOD;
                drawnCard.Money=((rand()%(30))+1)*10;
                break;
        default:return EXIT_FAILURE;
    } 
    return EXIT_SUCCESS;
}

int displayMap()
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

int graphicalMove(struct player *currentPlayer,int OldLocationID,int NewLocationID)
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

int thankYou()
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
    goto_XY(130,40);printf("Press any key to continue...");getch();
    return EXIT_SUCCESS;
}
