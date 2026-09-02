#ifndef DOG_H
#define DOG_H

#include <QObject>
#include <QDebug>

class Dog : public QObject
{
    Q_OBJECT
public:
    explicit Dog(QObject *parent = nullptr);

public slots:
    void chase();

signals:
    void bark();
};

#endif // DOG_H
