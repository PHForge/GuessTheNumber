# Guess The Number

A retro-style console-based game written in C, where players guess a randomly generated number with hints like "Too high" or "Too low." The game tracks attempts, saves the best score, and offers a bilingual interface in English and French.

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C-green.svg)

# Features

- **Bilingual Support**: Fully localized in English and French, with proper handling of accented characters (e.g., é, è) using UTF-8 encoding.
- **Interactive Menu**: Options to play, view the best score, configure settings, view credits, or quit.
- **Customizable Settings**:
  - Choose the language (English or French).
  - Set a custom number range (default: 1-100, supports -1000 to 1000).
- **Score Tracking**: Saves and loads the best score to/from a file, with feedback for new best scores or matching the current best.
- **Replay Option**: Allows immediate replay after a game, encouraging players to beat their best score.
- **Robust Input Handling**: Validates all user inputs to prevent crashes or unexpected behavior.
- **Retro Aesthetic**: Features an ASCII art banner for a nostalgic feel.

### Prerequisites
- A C compiler (e.g., GCC).
- Code::Blocks or any IDE/terminal that supports C compilation.
- Git (to clone the repository).

# Installation
1. Clone the repository:
git clone https://github.com/ton-username/GuessTheNumber.git

2. Compile the game:
gcc -o guess main.c

3. Run the game:
./guess

# Technologies
- Language: C
- Libraries: Standard C libraries (stdio.h, stdlib.h, time.h, ctype.h, locale.h, windows.h)
- Tools: Code::Blocks, GCC

# License
This project is licensed under the MIT License - see the LICENSE file for details.

# Crédits
Developed by PHForge. Special thanks to my wife and son for their patience and love.

# Example Output
```bash

  _____                  _______ _          _   _                 _
 / ____|                |__   __| |        | \ | |               | |
| |  __ _   _  ___  ___ ___| |  | |__   ___|  \| |_   _ _ __ ___ | |__   ___ _ __
| | |_ | | | |/ _ \/ __/ __| |  | '_ \ / _ \ . ` | | | | '_ ` _ \| '_ \ / _ \ '__|
| |__| | |_| |  __/\__ \__ \ |  | | | |  __/ |\  | |_| | | | | | | |_) |  __/ |
 \_____|\__,_|\___||___/___/_|  |_| |_|\___|_| \_|\__,_|_| |_| |_|_.__/ \___|_|

            by PHForge


=== Guess the Number ===
1. Play
2. Show best score
3. Settings
4. Credits
5. Quit

Enter choice: 1

Let's go! Beat the best score!

Guess the number (1-100)
Enter your guess: 50
Too high!
Enter your guess: