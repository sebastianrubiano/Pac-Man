#include "pinky.h"

void Pinky::cargarPixmap()
{
    m_upPixmap = m_thingsPixmap.copy(Resources::PINKY_ARRIBA.x(), Resources::PINKY_ARRIBA.y(), Resources::PINKY_CANT_FRAMES_ANIM*Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE);
    m_rightPixmap = m_thingsPixmap.copy(Resources::PINKY_DERECHA.x(), Resources::PINKY_DERECHA.y(), Resources::PINKY_CANT_FRAMES_ANIM*Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE);
    m_downPixmap = m_thingsPixmap.copy(Resources::PINKY_ABAJO.x(), Resources::PINKY_ABAJO.y(), Resources::PINKY_CANT_FRAMES_ANIM*Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE);
    m_leftPixmap = m_thingsPixmap.copy(Resources::PINKY_IZQUIERDA.x(), Resources::PINKY_IZQUIERDA.y(), Resources::PINKY_CANT_FRAMES_ANIM*Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE);
}

Pinky::Pinky()
    : Fantasma(13, 17, 26, 32), m_currentIndex(0), m_debilidad(0)
{
    m_velocidad = 0.7f;

    setPixmap(m_thingsPixmap.copy(Resources::PINKY_ABAJO.x(), Resources::PINKY_ABAJO.y(), Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE));
    cargarPixmap();

    setTransformOriginPoint(Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE);
    connect(&m_temporizador, &QTimer::timeout, this, &Pinky::actualizarPixmap);
    m_temporizador.start(VELOCIDAD_ANIMACION);

    m_animacionDebil = new QPropertyAnimation(this, "debilidad", this);
    m_animacionDebil->setStartValue(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setDuration(VELOCIDAD_MODO_DEBIL);
    m_animacionDebil->setEndValue(0);
}

void Pinky::iniciarModoDebilidad()
{
    m_animacionDebil->start();
}

void Pinky::detenerModoDebilidad()
{
    m_animacionDebil->stop();
    m_debilidad = 0;
}

void Pinky::actualizarPixmap()
{
    if(getDireccion() == Resources::Direccion::SinEstablecer || !m_esAnimado)
    {
        setPixmap(m_thingsPixmap.copy(Resources::PINKY_ABAJO.x(), Resources::PINKY_ABAJO.y(), Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE));
        return;
    }

    if(!estaDebilidad())
    {
        if(getDireccion() == Resources::Direccion::Arriba)
        {
            setPixmap(m_upPixmap.copy(m_currentIndex*Resources::TAMANO_BLOQUE, 0, Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE));
        }
        else if(getDireccion() == Resources::Direccion::Derecha)
        {
            setPixmap(m_rightPixmap.copy(m_currentIndex*Resources::TAMANO_BLOQUE, 0, Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE));
        }
        else if(getDireccion() == Resources::Direccion::Abajo)
        {
            setPixmap(m_downPixmap.copy(m_currentIndex*Resources::TAMANO_BLOQUE, 0, Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE));
        }
        else if(getDireccion() == Resources::Direccion::Izquierda)
        {
            setPixmap(m_leftPixmap.copy(m_currentIndex*Resources::TAMANO_BLOQUE, 0, Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE));
        }
    }
    else
    {
        setPixmap(m_pixmapAsustado.copy(m_currentIndex*Resources::TAMANO_BLOQUE, 0, Resources::TAMANO_BLOQUE, Resources::TAMANO_BLOQUE));
    }

    m_currentIndex += 1;
    m_currentIndex %= Resources::CANT_FRAMES_ANIM_PINKY;
}

void Pinky::setDebilidad(qreal val)
{
    m_debilidad = val;
}

qreal Pinky::debilidad() const
{
    return m_debilidad;
}

bool Pinky::estaDebilidad()
{
    return m_debilidad > 0;
}
