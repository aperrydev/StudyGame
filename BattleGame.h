
#ifndef STUDYGAME_BATTLEGAME_H
#define STUDYGAME_BATTLEGAME_H
#include "StudySet.h"
#include "Game.h"

class BattleGame : public Game {
    StudySet& studySet;
    int playerHP;
    int enemyHP;
    Question currentQuestion;
public:
    BattleGame(StudySet& studySet);
    bool isOver() const override;
    std::string statusLine() const override;
    Question nextQuestion() override;
    AnswerResult submitAnswer(std::size_t choice) override;
    bool playerWon() const override;
};

#endif //STUDYGAME_BATTLEGAME_H
