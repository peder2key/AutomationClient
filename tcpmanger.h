#ifndef TCPMANGER_H
#define TCPMANGER_H

#include <QThread>

class TcpManger : public QThread
{
public:
    TcpManger();
    ~TcpManger();
};

#endif // TCPMANGER_H
