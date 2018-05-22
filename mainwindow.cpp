#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partie.h"
#include "ordi.h"
#include "humain.h"
#include "joueur.h"
#include "couleur.h"
#include <QPushButton>
#include <QGridLayout>
#include <QPixmap>
#include <QLabel>
#include <QPointer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Partie p(QPointer<Ordi>(rouge), QPointer<Humain>(jaune));
    //p.lancer();

}

MainWindow::~MainWindow()
{
    delete ui;
}
