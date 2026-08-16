#include <QCoreApplication>
#include <QDebug>

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
    display(p); // the data is removed from heap so this can make app crash

    return QCoreApplication::exec();
}
