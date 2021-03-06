#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>


#include "tcpmanger.h"
#include "viewalldevicesdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionServer_Connection_triggered();
    void on_pushButton_clicked();
    void on_pushButtonSend_clicked();
    void on_actionShow_All_Devices_triggered();

private:
    Ui::MainWindow *ui;
    TcpManger *mTcpManger;
    ViewAllDevicesDialog *mViewAllDevicesDialig;
};

#endif // MAINWINDOW_H
