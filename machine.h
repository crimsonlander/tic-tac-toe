#ifndef MACHINE_H
#define MACHINE_H

#include "game.h"
#include <vector>
#include <tuple>
#include <string>

typedef std::vector< std::tuple<pos, double> > experience;

class machine {

    const game &_g;
    board _b;
    char _my_char, _opposite_char;
    std::vector<double> _w;
    std::vector<double> _f;
    const int m = 7;

    void update_b();
    void calc_f();
    double evaluate(pos p);
    double evaluate();
    
public:

    static experience extract_exp(const game &g); // todo
    static experience read_exp(const std::string &file_name); // todo
    void learn(const experience &exp); // todo

    machine(const game &g, int player) :
        _g(g),
        _b(),
        _my_char(player == 1? 'X' : 'O'),
        _opposite_char(player == 2? 'X' : 'O'),
        _w(m),
        _f(m){}
    pos get_move();
};

#endif // MACHINE_H
