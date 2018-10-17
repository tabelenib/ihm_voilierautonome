#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->connexion, SIGNAL(clicked()), this, SLOT(connexion()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete client;
}

void MainWindow::connexion() {
    if (ui->connexion->text() == QString("Connexion")) {
        ui->connexion->setText("Déconnexion");
        client = new ClientTcp(QString("127.0.0.1"), 4000, QString("Etienne"));
    } else if (ui->connexion->text() == QString("Déconnexion")) {
        ui->connexion->setText("Connexion");
        delete client;
    }
}
