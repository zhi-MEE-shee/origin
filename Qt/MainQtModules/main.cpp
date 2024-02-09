#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTcpSocket newTcpSocket;
    newTcpSocket.connectToHost("localhost", 2323);
    newTcpSocket.waitForDisconnected();

    QSqlDatabase newDB = QSqlDatabase::addDatabase("QSQLITE");
    newDB.setDatabaseName("books");
    newDB.removeDatabase("books");

    return a.exec();
}
