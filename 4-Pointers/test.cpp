#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << " Constructed";
}

Test::~Test()
{
    qInfo() << this << " DeConstructed";
}

void Test::doStuff()
{
    qInfo() << this << Q_FUNC_INFO;
}
