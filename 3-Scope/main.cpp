#include <QCoreApplication>
#include <QDebug>
#include "animal.h"

QString global_name;

void global_test()
{
    qInfo() << global_name;
}
void test(int number)
{
    number = 50;
    qInfo() << "2 - number : " << &number;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // episode 6 : lexical scope in functions
    int number = 75;
    qInfo() << "1 - number : " << &number;

    test(number);

    {
        number = 1000;
    }

    qInfo() << "3 - number : " << &number;

    // episode 7 : class scope
    QString name = "Bryan";     // Qstring is not Qobject and can be copied
    qInfo() << "My name is at : " << &name;
    Animal cat1(&a, name);
    Animal cat2(&a, "Fluufy");

    cat1.SayHello();
    cat2.SayHello();

    // episode 8 : global scope , Do not do this at home
    global_name = "bob";
    qInfo() << global_name;

    {
        QString global_name = "Tom";

        qInfo() << global_name; // tom
        qInfo() << ::global_name; // bob

        global_test(); // bob
    }

    global_test(); // bob

    // episode 9 : static scope in class
    qInfo() << "number of animals : " << Animal::count;

    // episode 10 : static functions in class
    Animal::doStuff();


    return QCoreApplication::exec();
}
