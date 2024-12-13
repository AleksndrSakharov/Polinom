#pragma once
#include "Monom.h"


class Polynom{
private:
    Monom* _head = nullptr;
public:
    Polynom(){

    }
    void AppendMonom(Monom* monom){
        if(_head == nullptr) _head = monom;
        else{
            Monom* tmp = _head;
            while (tmp->Next != nullptr){
                if (tmp->IsPowersEqual(*monom)) {tmp = &(*tmp + *monom);return;}
                tmp = tmp->Next;
            }
            tmp->Next = monom;
        }
    }
     void Print(){
        if(_head == nullptr){
            cout << 0 << endl;
        }else{
            Monom* tmp = _head;
            while (tmp->Next != nullptr){
                tmp->Print();
                if (tmp->Next != nullptr) cout << " + ";
                tmp = tmp->Next;
            }
            
        }
        cout << " ";
    }
};