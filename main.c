/*
 * GuessTheNumber - A retro-style Guess The Number program
 * Copyright (c) 2025 PHForge
 *
 * Guess the Number is a simple console game where players try to guess a randomly chosen
 * number, receiving hints like 'Too high' or 'Too low' with each attempt,
 * while the game tracks their tries and saves the best score.
 *
 * Licensed under the MIT License. See the LICENSE file in the repository for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // used for srand and seed the random number generator
#include <ctype.h> // For tolower and be sure that 'Y', 'y', 'O', ou 'o' will be accepted as correct answer
#include <locale.h> // For setlocale to handle accented characters
#ifdef _WIN32
#include <windows.h> // Pour SetConsoleOutputCP to configure Windows console encoding
#endif

// Game settings: language and number range
struct GameSettings {
    int is_english; // 1 for English, 0 for French
    int min_range;  // Minimum number
    int max_range;  // Maximum number
};

// Displays the retro ASCII banner
void display_banner(void) {
    printf("  _____                  _______ _          _   _                 _               \n");
    printf(" / ____|                |__   __| |        | \\ | |               | |              \n");
    printf("| |  __ _   _  ___  ___ ___| |  | |__   ___|  \\| |_   _ _ __ ___ | |__   ___ _ __ \n");
    printf("| | |_ | | | |/ _ \\/ __/ __| |  | '_ \\ / _ \\ . ` | | | | '_ ` _ \\| '_ \\ / _ \\ '__|\n");
    printf("| |__| | |_| |  __/\\__ \\__ \\ |  | | | |  __/ |\\  | |_| | | | | | | |_) |  __/ |   \n");
    printf(" \\_____|\\__,_|\\___||___/___/_|  |_| |_|\\___|_| \\_|\\__,_|_| |_| |_|_.__/ \\___|_|   \n");
    printf("\n");
    printf("            by PHForge\n");
    printf("\n");
}

// Generates a random number within the specified range
int generate_number(struct GameSettings *settings){
    return (rand() % (settings->max_range - settings->min_range + 1)) + settings->min_range;
}

// Plays one game, returns number of attempts
int play_game(struct GameSettings *settings) {
    int secret = generate_number(settings);
    int guess;
    int attempts = 0;

    printf(settings->is_english ? "\nLet's go! Beat the best score!\n" : "C'est parti ! Bats le meilleur score !\n");
    printf(settings->is_english ? "\nGuess the number (%d-%d)\n" : "Devinez le nombre (%d-%d)\n", settings->min_range, settings->max_range);
    while (1) {
        printf(settings->is_english ? "Enter your guess: " : "Entrez votre supposition : ");
        if (scanf("%d", &guess) != 1) {
            while (getchar() != '\n');
            printf(settings->is_english ? "\nInvalid input. Please enter a number.\n" : "Entrée invalide. Entrez un nombre.\n");
            continue;
        }
        while (getchar() != '\n');

        if (guess < settings->min_range || guess > settings->max_range) {
            printf(settings->is_english ? "\nNumber must be between %d and %d.\n" : "Le nombre doit être entre %d et %d.\n", settings->min_range, settings->max_range);
            continue;
        }

        attempts++;
        if (guess == secret) {
            printf(settings->is_english ? "\nCorrect! You won in %d attempts!\n" : "Correct ! Vous avez gagné en %d essais !\n", attempts);
            return attempts;
        } else if (guess < secret) {
            printf(settings->is_english ? "Too low!\n" : "Trop bas !\n");
        } else {
            printf(settings->is_english ? "Too high!\n" : "Trop haut !\n");
        }
    }
}

// Saves the best score to a file
void save_best_score(int best_score){
    FILE *file = fopen("best_score.txt", "w");
    if (file == NULL) {
        printf("Error: Could not save score.\n");
        return;
    }
    fprintf(file, "%d", best_score);
    fclose(file);
}

// Loads the best score from a file, returns -1 if not found
int load_best_score(void){
    FILE *file = fopen("best_score.txt", "r");
    if(file == NULL){
        return -1; //means no score yet
    }
    int best_score;
    if (fscanf(file, "%d", &best_score) != 1 || best_score < 1){
        best_score = -1; // Invalid or negative score
    }
    fclose(file);
    return best_score;
}

// Configures game settings (language and range)
void configure_settings(struct GameSettings *settings) {
    int choice;
    printf(settings->is_english ? "\n=== Settings ===\n" : "\n=== Paramètres ===\n");
    printf(settings->is_english ? "1. Language (Current: %s)\n" : "1. Langue (Actuelle : %s)\n", settings->is_english ? "English" : "Français");
    printf(settings->is_english ? "2. Number range (Current: %d-%d)\n" : "2. Plage de nombres (Actuelle : %d-%d)\n", settings->min_range, settings->max_range);
    printf(settings->is_english ? "3. Back\n" : "3. Retour\n");
    printf(settings->is_english ? "\nEnter choice: " : "\nEntrez votre choix : ");

    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf(settings->is_english ? "\nInvalid choice.\n" : "\nChoix invalide.\n");
        return;
    }
    while (getchar() != '\n');

    switch (choice) {
        // Change the current game language
        case 1:
            settings->is_english = !settings->is_english;
            printf(settings->is_english ? "\nLanguage set to English.\n" : "\nLangue définie sur Français.\n");
            printf(settings->is_english ? "Choice validated and recorded.\n" : "Choix validé et enregistré.\n");
            printf(settings->is_english ? "Back to main menu.\n" : "Retour au menu principal.\n");
            break;
        // Change the game range with a max of 1000
        case 2: {
            int min, max;
            printf(settings->is_english ? "Enter minimum number: " : "Entrez le nombre minimum : ");
            if (scanf("%d", &min) != 1) {
                while (getchar() != '\n');
                printf(settings->is_english ? "Invalid input.\n" : "Entrée invalide.\n");
                break;
            }
            printf(settings->is_english ? "Enter maximum number (max 1000): " : "Entrez le nombre maximum (max 1000) : ");
            if (scanf("%d", &max) != 1) {
                while (getchar() != '\n');
                printf(settings->is_english ? "Invalid input.\n" : "Entrée invalide.\n");
                break;
            }
            while (getchar() != '\n');
            if (min >= max || min < -1000 || max > 1000) {
                settings->min_range = 1;
                settings->max_range = 100;
                printf(settings->is_english ? "Invalid range. Reset to 1-100.\n" : "Plage invalide. Réinitialisée à 1-100.\n");
            } else {
                settings->min_range = min;
                settings->max_range = max;
            }
            break;
        }
        case 3:
            break;
        default:
            printf(settings->is_english ? "Invalid choice.\n" : "Choix invalide.\n");
    }
}

// Displays game credits
void display_credits(struct GameSettings *settings) {
    printf(settings->is_english ? "\n=== Credits ===\n" : "\n=== Crédits ===\n");
    printf(settings->is_english ? "\nThis game is dedicated to my beloved wife and son, whose patience and love inspire me every day.\n" : "\nCe jeu est dédié à ma femme et mon fils adorés, dont la patience et l’amour m’inspirent chaque jour.\n");
    printf(settings->is_english ? "\nPress Enter to continue...\n" : "\nAppuyez sur Entrée pour continuer...\n");
    while (getchar() != '\n');
}

int main() {
    // Configure character encoding to support accented characters (e.g., French é, è)
    setlocale(LC_ALL, ""); // Set program locale to system default
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); // Set Windows console to UTF-8 for proper accent display
    #endif
    srand(time(NULL)); // Seed the random number generator to avoid the same first secret number
    struct GameSettings settings = {1, 1, 100}; // Default: English, range 1-100
    int best_score = load_best_score();
    int choice;

    display_banner();
    do {
        // Main game menu
        printf(settings.is_english ? "\n=== Guess the Number ===\n" : "\n=== Devinez le Nombre ===\n");
        printf(settings.is_english ? "1. Play\n" : "1. Jouer\n");
        printf(settings.is_english ? "2. Show best score\n" : "2. Voir le meilleur score\n");
        printf(settings.is_english ? "3. Settings\n" : "3. Paramètres\n");
        printf(settings.is_english ? "4. Credits\n" : "4. Crédits\n");
        printf(settings.is_english ? "5. Quit\n" : "5. Quitter\n");
        printf(settings.is_english ? "\nEnter choice: " : "\nEntrez votre choix : ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf(settings.is_english ? "Invalid choice.\n" : "Choix invalide.\n");
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                // Launches the game and offers to play again at the end. Compares the current score to see if it should be saved as the new high score.
                char replay;
                do {
                    int attempts = play_game(&settings);
                    // Compare current score with best score
                    if (best_score == -1 || attempts < best_score) {
                        best_score = attempts;
                        save_best_score(best_score);
                        printf(settings.is_english ? "\nNew best score: %d attempts!\n" : "\nNouveau meilleur score : %d essais !\n", best_score);
                    } else if (attempts == best_score && best_score != -1) {
                        printf(settings.is_english ? "\nGreat job! You matched the best score of %d attempts! Try again to beat it!\n" : "\nBravo ! Vous avez égalisé le meilleur score de %d essais ! Réessayez pour le battre !\n", best_score);
                    } else {
                        printf(settings.is_english ? "\nBest score remains: %d attempts\n" : "\nMeilleur score inchangé : %d essais\n", best_score);
                    }

                    // Ask to replay
                    printf(settings.is_english ? "\nPlay again? (y/n): " : "\nRejouer ? (o/n) : ");
                    if (scanf(" %c", &replay) != 1) {
                        while (getchar() != '\n');
                        replay = 'n'; // Default to no if input is invalid
                    }
                    while (getchar() != '\n'); // Clear input buffer
                    replay = tolower(replay); // Convert to lowercase for consistency
                } while ((settings.is_english && replay == 'y') || (!settings.is_english && replay == 'o'));
                break;
            }
            case 2:
                if (best_score == -1) {
                    printf(settings.is_english ? "\nCurrently no best score recorded.\n" : "\nActuellement aucun meilleur score enregistré.\n");
                } else {
                    printf(settings.is_english ? "\nCurrent best score is : %d attempts\n" : "\nLe Meilleur score actuelle est de : %d essais\n", best_score);
                }
                break;
            case 3:
                configure_settings(&settings);
                break;
            case 4:
                display_credits(&settings);
                break;
            case 5:
                printf(settings.is_english ? "\nThank you for playing!\n" : "\nMerci d’avoir joué !\n");
                break;
            default:
                printf(settings.is_english ? "\nInvalid choice.\n" : "\nChoix invalide.\n");
        }
    } while (choice != 5);
    return 0;
}
