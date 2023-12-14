#include "sodoku.h"
#include <vector>
#include <array>
#include <bitset>

bool Sodoku::checkSolutionExists() {
    if(!tried) {
        setInitialFlags();
        solvable = solve();
        tried = true;
    }
    return solvable;
}

std::size_t Sodoku::cellNum(const std::size_t& i, const std::size_t& j) const { return (i/3)*3 + (j/3); }

Arr2d Sodoku::getAnswer() const { return Answer; }

void Sodoku::setInitialFlags() {
    for(std::size_t r = 0; r < 9; r++) {
        for(std::size_t c = 0; c < 9; c++) {
            int e = board[r][c]-1;
            if(e != -1) {
                rowSet[r].set(e);
                colSet[c].set(e);
                cellSet[cellNum(r, c)].set(e);
            }
        }
    }
}

bool Sodoku::solve(std::size_t r, std::size_t c) {
    if(r == 8 && c == 9) return true;
    if(c == 9) c = 0, r++;
    if(Answer[r][c] != 0) return solve(r, c+1);
    auto flag = rowSet[r] | colSet[c] | cellSet[cellNum(r, c)];
    for(std::size_t h = 0; h < 9; h++) {
        if(!flag[h]) {
            Answer[r][c] = -static_cast<int>(h+1);
            rowSet[r].set(h);
            colSet[c].set(h);
            cellSet[cellNum(r, c)].set(h);
            if(solve(r, c+1)) return true;
            Answer[r][c] = 0;
            rowSet[r].reset(h);
            colSet[c].reset(h);
            cellSet[cellNum(r, c)].reset(h);
        }
    }
    return false;
}