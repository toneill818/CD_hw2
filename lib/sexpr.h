//
// Created by Thomas O'Neill on 10/6/15.
//

#ifndef CALC_SEXPR_H
#define CALC_SEXPR_H

#include "ast.cpp"
#include "parser.cpp"
#include <string>
#include <iostream>

struct SExper:Visitor{
    void visit(Integer const *e) {
        std::cout << e->n;
    }

    void visit(Add const *e){
        std::cout << "(+";
        e->e1->accept(*this);
        //std::cout << "+";
        e->e2->accept(*this);
        std::cout << ")";
    }

    void visit(Multiply const *e){
        std::cout << "(*";
        e->e1->accept(*this);
        e->e2->accept(*this);
        std::cout << ")";
    }

    void visit(Divide const *e){
        std::cout << "(/";
        e->e1->accept(*this);
        e->e2->accept(*this);
        std::cout << ")" ;
    }
    void visit(Subtract const *e){
        std::cout << "(-";
        e->e1->accept(*this);
        e->e2->accept(*this);
        std::cout << ")";
    }
    void visit(Mod const *e){
        std::cout << "(%";
        e->e1->accept(*this);
        e->e2->accept(*this);
        std::cout << ")";
    }
};
#endif //CALC_SEXPR_H
