#include "recursos.h"
const QString Recursos::RUTA_A_PIXMAP_LABERINTO = ":/mapa/recursos/mapa/labyrinth.png";
const QString Recursos::RUTA_A_PIXMAP_COSAS = ":/objetos/recursos/ghosts/things.png";
const QString Recursos::RUTA_A_TIPO_LETRA = ":/res/font/arcadepi.ttf";

const QUrl Recursos::SFX_PACMAN_MASTICAR = QUrl("qrc:/audio/recursos/audios/pacman_chomp.wav");
const QUrl Recursos::SFX_PACMAN_MUERTE = QUrl("qrc:/audio/recursos/audios/pacman_death.wav");
const QUrl Recursos::SFX_PACMAN_COMER_FRUTA = QUrl("qrc:/audio/recursos/audios/pacman_eatfruit.wav");
const QUrl Recursos::SFX_PACMAN_COMER_FANTASMA = QUrl("qrc:/audio/recursos/audios/pacman_eatghost.wav");

Recursos::Recursos()
{

}
