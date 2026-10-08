
#ifndef STUDYGAME_QUESTIONMAKER_H
#define STUDYGAME_QUESTIONMAKER_H

#include <vector>
#include "Card.h"
#include "Question.h"

const int JITTER_MAX = 6;

std::vector<std::string> splitWords(const std::string& text);

int wordingScore(const std::string& correctTerm, const std::string& candidateTerm);

bool contains(const std::string& text, const std::string& piece);

bool hasDigit(const std::string& text);

bool hasLetter(const std::string& text);

int shapeScore(const std::string& correctAnswer, const std::string& candidateAnswer);

int totalScore(const Card& correctCard, const Card& candidateCard);

struct Candidate{
    std::string definition;
    int score = 0;
};

bool alreadyListed(const std::vector<Candidate>& candidates, const std::string definition);


Question makeQuestion(const Card& card, const std::vector<Card>& allCards);


#endif //STUDYGAME_QUESTIONMAKER_H
