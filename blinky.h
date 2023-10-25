#ifndef BLINKY_H
#define BLINKY_H
#include <qobject.h>
#include <QGraphicsPixmapItem>

class blinky: public QObject, public QGraphicsPixmapItem
{
public:
    blinky();
};

#endif // BLINKY_H
