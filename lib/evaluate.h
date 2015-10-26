//
// Created by Thomas O'Neill on 10/6/15.
//

#ifndef CALC_EVALUATE_H
#define CALC_EVALUATE_H

#include "ast.cpp"
#include "parser.cpp"
#include <iostream>

// Visitor pattern that will evaluate the expression depending on its most derived class.
// It will recurse down until it hits an Integer by calling accept on each expression for
// the binary operators. The evaluated value is store in value.
struct Eval:Visitor{
    // Hold the value of the expression being evaluated
    Eval():value(0){}

    // Base case where it returns the integer value by setting value to the integer.
    void visit(Integer const *e) {
        value = e->n;
    }

    // Add grabs the value from both of its expressions and saves them in arg1 and arg2
    // then adds the two together to get the new current value.
    void visit(Add const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        int arg2 = value;
        value =  arg1 + arg2;
    }

    // Multiply grabs the value from both of its expressions and saves them in arg1 and arg2
    // then multiplies the two  to get the new current value.
    void visit(Multiply const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        int arg2 = value;
        value = (arg2 * arg1);
    }

    // Divide grabs the value from both of its expressions and saves them in arg1 and arg2
    // then divides the two  to get the new current value.
    void visit(Divide const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        int arg2 = value;
        value = arg1 / arg2;
    }

    // Subtract grabs the value from both of its expressions and saves them in arg1 and arg2
    // then subtracts the two together to get the new current value.
    void visit(Subtract const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        int arg2 = value;
        value = arg1 - arg2;
    }

    // Mod grabs the value from both of its expressions and saves them in arg1 and arg2
    // then takes the modulus of the two to get the new current value.
    void visit(Mod const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        int arg2 = value;
        value = arg1 % arg2;
    }

    void visit(And const *e){
        e->e1->accept(*this);
        bool arg1 = result;
        e->e2->accept(*this);
        result = arg1 && result;
    }

    void visit(Or const *e){
        e->e1->accept(*this);
        bool arg1 = result;
        e->e2->accept(*this);
        result = arg1 && result;
    }

    //void visit(Not const *e){

    //}

    void visit(Equal const *e){
        if (e->e1->type == getIntType()){
            e->e1->accept(*this);
            int arg1 = value;
            e->e2->accept(*this);
            result = arg1 == result;
        }else{
            e->e1->accept(*this);
            bool arg1 = result;
            e->e2->accept(*this);
            result = arg1 == result;
        }
    }

    void visit(NotEqual const *e){
        if (e->e1->type == getIntType()){
            e->e1->accept(*this);
            int arg1 = value;
            e->e2->accept(*this);
            result = arg1 != result;
        }else{
            e->e1->accept(*this);
            bool arg1 = result;
            e->e2->accept(*this);
            result = arg1 != result;
        }
    }

    void visit(LessThan const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        result = arg1 < value;
    }

    void visit(LessThanEqual const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        result = arg1 <= value;
    }

    void visit(GreaterThan const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        result = arg1 > value;
    }

    void visit(GreaterThanEqual const *e){
        e->e1->accept(*this);
        int arg1 = value;
        e->e2->accept(*this);
        result = arg1 >= value;
    }

    void visit(Boolean const* e){
        result = e->value;
    }

    int getInt(){return value;}
    int getBool(){return result;};

private:
    int value;
    bool result;
};

#endif //CALC_EVALUATE_H
