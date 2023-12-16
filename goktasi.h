#include <QLabel>
#include <QRandomGenerator>
#include <QTimer>
#ifndef GOKTASI_H
#define GOKTASI_H


class Goktasi : public QObject
{
    Q_OBJECT
public:
    Goktasi(QWidget *);
    QLabel *btn;
    int x;
    int y = 77;
    QTimer *tmr;
    QWidget *pt;
    QList<QPoint> Koseler;
    QImage res;
    QRgb renk;

public slots:
    void dltd();
    void move();
    void poligonCiz();
    void DogruCizDDA2(QPoint ilk, QPoint son);
signals:
    void kaciyor();
};

#endif // GOKTASI_H

