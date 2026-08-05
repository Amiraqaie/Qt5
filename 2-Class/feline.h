#ifndef FELINE_H
#define FELINE_H

#include <QObject>
#include "mammal.h"

class Feline : public Mammal
{
    Q_OBJECT
public:
    explicit Feline(QObject *parent = nullptr);
    void meow() {qInfo() << "meowww  ... ";}
signals:
};

#endif // FELINE_H
