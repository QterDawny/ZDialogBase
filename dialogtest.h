#ifndef DIALOGTEST_H
#define DIALOGTEST_H

#include <QDialog>
#include "zdialogbase.h"

namespace Ui {
class DialogTest;
}

class DialogTest : public ZDialogBase
{
    Q_OBJECT

public:
    explicit DialogTest(QWidget *parent = 0);
    ~DialogTest();

private:
    Ui::DialogTest *ui;
};

#endif // DIALOGTEST_H
