#ifndef AREA_H
#define AREA_H

#include "figura.h"
class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
public:
    Area(QWidget *parent = 0); // конструктор
    ~Area();
    // фигуры
    MyLine *myline;
    MyRect *myrect;
protected:
    // обработчики событий
    void paintEvent(QPaintEvent *event); // рисует MyLine и MyRect
    void timerEvent(QTimerEvent *event); // прослушивает таймер
    void showEvent(QShowEvent *event); //
    void hideEvent(QHideEvent *event);
};
#endif // AREA_H
