#ifndef WIN_H
#define WIN_H

#include <QtWidgets>

class Counter:public QLineEdit // создаем новый класс редактируемой строки
{

 Q_OBJECT // макрос для компиляции слотов и сигналов

public:

 Counter(const QString & contents, QWidget *parent=0): // конструктор
 QLineEdit(contents,parent){}

signals:
 void tick_signal(); // новый сигнал, каждый раз при изменении
public slots:
 void add_one() // новый слот
 {
 QString str=text(); // записываем текст из текстового поля
 int r=str.toInt(); // переводим в int
 if (r!=0 && r%5 ==0) emit tick_signal(); // если значение не 0 и кратно 5 вызвать сигнал tick_signal
 r++;
 str.setNum(r);
 setText(str); // устанавливаем новый текст в поле
 }
};

class Win: public QWidget // новый класс окна
{
 Q_OBJECT
protected:
 QTextCodec *codec;
 QLabel *label1,*label2;
 Counter *edit1,*edit2;
 QPushButton *calcbutton;
 QPushButton *exitbutton;
public:
 Win(QWidget *parent = 0);
};

#endif // WIN_H
