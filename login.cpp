#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "user.h"


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}




void login::on_pushButton_2_clicked()
{
    user g;



         QString username, password;
         username =ui->utilisateur->text();
         password=ui->motdepasse->text();

        //QMessageBox::information(this, "Pseudo",username,password "Attention, Votre nom d'utilisateur ou mot de passe est incorrect !");

      if(username==g.getnom() &&  password==g.getpass())
      {
                  mainwindow = new MainWindow(this);
                  mainwindow->show();
                  this->hide();

      }

      else
      {
         QMessageBox::critical (this, "Error", "Something went wrong !");
      }
}
