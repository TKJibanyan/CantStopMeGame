//  clist.hpp
//  P7-Khamphouy
//  Created by Tony Khamphouy on 3/27/23.
#ifndef clist_hpp
#define clist_hpp
#include "column.hpp"
#include "badplayer.hpp"

template <class Item>
class CList {
private:
    class Cell {
    public:
        Item pData;
        shared_ptr<Cell> linkL = nullptr;
        Cell(Item p, shared_ptr<Cell> c): pData(p), linkL(c) {}
        ~Cell() {linkL.reset(); pData.reset();}
    };
    string name;
    ECcolor col;
    int ct = 0;
    bool avCol[5] = {true, true, true, true, true};
    shared_ptr<Cell> head;
    shared_ptr<Cell> tail;
    shared_ptr<Cell> curPt;
    shared_ptr<Cell> prior = head;
    void checkData();
public:
    CList(): head(nullptr), tail(nullptr), curPt(nullptr){}
    ~CList(){head.reset();tail.reset();curPt.reset();prior.reset();}
    int count() const {return ct;}
    bool empty();
    void addCell(shared_ptr<Cell> it);
    void init();
    void remove();
    shared_ptr<Cell> operator ()(){return nPlayer();}
    shared_ptr<Cell> nPlayer() {if(empty() == true)return nullptr;
        curPt = curPt->linkL; return curPt->linkL;}
    shared_ptr<Cell> next() const {return curPt;}
    ostream& print(ostream& os) const;
};
template <class Item>
inline ostream& operator <<(ostream& os, CList<Item>& c){ return c.print(os);}
// --------------------------------------------------------------------------
//  checks to see if empty
template <class Item> bool
CList<Item> :: empty(){
    if(count() == 0){
        return true;
    }
    return false;
}
// --------------------------------------------------------------------------
//  Adds new player into list
template <class Item> void
CList<Item> :: addCell(shared_ptr<Cell> it){
    int color;
    bool success = false;
    while(success != true){
        try{
            cout <<"New player!\n Please enter a name with no spaces: ";
            cin >> name;
            cout <<"\nYour color options are: ";
            for( int k = 1; k <= 4; k++ ){
                if(avCol[k] == true){cout << words[k] << "[" << k << "] ";}
            }
            cout <<"\nEnter a numbered value for the available color only: ";
            cin >> color;
            col = (ECcolor)color;
            checkData();
            avCol[color] = false;
            Item newPlay = Item(new Player(name, col));
            it = shared_ptr<Cell>(new Cell(newPlay, tail));
            if(empty() == true){
                head = it;
                head->linkL = head;
                curPt = it;
                tail = it;
            }
            else{
                tail->linkL = it;
                curPt = it;
                tail = it;
            }
            ct++;
            success = true;
        }
        catch (BadPlayer& bp) {bp.print(); }
    }
}
// --------------------------------------------------------------------------
//  checks player
template <class Item> void
CList<Item> :: checkData(){
    shared_ptr<Cell> t = head;
    if(head != nullptr){
        for(int k = 0; k < ct; k++){
            if(name.compare(t->pData->pName)== 0 && avCol[(int)col] == false){
                throw BadPlayer(name, col);
            }
            if(name.compare(t->pData->pName)== 0){
                throw BadName(name, col);
            }
            if(avCol[(int)col] == false){
                throw BadColor(name, col);
            }
            t = t->linkL;
        }
    }
}
// --------------------------------------------------------------------------
//  points curPT to head
template <class Item> void
CList<Item> :: init(){
    if(empty() == true){
        addCell(head);
    }
    curPt->linkL = head;
    curPt = head;
}
// --------------------------------------------------------------------------
//  removes current player
template <class Item> void
CList<Item> :: remove(){
    shared_ptr<Cell> temp;
    if(curPt == head){
        temp = head->linkL;
        head->linkL = temp;
        curPt->linkL = temp->linkL;
        if(ct == 1){
            head = nullptr;
        }
    }
    else{
        temp = curPt->linkL;
        curPt = curPt->linkL = temp->linkL;
        head->linkL = curPt->linkL;
    }
    avCol[(int)temp->pData->color()] = true;
    cout << "Removing player: " << *temp->pData;
    ct--;
    temp.reset();
}
// --------------------------------------------------------------------------
//  prints out list
template <class Item> ostream&
CList<Item> :: print(ostream& os) const {
    if(count() == 0){
        os << "No Players\n";
        return os;
    }
    shared_ptr<Cell> temp = head;
    if(head != nullptr){
        do {
            os << *temp->pData;
            temp = temp->linkL;
        } while (temp != head);
    }
    return os;
}
#endif /* clist_hpp */
