#ifndef MAPA__H
#define MAPA__H

#include <QObject>
#include "pacman.h"
#include "fantasmas.h".h"
#include "blinky.h"
class pacman;
class fantasmas;
class Laberinto : public QObject
{
    Q_OBJECT
public:
    explicit Laberinto();

    static const uint ANCHO_DEL_LABERINTO = 28;
    static const uint ALTO_DEL_LABERINTO = 36;

    uint obtenerCasilla(int x, int y) const;
    bool casillaBloqueaEntidad(int x, int y);
    bool esInterseccion(int x, int y);
    bool quitarPunto(Pacman* pacman, int& puntuacion);
signals:
    void seHaComidoPuntoGordo();
private:
    uint m_casillas[ANCHO_DEL_LABERINTO][ALTO_DEL_LABERINTO];
    static constexpr int NINGUN_CAMPO = 30;
    static constexpr int PUNTO_PEQUENO = 26;
    static constexpr int PUNTO_GRANDE = 27;
};


#endif // MAPA__H
