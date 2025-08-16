#include <iostream>
#include <string>

#include "Hangman.h"
#include "game_utils.h"

int main() {
    Hangman hangmanGame;
    hangmanGame.displayWord();

    while (hangmanGame.isActive()) {
        std::string guess = promptUser("Guess a letter");

        if (guess.size() != 1) {
            std::cout << "Input must be 1 character." << std::endl;
        } else {
            hangmanGame.guess(guess[0]);
        }

        hangmanGame.displayWord();
    }

    hangmanGame.gameOver();

    return 0;
}
