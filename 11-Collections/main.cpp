#include <QCoreApplication>
#include <QList>
#include <QVector>
#include <QSet>
#include <QMap>
#include <QStringList>
#include <QDebug>
#include <QSharedPointer>
#include "test.h"

typedef QMap<QString, QSharedPointer<Test>> TestMap;

void testListDeete()
{
    QList<Test*> list;
    for(int i = 0; i < 5; i++)
    {
        list.append(new Test());
    }

    qDeleteAll(list); // will call delete on all members
                        // this does not delete objects from the list itself!!!

    // qInfo() << list.at(0); // dangeling pointer => will crash
    list.clear();           // we should always clear the container after qDeleteAll
}

void testListAuto()
{
    QList<QSharedPointer<Test>> list;
    for(int i = 0; i < 5; i++)
    {
        QSharedPointer<Test> item(new Test());
        list.append(item);
    }
    list.removeAt(0);
    list.clear();    // it will automatically remove objects from heap
}

void testMapDelete()
{
    QMap<QString, Test*> map;
    for(int i = 0; i < 5; i++)
    {
        QString id = "ID-" + QString::number(i);
        map.insert(id, new Test());
    }
    qDeleteAll(map);// will call delete on all members
    // this does not delete objects from the list itself!!!
    map.clear(); // we should always clear the container after qDeleteAll
}

void testMapAuto()
{
    TestMap map;
    for(int i = 0; i < 5; i++)
    {
        QString id = "ID-" + QString::number(i);
        map.insert(id, QSharedPointer<Test> (new Test()));
    }
    map.clear(); // it will automatically remove objects from heap
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QList
    QList<int> list;
    list << 1 << 2 << 3;
    for(int i = 0; i < 5; i++)
    {
        list.append(i);
    }
    qInfo() << list;
    qInfo() << list.length();
    qInfo() << list.size();
    qInfo() << list.count();
    qInfo() << list.count(4);
    list.replace(2, 99);
    list.remove(3);
    QList<int> sliced = list.sliced(2, 3);

    // QVector is alias for QList
    QVector<int> vector;
    list << 1 << 2 << 3;

    // Qset has no order but very fast
    QSet<QString> people;
    people << "Bryan" << "Tammy" << "Chris" << "Heather";
    people.insert("Rango");
    foreach (QString person, people) {
        qInfo() << person;
    }
    qInfo() << people.contains("Bryan");

    // QMap
    QMap<QString, int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Tammy", 37);
    qInfo() << "keys : " << ages.keys();
    qInfo() << "values : " << ages.values();
    int bryanAge = ages["Bryan"];

    // QStringList
    QStringList names {"Bryan"};
    names << "Tammy";
    names.append("Rango");
    names.replaceInStrings("a", "@");
    qInfo() << names;
    QStringList filtered = names.filter("r");

    // qDeleteAll
    testListDeete();

    // QSharedPointer
    testListAuto();

    // qDelteAll with QMap
    testMapDelete();

    return QCoreApplication::exec();
}
