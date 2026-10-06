#include "QuestionMaker.h"
#include <algorithm>
#include <random>

Question makeQuestion(const Card& card, const std::vector<Card>& allCards) {
    std::vector<std::string> sameCategory;
    std::vector<std::string> otherCategory;
    for (const Card& c: allCards) {
        if (card.definition != c.definition) {
            if (c.category == card.category) {
                if (std::find(sameCategory.begin(), sameCategory.end(), c.definition) == sameCategory.end()) {
                    sameCategory.push_back(c.definition);
                }
            }
            else {
                if (std::find(otherCategory.begin(), otherCategory.end(), c.definition) == otherCategory.end()) {
                    otherCategory.push_back(c.definition);
                }
            }
        }
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(sameCategory.begin(), sameCategory.end(), gen);
    std::shuffle(otherCategory.begin(), otherCategory.end(), gen);
    Question question;
    question.prompt = card.term;
    question.explanation = card.explanation;
    for (std::size_t i = 0; i < sameCategory.size() && question.choices.size() < 3; i++) {
        question.choices.push_back(sameCategory[i]);
    }
    for (std::size_t i = 0; i < otherCategory.size() && question.choices.size() < 3; i++) {
        question.choices.push_back(otherCategory[i]);
    }
    question.choices.push_back(card.definition);
    std::shuffle(question.choices.begin(), question.choices.end(), gen);
    for (std::size_t i = 0; i < question.choices.size(); i++) {
        if (question.choices[i] == card.definition) {
            question.correctIndex = i;
        }
    }
    return question;


}
