#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr); // Magic!!! if parent is being deleted then the child will be removed
    ~Test();

    void doStuff();
signals:
};

#endif // TEST_H
