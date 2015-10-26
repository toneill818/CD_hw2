//
// Created by Thomas O'Neill on 10/6/15.
//

#ifndef CALC_AST_H
#define CALC_AST_H


#include "type_ast.h"

struct Expr;
struct Integer;
struct Add;
struct Multiply;
struct Subtract;
struct Divide;
struct Mod;
struct And;
struct Or;
struct Not;
struct NotEqual;
struct Equal;
struct LessThanEqual;
struct LessThan;
struct GreaterThanEqual;
struct GreaterThan;
struct Boolean;
struct Visitor;
struct AnnotateVisitor;

// Visitor class that will be used to evaluate and translate to posfix and sexpressions
struct Visitor{
    virtual void visit(Integer const *e)=0;
    virtual void visit(Add const *e)=0;
    virtual void visit(Multiply const *e)=0;
    virtual void visit(Subtract const *e)=0;
    virtual void visit(Divide const *e)=0;
    virtual void visit(Mod const *e)=0;
    virtual void visit(And const *e)=0;
    virtual void visit(Or const *e)=0;
//    virtual void visit(Not const *e)=0;
    virtual void visit(Equal const *e)=0;
    virtual void visit(NotEqual const *e)=0;
    virtual void visit(LessThanEqual const *e)=0;
    virtual void visit(LessThan const *e)=0;
    virtual void visit(GreaterThanEqual const *e)=0;
    virtual void visit(GreaterThan const *e)=0;
    virtual void visit(Boolean const *e)=0;
};

struct AnnotateVisitor{
    virtual void visit(Integer *e)=0;
    virtual void visit(Add *e)=0;
    virtual void visit(Multiply *e)=0;
    virtual void visit(Subtract *e)=0;
    virtual void visit(Divide *e)=0;
    virtual void visit(Mod *e)=0;
    virtual void visit(And *e)=0;
    virtual void visit(Or *e)=0;
    //virtual void visit(Not *e)=0;
    virtual void visit(Equal *e)=0;
    virtual void visit(NotEqual *e)=0;
    virtual void visit(LessThanEqual *e)=0;
    virtual void visit(LessThan *e)=0;
    virtual void visit(GreaterThanEqual *e)=0;
    virtual void visit(GreaterThan *e)=0;
    virtual void visit(Boolean *e)=0;
};

// Base class that everything will derive from.
struct Expr{
    virtual  ~Expr(){}
    // Pure vitural function inorder for all expressions to work with our visitor pattern
    virtual void accept(Visitor&)=0;
    virtual void accept(AnnotateVisitor&)=0;
    Type *type;
};

// Integer represents a single digit 0-9 and holds its value
struct Integer:Expr{
    int n;
    Integer(int n):n(n){type = getIntType();}
    void accept(Visitor &v){
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

// Add represents addion of 2 expressions (which will be evaluated down to the Integer class
struct Add:Expr{
    Expr *e1, *e2;
    Add(Expr *e, Expr *ee ):e1(e), e2(ee){type = getIntType();}
    void accept(Visitor &v){
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

// Multiply takes 2 expressions
struct Multiply:Expr{
    Expr *e1, *e2;
    Multiply(Expr* e, Expr* ee):e1(e), e2(ee){type = getIntType();}
    void accept(Visitor &v){
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

// Subtractions represents the subtraction of 2 expressions
struct Subtract:Expr{
    Expr *e1, *e2;
    Subtract(Expr* e, Expr* ee):e1(e), e2(ee){type = getIntType();}
    void accept(Visitor &v){
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

// Divide represents the division of 2 expressions
struct Divide:Expr{
    Expr *e1, *e2;
    Divide(Expr* e, Expr* ee):e1(e), e2(ee){type = getIntType();}
    void accept(Visitor &v){
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

// Mod is the modulous of 2 expressions
struct Mod:Expr{
    Expr *e1, *e2;
    Mod(Expr* e, Expr* ee):e1(e), e2(ee){type = getIntType();}
    void accept(Visitor &v){
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct And:Expr{
    Expr *e1, *e2;
    And(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct Or:Expr{
    Expr *e1, *e2;
    Or(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

//struct Not:Expr{
//    Expr *e1, *e2;
//    Not(Expr* e, Expr* ee):e1(e), e2(ee) {
//        type = getBoolType();
//    }
//    void accept(Visitor &v) {
//        v.visit(this);
//        return;
//    }
//    void accept(AnnotateVisitor &v){
//        v.visit(this);
//        return;
//    }
//};

struct NotEqual:Expr{
    Expr *e1, *e2;
    NotEqual(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct Equal:Expr{
    Expr *e1, *e2;
    Equal(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct GreaterThan:Expr{
    Expr *e1, *e2;
    GreaterThan(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct LessThan:Expr{
    Expr *e1, *e2;
    LessThan(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct GreaterThanEqual:Expr{
    Expr *e1, *e2;
    GreaterThanEqual(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct LessThanEqual:Expr{
    Expr *e1, *e2;
    LessThanEqual(Expr* e, Expr* ee):e1(e), e2(ee) {
        type = getBoolType();
    }
    void accept(Visitor &v) {
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};

struct Boolean:Expr{
    bool value;
    Boolean(bool v):value(v){type = getBoolType();}
    void accept(Visitor &v){
        v.visit(this);
        return;
    }
    void accept(AnnotateVisitor &v){
        v.visit(this);
        return;
    }
};
#endif //CALC_AST_H
