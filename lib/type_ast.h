//
// Created by Thomas O'Neill on 10/6/15.
//

#ifndef CALC_TYPE_AST_H
#define CALC_TYPE_AST_H


struct Type {

};

struct Bool_Type : Type{

};

struct Int_Type : Type{
public:
    int getPrecision(){return PRECISION;}
private:
    const int PRECISION = 32;

};

Bool_Type* getBoolType(){
    static Bool_Type b;
    return &b;
}
Int_Type* getIntType(){
    static Int_Type t;
    return &t;
}

#endif //CALC_TYPE_AST_H
