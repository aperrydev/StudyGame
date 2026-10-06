#include "StudySet.h"
#include <algorithm>
#include <random>

StudySet::StudySet(const std::string& name) : name(name), currentIndex(0){}

void StudySet::addCard(const Card& card) {
    cards.push_back(card);
}

void StudySet::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards.begin(), cards.end(), gen);
    currentIndex = 0;
}

const Card& StudySet::nextCard() {
    return cards[currentIndex++];
}

bool StudySet::hasMoreCards() const {
    return currentIndex < cards.size();
}

std::size_t StudySet::size() const {
    return cards.size();
}

const std::string& StudySet::getName() const {
    return name;
}

const std::vector<Card>& StudySet::getCards() const {
    return cards;
}

void StudySet::setName(const std::string& name) {
    this->name = name;
}


