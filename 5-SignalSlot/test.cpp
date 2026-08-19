#include "test.h"

QString Test::message() const
{
    return m_message;
}

void Test::setMessage(const QString &newMessage)
{
    emit messageChanged(newMessage);
    m_message = newMessage;
}

void Test::timeout()
{
    if (count++ < 3)
    {
        qInfo() << count << " Timer Test!!!";

    } else
    {
        m_timer.stop();
    }
}

Test::Test(QObject *parent, bool test_timer)
    : QObject{parent}
{
    // connect timer
    connect(&m_timer, &QTimer::timeout, this, &Test::timeout);
    count = 0;

    if (test_timer)
    {
        m_timer.setInterval(1000);
        m_timer.start();
    }
}

