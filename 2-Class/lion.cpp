#include "lion.h"

Lion::Lion(QObject *parent)
    : Feline{parent}
{}

void Lion::speak()
{
    qInfo() << this << "ROAR!!";
}
