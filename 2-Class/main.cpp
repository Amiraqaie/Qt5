#include <QCoreApplication>
#include "animal.h"
#include "laptop.h"
#include "mammal.h"
#include "feline.h"
#include "canine.h"
#include "appliance.h"
#include "lion.h"

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
    qInfo() << "Episode 2, 3 lessons : ";
    QCoreApplication a(argc, argv);

    QObject q;

    Animal cat;
    Animal dog;
    Animal fish;

    cat.speak("meow");

    // episode 4
    qInfo() << "Episode 4 lessons : ";
    makeLaptops();

    // episode 5, 6 inheritance
    qInfo() << "Episode 5, 6 lessons (inheritence) : ";
    Animal animal;
    Mammal mammal;
    Canine canine;
    canine.bark();
    canine.hasBackBone();
    Feline feline;
    feline.meow();
    feline.hasBackBone();

    // episode 7 Interfaces : Define contrct between objects to avoid multiple inheritence
    Appliance machine3000;
    qInfo() << machine3000.cook();
    qInfo() << machine3000.freeze();
    qInfo() << machine3000.grill();

    // episode 8 Overriding : We want to change behaviour of base class
    Lion lion;
    lion.speak(); // will not use speak of animal
    lion.Feline::speak(); // will call the Feline class speak that is not directly in Feline so it uses animal speak
    lion.Animal::speak(); // will call the animal class speak

    return QCoreApplication::exec();
}
