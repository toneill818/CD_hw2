//
// Created by Thomas O'Neill on 10/6/15.
//

#ifndef CALC_TOKEN_H
#define CALC_TOKEN_H

#include "symbol.h"
#include <vector>
#include <list>

enum Token_Kind{
    error_token = -1,
    int_token, // 0
    bool_token, // 1
    lparen_token, // 2
    rparen_token, // 3
    multiply_token, // 4
    divide_token, // 5
    mod_token, // 6
    add_token, // 7
    subtract_token,
    equality_token,
    notEqual_token,
    lessThan_token,
    greaterThan_token,
    lessThanEqual_token,
    greaterThanEqual_token,
    and_token,
    or_token,
    not_token,
};

class Token  {
public:
    Token();
    Token(int);
    Token(int, Symbol const*);

    int getKind() const;
    Symbol const* getSymbol();
    string const& getSpelling() const;
private:
    int kind; // Hold the kind (Should be in the enum Token_Kind)
    Symbol const* sym; // Pointer to a Symbol in the symbol table?
};

class Token_Stream{
public:
    Token_Stream():ts(), iter(ts.begin()){}
    void put(Token);
    Token peek();
    Token get();
private:
    //std::vector<Token> ts;
    //std::vector<Token>::iterator iter;
    std::list<Token> ts;
    std::list<Token>::iterator iter;
};
#endif //CALC_TOKEN_H
