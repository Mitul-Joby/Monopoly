#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "definitions.h"


int Readfile()
{
	FILE *file = fopen(PATH, "r");

	if (!file){
		printf("\nFile could not be opened\n");
        return 1;
    }
	else{
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
}                        