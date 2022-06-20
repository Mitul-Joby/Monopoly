#include "maingame.h"

int main()
{
    checkWindowSize(SCREENSIZE_X, SCREENSIZE_Y);
    if (Intro()!=EXIT_SUCCESS){
        printf("\nIntro Error\n");
        return EXIT_FAILURE;
    }
    char choice;
    while(TRUE)
    {
        clearScreen();
        printf("\n                                              888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P           "); 
        printf("\n                                              8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P      ");       
        printf("\n                                              88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P             "); 
        printf("\n                                              888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P              "); 
        printf("\n                                              888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888              ");  
        printf("\n                                              888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888               "); 
        printf("\n                                              888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888              ");  
        printf("\n                                              888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888         ");       
        printf("\n\n\n\n\n");
        printf("\n\t  1-Play Monopoly");
        printf("\n\t  2-Read Rules");
        printf("\n\t  X-Exit\n\n");
        hideCursor();
        choice = getch();
        showCursor();
        if (choice == '1')
        {
            if (mainGame()!=EXIT_SUCCESS){
                printf("\nError in main Game\n");
                return EXIT_FAILURE;
            }
        }
        else if (choice == '2'){
            if (ShowRules()!=EXIT_SUCCESS){
                printf("\nError in showing rules\n");
                return EXIT_FAILURE;
            }    
        }
        else if (choice == 'X'|| choice == 'x')
        {
            clearScreen();
            if (ThankYou()!=EXIT_SUCCESS){
                printf("\nError in Thank You screen\n");
                return EXIT_FAILURE;
            }  
            clearScreen();
            return EXIT_SUCCESS;
        }
        else
        {
            printf("\n\n\tYou entered an invalid choice \"%c\". Enter any key to try again.",choice);
            getch();
        }
    }
    return EXIT_SUCCESS;
}
