#include "tcpmanger.h"

TcpManger::TcpManger(QObject *parent) : QObject(parent)
{
    mSetupTcpDialog = new SetupTcpDialog();
    connect(mSetupTcpDialog, SIGNAL(newIpAndPort(QString,quint16)),this, SLOT(newIpAndPort(QString,quint16)));

    mTcpSocket = new QTcpSocket(this);
    connect(mTcpSocket, SIGNAL(readyRead()),this, SLOT(dataFromServer()));
    IpAdress = new QHostAddress();

    IpString = mSetupTcpDialog->getIpAdress();
    PortNumber = mSetupTcpDialog->getPortNumber();

    connectToServer();
    qDebug() << IpString << PortNumber;

}

TcpManger::~TcpManger()
{

}

void TcpManger::showSetupDialog()
{

    mSetupTcpDialog->show();
    mSetupTcpDialog->setModal(true);

}

void TcpManger::connectToServer()
{
    try
    {
        IpAdress->setAddress(IpString);
        mTcpSocket->connectToHost(*IpAdress, PortNumber, QIODevice::ReadWrite);
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



// /////////////////////////////////////////////////
//  PUBLIC SLOTS
// /////////////////////////////////////////////////

void TcpManger::newIpAndPort(QString ipAdress, quint16 portNumber)
{
    mTcpSocket->disconnectFromHost();
    IpAdress->clear();
    IpString = ipAdress;
    PortNumber = portNumber;
    connectToServer();


    qDebug() << IpString << PortNumber;

}



// /////////////////////////////////////////////////
//  PUBLIC SLOTS END
// /////////////////////////////////////////////////
