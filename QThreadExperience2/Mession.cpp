#include "Mession.h"

Mession::Mession(QObject *parent)
	:QObject(parent)
{
	_subM1 = new SubMession;

}
Mession::~Mession()
{
}

void Mession::printInfo()
{
	_subM1->_label = _labelM;
	while (_count<3)
	{
		qDebug() << "Mession current thread" << QThread::currentThread() << endl;
		//_subM1->printName();
		_count++;
	}
	_subM1->printName();
}
