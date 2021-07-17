#include "ConvertMatQImage.h"
#include "qdebug.h"
ConvertMatQImage::ConvertMatQImage()
{
}

ConvertMatQImage::~ConvertMatQImage()
{
}


//Mat转QImage, 从网上学习到的方法
//Mat是bgr QImage是rgb
QImage ConvertMatQImage::matToQImage(const cv::Mat * mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1
	if (mat->type() == CV_8UC1)
	{
		QImage image(mat->cols, mat->rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat
		uchar *pSrc = mat->data;
		for (int row = 0; row < mat->rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat->cols);
			pSrc += mat->step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3
	else if (mat->type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat->data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat->cols, mat->rows, mat->step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat->type() == CV_8UC4)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat->data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat->cols, mat->rows, mat->step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "can not match mat.type()";
	}
}

void ConvertMatQImage::qImageToMat(const QImage * image, cv::Mat* matImage)
{
	switch (image->format())
	{
		//ARGB32,RGB32,ARGB32_Premultiplied 类型转换成Mat
	case QImage::Format_ARGB32:
	case QImage::Format_RGB32:
	case QImage::Format_ARGB32_Premultiplied:
		qDebug() << image->format();
		*matImage = cv::Mat(image->height(), image->width(), CV_8UC4, (void*)image->constBits(), image->bytesPerLine());
		break;

		//RGB888转换成Mat
	case QImage::Format_RGB888:
	{
		*matImage = cv::Mat(image->height(), image->width(), CV_8UC3, (void*)image->constBits(), image->bytesPerLine());
		cv::cvtColor(*matImage, *matImage, CV_BGR2RGB);
		//QImage Format_RGB888是按照R,G,B排布，  Mat按照B,G,R排布， 因而，需要进行互换
		break;
	}

		//Indexed8转换成Mat
	case QImage::Format_Indexed8:
		*matImage = cv::Mat(image->height(), image->width(), CV_8UC1, (void*)image->constBits(), image->bytesPerLine());
		break;
	}
}
