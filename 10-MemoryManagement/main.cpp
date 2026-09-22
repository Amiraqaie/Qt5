#include <QObject>
#include <QDebug>
#include <qscopedpointer.h>
#include <QSharedPointer>

class MyObject : public QObject
{
public:
    MyObject(const QString& name, QObject* parent = nullptr)
        : QObject(parent), name(name)
    {
        qDebug() << name << "created";
    }

    ~MyObject()
    {
        qDebug() << name << "destroyed";
    }

private:
    QString name;
};

void CreateParentChild()
{
    MyObject* parent = new MyObject("Parent");
    MyObject* child  = new MyObject("Child", parent);

    qDebug() << "Memory Leanks ..."; // pointers will be removed not the actual object => so deconstructor will not be called
}

MyObject* CreateParentChildPtr()
{
    MyObject* parent = new MyObject("Parent");
    MyObject* child  = new MyObject("Child", parent);

    qDebug() << "No Memory Leak ...";
    return parent;
}

std::unique_ptr<MyObject> CreateParentChildSmart()
{
    std::unique_ptr<MyObject> parent = std::make_unique<MyObject>("Parent");
    MyObject* child  = new MyObject("Child", parent.get());

    qDebug() << "No Memory Leak in smart pointer ..."; // parent automatically will be removed
    return parent; // return ownership :  this means that parent will be removed at the end of scope but with "return expression" it does not remove the parent from heap
                    // it instead will return the ownership the smartParent in main function scope
                    // if we dont call the "return parent", this will cause object being removed from heap
}

void QScopedPtr()
{
    QScopedPointer<MyObject> sp(new MyObject("My Object"));
    sp->setObjectName("My scoped object");
    qInfo() << "Scoped pointer : " << &sp;
    // at the end of scope the Qobject will be removed by removing the sp
    // note that QScopedPointer can not be returned
}

QSharedPointer<MyObject> QSharedPtr()
{
    QSharedPointer<MyObject> sp(new MyObject("My shared Object"));
    sp->setObjectName("My shared object");
    qInfo() << "Shared pointer : " << &sp;
    // at the end of scope the Qobject will be removed by removing the sp unless we return it
    return sp;
}

int main()
{
    // Memory leak example
    CreateParentChild();

    // Tree Handeling Example
    MyObject* parent = CreateParentChildPtr();
    delete parent; // child will be removed too

    // smart Pointer
    std::unique_ptr<MyObject> smartParent = CreateParentChildSmart();   // get the ownership of unique pt
                                                                        // at the end of main function the pointer will be removed and call the
                                                                        // deconstructor automatically

    // Qscoped pointer
    QScopedPtr();

    // QSharedPointer => can return the ownership
    QSharedPointer<MyObject> sp = QSharedPtr(); // get the ownership of unique pt
                                                // at the end of main function the pointer will be removed and call the
                                                // deconstructor automatically

    qDebug() << "Done";
}