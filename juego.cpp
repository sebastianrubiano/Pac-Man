#include "juego.h"
#include "ui_juego.h"

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    esena = new QGraphicsScene;

    esena->setSceneRect(0,0,ui->graphicsView->width()-10,ui->graphicsView->height()-10);
    ui->graphicsView->setScene(esena);

}

Juego::~Juego()
{
    delete ui;
    delete esena;
}

