#include "zdialogbase.h"
#include "dialogtest.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZDialogBase w(0, Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    w.show();

    return a.exec();
}
