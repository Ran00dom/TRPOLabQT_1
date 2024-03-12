#include "area.h"
Area::Area(QWidget *parent):QWidget(parent) // конструктор
{
    setFixedSize(QSize(300,200));
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}
void Area::showEvent(QShowEvent *) // событие отображения виджета
{
    myTimer=startTimer(50); // создать таймер и сохранить его id в myTimer
}
void Area::paintEvent(QPaintEvent *) // событие обнавления холста
{
    QPainter painter(this); // создание пера
    painter.setPen(Qt::red); // установка цвета пера
    myline->move(alpha,&painter); // отрисовка фигуры с наклоном
    myrect->move(alpha*(-0.5),&painter); // отрисовка фигуры с наклоном
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной
    // обработки
}
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{
    delete myline;
    delete myrect;
}
