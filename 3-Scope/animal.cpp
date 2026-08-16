#include "animal.h"

int Animal::count = 0;

Animal::Animal(QObject *parent, QString name) : QObject(parent)
{
    this->name = name;
    qInfo() << "animal name param : " << &name << " = " << name;
    qInfo() << "animal name : " << &this->name << " = " << this->name;

    count++;
}

Animal::~Animal()
{
    count--;
}

void Animal::SayHello()
{
    qInfo() << "animal name param : " << &name << " = " << name;
    qInfo() << "animal name : " << &this->name << " = " << this->name;
}

void Animal::doStuff()
{
    qInfo() << "running static function";
    qInfo() << "can be runn without instance of class";
}