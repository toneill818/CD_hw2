//
// Created by Thomas O'Neill on 10/6/15.
//

#ifndef CALC_SYMBOL_H
#define CALC_SYMBOL_H

#include <string>
#include <unordered_map>

using std::string;

class Symbol {
public:
    Symbol(int t):str(nullptr), tok(t){}
    virtual ~Symbol() {}

    string const& getSpelling() const;
    int getToken() const;
    string const* str; // Point to the spelling in the symbol table?
private:
    int tok;
};

// Symbol for Integers
class Int_Symbol: public Symbol{
public:
    Int_Symbol(int kind, int v):Symbol(kind), value(v){}
    int getValue(){return value;}
private:
    int value;
};

// Represents Symbol for TRUE and FALSE literals
class Bool_Symbol: public Symbol{
public:
    Bool_Symbol(int kind, bool v): Symbol(kind), value(v){}
    bool getValue(){return value;}
private:
    bool value;
};

// Symbol Table? Do I need a class for this? Could just make a map at the beginning?
class SymbolTable{
public:
    void installSymbol( std::string name, int kind){
        auto result = st.emplace(name, nullptr);
        // Second is true if insertion was successful false if it already existed.
        if(result.second){
            result.first->second = new Symbol(kind);
            result.first->second->str = &result.first->first;
        }
    }

    void installIntSymbol(string name, int kind, int value){
        auto result = st.emplace(name, nullptr);
        if(result.second){
            result.first->second = new Int_Symbol(kind,value);
            result.first->second->str = &result.first->first;
        }
    }

    void installBoolSymbol(string name, int kind, bool value){
        auto result = st.emplace(name, nullptr);
        if (result.second){
            result.first->second = new Bool_Symbol(kind,value);
            result.first->second->str = &result.first->first; // Get key from symbol table for spelling
        }
    }

    Symbol const * find(string name){
        auto result = st.find(name);
        // Check if it was found, the iterator will equal end if it is not installed
        if(result == st.end())
            return nullptr;
        return result->second;
    }
private:
    std::unordered_map<string, Symbol *> st;
};

#endif //CALC_SYMBOL_H
