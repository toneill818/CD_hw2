//
// Created by Thomas O'Neill on 10/15/15.
//

#include <iostream>
#include "Lexer.h"

bool Lexer::lex(Token_Stream &ts) {
    while(!done()){
        scan(ts);
    }
    return !failed();
}

bool Lexer::scan(Token_Stream &ts) {
    Token t = scan();
    if(t.getKind() != error_token){
        ts.put(t);
        return true;
    }
    fail = true;
    return false;
}

Token Lexer::scan() {
    consumeWhiteSpace();
    switch(ss.peek()){
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            return digit();

        case '(':
            return lparen();
        case ')':
            return  rparen();
        case '*':
            return multiply();
        case '/':
            return divide();
        case '%':
            return mod();
        case '+':
            return  add();
        case '-':
            return subtract();

        case '<':
            return lessThan();
        case '>':
            return greaterThan();
        case '=':
            return equality();
        case '!':
            return not_t();

        case '&':
            return and_t();
        case '|':
            return or_t();

        case 'f':
        case 't':
            return letter();
    }
    addChar();
    getCurrent();
    return Token();

}

void Lexer::consumeWhiteSpace() {
    while(ss.peek() == ' ' || ss.peek() == '\n' || ss.peek() == '\r' || ss.peek() == '\t' ){
        ss.get();
    }
}

char Lexer::get() {
    return ss.get();
}

void Lexer::addChar() {
    current += (char)ss.get();
}

string Lexer::getCurrent() {
    string temp = current;
    current.clear();
    return temp;
}

Token Lexer::lparen() {
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::rparen() {
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::add() {
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::subtract(){
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::multiply(){
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::divide() {
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::mod(){
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::equality() {
    addChar();
    if(ss.peek() != '='){
        getCurrent(); // Flush current on error
        return Token();
    }
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::lessThan(){
    addChar();
    // Return a less than or equal
    if(ss.peek() == '='){
        return lessThanEqual();
    }

    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::lessThanEqual() {
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::greaterThan() {
    addChar();
    if(ss.peek() == '='){
        return greaterThanEqual();
    }
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::greaterThanEqual() {
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::not_t() {
    addChar();
    if(ss.peek() == '=') {
        return notEqual();
    }
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::notEqual() {
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::and_t() {
    addChar();
    if(ss.peek() == '&'){
        addChar();
        auto s = st.find(getCurrent());
        return Token(s->getToken(), s);
    }
    getCurrent(); // Flush current on error
    return error_token;
}

Token Lexer::or_t() {
    addChar();
    if(ss.peek() != '|'){
        getCurrent(); // Flush current on error
        return Token();
    }
    addChar();
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::digit() {
    addChar();
    while (isdigit(ss.peek()))
        addChar();
    return onInteger();
}

Token Lexer::onInteger() {
    int value = std::stoi(current);
    st.installIntSymbol(current,int_token,value);
    auto s = st.find(getCurrent());
    return Token(s->getToken(), s);
}

Token Lexer::letter() {
    addChar();
    while (isalpha(ss.peek()))
        addChar();
    return onBoolean();
}

Token Lexer::onBoolean() {
    // May need to check case? TRUE or true
    if(current == "true" || current == "false"){
        auto s = st.find(getCurrent());
        return Token(s->getToken(), s);
    }else
        return Token();
}