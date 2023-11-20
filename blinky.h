#ifndef BLINKY_H
#define BLINKY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPropertyAnimation>
#include "fantasmas.h"

class Blinky : public QObject, public QGraphicsPixmapItem, public Fantasmas
{
    Q_OBJECT
    Q_PROPERTY(qreal debil READ debil WRITE setDebil)
public:
    explicit Blinky();

    void iniciarModoDebil();
    void detenerModoDebil();
    bool estaDebil();
signals:

private slots:
    void actualizarPixmap();
    void setDebil(qreal val);
private:
    qreal debil() const;

    QTimer m_temporizador;
    int m_indiceActual;
    QPixmap m_pixmapArriba, m_pixmapDerecha, m_pixmapAbajo, m_pixmapIzquierda;
    QPixmap m_pixmapDebil;
    QPropertyAnimation *m_animacionDebil;
    qreal m_debil;
    constexpr static int VELOCIDAD_ANIMACION = 125;

    void cargarPixmap();
};


#endif // BLINKY_H
