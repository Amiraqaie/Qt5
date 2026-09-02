#include "temp.h"

template <class T>
Temp<T>::Temp()
{
}

template <class T>
T Temp<T>::add(T value1, T value2)
{
    return value1 + value2;
}
