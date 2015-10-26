//
// Created by Thomas O'Neill on 9/22/15.
//

#ifndef POSFIX_H
#define POSFIX_H

#include "ast.cpp"
#include "parser.cpp"
#include <iostream>

struct Postfix :Visitor {
    void visit(Integer const *e) {
        std::cout << e->n;
    }

    void visit(Add const *e){
        e->e1->accept(*this);
        //std::cout << "+";
        e->e2->accept(*this);
        std::cout << "+";
    }

    void visit(Multiply const *e){
        e->e1->accept(*this);
        e->e2->accept(*this);
        std::cout << "*";
    }

    void visit(Divide const *e){
        e->e1->accept(*this);
        e->e2->accept(*this);

        std::cout << "/" ;
    }
    void visit(Subtract const *e){
        e->e1->accept(*this);
        e->e2->accept(*this);
        std::cout << "-";
    }
    void visit(Mod const *e){
        e->e1->accept(*this);
        e->e2->accept(*this);
        std::cout << "%";
    }
};
#endif //CALC_POSFIX_H
