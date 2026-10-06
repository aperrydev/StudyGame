
#ifndef STUDYGAME_SESSION_H
#define STUDYGAME_SESSION_H
#include "Question.h"
#include "Attempt.h"
#include <vector>
class Session {
    std::vector<Attempt> attempts;
public:
    void record(const Question& question, std::size_t chosenIndex, bool correct);
    const std::vector<Attempt>& readAttempts() const;
    std::size_t total() const;
    std::size_t correctCount() const;
};

#endif //STUDYGAME_SESSION_H
