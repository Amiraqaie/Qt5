#include <QCoreApplication>
#include "dog.h"
#include "cat.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QVariant>
#include "pet.h"

void test(QVariant value) //Copy is allowed
{
    qInfo() << value;

    int i = 0;
    bool ok = false;
    i = value.toInt(&ok);
    if(ok)
    {
        qInfo() << "INT" << i;
    }
    else
    {
        qInfo() << "Not a int!";
    }
}

void test(QString name) //COPY
{
    qInfo() << name;
}

 typedef QMap<QString,Pet*> petList;

petList createPets(int max)
{
    petList map;
    for(int i = 0; i < max; i++)
    {
        QString id = QString::number(i);
        Pet* pet = new Pet(); //notice the possible memory leak!
        pet->setAge(i * 3);
        pet->setName("Pet: " + id);
        map.insert(id,pet);
    }

    return map; //Notice the copy!
}

void listPets(petList pets) //Notice the copy
{
    foreach(QString key, pets.keys())
    {
        Pet* pet = pets.value(key);
        qInfo() << key << pet->name() << " is Age: " << pet->age();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // episode 1 : QObject
    Dog dog;
    dog.setObjectName("Fido");
    dog.chase(); // the sender will be null
    Cat cat;
    cat.setObjectName("Fluffy");
    QObject::connect(&dog, &Dog::bark, &cat, &Cat::scared);
    QObject::connect(&cat, &Cat::run, &dog, &Dog::chase);
    dog.bark();

    // episode 3 : QDate, QTime, QDatetime
    QDate today = QDate::currentDate();
    qInfo() << today;
    qInfo() << today.addYears(5).addMonths(3).addDays(1);
    qInfo() << "ISO Date : " << today.toString(Qt::DateFormat::ISODate);

    QTime now = QTime::currentTime();
    qInfo() << now;
    qInfo() << now.addSecs(10);
    qInfo() << "ISO Date : " << now.toString(Qt::DateFormat::ISODate);

    QDateTime current = QDateTime::currentDateTime();
    qInfo() << current;
    qInfo() << current.addYears(5).addMonths(3).addDays(1);
    qInfo() << "ISO Date : " << current.toString(Qt::DateFormat::ISODate);

    // episode 4 : QString
    QString name = "Bryan Cairns";
    qInfo() << name;
    qInfo() << name.mid(1,3);
    qInfo() << name.insert(0,"Mr. ");
    qInfo() << name.split(" ");
    int index = name.indexOf(" ");
    if(index > -1)
    {
        qInfo() << name.remove(0, index).trimmed();
    }
    QString title = "Teacher";
    QString full = name.trimmed() + " " + title;
    qInfo() << full;
    qInfo() << full.toUtf8();
    test(full);

    // episode 5 : QByteArray
    QString greeting = "Hello World!";
    QByteArray buffer(greeting.toUtf8());
    buffer.append("!");
    qInfo() << buffer;

    qInfo() << buffer.rightJustified(20,'.');
    qInfo() << buffer.at(buffer.length() - 1);

    QString modified(buffer);
    qInfo() << modified;

    qInfo() << buffer.toBase64();   //Basic encoding and decoding
    qInfo() << buffer.toHex();

    // episode 6 : QVarient
    QVariant value  = 1;
    QVariant value2 = "Hello World";

    test(value);
    test(value2);

    // episode 7 : QStringList
    QString data = "Hello world how are you";
    QStringList lst = data.split(" ");
    qInfo() << lst;

    foreach(QString str,lst)
    {
        qInfo() << str;
    }

    lst.sort(Qt::CaseInsensitive);
    qInfo() << lst;

    QString myvar = "Hello";
    if(lst.contains(myvar))
    {
        int index = lst.indexOf(myvar);
        qInfo() << lst.value(index);
    }

    // episode 8 : Qlist
    QList<QString> list = data.split(" ");

    foreach(QString word, list)
    {
        qInfo() << word;
    }

    QList<int> age({44,56,21,13});
    age.append(99);
    age.remove(1);
    qInfo() << age;

    foreach(int word, age)
    {
        qInfo() << word;
    }

    // episode 9 : QVector
    // QVector is an alias for QList.
    // In Qt 5 this used to be a different class
    // Now QVector and QList are the same class
    QVector<QString> vector = data.split(" ");
    foreach(QString word, list) {
        qInfo() << word;
    }

    QVector<int> ages({44,56,21,13});
    foreach(int age, ages) {
        qInfo() << age;
    }

    // episode 10 : QMap
    // The QMap class is a template class that provides an associative array
    petList pets = createPets(5);
    qInfo() << "Count:" << pets.count();
    listPets(pets);
    //    Pet* pet = new Pet(); //notice the possible memory leak!
    //    pet->setAge(99);
    //    pet->setName("BadKitty");
    //    pets.insert("1",pet);
    qDeleteAll(pets.values());
    pets.clear();
    qInfo() << "Count:" << pets.count();
    listPets(pets);

    return QCoreApplication::exec();
}
