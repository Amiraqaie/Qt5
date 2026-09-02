#ifndef TEMP_H
#define TEMP_H

#include "QObject"

template<class T>
class Temp
{
public:
    Temp();
    T add(T value1, T value2);
};

// this should be add so compiler bedore reading temp.cpp knows for which types should compile Temp class
template class Temp<int>;
template class Temp<double>;
template class Temp<QString>;

#endif // TEMP_H
