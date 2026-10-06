
#ifndef STUDYGAME_QUESTION_H
#define STUDYGAME_QUESTION_H
#include <string>
#include <vector>
struct Question {
    std::string prompt;
    std::vector<std::string> choices;
    std::size_t correctIndex = 0;
    std::string explanation;
};

#endif //STUDYGAME_QUESTION_H
