#include "Window.h"
#include <QtWidgets/QApplication>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI gui = GUI();
    gui.display_windows();
    return a.exec();
}
