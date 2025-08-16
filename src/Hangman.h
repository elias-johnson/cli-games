// Hangman.h
#pragma once

#include <string>
#include <vector>

/* Maximum mistakes a player can make before the game is over */
const int MAX_MISTAKES = 6;

class Hangman {
private:
    int guesses;
    int mistakes;
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
