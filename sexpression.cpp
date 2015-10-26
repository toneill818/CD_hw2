//
// Created by Thomas O'Neill on 9/24/15.
//
#include "ast.cpp"
#include "parser.cpp"
#include "sexpr.cpp"
#include <string>
#include <iostream>

int main(){
    std::string equation;
    std::getline(std::cin,equation,'\n');
/*    Parser parser(equation);
    Expr* e ;
    e = parser.expr();
    SExper sexper;

    e->accept(sexper);
    std::cout << std::endl;*/
}