#pragma once

#include <QObject>
#include <qthread.h>
#include "Mession.h"
#include <qtimer.h>
class StartMession : public QThread
{
	Q_OBJECT

public:
	explicit StartMession(QObject *parent = nullptr);
	~StartMession();
	Mession* _mession;
	//QTimer* _timer;
protected:
	void run();
};
