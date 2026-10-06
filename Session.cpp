#include "Session.h"

using namespace std;

void Session::record(const Question& question, std::size_t chosenIndex, bool correct) {
    Attempt attempt;
    attempt.prompt = question.prompt;
    attempt.chosenAnswer = question.choices[chosenIndex];
    attempt.correctAnswer = question.choices[question.correctIndex];
    attempt.explanation = question.explanation;
    attempt.correct = correct;
    attempts.push_back(attempt);

}

const std::vector<Attempt>& Session::readAttempts() const {
    return attempts;
}

std::size_t Session::total() const {
    return attempts.size();
}

std::size_t Session::correctCount() const {
    size_t correctCount = 0;
    for (const auto& attempt : attempts) {
        if (attempt.correct) {
            correctCount++;
        }
    }
    return correctCount;
}
