#include <QCoreApplication>



#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothsocket.h>

#include <string.h>
#include <unistd.h>

#include <QBluetoothDeviceInfo>
#include <QDebug>
//#include <QObject>


//using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBluetoothLocalDevice localDevice;
    QBluetoothAddress adapterAddress = localDevice.address();


    QBluetoothSocket *socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);


    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress("98:D3:61:F5:D5:65"), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);

    //socket->connectToService(QBluetoothAddress("00:3D:E8:4C:8C:2F"), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);

    //socket->open(QIODevice::ReadWrite);

    while ( socket->state() != QBluetoothSocket::ConnectedState )
    {
        //socket->disconnectFromService();
        //socket->connectToService(QBluetoothAddress("98:D3:61:F5:D5:65"), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);
        //QByteArray line = socket->readLine();
        //usleep(1000000);
        printf("%d == %d == %d",socket->state(), QBluetoothSocket::ConnectingState, socket->error());

        //QString addy = localDevice.name();
        //qDebug() << "pp" << addy;

        printf( " -- %d -- %d ", socket->canReadLine(), socket->currentReadChannel() );
        printf(" - waiting \n");
        socket->localAddress();
        while (socket->canReadLine()) {
                QByteArray line = socket->readLine();
                QString::fromUtf8(line.constData(), line.length());
                printf("here2\n");
            }

        //char* y = "";
        //socket->read(y, 5);
        //const char* text2 = "p";
        //socket->write(text2);
        //qDebug() << socket->peerName() << socket->readAll();
        //printf("%s\n", y);
        //printf(line);
    }

/*
    QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
    agent->start();
    QBluetoothSocket * socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);

    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));

    socket->connectToService(QBluetoothAddress("98:D3:61:F5:D5:65"), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);
    //socket->connectToService(QBluetoothAddress("98:D3:61:F5:D5:65"), 1);


    usleep(5000000);

    //std::string message = "test string";
    //QByteArray text = message.toUtf8() + '\n';

    QString message = "test string";
    QByteArray text = message.toUtf8() + '\r' + '\n';

    socket->open(QIODevice::ReadWrite);
    //socket->open();
    socket->openMode();
socket->peerName();
char* xx = "l";
//socket->read(xx,1);
//printf(xx);

    while ( socket->state() != QBluetoothSocket::ConnectedState )
    {
        const char* text2 = "p";
        socket->write(text2);
        usleep(1000000);
        //int x = socket->state();
        printf("%d == %d == %d",socket->state(), QBluetoothSocket::ConnectingState, socket->error());
        printf(" - waiting \n");
    }

while(true)
{
    const char* text2 = "p";
    socket->write(text2);
    QString s = socket->peerName();
    qDebug() << s << socket->readAll();
    printf(socket->readAll());



    usleep(1000000);
}
*/
    return a.exec();
}
