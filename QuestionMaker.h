
#ifndef STUDYGAME_QUESTIONMAKER_H
#define STUDYGAME_QUESTIONMAKER_H

#include <vector>
#include "Card.h"
#include "Question.h"

Question makeQuestion(const Card& card, const std::vector<Card>& allCards);


#endif //STUDYGAME_QUESTIONMAKER_H
