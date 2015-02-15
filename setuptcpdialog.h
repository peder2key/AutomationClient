#ifndef SETUPTCPDIALOG_H
#define SETUPTCPDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QDebug>


namespace Ui {
class SetupTcpDialog;
}

class SetupTcpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupTcpDialog(QWidget *parent = 0);
    ~SetupTcpDialog();

    QString getIpAdress() const;
    void setIpAdress(const QString &value);

    quint16 getPortNumber() const;
    void setPortNumber(const quint16 &value);

private slots:
    void on_pushButton_clicked();
    void on_checkBox_clicked();

    void on_pushButton_2_clicked();

signals:
    void newIpAndPort(QString ipAdress, quint16 portNumber);

private:
    Ui::SetupTcpDialog *ui;
    void setDefaultValue();
    void updateIpAndPort();
    QString ipAdress;
    quint16 portNumber;

    QString defaultIpAdress;
    quint16 defaultPortNumber;
};

#endif // SETUPTCPDIALOG_H
