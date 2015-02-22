#include "viewalldevicesdialog.h"
#include "ui_viewalldevicesdialog.h"

ViewAllDevicesDialog::ViewAllDevicesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAllDevicesDialog)
{
    ui->setupUi(this);

     horizontalView << tr("Name") << tr("Type") << tr("Subtype") << tr("Status");
     ui->tableWidget->setColumnCount(4);
     ui->tableWidget->setHorizontalHeaderLabels(horizontalView);
     ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

ViewAllDevicesDialog::~ViewAllDevicesDialog()
{
    delete ui;
}
