#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mTcpManger = new TcpManger(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionServer_Connection_triggered()
{
    mTcpManger->showSetupDialog();
}


void MainWindow::on_pushButton_clicked()
{
    QByteArray data;
    data.append("Hello Geir");
   mTcpManger->sendData(data);
}

void MainWindow::on_pushButtonSend_clicked()
{
    QByteArray data;
    data.append(ui->lineEdit->text());
    mTcpManger->sendData(data);

}
