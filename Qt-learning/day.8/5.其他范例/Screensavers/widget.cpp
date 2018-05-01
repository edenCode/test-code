#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget * parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->connect(ui->pushButton, SIGNAL(clicked()),\
                  this, SLOT(slotTest()));

    tm = new QTimer(this);
    this->connect(tm, SIGNAL(timeout()), this, SLOT(slotBlackScreen()));

    bIsRun = false;
}

Widget::~Widget()
{
    tm->deleteLater();
    delete ui;
}

void Widget::slotTest()
{
    /*��ťģ���������㣬��ʼ����*/
    bIsRun = true;
    /*����������*/
    this->hide();
    blkwnd = new BlackScreen(NULL,Qt::FramelessWindowHint);
    blkwnd->show();

    /*�����ָ�*/
    tm->start(3000);
}

void Widget::slotBlackScreen()
{
    if(bIsRun){
        bIsRun = false;
        /*ģ���������㣬��������*/
        this->show();
        tm->stop();
        if(blkwnd->close()){
            qDebug("close wnd done.\n");
            /*������Դ*/
            blkwnd->deleteLater();
        }else{
            qDebug("close wnd fail.\n");
        }
    }
}

#include <QDesktopWidget>
BlackScreen::BlackScreen(QWidget * parent, Qt::WindowFlags f) :
    QWidget(parent,f)
{
    /*�õ������С�������ô���Ϊ�����С*/
    QDesktopWidget *desk = QApplication::desktop();
    QRect rect = desk->screenGeometry(-1);
    this->resize(rect.width(), rect.height());

    /*���ع��*/
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setCursor(Qt::BlankCursor);
#if 0
    /*����������Ϊ�����㴰�ڣ��ޱ�������������ģʽ������͸���������뽹��*/
    setWindowFlags( Qt::FramelessWindowHint |
                    Qt::Tool |
                    Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setFocusPolicy(Qt::NoFocus);
#endif
}

BlackScreen::~BlackScreen()
{
    /*��ʾ��꣬����ȱ�������ʽ������ָ��Ϊ��ͷ*/
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    this->setCursor(Qt::ArrowCursor);
}

#include <QPainter>
void BlackScreen::paintEvent(QPaintEvent *e)
{
    /*����������ڣ���������ָ����ɫ����ͼƬ*/
    //QPainter pt(this);
    //pt.fillRect(0,0,this->width(),this->height(), Qt::SolidPattern);
    return QWidget::paintEvent(e);
}
