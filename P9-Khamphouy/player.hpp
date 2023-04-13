//  player.hpp
//  P2-Khamphouy
//  Created by Tony Khamphouy on 1/26/23.
#ifndef player_hpp
#define player_hpp

#include "enums.hpp"

enum class ECcolor;

class Player{
private:
    int columnScore = 0;
    int playSco [3] = {};
public:
    string pName;
    ECcolor pColor;
    Player(string name, ECcolor color): pName(name), pColor(color){ }
    ~Player() = default;
    ECcolor color() const { return pColor;}
    int score() const { return columnScore;}
    bool wonColumn (int colNum);
    ostream& print(ostream& o)const;
};
inline ostream& operator <<(ostream& os, Player& p){ return p.print(os);}

#endif /* player_hpp */
