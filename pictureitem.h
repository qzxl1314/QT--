 #ifndef PICTUREITEM_H
#define PICTUREITEM_H
#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>
class pictureitem : public QGraphicsPixmapItem
{
public:
    pictureitem();
    void SetPic(QString path);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void setMouse(bool Mouse);
    bool isMouse();
    void setStart(bool Start);
    bool isStart();
private:
    bool Mouse;
    bool Start;
};

#endif // PICTUREITEM_H
