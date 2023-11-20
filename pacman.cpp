#include "pacman.h"
using namespace std;

Pacman::Pacman() : QGraphicsPixmapItem(), Entidad(13, 26), m_puntosComidos(0), m_muerto(false), m_indiceActual(0)
{
    cargarPixmap();
    //setPixmap(m_thingsPixmap.copy(0,0, Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE));
    setPixmap(m_pixmapDerecha);
    setTransformOriginPoint(Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE);
    connect(&m_temporizador, &QTimer::timeout, this, &Pacman::actualizarPixmap);
    m_temporizador.start(VELOCIDAD_ANIMACION);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Pacman::actualizarPixmap()
{
    if (m_direcciones.empty())
    {
        setPixmap(m_thingsPixmap.copy(0, 0, Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE));
        return;
    }
    if (!m_muerto)
    {
        if (m_direcciones.front() == Resources::Direccion::Arriba)
        {
            setPixmap(m_pixmapArriba.copy(m_indiceActual * Resources::THINGS_TILE_SIZE, 0, Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE));
        }
        else if (m_direcciones.front() == Resources::Direccion::Derecha)
        {
            setPixmap(m_pixmapDerecha.copy(m_indiceActual * Resources::THINGS_TILE_SIZE, 0, Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE));
        }
        else if (m_direcciones.front() == Resources::Direccion::Abajo)
        {
            setPixmap(m_pixmapAbajo.copy(m_indiceActual * Resources::THINGS_TILE_SIZE, 0, Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE));
        }
        else if (m_direcciones.front() == Resources::Direccion::Izquierda)
        {
            setPixmap(m_pixmapIzquierda.copy(m_indiceActual * Resources::THINGS_TILE_SIZE, 0, Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE));
        }

        m_indiceActual += 1;
        m_indiceActual %= Resources::PACMAN_COUNT_ANIM_FRAMES;
    }
    else
    {
        setPixmap(m_pixmapMuerto.copy(m_indiceActual * Resources::THINGS_TILE_SIZE, 0, Resources::THINGS_TILE_SIZE, Resources::THINGS_TILE_SIZE));
        m_indiceActual += 1;
        if (m_indiceActual == Resources::DEAD_PACMAN_COUNT_ANIM_FRAMES)
        {
            emit animacionMuerteTerminada();
        }
        m_indiceActual %= Resources::DEAD_PACMAN_COUNT_ANIM_FRAMES;
    }
}

void Pacman::cargarPixmap()
{
    m_pixmapArriba = m_thingsPixmap.copy(Resources::PACMAN_ARRIBA.x(), Resources::PACMAN_ARRIBA.y(), Resources::THINGS_TILE_SIZE * Resources::PACMAN_COUNT_ANIM_FRAMES, Resources::THINGS_TILE_SIZE);
    m_pixmapAbajo = m_thingsPixmap.copy(Resources::PACMAN_ABAJO.x(), Resources::PACMAN_ABAJO.y(), Resources::THINGS_TILE_SIZE * Resources::PACMAN_COUNT_ANIM_FRAMES, Resources::THINGS_TILE_SIZE);
    m_pixmapIzquierda = m_thingsPixmap.copy(Resources::PACMAN_IZQUIERDA.x(), Resources::PACMAN_IZQUIERDA.y(), Resources::THINGS_TILE_SIZE * Resources::PACMAN_COUNT_ANIM_FRAMES, Resources::THINGS_TILE_SIZE);
    m_pixmapDerecha = m_thingsPixmap.copy(Resources::PACMAN_DERECHA.x(), Resources::PACMAN_DERECHA.y(), Resources::THINGS_TILE_SIZE * Resources::PACMAN_COUNT_ANIM_FRAMES, Resources::THINGS_TILE_SIZE);
    m_pixmapMuerto = m_thingsPixmap.copy(Resources::PACMAN_MUERTO.x(), Resources::PACMAN_MUERTO.y(), Resources::THINGS_TILE_SIZE * Resources::DEAD_PACMAN_COUNT_ANIM_FRAMES, Resources::THINGS_TILE_SIZE);
}

void Pacman::limpiarColaDirecciones()
{
    queue<Resources::Direccion> clear;
    swap(m_direcciones, clear);
}

void Pacman::encolarDireccion(Resources::Direccion dir)
{
    if (!m_direcciones.empty())
    {
        if (int(dir) == -int(m_direcciones.front()))
        {
            queue<Resources::Direccion> clear;
            swap(m_direcciones, clear);
        }
    }

    if (m_direcciones.size() < 2)
        m_direcciones.push(dir);
}

void Pacman::mover()
{
    if (!m_direcciones.empty())
    {
        switch (m_direcciones.front())
        {
        case Resources::Direccion::Arriba:
            Entidad::mover(0, -VELOCIDAD);
            break;
        case Resources::Direccion::Abajo:
            Entidad::mover(0, VELOCIDAD);
            break;
        case Resources::Direccion::Izquierda:
            Entidad::mover(-VELOCIDAD, 0);
            break;
        case Resources::Direccion::Derecha:
            Entidad::mover(VELOCIDAD, 0);
            break;
        case Resources::Direccion::SinDefinir:
            break;
        }
    }
}

queue<Resources::Direccion> Pacman::obtenerDirecciones()
{
    return m_direcciones;
}

void Pacman::detener()
{
    if (m_direcciones.size() > 1)
    {
        if ((int)(m_posicionPantallaX + 8 + Resources::THINGS_TILE_SIZE / 2) % 16 == 0 && (int)(m_posicionPantallaY + 8 + Resources::THINGS_TILE_SIZE / 2) % 16 == 0)
        {
            switch (m_direcciones.front())
            {
            case Resources::Direccion::Arriba:
                m_direcciones.pop();
                break;
            case Resources::Direccion::Abajo:
                m_direcciones.pop();
                break;
            case Resources::Direccion::Izquierda:
                m_direcciones.pop();
                break;
            case Resources::Direccion::Derecha:
                m_direcciones.pop();
                break;
            case Resources::Direccion::SinDefinir:
                m_direcciones.pop();
                break;
            }
        }
    }
}

void Pacman::comerPunto()
{
    m_puntosComidos++;
}

int Pacman::obtenerPuntosComidos()
{
    return m_puntosComidos;
}

void Pacman::setMuerto(bool d)
{
    m_muerto = d;
    m_indiceActual = 0;
}

bool Pacman::estaMuerto()
{
    return m_muerto;
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
    {
        return;
    }
    if (!estaMuerto())
    {
        switch (event->key())
        {
        case Qt::Key_Up:
            encolarDireccion(Resources::Direccion::Arriba);
            break;
        case Qt::Key_Right:
            encolarDireccion(Resources::Direccion::Derecha);
            break;
        case Qt::Key_Down:
            encolarDireccion(Resources::Direccion::Abajo);
            break;
        case Qt::Key_Left:
            encolarDireccion(Resources::Direccion::Izquierda);
            break;
        }
    }

    QGraphicsPixmapItem::keyPressEvent(event);
}
