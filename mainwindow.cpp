#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tmr = new QTimer();
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(yeni()));
    tmr->start();

    gemi = new QLabel();
    gemi->setGeometry(300,300,110,110);
    gemi->setPixmap(QPixmap(":/new/prefix1/gemi.png"));
    gemi->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::yeni() {
    sure++;
    QString label("<font color='white'>Süre :</font> <font color='white'>%1</font>");
    ui->label->setText(label.arg(QString::number(sure)));
    bln = new Goktasi(this);
    bln->btn->setGeometry(bln->x, 80, 50, 50);
    bln->btn->setParent(this);
    bln->btn->show();
    grp.append(bln->btn);
}
void MainWindow::kacti() {

    kacan++;

}


