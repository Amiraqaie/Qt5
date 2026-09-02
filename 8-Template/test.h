#ifndef TEST_H
#define TEST_H

#include <QObject>

// template<class T>
class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    // T add(T value1, T value2) {return value1 + value2;}      // Template class is not allowed to be used by QObject

signals:
};

#endif // TEST_H
