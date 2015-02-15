#ifndef TCPMANGER_H
#define TCPMANGER_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>

#include "setuptcpdialog.h"


class TcpManger : public QObject
{
    Q_OBJECT
public:
    explicit TcpManger(QObject *parent = 0);
    ~TcpManger();
    void showSetupDialog();
    void connectToServer();
    void sendData(QByteArray SendSomeData);

signals:

private slots:
    void dataFromServer();

public slots:
    void newIpAndPort(QString ipAdress, quint16 portNumber);

private:
    SetupTcpDialog *mSetupTcpDialog;
    QTcpSocket *mTcpSocket;
    QHostAddress *IpAdress;

    quint16 PortNumber;
    QString IpString;
};

#endif // TCPMANGER_H
