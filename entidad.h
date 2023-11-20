#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <QPixmap>
#include <cmath>
#include "recursos.h"
class Entidad
{
public:
    Entidad(int tilePosX, int tilePosY);

    float obtenerPosXPantalla();
    float obtenerPosYPantalla();
    int obtenerTileX();
    int obtenerTileY();

    void mover(float x, float y);
    void teletransportar(int x, int y);
protected:
    float m_posXPantalla;
    float m_posYPantalla;
    int m_tileX;
    int m_tileY;
    const QPixmap m_pixmapCosas;
};


#endif // ENTIDAD_H
