#pragma once

#include <QObject>
#include <QThread>
#include <qdebug.h>
#include <qlabel.h>
#include <qstring.h>
#include <opencv2/opencv.hpp>
#include "ConvertMatQImage.h"
class SubMession : public QObject
{
	Q_OBJECT

public:
	SubMession(QObject *parent);
	SubMession();
	~SubMession();
	QLabel * _label;
	ConvertMatQImage* _cvt;
	void printName();
};
