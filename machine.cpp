#include "machine.h"
#include <stdexcept>

double machine::evaluate() {
    calc_f();

    double s = 0;
    for (int i = 0; i < m; ++i)
        s += _f[i] * _w[i];

    return s;
}

double machine::evaluate(pos p) {
    if (_b[p.first][p.second]  != ' ')
        throw std::runtime_error("Evaluating incorrect move!");

    _b[p.first][p.second] = _my_char;
    double value = evaluate();
    _b[p.first][p.second] = ' ';
    return value;
}

void machine::calc_f() {
    for (auto &v : _f)
        v = 0;

    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (int i = 0; i < 3; ++i) {
        s3 += _b[i][i] == 'X'? 1 : _b[i][i] == 'O'? -1 : 0;
        s4 += _b[i][2-i] == 'X'? 1 : _b[i][2-i] == 'O'? -1 : 0;

        s1 = 0, s2 = 0;
        for (int j = 0; j < 3; ++j) {
            s1 += _b[i][j] == 'X'? 1 : _b[i][j] == 'O'? -1 : 0;
            s2 += _b[j][i] == 'X'? 1 : _b[j][i] == 'O'? -1 : 0;

        }
        _f[3 + s1] += 1;
        _f[3 + s2] += 1;
    }
    _f[3 + s3] += 1;
    _f[3 + s4] += 1;
}

pos machine::get_move() {
    update_b();
    double max = -200;
    pos max_p = pos(0, 0);

    for (int i; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            if (_b[i][j] == ' ') {
                double value = evaluate(pos(i, j));
                if (value > max) {
                    max = value;
                    max_p = pos(i, j);
                }
            }
        }

    return max_p;
}

void machine::update_b() {
    for (int i; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _b[i][j] = _g.a()[i][j];
}
