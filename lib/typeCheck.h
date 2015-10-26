//
// Created by Thomas O'Neill on 10/22/15.
//

#ifndef CALC_TYPECHECK_H
#define CALC_TYPECHECK_H


#include <iostream>
#include "ast.h"

class TypeCheck:public AnnotateVisitor {
public:
    Type* type;
    TypeCheck():type(nullptr){}
    void visit(Integer * i){
        type = i->type;
    }
    void visit(Boolean * b){
        type = b->type;
    }

    void visit(Add * a){
        a->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            a->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        a->type = type;
    }

    void visit(Multiply * a){
        a->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            a->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        a->type = type;
    }

    void visit(Subtract * a){
        a->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            a->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        a->type = type;
    }

    void visit(Divide * a){
        a->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            a->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        a->type = type;
    }

    void visit(Mod * a){
        a->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            a->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        a->type = type;
    }

    void visit(And *e){
        e->e1->accept(*this);
        if(type != getBoolType()){
            type = nullptr;
            std::cout << "Error expected boolean type!\n";
        }else{
            e->e2->accept(*this);
            if(type != getBoolType()){
                type = nullptr;
                std::cout << "Error expected boolean type!\n";
            }
        }
        type = getBoolType();
    }

    void visit(Or *e){
        e->e1->accept(*this);
        if(type != getBoolType()){
            type = nullptr;
            std::cout << "Error expected boolean type!\n";
        }else{
            e->e2->accept(*this);
            if(type != getBoolType()){
                type = nullptr;
                std::cout << "Error expected boolean type!\n";
            }
        }
        type = getBoolType();
    }

    void visit(Equal *e){
        e->e1->accept(*this);
        if (type == getBoolType()){
            e->e2->accept(*this);
            if(type != getBoolType()){
                std::cout << "Error mismatch type near ==\n";
                type = nullptr;
            }
        }else{
            e->e2->accept(*this);
            if(type != getIntType()){
                std::cout << "Error mismatch type near ==\n";
                type = nullptr;
            }
        }
        type = getBoolType();
    }

    void visit(NotEqual *e){
        e->e1->accept(*this);
        Type t = *type;
        e->e2->accept(*this);
        if(&t != type){
            std::cout << "Error mismatch type near !=\n";
            type = nullptr;
        }
        type = getBoolType();
    }

    void visit(LessThan *e){
        e->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            e->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        type = getBoolType();
    }

    void visit(LessThanEqual *e){
        e->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            e->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        type = getBoolType();
    }

    void visit(GreaterThanEqual *e){
        e->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            e->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        type = getBoolType();
    }

    void visit(GreaterThan *e){
        e->e1->accept(*this);
        if(type != getIntType()){
            type = nullptr;
            std::cout << "Error expected int type!\n";
        }else{
            e->e2->accept(*this);
            if(type != getIntType()){
                type = nullptr;
                std::cout << "Error expected int type!\n";
            }
        }
        type = getBoolType();
    }
};


#endif //CALC_TYPECHECK_H
