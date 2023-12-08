#include "sodoku.h"
#include "rang.hpp"
#include <iostream>

void printV(Arr2d v) {
    for(const auto& i : v) {
        for(const auto& j : i) {
            if(j < 0) {
                std::cout << rang::fg::red << -j << rang::fg::reset << " ";
            } else {
                std::cout << j << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
Arr2d board1 = {{
    {0, 4, 0, 0, 1, 9, 8, 0, 6},
    {3, 0, 0, 0, 0, 0, 7, 0, 0},
    {0, 0, 0, 8, 0, 0, 0, 0, 0},
    {0, 0, 4, 0, 0, 8, 0, 9, 0},
    {0, 0, 0, 0, 0, 2, 0, 0, 0},
    {0, 9, 0, 0, 5, 6, 0, 0, 1},
    {0, 5, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 4, 0, 0, 0, 0, 8},
    {0, 0, 7, 0, 8, 5, 6, 0, 0}
    }};
    Sodoku game1{board1};
    if(game1.checkSolutionExists()) printV(game1.getAnswer());
    else std::cout << "can\'t solve.\n";
}