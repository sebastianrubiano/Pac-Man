#include "inky.h"

void Inky::cargarPixmap()
{
    m_pixmapArriba = m_pixmapCosas.copy(Recursos::INKY_ARRIBA.x(), Recursos::INKY_ARRIBA.y(), Recursos::INKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS);
    m_pixmapDerecha = m_pixmapCosas.copy(Recursos::INKY_DERECHA.x(), Recursos::INKY_DERECHA.y(), Recursos::INKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS);
    m_pixmapAbajo = m_pixmapCosas.copy(Recursos::INKY_ABAJO.x(), Recursos::INKY_ABAJO.y(), Recursos::INKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS);
    m_pixmapIzquierda = m_pixmapCosas.copy(Recursos::INKY_IZQUIERDA.x(), Recursos::INKY_IZQUIERDA.y(), Recursos::INKY_CANTIDAD_DE_FRAMES_DE_ANIMACION * Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS);
}

Inky::Inky()
    : Fantasmas(11, 17, 26, 32), m_indiceActual(0), m_debil(0)
{
    m_velocidad = 0.75f;

    setPixmap(m_pixmapCosas.copy(Recursos::INKY_ABAJO.x(), Recursos::INKY_ABAJO.y(), Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS));
    cargarPixmap();

    setTransformOriginPoint(Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS);
    connect(&m_temporizador, &QTimer::timeout, this, &Inky::actualizarPixmap);
    m_temporizador.start(VELOCIDAD_ANIMACION);

    m_animacionDebil = new QPropertyAnimation(this, "debil", this);
    m_animacionDebil->setStartValue(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setDuration(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setEndValue(0);
}

void Inky::comenzarModoDebil()
{
    m_animacionDebil->start();
}

void Inky::detenerModoDebil()
{
    m_animacionDebil->stop();
    m_debil = 0;
}

void Inky::actualizarPixmap()
{
    if (obtenerDireccion() == Recursos::Direccion::SinEstablecer || !m_estáAnimado)
    {
        setPixmap(m_pixmapCosas.copy(Recursos::INKY_ABAJO.x(), Recursos::INKY_ABAJO.y(), Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS));
        return;
    }

    if (!estaDebil())
    {
        if (obtenerDireccion() == Recursos::Direccion::Arriba)
        {
            setPixmap(m_pixmapArriba.copy(m_indiceActual * Recursos::TAMAÑO_COSAS, 0, Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS));
        }
        else if (obtenerDireccion() == Recursos::Direccion::Derecha)
        {
            setPixmap(m_pixmapDerecha.copy(m_indiceActual * Recursos::TAMAÑO_COSAS, 0, Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS));
        }
        else if (obtenerDireccion() == Recursos::Direccion::Abajo)
        {
            setPixmap(m_pixmapAbajo.copy(m_indiceActual * Recursos::TAMAÑO_COSAS, 0, Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS));
        }
        else if (obtenerDireccion() == Recursos::Direccion::Izquierda)
        {
            setPixmap(m_pixmapIzquierda.copy(m_indiceActual * Recursos::TAMAÑO_COSAS, 0, Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS));
        }
    }
    else
    {
        setPixmap(m_pixmapDebil.copy(m_indiceActual * Recursos::TAMAÑO_COSAS, 0, Recursos::TAMAÑO_COSAS, Recursos::TAMAÑO_COSAS));
    }

    m_indiceActual += 1;
    m_indiceActual %= Recursos::INKY_CANTIDAD_DE_FRAMES_DE_ANIMACION;
}

void Inky::setDebil(qreal val)
{
    m_debil = val;
}

qreal Inky::debil() const
{
    return m_debil;
}

bool Inky::estaDebil()
{
    return m_debil > 0;
}
