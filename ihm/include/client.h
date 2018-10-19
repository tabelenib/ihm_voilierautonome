#ifndef CLIENT_H
#define CLIENT_H 1


#include <QObject>
#include <QtNetwork>
#include <QString>
#include <iostream>
#include <unistd.h>

#include "message.h"

using namespace std;

class ClientTcp : public QObject {
    Q_OBJECT
    public:
        ClientTcp(QString ip, quint16 port, QString _pseudo);
        ~ClientTcp();
        void run();
    public slots:
        void donneesRecues();
        void connecte();
        void deconnecte();
        void erreurSocket(QAbstractSocket::SocketError erreur);

    signals:
        void received_data(QString);

    private:
        // Ip du serveur
        QString serverIp;
        // Port utilisé par le serveur
        quint16 serverPort;
        // Socket
        QTcpSocket* soc;
        // Taille du message
        quint16 tailleMessage;
        // Pseudo de l'utilisateur
        QString pseudo;

        bool isRunning;
    public:
        // Method to send a message to the server
        void send(QString msg);
        bool get_isRunning(){return isRunning;}
};


#endif // !CLIENT_H
