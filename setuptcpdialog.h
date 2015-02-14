#ifndef SETUPTCPDIALOG_H
#define SETUPTCPDIALOG_H

#include <QDialog>

namespace Ui {
class SetupTcpDialog;
}

class SetupTcpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetupTcpDialog(QWidget *parent = 0);
    ~SetupTcpDialog();

private:
    Ui::SetupTcpDialog *ui;
};

#endif // SETUPTCPDIALOG_H
