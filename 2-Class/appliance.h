#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <QObject>
#include "freezer.h"
#include "microwave.h"
#include "toaster.h"
#include <QDebug>

class Appliance : public QObject, public Freezer, public Toaster, public Microwave
{
    Q_OBJECT
public:
    explicit Appliance(QObject *parent = nullptr);

signals:

    // Microwave interface
public:
    bool cook();

    // Toaster interface
public:
    bool grill();

    // Freezer interface
public:
    bool freeze();
};

#endif // APPLIANCE_H
