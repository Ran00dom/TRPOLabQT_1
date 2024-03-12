
#include "win.h"

Win::Win(QWidget *parent):QWidget(parent)
{
 codec = QTextCodec::codecForName("UTF-8"); // кодировка текста

 this->setWindowTitle(codec->toUnicode("Счетчик")); // название окна
 // надписи
 label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);
 label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);
// создание обьектов счетчик
 edit1 = new Counter("0",this);
 edit2 = new Counter("0",this);
// создание кнопок
 calcbutton=new QPushButton("+1",this);
 exitbutton=new QPushButton(codec->toUnicode("Выход"),this);
// создание блоков
 QHBoxLayout *layout1 = new QHBoxLayout(); // блок с надписями
 layout1->addWidget(label1);
 layout1->addWidget(label2);
 QHBoxLayout *layout2 = new QHBoxLayout(); // блок с счетчиками
 layout2->addWidget(edit1);
 layout2->addWidget(edit2);
 QHBoxLayout *layout3 = new QHBoxLayout(); // блок с кнопками
 layout3->addWidget(calcbutton);
 layout3->addWidget(exitbutton);
 QVBoxLayout *layout4 = new QVBoxLayout(this); // общий блок
 layout4->addLayout(layout1);
 layout4->addLayout(layout2);
 layout4->addLayout(layout3);

 // Блокировка Counter
 edit1->setEnabled(false);
 edit2->setEnabled(false);

 // связь сигнала нажатия кнопки и слота закрытия окна
 // Новый вид сигнально-слотовой связи.
 connect(calcbutton,&QPushButton::clicked,
 edit1,&Counter::add_one);

 connect(edit1,&Counter::tick_signal,
 edit2,&Counter::add_one);

 connect(exitbutton,&QPushButton::clicked,
 this,&Win::close);
}

