#ifndef RECURSOS_H
#define RECURSOS_H
#include <QString>
#include <QPoint>
#include <QSize>
#include <QColor>
#include <QUrl>

class Recursos
{
public:
    Recursos();

    enum class Direccion
    {
        Arriba = 1,
        Abajo = -1,
        Izquierda = 2,
        Derecha = -2,
        NoDefinida = 0
    };

    constexpr static const QSize RESOLUCION = QSize(448, 596);
    constexpr static const QColor COLOR_FONDO = QColor(0, 0, 0);
    constexpr static const QColor COLOR_FUENTE = QColor(255, 255, 255);

    static const QString RUTA_A_TIPO_LETRA;

    static void cargarLaberinto();

    static const QString RUTA_A_PIXMAP_LABERINTO;
    constexpr static const unsigned int TAMAÑO_DE_CASILLA_LABERINTO = 16;

        static const QString RUTA_A_PIXMAP_COSAS;
    constexpr static const unsigned int TAMAÑO_DE_CASILLA_COSAS = 30;

    constexpr static const unsigned int PACMAN_CANTIDAD_DE_FRAMES_DE_ANIMACION = 3;
    constexpr static const QPoint PACMAN_ARRIBA = QPoint(0, 0);
    constexpr static const QPoint PACMAN_ABAJO = QPoint(90, 0);
    constexpr static const QPoint PACMAN_IZQUIERDA = QPoint(180, 0);
    constexpr static const QPoint PACMAN_DERECHA = QPoint(270, 0);

    constexpr static const unsigned int BLINKY_CANTIDAD_DE_FRAMES_DE_ANIMACION = 2;
    constexpr static const QPoint BLINKY_ARRIBA = QPoint(0, 30);
    constexpr static const QPoint BLINKY_ABAJO = QPoint(60, 30);
    constexpr static const QPoint BLINKY_IZQUIERDA = QPoint(120, 30);
    constexpr static const QPoint BLINKY_DERECHA = QPoint(180, 30);

    constexpr static const unsigned int PINKY_CANTIDAD_DE_FRAMES_DE_ANIMACION = 2;
    constexpr static const QPoint PINKY_ARRIBA = QPoint(0, 60);
    constexpr static const QPoint PINKY_ABAJO = QPoint(60, 60);
    constexpr static const QPoint PINKY_IZQUIERDA = QPoint(120, 60);
    constexpr static const QPoint PINKY_DERECHA = QPoint(180, 60);

    constexpr static const unsigned int INKY_CANTIDAD_DE_FRAMES_DE_ANIMACION = 2;
    constexpr static const QPoint INKY_ARRIBA = QPoint(0, 90);
    constexpr static const QPoint INKY_ABAJO = QPoint(60, 90);
    constexpr static const QPoint INKY_IZQUIERDA = QPoint(120, 90);
    constexpr static const QPoint INKY_DERECHA = QPoint(180, 90);

    constexpr static const unsigned int CLYDE_CANTIDAD_DE_FRAMES_DE_ANIMACION = 2;
    constexpr static const QPoint CLYDE_ARRIBA = QPoint(0, 120);
    constexpr static const QPoint CLYDE_ABAJO = QPoint(60, 120);
    constexpr static const QPoint CLYDE_IZQUIERDA = QPoint(120, 120);
    constexpr static const QPoint CLYDE_DERECHA = QPoint(0, 120);

    constexpr static const unsigned int PACMAN_MUERTO_CANTIDAD_DE_FRAMES_DE_ANIMACION = 12;
    constexpr static const QPoint PACMAN_MUERTO = QPoint(0, 150);

    constexpr static const unsigned int FANTASMA_ASUSTADO_CANTIDAD_DE_FRAMES_DE_ANIMACION = 2;
    constexpr static const QPoint FANTASMA_ASUSTADO = QPoint(240, 30);

    constexpr static const QPoint VIDA_PACMAN = QPoint(240, 0);

    constexpr static int FPS = 120;

    constexpr static const QPoint FRESA = QPoint(240, 60);
    constexpr static const QPoint CEREZA = QPoint(240, 90);
    constexpr static const QPoint CAMPANA = QPoint(240, 120);
    constexpr static const QPoint LLAVE = QPoint(270, 60);
    constexpr static int CANTIDAD_DE_PREMIOS = 4;

    static const QUrl SFX_PACMAN_MASTICAR;
    static const QUrl SFX_PACMAN_MUERTE;
    static const QUrl SFX_PACMAN_COMER_FRUTA;
    static const QUrl SFX_PACMAN_COMER_FANTASMA;
};


#endif // RECURSOS_H
