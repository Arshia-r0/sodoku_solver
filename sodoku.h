#pragma once
#include <bitset>
#include <array>

using Arr2d = std::array<std::array<int, 9>, 9>;
using Bitset2d = std::array<std::bitset<9>, 9>;

class Sodoku {

private:
    Arr2d board;
    Arr2d Answer;
    Bitset2d rowSet{};
    Bitset2d colSet{};
    Bitset2d cellSet{};
    bool tried = false;
    bool solvable;

    void setInitialFlags();
    bool solve(std::size_t r = 0, std::size_t c = 0);
    int cellNum(const std::size_t& i, const std::size_t& j) const;

public:

    Sodoku(Arr2d& v) :
    board{v},
    Answer{v} {}

    bool checkSolutionExists();
    Arr2d getAnswer() const;
};