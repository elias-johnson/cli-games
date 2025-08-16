#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Hangman.h"

Hangman::Hangman() {
    generateSecretWord();
    guesses = 0;
    mistakes = 0;
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
        bool madeMistake = true;

        for (char character : secretWord) {
            if (character == guess) {
                correctlyGuessedChars.push_back(character);
                madeMistake = false;
            }
        }
        
        if (madeMistake) {
            mistakes++;
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
        mistakes > MAX_MISTAKES) {
        return false;
    }

    return true;
}

void Hangman::gameOver() {
    if (correctlyGuessedChars.size() == secretWord.size()) {
        std::cout << "You guessed it! It took you " << guesses << " guesses." << std::endl;
    } else {
        std::cout << "Game over. The secret word was " << secretWord << "." << std::endl;
    }
}
