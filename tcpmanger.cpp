#include "tcpmanger.h"

TcpManger::TcpManger(QObject *parent) : QObject(parent)
{
    mSetupTcpDialog = new SetupTcpDialog();
    connect(mSetupTcpDialog, SIGNAL(newIpAndPort(QString,quint16)),this, SLOT(newIpAndPort(QString,quint16)));

    mTcpSocket = new QTcpSocket(this);
    connect(mTcpSocket, SIGNAL(readyRead()),this, SLOT(dataFromServer()));
    connect(mTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error(QAbstractSocket::SocketError)));

    IpAdress = new QHostAddress();

   // QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();


    IpString = mSetupTcpDialog->getIpAdress();
    PortNumber = mSetupTcpDialog->getPortNumber();

    connectToServer();


}

TcpManger::~TcpManger()
{

}

void TcpManger::showSetupDialog()
{

    mSetupTcpDialog->show();
    mSetupTcpDialog->setModal(true);
    mTcpSocket->abort();

}

void TcpManger::connectToServer()
{
    try
    {
        //IpAdress->setAddress(IpString);
        mTcpSocket->connectToHost(*IpAdress, PortNumber, QIODevice::ReadWrite);
        //mTcpSocket->connectToHost(IpString,PortNumber, QIODevice::ReadWrite);
    }
    catch(...)
    {
       QMessageBox::warning(qobject_cast<QWidget *>(parent()), "Error Connecting", "Could Not Connect To The Server");
    }


    qDebug() << "We are connected: " << IpAdress << "and Port: " << PortNumber;

}

void TcpManger::sendData(QByteArray SendSomeData)
{
    if(mTcpSocket->isOpen())
    {
    mTcpSocket->write(SendSomeData);
    }
    else
    {
        QMessageBox::warning(qobject_cast<QWidget *>(parent()), "No Connection Error", "We are not connected to the server\nCheck IP and Port");
    }

}

void TcpManger::dataFromServer()
{
    qDebug() << mTcpSocket->readAll();

}

void TcpManger::error(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(qobject_cast<QWidget *>(parent()), tr("Client"), tr("The host was not found. Please check the host name and port settings."));


        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(qobject_cast<QWidget *>(parent()), tr("Client"), tr("The connection was refused by the Server. "
                                    "Make sure the WD electronic server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(qobject_cast<QWidget *>(parent()), tr("Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(mTcpSocket->errorString()));
    }

}



// /////////////////////////////////////////////////
//  PUBLIC SLOTS
// /////////////////////////////////////////////////

void TcpManger::newIpAndPort(QString ipAdress, quint16 portNumber)
{

    IpAdress->clear();
    IpString = ipAdress;
    PortNumber = portNumber;
    connectToServer();


    qDebug() << IpString << PortNumber;

}



// /////////////////////////////////////////////////
//  PUBLIC SLOTS END
// /////////////////////////////////////////////////
