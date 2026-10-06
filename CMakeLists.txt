cmake_minimum_required(VERSION 4.3)
project(StudyGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(StudyGame main.cpp
        Card.h
        StudySet.h
        StudySet.cpp
        SetLoader.h
        SetLoader.cpp
        Question.h
        QuestionMaker.h
        QuestionMaker.cpp
        AnswerResult.h
        Game.h
        BattleGame.h
        BattleGame.cpp
        ConsoleUI.h
        ConsoleUI.cpp
        Attempt.h
        Session.h
        Session.cpp)
