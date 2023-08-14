//  badchoice.hpp
//  P10-Khamphouy
//  Created by Tony Khamphouy on 4/26/23.
#ifndef badchoice_hpp
#define badchoice_hpp

#include "enums.hpp"

class BadChoice {
public:
    BadChoice() {}
    virtual ~BadChoice()=default;
    virtual void print();
};

class DuplicateSlot : public BadChoice {
public:
    char let;
    char slet;
    DuplicateSlot(char fl, char sl) : BadChoice(), let(fl), slet(sl){};
    virtual ~DuplicateSlot(){}
    virtual void print();
};

class BadSlot : public BadChoice {
public:
    char let;
    char slet;
    BadSlot(char fl, char sl) : BadChoice(), let(fl), slet(sl){};
    virtual ~BadSlot(){}
    virtual void print();
};
#endif /* badchoice_hpp */
