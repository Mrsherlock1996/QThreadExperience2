#pragma once

#include <QObject>
#include <opencv.hpp>
#include <qimage.h>
#include <qdebug.h>
/*功能:
		负责Mat和QImage类型转换
		QImage主要类型:
			    QImage::Format
				QImage::Format_Invalid 图像无效
				QImage::Format_Mono 存储使用1位每像素的图像，字节填充最重要位第一
				QImage::Format_MonoLSB 存储使用1位每像素的图像，字节填充不显著位第一
				QImage::Format_Indexed8 图像存储使用8位指标转化成Colormap
				QImage::Format_RGB32 存储使用32位RGB格式的图像(0xffrrggbb)
				QImage::Format_ARGB32 存储使用32为ARGB格式的图像(0xaarrggbb)
				QImage::Format_ARGB32_Premultiplied 图像存储使用一个自左乘32位ARGB格式
				QImage::Format_RGB16 图像存储使用5-6-5 16位RGB格式
				QImage::Format_ARGB8565_Premultiplied 图像存储使用一个自左乘24位ARGB格式8-5-6-5
				QImage::Format_RGB666 图像存储使用6-6-6 24位RGB格式，未使用的最重要的位总是为零
				QImage::Format_ARGB6666_Premultiplied 图像存储使用一个自左乘24位ARGB格式6-6-6-6
				QImage::Format_RGB555 图像存储使用16位RGB格式（5-5-5），位置用的最重要的始终为零
				QImage::Format_ARGB8555_Premultiplied 图像存储使用一个自左乘24位ARGB格式8-5-5-5
				QImage::Format_RGB888 图像存储使用8-8-8 24位RGB格式
				QImage::Format_RGB444 图像存储使用16位RGB格式（4-4-4）未使用的位始终为零
				QImage::Format_ARGB4444_Premultiplied 图像存储使用一个自左乘16位ARGB格式4-4-4-4
				QImage::Format_RGBX8888 图像存储使用32位字节命令RGB（x）格式8-8-8-8
				QImage::Format_RGBA8888 存储使用32位字节命令RGBA格式（8-8-8-8）的的图像
				QImage::Format_RGBA8888_Premultiplied 图像存储使用一个自左乘32位字节命令RGBA格式8-8-8-8
				QImage::Format_BGR30 存储使用32位BGR格式（x-10-10-10）的的图像
				QImage::Format_A2BGR30_Premultiplied 图像存储使用32位自左乘abgr格式2-10-10-10
				QImage::Format_RGB30 存储使用32位RGB格式（x-10-10-10）的的图像
				QImage::Format_A2RGB30_Premultiplied 图像存储使用2-10-10-10 32位自左乘ARGB格式
				QImage::Format_Alpha8 该图像是使用一个8位的阿尔法格式存储
				QImage::Format_Grayscale8 图像是使用一个8位灰度格式存储
*/
class ConvertMatQImage : public QObject
{
	Q_OBJECT

public:
	ConvertMatQImage();
	~ConvertMatQImage();
	QImage matToQImage(const cv::Mat* mat);
	void  qImageToMat(const QImage*, cv::Mat*);
};
