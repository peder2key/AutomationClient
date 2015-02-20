#ifndef PROCESSINCOMMINGDATA_H
#define PROCESSINCOMMINGDATA_H

#include <QObject>



class processIncommingData : public QObject
{
    Q_OBJECT
public:
    explicit processIncommingData(QObject *parent = 0);
    ~processIncommingData();

signals:

public slots:
};

#endif // PROCESSINCOMMINGDATA_H
