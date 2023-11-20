#include "blinky.h"

void Blinky::cargarPixmap()
{
    m_pixmapArriba = m_pixmapCosas.copy(Recursos::BLINKY_ARRIBA.x(), Recursos::BLINKY_ARRIBA.y(), Recursos::BLINKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    m_pixmapDerecha = m_pixmapCosas.copy(Recursos::BLINKY_DERECHA.x(), Recursos::BLINKY_DERECHA.y(), Recursos::BLINKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    m_pixmapAbajo = m_pixmapCosas.copy(Recursos::BLINKY_ABAJO.x(), Recursos::BLINKY_ABAJO.y(), Recursos::BLINKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    m_pixmapIzquierda = m_pixmapCosas.copy(Recursos::BLINKY_IZQUIERDA.x(), Recursos::BLINKY_IZQUIERDA.y(), Recursos::BLINKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
}

Blinky::Blinky(): Fantasmas(13, 14, 3, 4), m_indiceActual(0), m_debil(0)
{
    m_velocidad = 0.815f;

    setPixmap(m_pixmapCosas.copy(Recursos::BLINKY_ABAJO.x(), Recursos::BLINKY_ABAJO.y(), Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
    cargarPixmap();

    setTransformOriginPoint(Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    connect(&m_temporizador, &QTimer::timeout, this, &Blinky::actualizarPixmap);
    m_temporizador.start(VELOCIDAD_ANIMACION);

    m_animacionDebil = new QPropertyAnimation(this, "debil", this);
    m_animacionDebil->setStartValue(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setDuration(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setEndValue(0);
}

void Blinky::iniciarModoDebil()
{
    m_animacionDebil->start();
}

void Blinky::detenerModoDebil()
{
    m_animacionDebil->stop();
    m_debil = 0;
}

void Blinky::actualizarPixmap()
{
    if(getDireccion() == Recursos::Direccion::NoDefinida || !m_estáAnimado)
    {
        setPixmap(m_pixmapAbajo);
        return;
    }

    if(!estaDebil())
    {
        if(getDireccion() == Recursos::Direccion::Arriba)
        {
            setPixmap(m_pixmapArriba.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
        else if(getDireccion() == Recursos::Direccion::Derecha)
        {
            setPixmap(m_pixmapDerecha.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
        else if(getDireccion() == Recursos::Direccion::Abajo)
        {
            setPixmap(m_pixmapAbajo.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
        else if(getDireccion() == Recursos::Direccion::Izquierda)
        {
            setPixmap(m_pixmapIzquierda.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
    }
    else
    {
        setPixmap(m_pixmapDebil.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
    }

    m_indiceActual += 1;
    m_indiceActual %= Recursos::BLINKY_CANTIDAD_DE_FRAMES_DE_ANIMACION;
}

void Blinky::setDebil(qreal val)
{
    m_debil = val;
}

qreal Blinky::debil() const
{
    return m_debil;
}

bool Blinky::estaDebil()
{
    return m_debil > 0;
}
