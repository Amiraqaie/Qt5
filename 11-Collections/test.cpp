#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << "new object constructed";
}

Test::~Test()
{
    qInfo() << "test object deconstructed";
}
