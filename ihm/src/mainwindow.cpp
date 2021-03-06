#include "./../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    send_button = new QPushButton(this);
    send_button->setGeometry(100,200,180,50);
    send_button->setText("Send message to serveur");
    _msg = new QLineEdit(this);
    _msg->setGeometry(140,175,100,20);
    _konsole = new QPlainTextEdit(this);
    _konsole->setGeometry(40,325,300,200);
    _konsole->setReadOnly(true);

    connect(ui->connexion, SIGNAL(clicked()), this, SLOT(connexion()));
    connect(send_button, SIGNAL(clicked()), this, SLOT(send()));

}

MainWindow::~MainWindow() {
    delete ui;
    delete client;
    delete _konsole;
    delete _msg;
    delete send_button;
}

void MainWindow::connexion() {
    if (ui->connexion->text() == QString("Connexion")) {
        client = new ClientTcp(QString("127.0.0.1"), 4000, QString("Etienne"));
        connect(client, SIGNAL(received_data(QString)), this, SLOT(msg_processing(QString)));
        ui->connexion->setText("Déconnexion");
    } else if (ui->connexion->text() == QString("Déconnexion")) {
        ui->connexion->setText("Connexion");
        delete client;
        client = nullptr;
    }
}

void MainWindow::send() {
    if (client)
        client->send(get_msg());
}


void MainWindow::msg_processing(QString msg){
    write_in_konsole(msg);
}
