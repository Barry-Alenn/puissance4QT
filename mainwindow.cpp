#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partie.h"
#include "ordi.h"
#include "humain.h"
#include "couleur.h"
#include <QLabel>
#include <memory>
#include <QDebug>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    p(std::make_unique<const Humain>(jaune), std::make_unique<const Ordi>(rouge))
{
    ui->setupUi(this);

    //Partie p(std::make_unique<const Humain>(jaune), std::make_unique<const Ordi>(rouge));

    setCentralWidget(p.lancer());

    connect( p.getJeu()->getBgroup(), static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
        [=](int colButton){
        //p.getJeu()->setColJoue(colButton);
        qDebug() << colButton;
        p.getJeu()->addPion();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
