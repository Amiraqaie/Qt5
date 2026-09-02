#include <QCoreApplication>
#include <QDebug>
#include "temp.h"

template<typename T>
void print(T value)
{
    qInfo() << "your input is : " << value;
}

template<class T, class F>
T add(T value1, F value2)
{
    return value1 + value2;
}

template<typename T>
void display(T value)
{
    qInfo() << value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // episode 4 : Template example
    print<int>(1);
    print<double>(2.656);
    print<QString>("Hello World");



    // episode 5 : Template Isuues ==> always declare the data types!!!
    qInfo() << add<int, double>(1, 2.789);
    qInfo() << add(1, true);
    qInfo() << add(true, 1);
    // qInfo() << add(1, "bryan"); // this will not going to compile
    qInfo() << add("bryan", 1);



    // episode 6 : Template class
    Temp<int> intCalc;
    qInfo() << intCalc.add(1, 3);
    Temp<double> doubleCalc;
    qInfo() << doubleCalc.add(1.3, 3.56);
    Temp<QString> stringCalc;
    qInfo() << stringCalc.add("ali", "reza");


    // episode 7 : Templates and QObjects => we have to use pointers
    // Qt template classes does not inheritate QObject and can be copied
    display<double>(3.14);
    display<QString>("Hellooooo!!!");
    QObject obj;
    // display<QObject>(obj); // we can not copy qobjects
    display<QObject*>(&obj);


    return QCoreApplication::exec();
}
