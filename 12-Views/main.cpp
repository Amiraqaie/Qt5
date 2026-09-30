#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>
#include <QByteArrayView>
#include <QString>
#include <QStringView>

// ***************** //
// View means Read Only//
// ****************** //


void display(QByteArrayView view)
{
    qInfo() << view;
    // we can not modify the view
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QByte Array view
    QByteArray bytes("Hello world how are you?");
    QByteArrayView view(bytes);

    display(view);

    // QString View
    QString Data = "Hello world how are you?";
    QStringView string_view(Data);
    qInfo() << string_view; // we can not modify this as well

    return a.exec();
}
