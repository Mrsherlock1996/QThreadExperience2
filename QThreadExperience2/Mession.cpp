#include "Mession.h"

Mession::Mession(QObject *parent)
	:QObject(parent)
{

}
Mession::~Mession()
{
}

void Mession::printInfo()
{
	while (_count<10)
	{
		qDebug() << "version: " << _version << endl;
		qDebug() << "Mession current thread" << QThread::currentThread() << endl;
		_count++;
	}
}
