#ifndef FIGURA_H
#define FIGURA_H

#include <QtWidgets>

class Figura // базовый класс фигуры
{
protected:
    int x,y,halflen,dx,dy,r; // атрибуты, halflen - размер фигуры, x,y - центр, dx,dy - новая точка
    virtual void draw(QPainter *Painter)=0; // рисует фигуру
public:
    Figura(int X,int Y,int Halflen): // конструктор
        x(X),y(Y),halflen(Halflen){}

    void move(float Alpha,QPainter *Painter); // поворот фигуры
};

class MyLine:public Figura // линия
{
protected:
    void draw(QPainter *Painter); // переопределенная
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){} // конструктор
};

class MyRect:public Figura // квадрат
{
protected:
    void draw(QPainter *Painter); // переопределенная
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){} // конструктор
};

#endif // FIGURA_H
