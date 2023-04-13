//  clist.hpp
//  P7-Khamphouy
//  Created by Tony Khamphouy on 3/27/23.
#ifndef clist_hpp
#define clist_hpp
#include "column.hpp"

template <class Item>
class CList {
private:
    class Cell {
    public:
        Item pData;
        Cell* linkL = nullptr;
        Cell(Item p, Cell* c): pData(p), linkL(c) {}
        ~Cell() = default;
    };
    int ct = 0;
    bool avalCol[5];
    Cell* head;
    Cell* tail;
    Cell* curPt;
public:
    CList(): head(nullptr), tail(nullptr), curPt(nullptr){
        for(int k = 1; k < 5; k++){
            avalCol[k] = true; // assigns bool array to true
        }
    }
    ~CList(){
       /* Cell* temp = head;
        Cell* next;
        while(temp != tail){
            next = temp->linkL;
            delete temp;
            temp = next;
        }
        delete temp;*/
    }
    int count() {return ct;}
    bool empty();
    void addCell(Cell* it);
    void init();
    void remove();
    Item nextPlayer();
    Cell* next() {return curPt;}
    ostream& print(ostream& os) const;
};
template <class Item>
inline ostream& operator <<(ostream& os, CList<Item>& c){ return c.print(os);}

template <class Item> bool
CList<Item> :: empty(){
    if(ct == 0){
        return true;
    }
    return false;
}
// --------------------------------------------------------------------------
//  Adds new player into list
template <class Item> void
CList<Item> :: addCell(Cell* it){
    string name;
    int color;
    ECcolor col;
    cout <<"New player!\n Please enter a name with no spaces: ";
    cin >> name;
    cout <<"\nYour color options are: ";
    for( int k = 1; k <= 4; k++ ){
        if(avalCol[k] == true){
            cout << words[k] + " ";
        }
    }
    cout <<"\nEnter a numbered value for the available color only: ";
    cout << "Orange(1), Yellow(2), Green(3), or Blue(4): ";
    cin >> color;
    while( avalCol[color] == false ){
        cout <<"\nNot available\n";
        cout <<"\nEnter a numbered value for the available color only: ";
        cout <<"Orange(1), Yellow(2), Green(3), or Blue(4): ";
        cin >> color;
    }
    avalCol[color] = false;
    col = (ECcolor)color;
    Item newPlay = Item(new Player(name, col));
    it = new Cell(newPlay, curPt);
    if(empty() == true){
        head = it;
        head->linkL = head;
        curPt = it;
        tail = it;
    }
    else{
        curPt->linkL = it;
        curPt = it;
        //it->linkL = head;
        tail = it;
    }
    ct++;
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
//  returns next player in the list
template <class Item> Item
CList<Item> :: nextPlayer(){
    curPt = curPt->linkL;
    return curPt->linkL->pData;
}

// --------------------------------------------------------------------------
//  removes current player
template <class Item> void
CList<Item> :: remove(){
    Cell* temp;
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
        curPt->linkL = temp->linkL;
    }
    avalCol[(int)temp->pData->color()] = true;
    cout << "Removing player: " << *temp->pData;
    ct--;
    delete temp;
}
// --------------------------------------------------------------------------
//  prints out list
template <class Item> ostream&
CList<Item> :: print(ostream& os) const {
    if(ct == 0){
        os << "No Players\n";
        return os;
    }
    Cell* temp = head;
    if(head != nullptr){
        do {
            os << *temp->pData;
            temp = temp->linkL;
        } while (temp != head);
    }
    return os;
}
#endif /* clist_hpp */
