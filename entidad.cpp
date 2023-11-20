#include "entidad.h"

Entidad::Entidad(int tilePosX, int tilePosY)
    : m_pixmapCosas(Recursos::RUTA_A_PIXMAP_COSAS)
{
    m_tileX = tilePosX;
    m_tileY = tilePosY;
    m_posXPantalla = tilePosX * Recursos::TAMAÑO_DE_CASILLA_LABERINTO + 8.0f + 8.0f - Recursos::TAMAÑO_DE_CASILLA_COSAS/2;
    m_posYPantalla = tilePosY * Recursos::TAMAÑO_DE_CASILLA_LABERINTO + 8.0f - Recursos::TAMAÑO_DE_CASILLA_COSAS/2;
}

float Entidad::obtenerPosXPantalla()
{
    return m_posXPantalla;
}

float Entidad::obtenerPosYPantalla()
{
    return m_posYPantalla;
}

int Entidad::obtenerTileX()
{
    return m_tileX;
}

int Entidad::obtenerTileY()
{
    return m_tileY;
}

void Entidad::mover(float x, float y)
{
    m_posXPantalla += x;
    m_posYPantalla += y;

    if ((int)(m_posXPantalla + 8 + Recursos::TAMAÑO_DE_CASILLA_COSAS/2) % 16 == 0 && (int)(m_posYPantalla + 8 + Recursos::TAMAÑO_DE_CASILLA_COSAS/2) % 16 == 0)
    {
        m_tileX = (int) round((m_posXPantalla - 8 + Recursos::TAMAÑO_DE_CASILLA_COSAS/2) / 16);
        m_tileY = (int) round((m_posYPantalla - 8 + Recursos::TAMAÑO_DE_CASILLA_COSAS/2) / 16);
    }
}

void Entidad::teletransportar(int x, int y)
{
    m_tileX = x;
    m_tileY = y;
    m_posXPantalla = x * 16.0f + 8.0f - Recursos::TAMAÑO_DE_CASILLA_COSAS/2;
    m_posYPantalla = y * 16.0f + 8.0f - Recursos::TAMAÑO_DE_CASILLA_COSAS/2;
}
