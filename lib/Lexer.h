//
// Created by Thomas O'Neill on 10/15/15.
//

#ifndef CALC_LEXER_H
#define CALC_LEXER_H


#include <sstream>
#include <unordered_map>
#include "symbol.h"
#include "token.h"

class Lexer {
public:
    Lexer(SymbolTable & s, string str):ss(str), st(s), fail(false) {}
    bool done(){return ss.eof() || ss.peek() == '\xff';}
    bool failed() {return fail;}

    bool lex(Token_Stream&);
    bool scan(Token_Stream&);

private:
    Token scan();
    Token lparen();
    Token rparen();
    Token multiply();
    Token divide();
    Token mod();
    Token add();
    Token subtract();
    Token equality();
    Token notEqual();
    Token lessThan();
    Token greaterThan();
    Token lessThanEqual();
    Token greaterThanEqual();
    Token not_t();
    Token and_t();
    Token or_t();
    Token digit();
    Token letter();
    Token onInteger();
    Token onBoolean();
    Token onToken();

    void consumeWhiteSpace();
    char get();

    string getCurrent();
    void addChar();

    string current;

    std::stringstream ss;
    SymbolTable &st; // Symbol Table
    bool fail;

};


#endif //CALC_LEXER_H
