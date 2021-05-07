#include "login.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(database.isOpen())
    {
        login l;
        l.show();

        return a.exec();
    }
    else

    {
        QMessageBox::critical(0, "Database not connected !", "Cannot connect to the database ...");
        return a.exec();
    }

}
