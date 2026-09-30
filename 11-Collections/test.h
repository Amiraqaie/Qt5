#ifndef TEST_H
#define TEST_H

#include <QDebug>
#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();
signals:
};

#endif // TEST_H
