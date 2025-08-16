#include <iostream>

#include "Hangman.h"

int main() {
    Hangman hangmanGame;
    char guess;

    hangmanGame.displayWord();

    while (hangmanGame.isActive()) {
        std::cout << "Guess a letter: "; // maybe have a general utils class...one that takes user input with a prompt
        std::cin >> guess;
        
        hangmanGame.guess(guess);

        hangmanGame.displayWord();
    }

    hangmanGame.gameOver();

    return 0;
}
