1��ʹ��oleview���߲���ActiveX�ռ��clsid
OLEVIEW.EXE
clsid:{00020906-0000-0000-C000-000000000046}

2��ʹ��qt��dumpcpp.exe���ߵ����ඨ��
dumpcpp.exe {00020906-0000-0000-C000-000000000046}
������word.cpp word.h

3���޸�word.h�����enum�ඨ��
namespace Office {
    enum MsoArrowheadStyle{
		msoArrowheadDiamond           =0x5,
		msoArrowheadNone              =0x1,
		msoArrowheadOpen              =0x3,
		msoArrowheadOval              =0x6,
		msoArrowheadStealth           =0x4,
		msoArrowheadStyleMixed        =-2 ,
		msoArrowheadTriangle          =0x2,
	};

	enum MsoArrowheadLength{
		msoArrowheadLengthMedium      =0x2,
		msoArrowheadLengthMixed       =-2 ,
		msoArrowheadLong              =0x3,
		msoArrowheadShort             =0x1,
	};

	enum MsoAlignCmd{
		msoAlignBottoms               =0x5,
		msoAlignCenters               =0x1,
		msoAlignLefts                 =0x0,
		msoAlignMiddles               =0x4,
		msoAlignRights                =0x2,
		msoAlignTops                  =0x3,
	};
	
	......
}

4����word.cpp word.h��ӵ���Ŀ

#include <QtGui/QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include "word.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//����һ�����ĵ�
	Word::Document *doc = new Word::Document();
	if(!doc){
		QMessageBox::warning(NULL, QString("Warning"),\
			QString("Fail to Word::Application()")\
		);
		return 0;
	}

	//��ӡ��ǰ�ĵ���
	qDebug()<< "RET: " << doc->Name();

	//���ĵ���д����Ϣ
	doc->Range()->SetText("hello world office word 2003");

	//�����ĵ�
	QVariant filename = QVariant(QDir::currentPath()+"/a.doc");
	doc->SaveAs(filename);

	//�ر��ĵ�
	doc->Close();

	delete doc;

	return 0;
}