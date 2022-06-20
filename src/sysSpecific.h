#ifndef SYSSPECIFIC_H_
#define SYSSPECIFIC_H_
#ifdef _WIN32
    void checkWindowSize(int screenWidth, int screenHeight);
#elif defined __unix__
    int _kbhit(); 
    char getch_(int echo);
    char getch(void);
    char getche(void);
    void checkWindowSize(int screenWidth, int screenHeight);
#endif

#endif
