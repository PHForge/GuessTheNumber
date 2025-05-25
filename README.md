
# Guess The Number

A retro-style console-based game written in C, where players guess a randomly generated number with hints. The code show robust input handling, bilingual support with UTF-8 encoding, and persistent score tracking. Designed with modularity and cross-platform compatibility in mind, this project demonstrates clean C programming practices and attention to user experience.

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C-green.svg)

## Features 📋

- **Bilingual Support**: Fully localized in English and French, with UTF-8 encoding for proper handling of accented characters (e.g., é, è) across platforms.
- **Interactive Menu**: Modular menu system with options to play, view best scores, configure settings, view credits, or quit, ensuring a smooth user experience.
- **Customizable Settings**:
  - Language selection (English/French) with persistent storage.
  - Configurable number range (-1000 to 1000, default: 1-100) for flexible gameplay.
- **Score Tracking**: Persists best scores to a file using robust file I/O, with feedback for new or matching high scores.
- **Replay Option**: Seamless replay functionality to encourage repeated play and improve user engagement.
- **Robust Input Handling**: Comprehensive input validation to prevent crashes and handle edge cases gracefully.
- **Retro Aesthetic**: ASCII art banner for a nostalgic console experience, optimized for terminal display.

## System Requirements ⚙️

The following components are required to build, run, or contribute to this project:

| Component          | Requirement                              | Notes                                      |
|--------------------|------------------------------------------|--------------------------------------------|
| Language | C                                      | Core language used for the project         |
| Compiler       | GCC                                      | Ensure GCC is installed (e.g., MinGW for Windows) |
| Libraries      | Standard C Libraries (stdio.h, stdlib.h, time.h, ctype.h, locale.h, windows.h) | Included with standard C installations      |
| IDE/Editor     | Code::Blocks or any C-compatible IDE/terminal | Other IDEs like VS Code or CLion can be used |
| Version Control | Git                                     | Required to clone the repository           |

> [!TIP]
> For optimal setup, install GCC via [MinGW](https://www.mingw-w64.org/) on Windows or use a package manager like `apt` or `brew` on Linux/macOS to install Git and GCC.


## Installation </>

1. Clone the repository:
	```bash
	git clone https://github.com/ton-username/GuessTheNumber.git
	cd GuessTheNumber
	```
2. Compile the game:
	- Windows: Use MinGW and run:
		```bash
		gcc -o guess main.c
		```
	- Linux/macOS: Ensure GCC is installed (`sudo apt install gcc` or `brew install gcc`) and run:
		```bash
		gcc -o guess main.c
		```
3. Run the game:
	```bash
	./guess
	```
	
## License 🧾

This project is licensed under the MIT License - see the LICENSE file for details.

## Crédits ☕

> Developed by PHForge. 
> Feel free to reach out via [GitHub](https://github.com/PHForge) for feedback or collaboration ideas!

> Special thanks ❤️ to my wife and son for their patience and love.

## Example Output 💻

```c
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

Guess the *number* (1-100)
Enter your guess: 50
Too high!
Enter your guess:
```