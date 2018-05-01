#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
    class Widget;
}

class BlackScreen;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void slotTest();
    void slotBlackScreen();

private:
    Ui::Widget *ui;

    bool bIsRun;
    QTimer *tm;
    BlackScreen *blkwnd;
};

/*�����ʵ�ֽ��̵Ŀ��ƣ������ڼ����߾�������*/
/*ʵ�ֺ����Ĵ��ڣ������Ҫ�����̼���ڣ��������Ӧ�¼�����*/
class BlackScreen : public QWidget
{
    Q_OBJECT

public:
    explicit BlackScreen(QWidget * parent = 0, Qt::WindowFlags f = 0);
    ~BlackScreen();

protected:
    void paintEvent(QPaintEvent *e);
};


#endif // WIDGET_H
