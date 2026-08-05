#include "animal.h"

Animal::Animal(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed";
}

void Animal::speak(QString message)
{
    qInfo() << message;
}

void Animal::speak()
{
    qInfo() << "random animal voice";
}
