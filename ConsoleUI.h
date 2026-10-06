
#ifndef STUDYGAME_CONSOLEUI_H
#define STUDYGAME_CONSOLEUI_H
#include "Game.h"
#include "Session.h"

int readChoice(size_t numChoices);

void printReview(const Session& session);

void runGame(Game& game);


#endif //STUDYGAME_CONSOLEUI_H
