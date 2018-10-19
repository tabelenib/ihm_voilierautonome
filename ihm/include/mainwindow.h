#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "client.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        QString get_msg(){return _msg->text();}

    private:
        Ui::MainWindow *ui;
        QPushButton *send_button;
        QLineEdit *_msg;

        ClientTcp* client;

    private slots:
        void connexion();
        void send();
};

#endif // MAINWINDOW_H
