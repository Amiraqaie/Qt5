#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
    QString m_message;
public:
    explicit Test(QObject *parent = nullptr, bool test_timer = false);

    QString message() const;
    void setMessage(const QString &newMessage);

    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged FINAL)
    QTimer m_timer;
    int count;

public slots:
    // timer
    void timeout();

signals:
    void messageChanged(QString message);
};

#endif // TEST_H
