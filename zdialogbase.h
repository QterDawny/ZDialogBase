#ifndef ZDIALOGBASE_H
#define ZDIALOGBASE_H

#include <QDialog>

namespace Ui {
class ZDialogBase;
}

class ZDialogBase : public QDialog
{
    Q_OBJECT

public:
    explicit ZDialogBase(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~ZDialogBase();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void changeEvent(QEvent *);
    bool eventFilter(QObject *, QEvent *);

private slots:
    void slot_maxOrRestore();

private:
    Ui::ZDialogBase *ui;

    bool isMaxWindow;
    bool isDraggingWindow;
    QPoint lastPos;
    QPoint globalPos;
    bool isAltF4Pressed;

};

#endif // ZDIALOGBASE_H
