#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <queue>
#include <QKeyEvent>
#include "recursos.h"
#include "entidad.h"
using namespace std;

class Pacman : public QObject, public QGraphicsPixmapItem, public Entidad
{
    Q_OBJECT
public:
    explicit Pacman();

signals:
    void animacionMuerteTerminada();

private slots:
    void actualizarPixmap();

private:
    void cargarPixmap();
    queue<Recursos::Direccion> m_direcciones;
    int m_puntosComidos;
    bool m_muerto;

    QPixmap m_pixmapArriba, m_pixmapAbajo, m_pixmapIzquierda, m_pixmapDerecha;
    QPixmap m_pixmapMuerto;
    int m_indiceActual;
    QTimer m_temporizador;
    constexpr static float VELOCIDAD = 0.8f;
    constexpr static int VELOCIDAD_ANIMACION = 125;

public:
    void limpiarColaDirecciones();
    void encolarDireccion(Recursos::Direccion dir);
    void mover();
    queue<Recursos::Direccion> obtenerDirecciones();
    void detener();

    void comerPunto();
    int obtenerPuntosComidos();

    void setMuerto(bool d);
    bool estaMuerto();

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // PACMAN_H
