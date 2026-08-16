#include "child.h"

Child::Child(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << " Constructed";
}

Child::~Child()
{
    qInfo() << this << " DeConstructed";
}
