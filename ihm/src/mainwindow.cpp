#include "./../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    send_button = new QPushButton(this);
    send_button->setGeometry(100,200,180,50);
    send_button->setText("Send message to serveur");
    _msg = new QLineEdit(this);
    _msg->setGeometry(140,175,100,20);

    connect(ui->connexion, SIGNAL(clicked()), this, SLOT(connexion()));
    connect(send_button, SIGNAL(clicked()), this, SLOT(send()));

}

MainWindow::~MainWindow() {
    delete ui;
    delete client;
}

void MainWindow::connexion() {
    if (ui->connexion->text() == QString("Connexion")) {
        client = new ClientTcp(QString("127.0.0.1"), 4000, QString("Etienne"));
        if (client->get_isRunning()){ui->connexion->setText("Déconnexion");}
    } else if (ui->connexion->text() == QString("Déconnexion")) {
        ui->connexion->setText("Connexion");
        delete client;
    }
}

void MainWindow::send() {
    if(client->get_isRunning()){
        client->send(get_msg());
    }
    else
        ui->connexion->setText("Connexion");
}
