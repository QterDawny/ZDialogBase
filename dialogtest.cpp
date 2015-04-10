#include "dialogtest.h"
#include "ui_dialogtest.h"
#include "zdialogbase.h"

DialogTest::DialogTest(QWidget *parent) :
    ZDialogBase(parent),
    ui(new Ui::DialogTest)
{
    ui->setupUi(this);
}

DialogTest::~DialogTest()
{
    delete ui;
}
