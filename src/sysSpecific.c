#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    void checkWindowSize(int screenWidth, int screenHeight)
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int width, height;  
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;  
        if (width < screenWidth || height < screenHeight)
        {
            printf("\nTerminal size is too small. Please resize terminal.");
            printf("\nSuggested size: %d X %d", screenWidth, screenHeight);
            printf("\nCurrent size  : %d X %d", width, height);
            printf("\n\n");
            exit(1);
        }
    }

#elif defined __unix__
    #include <ctype.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <termios.h>
    #include <sys/ioctl.h>

    int _kbhit(void)
    {
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
    }

    static struct termios old, current;

    char getch_(int echo)
    {
        char ch;
        tcgetattr(0, &old);
        current = old;
        current.c_lflag &= ~ICANON;
        if (echo) current.c_lflag |= ECHO;
        else current.c_lflag &= ~ECHO;
        tcsetattr(0, TCSANOW, &current);
        ch = getchar();
        tcsetattr(0, TCSANOW, &old);
        return ch;
    }

    char getch(void)
    {
        return getch_(0);
    }

    char getche(void)
    {
        return getch_(1);
    }

    void checkWindowSize(int screenWidth, int screenHeight)
    {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        if (w.ws_col< screenWidth || w.ws_row < screenHeight)
        {
            printf("\nTerminal size is too small. Please resize terminal.");
            printf("\nSuggested size: %d X %d", screenWidth, screenHeight);
            printf("\nCurrent size  : %d X %d", w.ws_col, w.ws_row);
            printf("\n\n");
            exit(1);
        }
    }
#endif
