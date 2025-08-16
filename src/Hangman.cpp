#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Hangman.h"

Hangman::Hangman() {
    guesses = 0;
    errors = 0;
    generateSecretWord();
}

void Hangman::generateSecretWord() {
    std::string generatedWord = "buffalo";
    secretWord = generatedWord;
}

bool Hangman::charHasBeenGuessed(const char& guess) {
    return std::find(guessedChars.begin(), guessedChars.end(), guess) != guessedChars.end();
}

void Hangman::guess(const char& guess) {
    if (charHasBeenGuessed(guess)) {
        std::cout << "You already guessed '" << guess << "'." << std::endl;
    } else {
        guesses++;
        guessedChars.push_back(guess);
        bool correct = false;

        for (char character : secretWord) {
            if (character == guess) {
                correct = true;
                correctlyGuessedChars.push_back(character);
            }
        }

        if (!correct) {
            errors++;
        }
    }
}

void Hangman::displayWord() {
    for (char character : secretWord) {
        char charToPrint = '_';

        if (charHasBeenGuessed(character)) {
            charToPrint = character;
        }

        std::cout << charToPrint << " ";
    }
    std::cout << std::endl;
}

bool Hangman::isActive() {
    if (correctlyGuessedChars.size() == secretWord.size() ||
        errors > MAX_ERRORS) {
        return false;
    }

    return true;
}

void Hangman::gameOver() {
    if (errors > MAX_ERRORS) {
        std::cout << "Game over. The secret word was " << secretWord << "." << std::endl;
    } else {
        std::cout << "You guessed it! It took you " << guesses << " guesses." << std::endl;
    }
}
