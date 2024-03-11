#include "win.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // обьект обрабатывает инициализацию и финализацию виджета.
    Win win(0); // создание окна
    win.show(); // показать
    return app.exec(); // ждет закрытия приложения
}
