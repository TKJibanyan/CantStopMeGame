//  board.hpp
//  P5-Khamphouy
//  Created by Tony Khamphouy on 2/20/23.
#ifndef board_hpp
#define board_hpp

#include "column.hpp"

using upi = unique_ptr<Column>;
class Board {
private:
    int tCount = 0;
    int towInCol[3] = {};
    upi backBone[13];
    spt currP;
public:
    Board():backBone{nullptr} {
        for(int k = 2; k <= 12; k++){
            backBone[k] = upi(new Column(k));
        }
    }
    ~Board() = default;
    void startTurn(spt p);
    bool move(int col);
    void stop();
    void bust();
    ostream& print(ostream& os) const;
};
inline ostream& operator <<(ostream& os, Board& bd){ return bd.print(os);}
#endif /* board_hpp */
