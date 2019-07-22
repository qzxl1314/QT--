#include "pictureitem.h"
#include <QPixmap>
#include "hander.h"
#include <QCursor>
pictureitem::pictureitem()
{
    this->setPixmap(QPixmap(":/pic/pic/hole.jpg"));
    this->Start=false;
    this->Mouse=false;
    this->setCursor(QCursor(QPixmap(":/pic/pic/2.png")));
}

void pictureitem::SetPic(QString path){
    this->setPixmap(QPixmap(path));
}
void pictureitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/pic/pic/1.png")));
    if(this->isStart()){
        hander *hand=hander::getInstance();
        if(this->isMouse()){
            hand->addscore();
            this->setPixmap(QPixmap(":/pic/pic/beaten.png"));
            this->Mouse=false;
        }else{

        }
    }
}
void pictureitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   this->setCursor(QCursor(QPixmap(":/pic/pic/2.png")));
}

void pictureitem::setMouse(bool Mouse)
{
    this->Mouse=Mouse;
}
bool pictureitem::isMouse()
{
    return this->Mouse;
}
void pictureitem::setStart(bool Start)
{
    this->Start=Start;
}
bool pictureitem::isStart()
{
    return this->Start;
}
