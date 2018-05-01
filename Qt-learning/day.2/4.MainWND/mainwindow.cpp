#include "mainwindow.h"  

#include <QWidget>

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QListWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>

#include <QFileDialog>

#include <QDebug>

// ������ʵ��
MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags):
    QMainWindow(parent, flags)
{
    /*QWidget*/
    setWindowTitle(tr("Demo for DOC"));
    text = new QTextEdit(this);
    setCentralWidget(text);

    statusbar = this->statusBar();

    createActions();
    createMenus();
    createToolBars();

    label = new QLabel(statusbar);
    label->setText(tr("label for Status"));
    statusbar->addWidget(label);

    btn = new QPushButton(statusbar);
    btn->setText(tr("StatusBtn"));
    statusbar->addWidget(btn);

    QComboBox *cbox =  new QComboBox(editTool);
    QStringList ls;
    ls << "NO.1" << "NO.2" << "NO.3";
    cbox->addItems(ls);
    statusbar->addWidget(cbox);


    //statusbar->setAttribute(Qt::WA_RightToLeft);

    this->setMinimumSize(640,480);
}
MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    // file open action

    fileOpenAction = new QAction(QIcon(":/images/open.png"),tr("Open"),this);	// ���ļ�
    fileOpenAction->setShortcut(tr("Ctrl+O"));
    fileOpenAction->setStatusTip(tr("open a file"));
    connect(fileOpenAction,SIGNAL(triggered()),this,SLOT(slotOpenFile()));

    
    // file new action
    fileNewAction = new QAction(QIcon(":/images/new.png"),tr("New"),this);	// �½��ļ�
    fileNewAction->setShortcut(tr("Ctrl+N"));
    fileNewAction->setStatusTip(tr("new file"));
    connect(fileNewAction,SIGNAL(triggered()),this,SLOT(slotNewFile()));

    // save file action
    fileSaveAction = new QAction(QPixmap(":/images/save.png"),tr("Save"),this);	// �����ļ� 
    fileSaveAction->setShortcut(tr("Ctrl+S"));
    fileSaveAction->setStatusTip(tr("save file"));
    connect(fileSaveAction,SIGNAL(triggered()),this,SLOT(slotSaveFile()));

    // exit action
    exitAction = new QAction(tr("Exit"), this);	// �˳�
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("exit"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    cutAction = new QAction(QIcon(":/images/cut.png"), tr("Cut"), this);		// ����
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("cut to clipboard"));
    connect(cutAction, SIGNAL(triggered()), text, SLOT(cut()));

    copyAction = new QAction(QIcon(":/images/copy.png"), tr("Copy"), this);		// ����
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("copy to clipboard"));
    connect(copyAction, SIGNAL(triggered()), text, SLOT(copy()));

    pasteAction = new QAction(QIcon(":/images/paste.png"), tr("Paste"), this);		// ճ��
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("paste clipboard to selection"));
    connect(pasteAction, SIGNAL(triggered()), text, SLOT(paste()));

    aboutAction = new QAction(tr("About"), this);		// ����
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(slotAbout()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("File"));
    editMenu = menuBar()->addMenu(tr("Edit"));
    aboutMenu = menuBar()->addMenu(tr("Help"));
    
    fileMenu->addAction(fileNewAction);
    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(fileSaveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    
    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);
    
    aboutMenu->addAction(aboutAction);
         
}

void MainWindow::createToolBars()
{
	
    fileTool = addToolBar("File");
    fileTool->setMovable(true);
    editTool = addToolBar("Edit");
    
    fileTool->addAction(fileNewAction);
    fileTool->addAction(fileOpenAction);
    fileTool->addAction(fileSaveAction);
    
    editTool->addAction(copyAction);
    editTool->addAction(cutAction);
    editTool->addAction(pasteAction);

    QListWidget *list = new QListWidget(editTool);
    list->addItem("demo 1");
    list->addItem("demo 2");
    list->addItem("demo 3");
    list->addItem("demo 4");
    list->addItem("demo 5");
    list->addItem("demo 6");
    list->setMaximumHeight(2*editTool->height());
    list->setMaximumWidth(120);
    list->setStatusTip("Demo for QListWidget");
    editTool->addWidget(list);

    editTool->addSeparator();

    QComboBox *cbox =  new QComboBox(editTool);
    QStringList ls;
    ls << "NO.1" << "NO.2" << "NO.3";
    cbox->addItems(ls);
    cbox->setStatusTip("Demo for QComboBox");
    editTool->addWidget(cbox);

    editTool->addSeparator();

    QCheckBox *checkbox = new QCheckBox(tr("Status Hide"),editTool);
    checkbox->setEnabled(true);
    checkbox->setChecked(false);
    checkbox->setStatusTip(tr("demo for QCheckBox"));
    QObject::connect(checkbox, SIGNAL(clicked(bool)), statusbar, SLOT(setHidden(bool)));
    editTool->addWidget(checkbox);
}

void MainWindow::slotNewFile()
{
    //��������ʾ�´���
    MainWindow *newdoc = new MainWindow;
    newdoc->show();
}

void MainWindow::slotOpenFile()
{
    QString str = QFileDialog::getOpenFileName(this,
                                 "Open",
                                 QDir::currentPath(),
                                 "TXT(*.txt);;All(*.*)");
    if(str == "")
        return;
}

void MainWindow::slotSaveFile()
{
    QString str = QFileDialog::getSaveFileName(this,
                                 "Save",
                                 QDir::currentPath(),
                                 "TXT(*.txt);;All(*.*)");
    if(str == "")
        return;
}

void MainWindow::slotAbout()
{
}


