//  clist.cpp
//  P7-Khamphouy
//  Created by Tony Khamphouy on 3/27/23.
//#include "clist.hpp"
// --------------------------------------------------------------------------
//  Checks if empty
/*template <class Item> bool
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
    spt newPlay = spt(new Player(name, col));
    it = new Cell(newPlay, curPt);
    if(ct == 0){
        head = it;
        head->linkL = head;
        curPt = it;
        tail = it;
    }
    else{
        curPt->linkL = it;
        curPt = it;
        it->linkL = head;
        tail = it;
    }
    ct++;
}
// --------------------------------------------------------------------------
//  points curPT to head
template <class Item> void
CList<Item> :: init(){
    if(ct==0){
        addCell(head);
    }
    curPt->linkL = head;
    curPt = head;
}
// --------------------------------------------------------------------------
//  returns next player in the list
template <class Item> spt
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
        head->linkL = temp->linkL;
        curPt->linkL = temp->linkL;
    }
    else{
        temp = curPt->linkL;
        curPt->linkL = temp->linkL;
    }
    avalCol[(int)temp->pData->color()] = true;
    cout << "Removing player: " << *temp->pData;
    delete temp;
}
// --------------------------------------------------------------------------
//  prints out list
template <class Item> ostream&
CList<Item> :: print(ostream& os) const {
    Cell* temp = head;
    if(head != nullptr){
        do {
            os << *temp->pData;
            temp = temp->linkL;
        } while (temp != head);
    }
    else{
        os << "No players\n";
    }
    return os;
}*/
