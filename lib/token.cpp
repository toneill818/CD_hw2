//
// Created by Thomas O'Neill on 10/6/15.
//

#include "token.h"

Token::Token():Token(error_token){}

Token::Token(int t):Token(t,nullptr){}

Token::Token(int t, Symbol const *s):kind(t), sym(s) { }

int Token::getKind() const { return kind; }

string const& Token::getSpelling() const { return sym->getSpelling(); }

Symbol const * Token::getSymbol() { return sym; }


// Returns the current token and sets iter to the next value.
Token Token_Stream::get() {
    if(iter == ts.end()){
        return Token(); // Return a token with the error token set
    }
    return *iter++; // Increment iter to the next token.
}

// Returns current token and keeps the iterator at the same position.
Token Token_Stream::peek() {
    if(iter == ts.end()){
        return Token(); // Return a token with the error token set
    }
    return *iter;
}

// Insert a token to the end of the token stream
void Token_Stream::put(Token t) {
    ts.push_back(t);

    // If the token stream was empty set our iterator to the beginning.
    if(iter == ts.end()){
        iter = ts.begin();
    }
}