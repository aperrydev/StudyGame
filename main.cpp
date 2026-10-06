#include <iostream>
#include "StudySet.h"
#include "SetLoader.h"
#include "QuestionMaker.h"
#include "BattleGame.h"
#include "ConsoleUI.h"
using namespace std;

int main() {

    StudySet mySet("Calculus");

    if (!loadSet("sets/sample.txt", mySet)) {
        cout << "Could not load set file." << endl;
        return 1;
    }
    BattleGame game(mySet);
    runGame(game);



    return 0;
}