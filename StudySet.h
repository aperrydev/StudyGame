
#ifndef STUDYGAME_STUDYSET_H
#define STUDYGAME_STUDYSET_H

#include <string>
#include <vector>
#include "Card.h"

class StudySet {
    std::string name;
    std::vector<Card> cards;
    std::size_t currentIndex;
public:
    StudySet(const std::string& name);


    void addCard(const Card& card);
    void shuffle();
    const Card& nextCard();


    bool hasMoreCards() const;
    std::size_t size() const;
    const std::string& getName() const;
    const std::vector<Card>& getCards() const;
    void setName(const std::string& name);
};

#endif //STUDYGAME_STUDYSET_H
