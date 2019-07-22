#ifndef HANDER_H
#define HANDER_H

#include <QObject>

class hander : public QObject
{
    Q_OBJECT

public:
    static hander * getInstance();
    void addscore();

private:
    explicit hander(QObject *parent = 0);

signals:
    void beatMouse();

public slots:
private:
    static hander * hand;

};

#endif // HANDER_H
