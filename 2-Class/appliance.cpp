#include "appliance.h"

Appliance::Appliance(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed as Mammal";
}


bool Appliance::cook()
{
    return true;
}

bool Appliance::grill()
{
    return true;
}

bool Appliance::freeze()
{
    return true;
}