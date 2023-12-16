#include "goktasi.h"

Goktasi::Goktasi(QWidget *p)
{
    pt = p;
    btn = new QLabel();
    poligonCiz();
    x = QRandomGenerator::global()->bounded(10, 945);
    tmr = new QTimer();
    tmr->setInterval(17);
    connect(tmr, SIGNAL(timeout()), this, SLOT(move()));
    connect(btn, SIGNAL(destroyed()), this, SLOT(dltd()));
    connect(this, SIGNAL(kaciyor()), p, SLOT(kacti()));
    tmr->start();
}
void Goktasi::move() {
    if (y >= 800) {
        emit kaciyor();
        disconnect(btn, SIGNAL(destroyed()), 0, 0);
        delete btn;
        delete this;
    } else {
        y+=3;
        btn->setGeometry(x, y, 70, 70);
    }
}
void Goktasi::DogruCizDDA2(QPoint ilk, QPoint son)
{
    double dx=son.x()-ilk.x();
    double dy=son.y()-ilk.y();
    double Xartim, Yartim;
    double adim;
    double x,y;
    if(fabs(dx)>fabs(dy))
    {
        adim=fabs(dx);
    }
    else
    {
        adim=fabs(dy);
    }
    Xartim=dx/adim;
    Yartim=dy/adim;
    x=ilk.x();
    y=ilk.y();

    for(int i=0; i<adim; i++)
    {
        x+=Xartim;
        y+=Yartim;
        res.setPixel(round(x),round(y),renk);
    }
}
void Goktasi::poligonCiz(){
    QPixmap temp(":/new/prefix1/png.png");
    res=temp.toImage();
    int control_variable = 0;
    // random ile sayi atariz
    if(control_variable == 0)
    {
        Koseler.append(QPoint(0,20));
        Koseler.append(QPoint(35,70));
        Koseler.append(QPoint(70,20));
        Koseler.append(QPoint(0,20));
        Koseler.append(Koseler[0]);

        for(int i=0; i<Koseler.length()-1; i++)
        {
            DogruCizDDA2(Koseler[i],Koseler[i+1]);
        }
        Koseler.clear();

        btn->setPixmap(QPixmap::fromImage(res));

        Koseler.append(QPoint(35,0));
        Koseler.append(QPoint(0,50));
        Koseler.append(QPoint(70,50));
        Koseler.append(QPoint(35,0));
        Koseler.append(Koseler[0]);

        for(int i=0; i<Koseler.length()-1; i++)
        {
            DogruCizDDA2(Koseler[i],Koseler[i+1]);
        }
        Koseler.clear();

        btn->setPixmap(QPixmap::fromImage(res));
    }
    else
    {
    // dds
        Koseler.append(QPoint(35,0));
        Koseler.append(QPoint(10,10));
        Koseler.append(QPoint(0,35));
        Koseler.append(QPoint(60,10));
        Koseler.append(QPoint(35,70));
        Koseler.append(QPoint(60,10));
        Koseler.append(QPoint(70,35));
        Koseler.append(QPoint(60,10));
        Koseler.append(QPoint(35,0));
        Koseler.append(Koseler[0]);

        for(int i=0; i<Koseler.length()-1; i++)
        {
            DogruCizDDA2(Koseler[i],Koseler[i+1]);
        }
        Koseler.clear();

        btn->setPixmap(QPixmap::fromImage(res));
    }



}
void Goktasi::dltd(){
    /*
    btn = new QPushButton(pt);
    QIcon *icn = new QIcon(":/img/img/8.jpg");
    btn->setIcon(*icn);
    btn->setIconSize(QSize(50, 50));
    btn->setGeometry(x, y, 50, 50);
    btn->show();
    QTimer::singleShot(1000, btn, SLOT(deleteLater()));
    delete this;
    */
}
