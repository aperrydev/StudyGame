
#ifndef STUDYGAME_GAME_H
#define STUDYGAME_GAME_H
#include <string>
#include "Question.h"
#include "AnswerResult.h"
class Game {
public:
    virtual bool isOver() const = 0;
    virtual std::string statusLine() const = 0;
    virtual Question nextQuestion() = 0;
    virtual AnswerResult submitAnswer(std::size_t choice) = 0;
    virtual bool playerWon() const = 0;
    virtual ~Game () = default;
};



#endif //STUDYGAME_GAME_H
