#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partie.h"
#include "ordi.h"
#include "humain.h"
#include "joueur.h"
#include "couleur.h"
#include <QLabel>
#include <QPointer>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Partie p(std::make_unique<const Ordi>(rouge), std::make_unique<const Humain>(jaune));
    p.lancer();

}

MainWindow::~MainWindow()
{
    delete ui;
}
