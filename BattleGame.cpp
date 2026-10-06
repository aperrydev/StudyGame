#include "BattleGame.h"
#include "QuestionMaker.h"
#include <string>
using namespace std;


const int STARTING_HP = 100;
const int DAMAGE = 10;

BattleGame::BattleGame(StudySet& studySet) : studySet(studySet), playerHP(STARTING_HP), enemyHP(STARTING_HP) {
    this->studySet.shuffle();
}

bool BattleGame::isOver() const {
    return playerHP <= 0 ||  enemyHP <= 0;
}

bool BattleGame::playerWon() const {
    return enemyHP <= 0;
}

std::string BattleGame::statusLine() const {
    string playerStatus = "You: " + to_string(playerHP) + "HP";
    string enemyStatus = "Enemy: " + to_string(enemyHP) + "HP";
    return playerStatus + "  " + enemyStatus;
}

Question BattleGame::nextQuestion() {
    if (!studySet.hasMoreCards()) {
        studySet.shuffle();
    }
    const Card& card = studySet.nextCard();
    currentQuestion = makeQuestion(card, studySet.getCards());
    return currentQuestion;
}

AnswerResult BattleGame::submitAnswer(std::size_t choice) {
    AnswerResult result;
    if (choice == currentQuestion.correctIndex) {
        enemyHP -= DAMAGE;
        result.correct = true;
        result.message = "Correct! You hit for " + to_string(DAMAGE) + " HP.";
    }
    else {
        playerHP -= DAMAGE;
        result.correct = false;
        result.message = "Wrong. The answer was "
            + currentQuestion.choices[currentQuestion.correctIndex]
            + ". You take " + to_string(DAMAGE) + " damage.";
    }
    return result;
}
