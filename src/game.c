#include "definitions.h"

int ReadLocations()
{
	FILE *file = fopen(LOCATION_PATH, "r");
	if (!file)
        return EXIT_FAILURE;
	else
    {
		char buffer[1024];
		int row = 0, column = 0, flag = 0;
		while (fgets(buffer,1024, file)) {
			column = 0; 
			char* value = strtok(buffer, ",");
            while (value) {
                if (row == 0)
				    break;
                if (strcmpi(value,"-")!=0){    
                    switch(column){
                        case 0: Location[row-1].ID = atoi(value);
                                break;
                        case 1: if (strcmpi(value,"FREE")==0){
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
                                else if (strcmpi(value,"UTILITY")==0){
                                    Location[row-1].Type = UTILITY;
                                    Location[row-1].isOwnable = True;
                                }
                                else if (strcmpi(value,"TAX")==0){
                                    Location[row-1].Type = TAX;
                                    Location[row-1].isOwnable = False;
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
                        case 2: strcpy(Location[row-1].name,value);          
                                break;    
                    }
                    if (column==5 && Location[row-1].Type > 4){
                        Location[row-1].Cost = atoi(value);
                    }
                    if (column==6 && Location[row-1].Type > 5){
                        Location[row-1].intialRent = atoi(value);
                        Location[row-1].Rent = atoi(value);
                    }
                    if (Location[row-1].Type == PROPERTY){
                        switch(column){
                            case 3: Location[row-1].SetID=atoi(value);
                                    break;
                            case 4: strcpy(Location[row-1].colour,value);
                                    break;
                            case 7: Location[row-1].house[0]=atoi(value);
                                    break;
                            case 8: Location[row-1].house[1]=atoi(value);
                                    break;
                            case 9: Location[row-1].house[2]=atoi(value);
                                    break;
                            case 10:Location[row-1].house[3]=atoi(value);
                                    break;
                            case 11:Location[row-1].hotel=atoi(value);
                                    break;
                            case 12:Location[row-1].houseCost=atoi(value);
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

int ReadCards(int CardType)
{
    FILE *file;
    srand(time(0));
    int randomRecord=0;
    if (CardType == CHEST)
    {
	    file = fopen(CHEST_PATH, "r");
        randomRecord = (rand()%(MAX_CHESTCARDS))+1;
    }
    else if (CardType == CHANCE)
    {
	    file = fopen(CHANCE_PATH, "r");	  
        randomRecord = (rand()%(MAX_CHANCECARDS))+1;
    }
    else
    {
        return EXIT_FAILURE;   
    }

	if (!file)
        return EXIT_FAILURE;
	else
    {
        drawnCard.ID  =0;
        drawnCard.Type=0;
        strcpy(drawnCard.Description,0);
		char buffer[1024];
		int row = 0, column = 0, flag = 0;
		while (fgets(buffer,1024, file)) {
			column = 0; 
			char* value = strtok(buffer, ",");
            while (value) {
                if (row != randomRecord)
				    break;   
                else
                {
                    switch(column){
                        case 0: drawnCard.ID=atoi(value);
                                break;
                        case 1: drawnCard.Type=atoi(value);
                                break;
                        case 2: strcpy(drawnCard.Description,value);   
                                break;    
                    } 
                    value = strtok(NULL, ",");
                    column++;
                }
			}
            row++;
		}
		fclose(file);
	}
    return EXIT_SUCCESS;
}

int TimedInput(int seconds,int Default)
{
    int numInput;
    clock_t start = clock();
    while ( ! _kbhit() )
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= seconds) 
            return Default;
    scanf("%d",&numInput);
    return numInput;
}
