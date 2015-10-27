//
// Created by Thomas O'Neill on 9/24/15.
//
#include <typeCheck.h>
#include "lib/ast.h"
#include "lib/evaluate.h"
#include "lib/parser.cpp"
#include "lib/Lexer.h"
#include "lib/token.h"

// Evaluates an equation from standard input
int main(){
    //std::unordered_map<string, Symbol *> st;
    //std::vector<Token> ts;
    //std::list<Token> tsl;
    Token_Stream ts;
    SymbolTable st;

    st.installSymbol("+",add_token);
    st.installSymbol("||",or_token);
    st.installSymbol("-",subtract_token);
    st.installSymbol("/",divide_token);
    st.installSymbol("%",mod_token);
    st.installSymbol("*",multiply_token);
    st.installSymbol("(",lparen_token);
    st.installSymbol(")", rparen_token);
    st.installSymbol("<",lessThan_token);
    st.installSymbol("<=",lessThanEqual_token);
    st.installSymbol(">",greaterThan_token);
    st.installSymbol(">=",greaterThanEqual_token);
    st.installSymbol("||",or_token);
    st.installSymbol("&&", and_token);
    st.installSymbol("==",equality_token);
    st.installSymbol("!=",notEqual_token);
    st.installSymbol("!",not_token);
    st.installBoolSymbol("false",bool_token,false);
    st.installBoolSymbol("true",bool_token,true);

    std::string equation;
    std::getline(std::cin,equation,'\n');

    Lexer lex(st,equation);
    auto error = lex.lex(ts);
    if (!error){
        std::cout << "Error lexing\n";
        exit(9);
    }
    Parser parser(ts);
    Expr* e ;
    e =parser.expr();
    TypeCheck tc;
    e->accept(tc);
    Eval eval;
    e->accept(eval);
    if(tc.type == getIntType()){
        std::cout << eval.getInt() << std::endl;
    }else if(tc.type == getBoolType()){
        std::cout << (eval.getBool() ? "True" : "False") << std::endl;
    }else{
        std::cout << "Type error\n"; // Should never get here
    }


    return 0;
}
