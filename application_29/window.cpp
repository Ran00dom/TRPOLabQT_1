#include "window.h"

Window::Window()
{
 codec = QTextCodec::codecForName("UTF-8");
 this->setWindowTitle(codec->toUnicode("Обработка событий"));
 area = new Area( this );
 btn = new QPushButton(codec->toUnicode("Завершить"),this );
 QVBoxLayout *layout = new QVBoxLayout(this);
 layout->addWidget(area);
 layout->addWidget(btn);

 // Новый вид сигнально-слотовых соединений
 connect(btn,&QPushButton::clicked,this,&Window::close);
};


