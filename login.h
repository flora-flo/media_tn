#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <QMessageBox>
#include "mainwindow.h"
#include "user.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    MainWindow *mainwindow;
};

#endif // LOGIN_H
