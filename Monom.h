#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

// template <size_t size>
class Monom
{
private:
    double _coef;
    size_t _size;
    int* _powers;
public:
    Monom* Next = nullptr;
    Monom() : _coef(0), _size(1), _powers(new int[_size]){}
    Monom(double coef, size_t size) : _coef(coef), _size(size){
        _powers = new int[size];
    }
    Monom(double coef, size_t size,  int* power) : _coef(coef), _size(size){
         _powers = power;
    }
    Monom(const Monom& tmp) : _coef(tmp._coef), _size(tmp._size){
        _powers = new int[tmp._size];
        for(size_t i = 0; i < _size; i++) _powers[i] = tmp._powers[i];
    }
    Monom& operator=(const Monom& tmp){
        if (_powers == tmp._powers) return *this;
        _coef = tmp._coef;
        _size = tmp._size;
        delete [] _powers;
        _powers = new int[_size];
        for(size_t i = 0; i < _size; i++) _powers[i] = tmp._powers[i];
        return *this;
    }
    Monom operator+(const Monom& tmp){
        if (_size != tmp._size) throw "Yooooo";
        for(size_t i = 0; i < _size; i++) if (_powers[i] != tmp._powers[i]) throw "No poweeer????";
        return Monom(_coef + tmp._coef, _size, _powers);
    }

    Monom operator-(const Monom& tmp){
        if (_size != tmp._size) throw "Yooooo";
        for(size_t i = 0; i < _size; i++) if (_powers[i] != tmp._powers[i]) throw "No poweeer????";
        return Monom(_coef - tmp._coef, _size, _powers);
    }

    Monom operator*(const Monom& tmp){
        size_t max_size = max(_size, tmp._size);
        size_t min_size = min(_size, tmp._size);
        int* new_powers = new int[max_size];
        int* tmp1 = max_size == _size ? _powers : tmp._powers;
        for(size_t i = 0; i < max_size; i++){ 
                if (i < min_size) new_powers[i] = _powers[i] + tmp._powers[i];
                else new_powers[i] = tmp1[i];
            }
        return Monom(_coef * tmp._coef, max_size, new_powers);
    }

    Monom operator/(const Monom& tmp){
        size_t max_size = max(_size, tmp._size);
        size_t min_size = min(_size, tmp._size);
        int* new_powers = new int[max_size];
        int* tmp1 = max_size == _size ? _powers : tmp._powers;
        for(size_t i = 0; i < max_size; i++){ 
                if (i < min_size) new_powers[i] = _powers[i] - tmp._powers[i];
                else new_powers[i] = tmp1[i];
            }
        return Monom(_coef / tmp._coef, max_size, new_powers);
    }

    bool operator==(const Monom& tmp){
        if (_size != tmp._size) return false;
        for(size_t i = 0; i < _size; i++) if (_powers[i] != tmp._powers[i]) return false;
        return (_coef == tmp._coef);
    }

    void Print(){
        if(_coef == 0){
            cout << 0 << endl;
        }else{
            cout << _coef << " * ";
            for (size_t i = 0; i < _size; i++){
                if (i != _size - 1) cout << "x" << i << "^" << _powers[i] << " * ";
                else cout << "x" << i << "^" << _powers[i];
            }
        }
        cout << " ";
    }

    bool IsPowersEqual(const Monom& tmp){
        if (_size != tmp._size) return false;
        for(size_t i = 0; i < _size; i++) if (_powers[i] != tmp._powers[i]) return false;
        return true;
    }


    // ~Monom(){
    //     delete [] _powers;
    //     delete [] _next;
    // }
};
