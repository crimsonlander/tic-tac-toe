#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <array>
#include <utility>
#include <vector>

template <class val, size_t m, size_t n>
using matrix = std::array< std::array<val, n>, m >;

typedef std::pair<int, int> pos;

class board : public matrix <char, 3, 3> {
public:
    board() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                (*this)[i][j] = ' ';
    }
};

class game
{
    int _current_player;
    board _a;
    std::vector<pos> _turns;
    
public:
    game() : _current_player(1), _a(), _turns() {}
    void make_turn(pos p);
    int ended();

    int current_player() const { return _current_player; }
    const board &a() const { return _a; }
    std::vector<pos>::const_iterator first_turn() const { return _turns.begin(); }
    std::vector<pos>::const_iterator last_turn() const { return _turns.end(); }


    friend std::ostream& operator<<(std::ostream& os, const game &g);
};

#endif // GAME_H
