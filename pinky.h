#ifndef PINKY_H
#define PINKY_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPropertyAnimation>
#include "fantasmas.h"

class Pinky: public QObject, public QGraphicsPixmapItem, public Fantasmas
{
    Q_OBJECT
    Q_PROPERTY(qreal debilidad READ debilidad WRITE setDebilidad)
public:
    explicit Pinky();

    void iniciarModoDebilidad();
    void detenerModoDebilidad();
    bool estaDebilidad();

signals:

private slots:
    void actualizarPixmap();
    void setDebilidad(qreal val);

private:
    qreal debilidad() const;

    QTimer temporizador;
    int indiceActual;
    QPixmap pixmapArriba, pixmapDerecha, pixmapAbajo, pixmapIzquierda;
    QPixmap pixmapDebil;
    QPropertyAnimation *animacionDebil;
    qreal debilidad;
    constexpr static int VELOCIDAD_ANIMACION = 125;

    void cargarPixmap();
};

#endif // PINKY_H
