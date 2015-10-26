//
// Created by Thomas O'Neill on 9/24/15.
//

#include "ast.cpp"
#include "parser.cpp"
#include "postfix.h"
#include <iostream>

// Evaluate the postfix
int main(){
    std::string equation;
    std::getline(std::cin,equation,'\n');
/*    Parser parser(equation);
    Expr* e ;
    e = parser.expr();
    Postfix postfix;

    e->accept(postfix);
    std::cout << std::endl;
    */
}
