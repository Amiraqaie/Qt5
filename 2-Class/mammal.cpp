#include "mammal.h"

Mammal::Mammal(QObject *parent)
    : Animal{parent}
{
    //first calls Qobjects constructor
    // then calls Animal Constructor
    // at last it calls bellow statements

    qInfo() << this << "Constructed as Mammal";
}
