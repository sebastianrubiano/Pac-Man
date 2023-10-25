#ifndef PINKY_H
#define PINKY_H
#include <qobject.h>
#include <QGraphicsPixmapItem>

class pinky: public QObject, public QGraphicsPixmapItem
{
public:
    pinky();
};

#endif // PINKY_H
