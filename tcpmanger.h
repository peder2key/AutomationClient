#ifndef TCPMANGER_H
#define TCPMANGER_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>

#include "setuptcpdialog.h"
#include "processincommingdata.h"


class TcpManger : public QObject
{
    Q_OBJECT
public:
    explicit TcpManger(QObject *parent = 0);
    ~TcpManger();
    void showSetupDialog();
    void connectToServer();
    void sendData(QByteArray SendSomeData);
    void sendRequest(quint16 blockSize, quint8 command, quint8 readOrWrite, quint16 elements);

signals:

private slots:
    void readyRead();
    void error(QAbstractSocket::SocketError socketError);

public slots:
    void newIpAndPort(QString ipAdress, quint16 portNumber);

private:
    SetupTcpDialog *mSetupTcpDialog;
    QTcpSocket *mTcpSocket;
    QHostAddress *IpAdress;
    processIncommingData *mProcessIncommingData;

    quint16 PortNumber;
    QString IpString;
};

#endif // TCPMANGER_H
