#ifndef RACECAR_H
#define RACECAR_H

#include <QObject>
#include "car.h"

class RaceCar : public Car
{
    Q_OBJECT
public:
    explicit RaceCar(QObject *parent = nullptr);

    bool superCharger = true;
    void goFast() {qInfo() << "Go very Fast with car ...";};

signals:
};

#endif // RACECAR_H
