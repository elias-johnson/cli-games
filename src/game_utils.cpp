#include <iostream>
#include <string>

#include "game_utils.h"

std::string promptUser(const std::string& prompt) {
    std::string input;

    std::cout << prompt << ": ";
    std::getline(std::cin, input);

    return input;
}
