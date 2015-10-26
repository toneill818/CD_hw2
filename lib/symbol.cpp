//
// Created by Thomas O'Neill on 10/6/15.
//

#include "symbol.h"

int Symbol::getToken() const { return tok; }

string const& Symbol::getSpelling() const { return *str; }
