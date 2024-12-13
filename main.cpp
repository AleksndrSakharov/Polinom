#include "Polynom.h"

int main(){
    int* powers1= new int[1] {2};
    Monom a  = Monom(2, 1, powers1);
    int* powers2 = new int[1] {1};
    Monom b  = Monom(2, 1, powers2);
    int* powers3 = new int[1] {3};
    Monom c = Monom(2, 1, powers3);
    a.Print();
    return 0;
}