#include "game.h"
#include <string>
#include <stdexcept>
#include <cmath>

void game::make_turn(pos p) {
    if (_a[p.first][p.second] != ' ')
        throw std::runtime_error("Incorrect move!");
    else if (_current_player == 1) {
        _a[p.first][p.second] = 'X';
        _current_player = 2;
    }
    else {
        _a[p.first][p.second] = 'O';
        _current_player = 1;
    }
    _turns.push_back(p);
}

int game::ended() {
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (int i = 0; i < 3; ++i) {
        s3 += _a[i][i] == 'X'? 1 : _a[i][i] == 'O'? -1 : 0;
        s4 += _a[i][2-i] == 'X'? 1 : _a[i][2-i] == 'O'? -1 : 0;

        s1 = 0, s2 = 0;
        for (int j = 0; j < 3; ++j) {
            s1 += _a[i][j] == 'X'? 1 : _a[i][j] == 'O'? -1 : 0;
            s2 += _a[j][i] == 'X'? 1 : _a[j][i] == 'O'? -1 : 0;

        }
        if (std::abs(s1) == 3 || std::abs(s2) == 3)
            break;

    }
    if (s1 == 3 || s2 == 3 || s3 == 3 || s4 == 3)
        return 1;
    if (s1 == -3 || s2 == -3 || s3 == -3 || s4 == -3)
        return 2;
    return 0;

}

std::ostream& operator<<(std::ostream& os, const game &g) {
    os << "-------\n";
    for (int i = 0; i < 3; ++i) {
        os << '|' << g._a[i][0] << '|' << g._a[i][1] << '|' << g._a[i][2] << "|\n";
        os << "-------\n";
    }
    return os;
}
