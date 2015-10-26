//
// Created by Thomas O'Neill on 10/6/15.
//

#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <string>
#include <cctype>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include "ast.cpp"
#include "token.h"

struct Parser{
private:
    std::string equation;
    Token_Stream &ts;
    int lookAhead;
    int numOpenParen;

    // Clear all whitespace (spaces and tabs) from the string.
    void removeSpaces(std::string &input){
        input.erase(std::remove(input.begin(),input.end(),' '),input.end());
        input.erase(std::remove(input.begin(),input.end(),'\t'),input.end());
    }

    // Increments the lookAhead to the next character
    void next(){
        lookAhead++;
       ts.get();
    }

public:
    // Prepare the parser by removing the whitespaces from the equation and setting the lookahead to 0
    Parser(Token_Stream &e):ts(e), lookAhead(0), numOpenParen(0){ }

   // Parser():equation(""),lookAhead(0), numOpenParen(0), ts(nullptr){}

    // An expr is a + or - operation or a factor. This give us proper order of operations by splitting
    // + and - from *, % and /.
    Expr* expr(){
        // Get e1 which cannot be a nullptr
        return LogicOr();
    }

    Expr* LogicOr(){
        Expr* e1 = LogicAnd();
        while(true){
            if(ts.peek().getKind() == or_token){
                next();
                Expr*e2 = LogicAnd();
                e1 = new Or(e1,e2);
            }else
                break;
        }
        return e1;
    }

    Expr* LogicAnd(){
        Expr* e1 = Equality();
        while(true){
            if(ts.peek().getKind() == and_token){
                next();
                Expr* e2 = Equality();
                e1 = new And(e1,e2);
            }else
                break;
        }
        return e1;
    }

    Expr* Equality(){
        Expr* e1 = Ordering();
        while(true){
           if(ts.peek().getKind() == equality_token){
               next();
               Expr* e2 = Ordering();
               e1 = new Equal(e1,e2);
           } else if(ts.peek().getKind() == notEqual_token){
               next();
               Expr* e2 = Ordering();
               e1 = new NotEqual(e1,e2);
           }else
               break;
        }
        return e1;
    }

    Expr* Ordering(){
        Expr* e1 = Additve();
        while (true){
            if(ts.peek().getKind() == lessThan_token){
                next();
                Expr*e2 = Additve();
                e1 = new LessThan(e1,e2);
            }else if(ts.peek().getKind() == lessThanEqual_token){
                next();
                Expr*e2 = Additve();
                e1 = new LessThanEqual(e1,e2);
            }else if(ts.peek().getKind() == greaterThan_token){
                next();
                Expr*e2 = Additve();
                e1 = new GreaterThan(e1,e2);
            }else if (ts.peek().getKind() == greaterThanEqual_token){
                next();
                Expr*e2 = Additve();
                e1 = new GreaterThanEqual(e1,e2);
            }else{
                break;
            }
        }
        return e1;
    }

    Expr* Additve(){
        Expr * e1 = Factor();
        while(true) {
            if (ts.peek().getKind() == add_token) {
                next();
                Expr *e2 = Factor();
                e1 = new Add(e1, e2);
            } else if (ts.peek().getKind() == subtract_token) {
                next();
                Expr *e2 = Factor();
                e1 = new Subtract(e1, e2);
            } else {
                break;
            }
        }
        return e1;
    }

    // A factor is *, /, % or a term.
    Expr* Factor(){
        // Get the first term in the factor. e1 cannot be a nullptr
        Expr* e1 = T();

        // Loop while we still have factors
        while(true){
            if(ts.peek().getKind() == multiply_token){
                next();
                Expr* e2 = T();
                e1 = new Multiply(e1,e2);
            }else if(ts.peek().getKind() == divide_token){
                next();
                Expr* e2 = T();
                e1 = new Divide(e1,e2);
            }else if(ts.peek().getKind() == mod_token) {
                next();
                Expr* e2 = T();
                e1 = new Mod(e1,e2);
                // Check for a closing parenthesis. If detected check that there was an open parenthesis and return
                // the factor/expression.
            }else if(ts.peek().getKind() == rparen_token) {
                if(numOpenParen == 0){
                    std::cout << "Error extra ) found\n";
                    exit(-3);
                }
                numOpenParen--;
                next();
                return e1;
            }else{
                break;
            }
        }
        return e1;
    }

    // Term is simply a digit 0-9
    Expr* T(){
        // Check for boolean type
        if(ts.peek().getKind() == bool_token){
            if(ts.peek().getKind() == not_token){
                ts.get();
                //Bool_Symbol *  b = (Bool_Symbol*) ts.get().getSymbol();
                if (ts.get().getSpelling() == "true")
                    return new Boolean(false);
                else
                    return new Boolean(true);

            }
            if (ts.get().getSpelling() == "true")
                return new Boolean(true);
            else
                return new Boolean(false);
        }
        // Check if it is a unary + and do nothing since + does not change sign.
        if(ts.peek().getKind() == add_token){
            ts.get();
        }
        // Check if we have an open Parenthesis and begin a new expression parse
        // This will build the entire expression ast that will then get passed back
        // up when the closing parenthesis is found.
        if(ts.peek().getKind() == lparen_token){
            numOpenParen++;
            next();
            return(expr());
        }
        // Check if it is a - and negate the integer
        if(ts.peek().getKind() == subtract_token){
            ts.get();
            return new Integer(-atoi(ts.get().getSpelling().c_str()));
        }

        if(ts.peek().getKind() == int_token){
            return new Integer(atoi(ts.get().getSpelling().c_str()));
        }else{
            std::cout << "Error: expected a digit or boolean but got " << ts.peek().getSpelling() << std::endl;
            exit(-4);
        }
    }
};
#endif //CALC_PARSER_H
