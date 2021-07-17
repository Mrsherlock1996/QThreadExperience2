#include "SubMession.h"

SubMession::SubMession(QObject *parent)
	: QObject(parent)
{
}
SubMession::SubMession()
{

}

SubMession::~SubMession()
{
}

void SubMession::printName()
{
	using namespace cv;
	qDebug() << "SubMession Thread: " << QThread::currentThread() << endl;
	VideoCapture cap(0);
	Mat frame;
	cap.read(frame);
	QImage img;
	Mat gray;
	while (cap.read(frame))
	{
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		img = _cvt->matToQImage(&gray);
		_label->setPixmap(QPixmap::fromImage(img));
	}
}
