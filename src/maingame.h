#ifndef MAINGAME_H_
#define MAINGAME_H_

#include "definitions.h"
#include "game.h"
#include "player.h"

// Clears screen and displays intro screen "WELCOME TO MONOPOLY"
// Returns EXIT_SUCCESS when displayed properly
int Intro();

// Clears screen and displays rules of monopoly
// Returns EXIT_SUCCESS when displayed properly
int ShowRules();

// Clears screen and displays rules of monopoly
// Returns EXIT_SUCCESS after game played successfully
int mainGame();

// Clears screen and displays intro screen "THANKS FOR PLAYING"
// Returns EXIT_SUCCESS when displayed properly
int ThankYou();

#endif
