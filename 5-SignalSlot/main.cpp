#include <QCoreApplication>
#include "source.h"
#include "destination.h"
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"
#include "test.h"
#include "watcher.h"
#include <QVariant>
#include <QTimer>
#include "dog.h"
#include "owner.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // episode 4 : connecting a signal to slot
    Source src;
    Destination des;
    QObject::connect(&src, &Source::mySignal, &des, &Destination::mySlot);

    src.test();

    // episode 5 : Disconnecting
    Radio boombox;
    Station* channels[3];

    channels[0] = new Station(&boombox, 94, "Rock and Roll"); // if parent (radio) is deleted then the child Qobject will be removed auto => no need of delete manually
    channels[1] = new Station(&boombox, 87, "Hip Hop");
    channels[2] = new Station(&boombox, 104, "News");

    QObject::connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection); // should use the "Qt::QueuedConnection" not the auto mode

    QTextStream qtin(stdin);

    do
    {
        qInfo() << "Enter on, off, test or quit";
        QString line = qtin.readLine().trimmed().toUpper();

        if (qtin.atEnd())
        {
            qInfo() << "No stdin available (EOF).";
            break;
        }

        if (line == "ON")
        {
            qInfo() << "Turning Radio on";
            for (int i = 0; i < 3; i++)
            {
                QObject::connect(channels[i], &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio is on";
        }

        if (line == "OFF")
        {
            qInfo() << "Turning Radio off";
            for (int i = 0; i < 3; i++)
            {
                QObject::disconnect(channels[i], &Station::send, &boombox, &Radio::listen);
            }
            qInfo() << "Radio is off";
        }

        if (line == "TEST")
        {
            qInfo() << "Testing";
            for (int i = 0; i < 3; i++)
            {
                channels[i]->broadcast("BroadCsting live!");
            }
            qInfo() << "Test Completed";
        }


        if (line == "QUIT")
        {
            qInfo() << "QUIT";
            // emit boombox.quit();
            break;
        }

    } while(true);

    // Toturial pointer to instance-function of a class for understanding "QObject::connect(channels[i], &Station::send, &boombox, &Radio::listen);"
    class Example {
    public:
        void instanceMethod() {
        }
    };
    void (Example::*ptr)() = &Example::instanceMethod;
    Example e;
    (e.*ptr)();

    // episode 6 : Q_property
    Test tester;
    Watcher destination;
    QObject::connect(&tester, &Test::messageChanged, &destination, &Watcher::messageChanged);

    tester.setProperty("message", QVariant("Hello World"));
    tester.setMessage("testing");


    // episoed 7 : Timer example
    Test timer_test(&a, true);

    // episode 8 : Dog example
    Owner owner;
    Dog dog;
    for (int i = 0; i < 10; i++)
        // QObject::connect(&owner, &Owner::treats, &dog, &Dog::treats); // AutoConnection
        // QObject::connect(&owner, &Owner::treats, &dog, &Dog::treats, Qt::QueuedConnection); // Qued
        QObject::connect(&owner, &Owner::treats, &dog, &Dog::treats, Qt::UniqueConnection); // Qued
    owner.giveSnacks();

    return QCoreApplication::exec();
}
