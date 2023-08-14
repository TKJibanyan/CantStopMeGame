//  column.hpp
//  P3-Khamphouy
//  Created by Tony Khamphouy on 2/5/23.
#ifndef column_hpp
#define column_hpp

#include "player.hpp"
using sharedpt = shared_ptr<Player>;
class Column{
private:
    constexpr static const int columns[ 13 ]= { 0, 0, 3, 5, 7, 9, 11, 13,
        11, 9, 7, 5, 3 };
    int cNum;
    ECcolumn cState;
    int colPos [5] = {};
    ECcolor tiles;
    ECcolor playCol;
    int cLen;
public:
    static int colCt;
    Column() = default;
    Column(int cn): cNum(cn),cState(ECcolumn::Available), cLen(columns[cn]){
        colCt++;
    }
    ~Column() {colCt--;cerr << "Col Deallocated:" <<colCt <<"\n"; };
    ECcolumn colState() const{ return cState; }
    bool startTower( sharedpt p );
    bool move();
    bool towInCol();
    void stop( sharedpt p );
    void bust();
    ostream& print(ostream& os) const;
};
inline ostream& operator <<(ostream& os, Column& c){ return c.print(os);}

#endif /* column_hpp */

