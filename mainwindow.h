#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "partie.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    Ui::MainWindow *ui;
    Partie p;
};

#endif // MAINWINDOW_H
