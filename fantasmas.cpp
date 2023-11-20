#include "Fantasmas.h"

Fantasmas::Fantasmas(int tilePosX, int tilePosY, int destinoX, int destinoY)
    : Entidad(tilePosX, tilePosY), m_dispersión(true), m_fueraDeJaula(false),
      m_tomarDecision(true), m_asustado(false), VELOCIDAD_MODO_DÉBIL(4000)
{
    establecerDestino(destinoX, destinoY);
    establecerDirección(Recursos::Dirección::SinDefinir);
    m_pixmapAsustado = m_pixmapCosas.copy(Recursos::FANTASMA_ASUSTADO.x(), Recursos::FANTASMA_ASUSTADO.y(), Recursos::TAMAÑO_MOSAICO_COSAS * Recursos::CANTIDAD_DE_MARCOS_ANIMACIÓN_FANTASMA_ASUSTADO, Recursos::TAMAÑO_MOSAICO_COSAS);
}

void Fantasmas::establecerDestino(int x, int y)
{
    m_destinoMosaicoX = x;
    m_destinoMosaicoY = y;
}

int Fantasmas::obtenerDestinoX()
{
    return m_destinoMosaicoX;
}

int Fantasmas::obtenerDestinoY()
{
    return m_destinoMosaicoY;
}

void Fantasmas::establecerDirección(Recursos::Dirección dir)
{
    m_movimiento = dir;
}

Recursos::Dirección Fantasmas::obtenerDirección()
{
    return m_movimiento;
}

void Fantasmas::mover()
{
    switch (m_movimiento)
    {
    case Recursos::Direccion::Arriba:
        Entidad::mover(0, -m_velocidad);
        break;
    case Recursos::Dirección::Abajo:
        Entidad::mover(0, m_velocidad);
        break;
    case Recursos::Dirección::Izquierda:
        Entidad::mover(-m_velocidad, 0);
        break;
    case Recursos::Dirección::Derecha:
        Entidad::mover(m_velocidad, 0);
        break;
    }
}

bool Fantasma::estáEnModoDispersión()
{
    return m_dispersión;
}

void Fantasma::establecerModoDispersión(bool s)
{
    m_dispersión = s;
}

bool Fantasma::estáFueraDeJaula()
{
    return m_fueraDeJaula;
}

bool Fantasma::deberíaTomarDecisión()
{
    return m_tomarDecision;
}

void Fantasma::establecerTomarDecisión(bool d)
{
    m_tomarDecision = d;
}

void Fantasma::teletransportar(int x, int y)
{
    Entidad::teletransportar(x, y);
    m_fueraDeJaula = true;
}

bool Fantasma::estáAnimado() const
{
    return m_animado;
}

void Fantasma::establecerAnimado(bool val)
{
    m_animado = val;
}
