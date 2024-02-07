#ifndef SKULLKINGSERVER_H
#define SKULLKINGSERVER_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <fstream>
#include <iostream>
#include <map>
#include "MyClasses/king.h"
#include "MyClasses/deck.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class SkullKingServer;
}
QT_END_NAMESPACE

class SkullKingServer : public QDialog
{
    Q_OBJECT

public:
    SkullKingServer(QWidget *parent = nullptr);
    ~SkullKingServer();

private slots:
    void on_Ok_clicked();

    void newConnection();
    void appendToSocketList(QTcpSocket *socket);
    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);

    void sendSignal(QTcpSocket *socket, QString signal);
    void sendFile(QTcpSocket *socket, QString filePath, QString signal);

    void start_game();
    void start_round(QTcpSocket *qts, int r);
    void play_card(QTcpSocket *qts);

private:
    Ui::SkullKingServer *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    int client_number;
    unordered_map<QTcpSocket *, King> clients;
    Deck deck;
};
#endif // SKULLKINGSERVER_H
