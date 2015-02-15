#include "setuptcpdialog.h"
#include "ui_setuptcpdialog.h"

SetupTcpDialog::SetupTcpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupTcpDialog)
{
    ui->setupUi(this);
    ui->lineEditIPAdress->setInputMask("000.000.000.000");

    defaultIpAdress = "10.10.100.254";
    defaultPortNumber = 8899;

    setIpAdress(defaultIpAdress);
    setPortNumber(defaultPortNumber);
    setDefaultValue();

    ui->checkBox->setChecked(true);

}

SetupTcpDialog::~SetupTcpDialog()
{
    delete ui;
}

void SetupTcpDialog::on_pushButton_clicked()
{
    updateIpAndPort();
    ipAdress = ui->lineEditIPAdress->text();
    portNumber = ui->lineEditPortNumber->text().toInt();
    emit newIpAndPort(ipAdress, portNumber);
    this->hide();

}

void SetupTcpDialog::on_checkBox_clicked()
{
    setDefaultValue();

}

void SetupTcpDialog::setDefaultValue()
{
    if(ui->lineEditIPAdress->isEnabled())
    {
        ui->lineEditIPAdress->setEnabled(false);
        ui->lineEditPortNumber->setEnabled(false);
        ui->lineEditIPAdress->setText(defaultIpAdress);
        ui->lineEditPortNumber->setText(QString::number(defaultPortNumber));

        ipAdress = ui->lineEditIPAdress->text();
        portNumber = ui->lineEditPortNumber->text().toInt();

    }
    else
    {
        ui->lineEditIPAdress->setEnabled(true);
        ui->lineEditPortNumber->setEnabled(true);

    }

}

void SetupTcpDialog::updateIpAndPort()
{
    ipAdress = ui->lineEditIPAdress->text();
    portNumber = ui->lineEditPortNumber->text().toInt();

}


quint16 SetupTcpDialog::getPortNumber() const
{
    return portNumber;
}

void SetupTcpDialog::setPortNumber(const quint16 &value)
{
    portNumber = value;
}

QString SetupTcpDialog::getIpAdress() const
{
    return ipAdress;
}

void SetupTcpDialog::setIpAdress(const QString &value)
{
    ipAdress = value;
}



void SetupTcpDialog::on_pushButton_2_clicked()
{
    this->hide();
}
