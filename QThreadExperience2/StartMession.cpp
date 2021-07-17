#include "StartMession.h"

StartMession::StartMession(QObject *parent):QThread(parent)
{
	_mession = new Mession();

}

StartMession::~StartMession()
{
}

void StartMession::run()
{
	qDebug() << "StartMession Thread: " << QThread::currentThread() << endl;
	QTimer*_timer = new QTimer();
	connect(_timer, &QTimer::timeout, _mession, &Mession::printInfo);
	_mession->_version = 12.34;
	_timer->start(2);
	exec();
}
