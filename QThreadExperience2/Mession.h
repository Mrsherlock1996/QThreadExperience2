#pragma once

#include <QWidget>
#include "ui_Mession.h"
#include <qdebug.h>
#include <qtimer.h>
#include <qthread.h>
#include "SubMession.h"
#include <qtimer.h>
class Mession : public QObject
{
	Q_OBJECT

public:
	Mession(QObject *parent = Q_NULLPTR);
	~Mession();
	double _version;
	void printInfo();
	int _count = 0;
	SubMession* _subM1;
	QTimer* _t1;
	QLabel* _labelM;
private:
	Ui::Mession ui;
};
