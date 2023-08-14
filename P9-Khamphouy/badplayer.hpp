//  badplayer.hpp
//  P10-Khamphouy
//  Created by Tony Khamphouy on 4/18/23.
#ifndef badplayer_hpp
#define badplayer_hpp

#include "enums.hpp"

class BadPlayer {
public:
    string name;
    ECcolor color;
    BadPlayer(string n, ECcolor c) : name(n), color(c) {};
    virtual ~BadPlayer()=default;
    virtual void print();
    void pr();
    
};

class BadName : public BadPlayer {
public:
    BadName(string n, ECcolor c) : BadPlayer(n, c) {};
    virtual ~BadName(){}
    virtual void print();
};

class BadColor : public BadPlayer {
public:
    BadColor(string n, ECcolor c) : BadPlayer(n, c) {};
    virtual ~BadColor(){}
    virtual void print();
};

#endif /* badplayer_hpp */
