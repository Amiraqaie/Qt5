#include <QCoreApplication>
#include <QList>
#include <QVector>
#include <QSet>
#include <QMap>
#include <QStringList>
#include <QDebug>

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

    return QCoreApplication::exec();
}
