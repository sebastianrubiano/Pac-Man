#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class Juego; }
QT_END_NAMESPACE

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    ~Juego();

private:
    Ui::Juego *ui;
    QGraphicsScene *esena;

};
#endif // JUEGO_H
