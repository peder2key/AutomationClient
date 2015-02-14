#include "setuptcpdialog.h"
#include "ui_setuptcpdialog.h"

SetupTcpDialog::SetupTcpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupTcpDialog)
{
    ui->setupUi(this);
}

SetupTcpDialog::~SetupTcpDialog()
{
    delete ui;
}
