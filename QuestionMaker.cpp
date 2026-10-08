#include "QuestionMaker.h"
#include <algorithm>
#include <random>
#include <cctype>
#include <sstream>
using namespace std;

vector<string> splitWords(const string& text) {
    vector<string> words;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

int wordingScore(const string& correctTerm, const string& candidateTerm) {
    vector<string> correctWords = splitWords(correctTerm);
    vector<string> candidateWords = splitWords(candidateTerm);
    int score = 0;

    for (const string& word : correctWords) {
        if (find(candidateWords.begin(), candidateWords.end(), word) != candidateWords.end()) {
            score++;
        }
    }
    return score;
}

bool contains(const string& text, const string& piece) {
    return text.find(piece) != string::npos;
}

bool hasDigit(const string& text) {
    for (char c : text) {
        if (isdigit(static_cast<unsigned char>(c))) {
            return true;
        }
    }
    return false;
}

bool hasLetter(const string& text) {
    for (char c : text) {
        if (isalpha(static_cast<unsigned char>(c))) {
            return true;
        }
    }
    return false;
}

int shapeScore(const string& correctAnswer, const string& candidateAnswer) {
    int score = 0;

    if (hasDigit(correctAnswer) == hasDigit(candidateAnswer)) {
        score++;
    }
    if (hasLetter(correctAnswer) == hasLetter(candidateAnswer)) {
        score++;
    }
    if (contains(correctAnswer, " ") == contains(candidateAnswer, " ")) {
        score++;
    }
    if (contains(correctAnswer, "π") == contains(candidateAnswer, "π")) {
        score++;
    }
    if (contains(correctAnswer, "√") == contains(candidateAnswer, "√")) {
        score++;
    }
    if (contains(correctAnswer, "/") == contains(candidateAnswer, "/")) {
        score++;
    }
    if (contains(correctAnswer, "=") == contains(candidateAnswer, "=")) {
        score++;
    }
    if (contains(correctAnswer, "(") == contains(candidateAnswer, "(")) {
        score++;
    }
    if (contains(correctAnswer, "º") == contains(candidateAnswer, "º")) {
        score++;
    }
    return score;
}

int totalScore(const Card& correctCard, const Card& candidateCard) {
    const int SAME_CATEGORY_POINTS = 100;
    const int SAME_WORD_POINTS = 5;
    int score = 0;

    if (correctCard.category == candidateCard.category) {
        score += SAME_CATEGORY_POINTS;
    }
    score += wordingScore(correctCard.term, candidateCard.term) * SAME_WORD_POINTS;
    score += shapeScore(correctCard.definition, candidateCard.definition);
    return score;
}

bool alreadyListed(const vector<Candidate>& candidates, const string& definition) {
    for (const Candidate& c : candidates) {
        if (c.definition == definition) {
            return true;
        }
    }
    return false;
}

Question makeQuestion(const Card& card, const vector<Card>& allCards) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> jitter(0, JITTER_MAX);
    vector<Candidate> candidates;
    for (const Card& c: allCards) {
        if (c.definition == card.definition) {
            continue;
        }
        if (alreadyListed(candidates, c.definition)) {
            continue;
        }
        Candidate candidate;
        candidate.definition = c.definition;
        candidate.score = totalScore(card, c) + jitter(gen);
        candidates.push_back(candidate);
    }
    sort(candidates.begin(), candidates.end(), []
        (const Candidate& x, const Candidate& y) {
        return x.score > y.score;
    });
    Question question;
    question.prompt = card.term;
    question.explanation = card.explanation;

    for (size_t i = 0; i < 3 && i < candidates.size(); i++) {
        question.choices.push_back(candidates[i].definition);
    }

    question.choices.push_back(card.definition);
    shuffle(question.choices.begin(), question.choices.end(), gen);
    for (size_t i = 0; i < question.choices.size(); i++) {
        if (question.choices[i] == card.definition) {
            question.correctIndex = i;
        }
    }
    return question;


}
