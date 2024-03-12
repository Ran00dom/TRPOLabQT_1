#include "win.h"

Win::Win(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8"); // изменяем кодировку для русского
    setWindowTitle(codec->toUnicode("Возведение в квадрат")); // Изменяем отображаемое название виджета
    frame = new QFrame(this); // создаем рамку и связываем с окном
    frame->setFrameShadow(QFrame::Raised); // эффект тени на рамке
    frame->setFrameShape(QFrame::Panel); // рисует заполненую рамку draws a panel to make the contents appear raised or sunken
    inputLabel = new QLabel(codec->toUnicode("Введите число:"), // создаем текстовую строку с именем, связываем с окном
                            this);
    inputEdit = new QLineEdit("",this); // создаем стрку ввода начального значения
    StrValidator *v=new StrValidator(inputEdit); // создаем обьект контроля событий который прослушивает inputEdit
    inputEdit->setValidator(v); // устанавливаем валидатор для строки ввода
    outputLabel = new QLabel(codec->toUnicode("Результат:"), // текст с именем
                             this);
    outputEdit = new QLineEdit("",this); // текстовое поле с ответом
    nextButton = new QPushButton(codec->toUnicode("Следующее"), // кнопка обнуляющая результат
 this);
    exitButton = new QPushButton(codec->toUnicode("Выход"), // кнопка выхода
 this);
    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // создаем вертикальный блок для элементов
    // элементы блока ответов
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout(); // создаем вертикальный блок для элементов
    // блок кнопок справа
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this); // создаем горизонтальный блок для элементов
    // добавляем созданые блоки в один
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin(); // обновляем программу

    // Новыя версия сигнально-слотовых соединений
    connect(exitButton,&QPushButton::clicked, // сигнал типа "клик" кнопки exitButton связываем с слотом close() обьекта win
            this, &Win::close);
    connect(nextButton,&QPushButton::clicked, // сигнал типа "клик" кнопки nextButton связываем с слотом begin() обьекта win
            this,&Win::begin);
    connect(inputEdit,&QLineEdit::returnPressed, // сигнал типа "нажатие кнопки" (Этот сигнал издается при использовании клавиши Return или Enter.) текстового поля inputEdit связываем с слотом calc() обьекта win
            this,&Win::calc);
}
void Win::begin() // обновление интерфейса программы
{
    inputEdit->clear();
    inputEdit->setEnabled(true);

    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);

    inputEdit->setFocus();
}
void Win::calc() // вычисление значений
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text(); // записываем текст из inputEdit в str
    a=str.toDouble(&Ok); // переводим str в Float a и устанавливаем флаг OK
    if (Ok) // если преобразование успешно, производим расчет и выводи информацию, изменяем интерфейс
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else // если во время преобразования произошли проблемы
        if (!str.isEmpty()) // если пользователь ввел строку
        {  // создаем окно с уведомлением о неправильном формате ввода
            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Возведение в квадрат."),
                               codec->toUnicode("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
}
