#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "goktasi.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int vurulan = 0;
        int kacan = 0;
        QList<QLabel*> grp;
        QTimer *tmr;
        int sure = 0;
        Goktasi *bln;
        QLabel *gemi;

public slots:
    void kacti();
    void yeni();

};
#endif // MAINWINDOW_H
