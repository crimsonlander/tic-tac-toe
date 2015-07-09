#include "game.h"
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <iomanip>

using namespace std;

pos get_move() {
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        throw runtime_error("Incorrect format!");
    }
    return pos(x,y);
}

int main() {

    game g;
    int w;

    while (!(w = g.ended())) {
        try {
            std::cout << g << flush;
            g.make_turn(get_move());
        }
        catch (runtime_error e) {
            cout << e.what() << endl;
        }
    }

    std::cout << g << "Winner: " << w << std::endl;

    return 0;
}
