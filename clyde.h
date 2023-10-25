#ifndef CLYDE_H
#define CLYDE_H
#include <qobject.h>
#include <QGraphicsPixmapItem>

class clyde: public QObject, public QGraphicsPixmapItem
{
public:
    clyde();
};

#endif // CLYDE_H
