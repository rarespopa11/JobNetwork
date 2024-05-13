#include "Data.h"
#include <iostream>
Data& Data::operator=(const Data& other) {
    if (this == &other) {
        return *this;
    }

    zi = other.zi;
    luna = other.luna;
    an = other.an;

    return *this;
}
Data::Data(int z, int l, int a)
{
    zi = z;
    luna = l;
    an = a;
}
Data::Data()
{
    zi = 0;
    luna = 0;
    an = 0;
}
const int& Data::getzi() const {
    return zi;
}
const int& Data::getluna() const {
    return luna;
}
const int& Data::getan() const {
    return an;
}
void Data::print(){
    std::cout << zi << "." << luna << "." << an << "\n";
}
