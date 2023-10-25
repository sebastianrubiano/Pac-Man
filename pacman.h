#ifndef PACMAN_H
#define PACMAN_H

#include <qobject.h>
#include <QGraphicsPixmapItem>
#include <QString>

class Pacman: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Pacman(QString name);
};

#endif // PACMAN_H
