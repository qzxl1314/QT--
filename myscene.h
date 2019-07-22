#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <pictureitem.h>
#include <QTimer>
#include <QString>
class myscene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myscene(QObject *parent = 0);

signals:

public slots:
    void showMouse();
    void start();
    void stop();
    void pause();
    void contin();
private:
    pictureitem * item[16];
    QTimer * ptimer;
};

#endif // MYSCENE_H
