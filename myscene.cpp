#include "myscene.h"
#include <stdlib.h>
#include "hander.h"
#include <QString>
#include <QDebug>
myscene::myscene(QObject *parent) : QGraphicsScene(parent)
{
    int i=0;
    for(i=0;i<16;i++){
        this->item[i]= new pictureitem;
        this->item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }
    this->ptimer=new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));

}
void myscene::showMouse()
{
    int count=rand()%3+1;
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->SetPic(":/pic/pic/hole.jpg");
        this->item[i]->setMouse(false);
    }
    for(i=0;i<count;i++)
    {
        int index=rand()%16;
        this->item[index]->SetPic(":/pic/pic/mouse.jpg");
        this->item[index]->setMouse(true);
    }

}
void myscene::start() {
    int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(true);
    }
    this->ptimer->start(1000);
}
void myscene::stop(){
    this->ptimer->stop();
    int i=0;
    for(i=0;i<16;i++)
    {
        this->item[i]->SetPic(":/pic/pic/hole.jpg");
        this->item[i]->setMouse(false);
    }
}
void myscene::pause(){
    this->ptimer->stop();
    int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(false);
    }
}
void myscene::contin(){
    this->ptimer->start();
    int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(true);
    }
}
