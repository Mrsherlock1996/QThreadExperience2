#pragma once

#include <QWidget>
#include "ui_Mession.h"
#include <qdebug.h>
#include <qtimer.h>
#include <qthread.h>
class Mession : public QObject
{
	Q_OBJECT

public:
	Mession(QObject *parent = Q_NULLPTR);
	~Mession();
	double _version;
	void printInfo();
	int _count = 0;

private:
	Ui::Mession ui;
};
