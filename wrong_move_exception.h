#ifndef WRONG_MOVE_EXCEPTION_H
#define WRONG_MOVE_EXCEPTION_H
#include <string>

class wrong_move_exception : public std::exception
{
    string _message;
public:
    wrong_move_exception();
    wrong_move_exception(string &msg);
    string &message();
};

#endif // WRONG_MOVE_EXCEPTION_H
