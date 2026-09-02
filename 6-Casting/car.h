#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QDebug>

class Car : public QObject
{
    Q_OBJECT
public:
    explicit Car(QObject *parent = nullptr);

    QString color = "white";
    int tires = 4;
    void drive() {qInfo() << "Driving the car ...";};
    void stop() {qInfo() << "Stoping the car ...";};

signals:
};

#endif // CAR_H
