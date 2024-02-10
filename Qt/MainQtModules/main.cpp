#include <QCoreApplication>
#include <QSqlDatabase>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket newTcpSocket;
    newTcpSocket.connectToHost("localhost", 2323);
    newTcpSocket.waitForDisconnected();

    QSqlDatabase newDB = QSqlDatabase::addDatabase("QSQLITE");
    newDB.setDatabaseName("books");
    newDB.removeDatabase("books");

    return a.exec();
}
