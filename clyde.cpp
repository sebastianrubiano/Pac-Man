#include "clyde.h"

void Clyde::cargarPixmap()
{
    m_pixmapArriba = m_pixmapCosas.copy(Recursos::CLYDE_ARRIBA.x(), Recursos::CLYDE_ARRIBA.y(), Recursos::CLYDE_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    m_pixmapDerecha = m_pixmapCosas.copy(Recursos::CLYDE_DERECHA.x(), Recursos::CLYDE_DERECHA.y(), Recursos::CLYDE_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    m_pixmapAbajo = m_pixmapCosas.copy(Recursos::CLYDE_ABAJO.x(), Recursos::CLYDE_ABAJO.y(), Recursos::CLYDE_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    m_pixmapIzquierda = m_pixmapCosas.copy(Recursos::CLYDE_IZQUIERDA.x(), Recursos::CLYDE_IZQUIERDA.y(), Recursos::CLYDE_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
}

Clyde::Clyde()
    : Fantasmas(14, 14, 26, 32), m_indiceActual(0), m_debil(0)
{
    m_velocidad = 0.75f;

    setPixmap(m_pixmapCosas.copy(Recursos::CLYDE_ABAJO.x(), Recursos::CLYDE_ABAJO.y(), Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
    cargarPixmap();

    setTransformOriginPoint(Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS);
    connect(&m_temporizador, &QTimer::timeout, this, &Clyde::actualizarPixmap);
    m_temporizador.start(VELOCIDAD_ANIMACION);

    m_animacionDebil = new QPropertyAnimation(this, "debil", this);
    m_animacionDebil->setStartValue(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setDuration(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setEndValue(0);
}

void Clyde::iniciarModoDebil()
{
    m_animacionDebil->start();
}

void Clyde::detenerModoDebil()
{
    m_animacionDebil->stop();
    m_debil = 0;
}

void Clyde::actualizarPixmap()
{
    if (getDireccion() == Recursos::Direccion::NoDefinida || !m_estáAnimado)
    {
        setPixmap(m_pixmapCosas.copy(Recursos::CLYDE_ABAJO.x(), Recursos::CLYDE_ABAJO.y(), Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        return;
    }

    if (!estaDebil())
    {
        if (getDireccion() == Recursos::Direccion::Arriba)
        {
            setPixmap(m_pixmapArriba.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
        else if (getDireccion() == Recursos::Direccion::Derecha)
        {
            setPixmap(m_pixmapDerecha.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
        else if (getDireccion() == Recursos::Direccion::Abajo)
        {
            setPixmap(m_pixmapAbajo.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
        else if (getDireccion() == Recursos::Direccion::Izquierda)
        {
            setPixmap(m_pixmapIzquierda.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
        }
    }
    else
    {
        setPixmap(m_pixmapDebil.copy(m_indiceActual * Recursos::TAMAÑO_DE_CASILLA_COSAS, 0, Recursos::TAMAÑO_DE_CASILLA_COSAS, Recursos::TAMAÑO_DE_CASILLA_COSAS));
    }

    m_indiceActual += 1;
    m_indiceActual %= Recursos::CLYDE_CANTIDAD_DE_FRAMES_DE_ANIMACION;
}

void Clyde::setDebil(qreal val)
{
    m_debil = val;
}

qreal Clyde::debil() const
{
    return m_debil;
}

bool Clyde::estaDebil()
{
    return m_debil > 0;
}
