#include "ConsoleUI.h"
#include "Session.h"
#include <iostream>
#include <limits>
using namespace std;

int readChoice(size_t numChoices) {

    while (true) {
        int choice = 0;
        cout << "Your answer choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number." << endl;
            continue;
        }
        if (choice < 1 || choice > numChoices) {
            cout << "Enter a number between 1 and " << numChoices << "." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return choice;
    }
}

void printReview(const Session& session) {
    cout << endl;
    cout << "-----Review-----" << endl;
    cout << "Score: " << session.correctCount() * 100 / session.total() << "%" << endl;
    cout << endl;

    const vector<Attempt>& attempts = session.readAttempts();
    for (size_t i = 0; i < attempts.size(); i++) {
        const Attempt& a = attempts[i];
        cout << i + 1 << ". " << a.prompt << endl;
        if (a.correct) {
            cout << "Correct: " << a.correctAnswer << endl;
        }
        else {
            cout << "You answered: " << a.chosenAnswer << endl;
            cout << "Correct answer: " << a.correctAnswer << endl;
        }
        if (!a.explanation.empty()) {
            cout << "Why: " << a.explanation << endl;
        }
    }


}

void runGame(Game& game) {
    Session session;
    while (!game.isOver()) {
        cout << game.statusLine() << endl;
        Question q = game.nextQuestion();
        cout << q.prompt << endl;
        for (size_t i = 0; i < q.choices.size(); i++) {
            cout << i + 1 << ". " << q.choices[i] << endl;
        }
        int playerChoice = readChoice(q.choices.size());
        size_t index = playerChoice - 1;
        AnswerResult result = game.submitAnswer(index);
        session.record(q, index, result.correct);
        cout << result.message << endl;
        cout << endl;
    }
    cout << game.statusLine() << endl;
    if (game.playerWon()) {
        cout << "You win!!" << endl;
    }
    else {
        cout << "You lose!!" << endl;
    }
    printReview(session);
}
