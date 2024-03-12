#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter) // поворот фигуры
{
    // вычисление новых координат, halflen определяет размер фигур
    dx=halflen*cos(Alpha);
    dy=halflen*sin(Alpha);
    draw(Painter);
}
void MyLine::draw(QPainter *Painter) // рисует линию
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);
}
void MyRect::draw(QPainter *Painter) // рисует квадрат
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
