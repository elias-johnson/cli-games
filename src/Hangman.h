// Hangman.h
#pragma once

#include <string>
#include <vector>

/* Maximum errors a player can make before the game is over */
const int MAX_ERRORS = 6;

class Hangman {
private:
    int guesses;
    int maxGuesses;
    std::string secretWord;
    std::vector<char> guessedChars;
    std::vector<char> correctlyGuessedChars;
    void generateSecretWord();
    bool charHasBeenGuessed(const char& character);

public:
    Hangman();
    void guess(const char& guess);
    void displayWord();
    bool isActive();
    void gameOver();
};
