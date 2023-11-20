#ifndef FANTASMAS_H
#define FANTASMAS_H
#include <QPixmap>
#include "recursos.h"
#include "entidad.h"

class Fantasmas : public Entidad
{
public:
    Fantasmas(int x, int y, int destinoX, int destinoY);
    void setDestino(int x, int y);
    int getDestX();
    int getDestY();

    void setDireccion(Recursos::Direccion dir);
    Recursos::Direccion getDireccion();
    void mover();

    bool estáEnModoEsparcimiento();
        void setEnModoEsparcimiento(bool s);

    bool estáFueraDeCelda();

        bool debeTomarDecision();
    void setTomarDecision(bool d);

    void teletransportar(int x, int y);

    bool estáAnimado() const;
        void setAnimado(bool val);
protected:
    int m_destinoTileX;
    int m_destinoTileY;
    Recursos::Direccion m_moviéndose;

        bool m_enModoEsparcimiento;
    bool m_fueraDeCelda;

    bool m_debeTomarDecision;

    int m_asustado;

    QPixmap m_pixmapAsustado;

    bool m_estáAnimado;

    const int VELOCIDAD_MODO_DEBIL;

    float m_velocidad;
};


#endif // FANTASMAS_H
