
#ifndef STUDYGAME_ATTEMPT_H
#define STUDYGAME_ATTEMPT_H
#include <string>

struct Attempt {
    std::string prompt;
    std::string chosenAnswer;
    std::string correctAnswer;
    std::string explanation;
    bool correct = false;
};
#endif //STUDYGAME_ATTEMPT_H
