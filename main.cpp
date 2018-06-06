#include "mainwindow.h"
#include "QDesktopWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setMinimumSize(600, 400);
    w.setMaximumSize(600, 400);
    QRect r = w.geometry();
    r.moveCenter(QApplication::desktop()->availableGeometry().center());
    w.setGeometry(r);

    w.show();

    return a.exec();
}
