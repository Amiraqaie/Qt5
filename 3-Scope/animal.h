#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>
#include <QString>


class Animal : public QObject
{
public:
    explicit Animal(QObject *parent = nullptr, QString name="");
    ~Animal();

    QString name;
    void SayHello();
    static int count;

    static void doStuff();
};

#endif // ANIMAL_H
