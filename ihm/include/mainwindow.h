#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
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
        void write_in_konsole(QString log) {_konsole->appendPlainText(log+"\n");}

    private:
        Ui::MainWindow *ui;
        QPlainTextEdit *_konsole;
        QPushButton *send_button;
        QLineEdit *_msg;

        ClientTcp* client;

    private slots:
        void connexion();
        void send();
        void msg_processing(QString msg);
};

#endif // MAINWINDOW_H
