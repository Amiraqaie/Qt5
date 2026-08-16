#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "child.h"

void test(QString value)
{
    // copied in stack
    qInfo() << &value << "Size : " << value.length();
    // destroyed from stack
}

void test_ptr(QString *value)
{
    // pointer is copied on stack but the actual value is on heap
    qInfo() << value << "Size : " << value->length();
    qInfo() << &value << "Size : " << sizeof(value); // a pointer itself is a object and has address on stack
    // destry just pointer not the value itself
}

void display(QString *p)
{
    qInfo() << "pointer" << p;
    qInfo() << "address" << &p;
    qInfo() << "data" << *p;
}

void wow()
{
    // Automatic memory managment
    std::unique_ptr<Test> t(new Test());
    t->doStuff();

    // pointer will automatically deleted
}

void test(QObject object)
{
    qInfo() << &object << Q_FUNC_INFO;
}

void test_ptr(QObject *object)
{
    qInfo() << object << Q_FUNC_INFO;
}

// QObject get_object()
// {
//     QObject o;
//     return o; // can not return a copy
// }

// QObject* get_object()
// {
//     QObject o;
//     return &o; // o will be removed from stack and pointer will point to a removed object bad!!!
// }

QObject* get_object()
{
    QObject *o = new QObject();
    return o; // o will not be removed from Heap and pointer will point to a good object
    // this can create memory leak if not calling delete
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // episode 3 : pointers vs copies
    QString name = "Bryan";
    qInfo() << &name << "Size : " << name.length();
    test(name); // same size but diffrent adress
    test_ptr(&name); // c++ converts &name to a pointer by copy constructor of its pointer automatically

    // episode 4 : pointer memory managment
    QString* p = new QString("Hello"); // create var on Heap
    display(p);
    delete p;
    // display(p); // the data is removed from heap so this can make app crash

    // episode 5 : automatic memory managment
    wow();

    // episode 6 : Qobject parent child relationship
    Test* parent = new Test();
    Child* child = new Child(parent);
    delete parent; // child will be deconstructed

    // episode 7 : Qobject cannot be copied because of signals and slots concept
    QObject* q_ptr = get_object();
    test_ptr(q_ptr);
    delete q_ptr; // you are responsable for deleting this object from HEAP!!!

    return QCoreApplication::exec();
}
