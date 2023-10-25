#ifndef INKY_H
#define INKY_H
#include <qobject.h>
#include <QGraphicsPixmapItem>

class inky: public QObject, public QGraphicsPixmapItem
{
public:
    inky();
};

#endif // INKY_H
