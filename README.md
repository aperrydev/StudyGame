# StudyGame

A C++ study tool that turns any set of flashcards into a playable game. Load a study set from a plain text file, then answer multiple-choice questions in a turn-based battle: correct answers damage the enemy, wrong answers damage you. A review at the end lists every question, what you answered, and the correct answer.

The goal is a study tool built for college-age learners that makes review feel like a game rather than a stack of flashcards.

## Features

- **Custom study sets** loaded from a simple text format, with no code changes required
- **Automatic multiple-choice generation**: wrong answers are drawn from other cards in the set
- **Category-aware answer choices**: wrong answers come from the same category first, so questions cannot be solved by elimination
- **Battle game mode** with HP, damage, and win/lose conditions
- **End-of-game review** with score, percentage, and a per-question breakdown
- **Input validation** so invalid entries never count as an answer

## Sample

```
You: 90HP  Enemy: 40HP
Csc45° = ?
1. 1/2
2. 2
3. √3/3
4. √2
Your answer choice: 1
Wrong. The answer was √2. You take 10 damage.

-----Review-----
Score: 83%

1. Sec30° = ?
You answered: √3/3
Correct answer: 2√3/3
2. Cot = ?
Correct: x/y
```

## Study set format

The first line is the set name. Each following line is one card: `term|definition`, with an optional third field for an explanation. Lines beginning with `#` start a category.

```
Trigonometry
# Radians
Radian form of 30°|π/6
Radian form of 60°|π/3|60° is a third of 180°, so it's π/3
# Exact values
Sin45° = ?|√2/2
Tan60° = ?|√3
```

## Build and run

Requires CMake and a C++17 compiler.

```
cmake -S . -B build
cmake --build build
./build/StudyGame
```

Run the program from the project root so it can find `sets/sample.txt`.

## Design

The project is split into three layers so that study sets, game rules, and the interface stay independent of one another.

```
Study set (data)  →  Game (rules)  →  UI (console)
```

| Component | Responsibility |
|---|---|
| `Card`, `StudySet` | Card data, shuffling, and iteration |
| `SetLoader` | Parses a study set file into a `StudySet` |
| `QuestionMaker` | Builds a multiple-choice `Question` from a card |
| `Game` | Abstract interface that every game mode implements |
| `BattleGame` | Battle rules: HP, damage, win and lose conditions |
| `Session` | Records each attempt for the end-of-game review |
| `ConsoleUI` | All input and output; drives any `Game` |

Only `ConsoleUI` performs input and output. Game modes return data and never print, so a new game mode or a different interface can be added without changing the rest of the code.

## Roadmap

- Smarter wrong-answer selection based on answer similarity
- Additional game modes
- Typed-answer and true/false question types
- Web interface

---

© 2026 Anthony Perry. All rights reserved.