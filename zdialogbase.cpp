#include "zdialogbase.h"
#include "ui_zdialogbase.h"

#include <QMouseEvent>
#include <QDesktopWidget>

ZDialogBase::ZDialogBase(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint),
    ui(new Ui::ZDialogBase),
    isDraggingWindow(false), isMaxWindow(false), isAltF4Pressed(false)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);

    if (0 == (f & Qt::WindowMinimizeButtonHint)) {
        ui->btn_min->hide();
    }
    if (0 == (f & Qt::WindowMaximizeButtonHint)) {
        ui->btn_max->hide();
    }
    if (0 == (f & Qt::WindowCloseButtonHint)) {
        ui->btn_close->hide();
    }

    connect(ui->btn_max, SIGNAL(clicked()), SLOT(slot_maxOrRestore()));

    installEventFilter(this);
}

ZDialogBase::~ZDialogBase()
{
    delete ui;
}

void ZDialogBase::mousePressEvent(QMouseEvent *e)
{
    if (isMaxWindow) return;
    if (e->buttons() & Qt::LeftButton) {
        int ex = e->pos().x();
        int ey = e->pos().y();

        int tlx = ui->wgt_title->pos().x();
        int tly = ui->wgt_title->pos().y();

        int brx = tlx + ui->wgt_title->width();
        int bry = tly + ui->wgt_title->height();

        if (ex > tlx && ex < brx && ey > tly && ey < bry) {
            isDraggingWindow = true;
            lastPos = e->pos();
        }
    }
}

void ZDialogBase::mouseMoveEvent(QMouseEvent *e)
{
    if(isDraggingWindow) {
        move(e->globalPos() - lastPos);
    }
}

void ZDialogBase::mouseReleaseEvent(QMouseEvent */*e*/) {
    isDraggingWindow = false;
}

void ZDialogBase::keyPressEvent(QKeyEvent *e) {
    e->ignore();
}

void ZDialogBase::changeEvent(QEvent *e) {
    if(e->type()== QEvent::WindowStateChange
            && this->windowState() == Qt::WindowNoState) {
        repaint();
    }
}

bool ZDialogBase::eventFilter(QObject *obj, QEvent *event) {
    if(obj->isWidgetType()) {
        switch(event->type()) {
        case QEvent::Close: {
            if(isAltF4Pressed){
                isAltF4Pressed = false;
                event->ignore();
                return true;
            }
            break;
        }
        case QEvent::KeyPress: {
            if(((QKeyEvent*)event)->key() == Qt::Key_F4
                    || (((QKeyEvent*)event)->modifiers() == Qt::AltModifier)) {
                isAltF4Pressed = true;
            }
            break;
        }
        default: break;
        }
    }
    return QObject::eventFilter(obj, event);
}

void ZDialogBase::slot_maxOrRestore() {
    static QPoint lastPos;
    static QSize lastSize;
    if(isMaxWindow) {
        move(lastPos);
        resize(lastSize);
    } else {
        lastPos = mapToGlobal(rect().topLeft());
        lastSize = size();

        // multi screen
        int screen = qApp->desktop()->screenNumber(this);
        QRect rect = qApp->desktop()->availableGeometry(screen);
        move(rect.topLeft());
        resize(rect.size());
    }
    isMaxWindow = !isMaxWindow;
}
