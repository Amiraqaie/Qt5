/*
    What
    qobject_cast

    Why
    Casting is hard, we want to make it simple

    How
    use the qobject_cast function

    Remember:
    The implicit cast is C++ doing it for us
    The explicit cast is us telling C++ what to do
    The static_cast operator performs a nonpolymorphic cast.
    The dynamic_cast operator ensures inheritence is good (safe type conversion between polymorphic classes)
    The reinterpret_cast operator types to convert it to a different type
    The qobject_cast works with QObjects and takes away a lot of the complexity
*/

#include <QCoreApplication>
#include "car.h"
#include "racecar.h"
#include "feline.h"

void testDrive(Car* obj)
{
    obj->drive();
    obj->stop();
}

void goFast(RaceCar* obj)
{
    obj->drive();
    obj->stop();
    obj->goFast();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // episode 4 : implicit casting
    double value = 5.75;
    int age = value; // implicatly convert double to an integer (5)



    // episode 5 :explicit casting (more trusted in programming)
    age = (int) value;



    // episode 6 : dynamic casting can done in DownCasting and Upcasting
    RaceCar* player1 = new RaceCar(&a);
    testDrive(player1); // this is implicit conversion with is dangerous
    Car* car = dynamic_cast<Car*>(player1); // this is dynamic casting and is correct way (Explicitly casted)
    if (car)
        testDrive(car);

    Feline* cat = new Feline(&a);
    Car* catcar = dynamic_cast<Car*>(cat); // we can not cast a car to a cat => no pointer will be generated
    if (catcar)
        testDrive(catcar);

    // Note : implicit casting vs dynamic casting (up casting case)
    // Converting derived to base is safe and usually does not require dynamic_cast
    // in case of DownCasting we should always use dynamic_cast for safty
    Car* car_implicit = player1;
    testDrive(car_implicit);

    // episode 7 : static casting (it can cast a base class pointer to derived class pointer)
    Car* newCar = new Car(&a);
    // goFast(newCar) // no implicit casting can occur from base to derived class pointer => not possible
    goFast((RaceCar*) newCar); // explicit casting works but its dangerous (dont do that)
    RaceCar* racer = static_cast<RaceCar*>(newCar);
    if (racer)
        goFast(racer);
    // Feline* catcar2 = static_cast<Feline*>(newCar); // not going to work


    // episode 8, 9 : Reinterpret casting (do not do this very dangerous) and qObject Casting
    Car* dynamicCar = dynamic_cast<Car*>(player1);
    if (dynamicCar)
        testDrive(dynamicCar);
    Car* staticCar = static_cast<Car*>(player1);
    if (staticCar)
        testDrive(dynamicCar);
    int* interpretedInt = reinterpret_cast<int*>(player1); // does not change memor at all
    if (interpretedInt)
        qInfo() << "Pointer : " << interpretedInt << " = " << *interpretedInt;
    Car* qobjectCar = qobject_cast<Car*>(player1); // can cas base->derived and derived->base
    if(qobjectCar)
        testDrive(qobjectCar);
    RaceCar* qobjectRaceCar = qobject_cast<RaceCar*>(qobjectCar); // can cas base->derived and derived->base (can  not work with non qobjects)
    if(qobjectRaceCar)
        goFast(qobjectRaceCar);

    return QCoreApplication::exec();
}
