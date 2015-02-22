#ifndef VIEWALLDEVICESDIALOG_H
#define VIEWALLDEVICESDIALOG_H

#include <QDialog>

typedef struct DATA_FOR_TABLE
{

    QString name;
    QString type;
    QString subtype;
    QString Status;


}DATA_TABLE;

namespace Ui {
class ViewAllDevicesDialog;
}

class ViewAllDevicesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAllDevicesDialog(QWidget *parent = 0);
    ~ViewAllDevicesDialog();

private:
    Ui::ViewAllDevicesDialog *ui;
    QStringList horizontalView;
};

#endif // VIEWALLDEVICESDIALOG_H
