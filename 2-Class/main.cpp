#include <QCoreApplication>
#include "animal.h"
#include "laptop.h"

void test(Laptop& machine)
{
    machine.test();
}

void makeLaptops()
{
    // the stack
    Laptop mine(nullptr, "mac");
    Laptop yours(nullptr, "asus");

    mine.weight = 3.2;
    yours.weight = 2.5;

    test(mine);
    test(yours);
    // will be deleted from the stack automatically

    mine.test();
    yours.test();
}

int main(int argc, char *argv[])
{
    // episode 2, 3
    QCoreApplication a(argc, argv);

    QObject q;

    Animal cat;
    Animal dog;
    Animal fish;

    cat.speak("meow");

    // episode 4
    makeLaptops();

    // episode 5 inheritance


    return QCoreApplication::exec();
}
