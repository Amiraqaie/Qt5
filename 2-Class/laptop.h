#ifndef LAPTOP_H
#define LAPTOP_H

#include <QObject>
#include <QDebug>
#include <QString>

class Laptop : public QObject
{
    Q_OBJECT
public:
    explicit Laptop(QObject *parent = nullptr, QString name = "");

    // Deconstructor
    ~Laptop();

    double weight;
    QString name;
    double asKilo();
    void test();

signals:
};

#endif // LAPTOP_H
