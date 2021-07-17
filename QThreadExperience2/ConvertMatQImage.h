#pragma once

#include <QObject>
#include <opencv.hpp>
#include <qimage.h>
#include <qdebug.h>
/*����:
		����Mat��QImage����ת��
		QImage��Ҫ����:
			    QImage::Format
				QImage::Format_Invalid ͼ����Ч
				QImage::Format_Mono �洢ʹ��1λÿ���ص�ͼ���ֽ��������Ҫλ��һ
				QImage::Format_MonoLSB �洢ʹ��1λÿ���ص�ͼ���ֽ���䲻����λ��һ
				QImage::Format_Indexed8 ͼ��洢ʹ��8λָ��ת����Colormap
				QImage::Format_RGB32 �洢ʹ��32λRGB��ʽ��ͼ��(0xffrrggbb)
				QImage::Format_ARGB32 �洢ʹ��32ΪARGB��ʽ��ͼ��(0xaarrggbb)
				QImage::Format_ARGB32_Premultiplied ͼ��洢ʹ��һ�������32λARGB��ʽ
				QImage::Format_RGB16 ͼ��洢ʹ��5-6-5 16λRGB��ʽ
				QImage::Format_ARGB8565_Premultiplied ͼ��洢ʹ��һ�������24λARGB��ʽ8-5-6-5
				QImage::Format_RGB666 ͼ��洢ʹ��6-6-6 24λRGB��ʽ��δʹ�õ�����Ҫ��λ����Ϊ��
				QImage::Format_ARGB6666_Premultiplied ͼ��洢ʹ��һ�������24λARGB��ʽ6-6-6-6
				QImage::Format_RGB555 ͼ��洢ʹ��16λRGB��ʽ��5-5-5����λ���õ�����Ҫ��ʼ��Ϊ��
				QImage::Format_ARGB8555_Premultiplied ͼ��洢ʹ��һ�������24λARGB��ʽ8-5-5-5
				QImage::Format_RGB888 ͼ��洢ʹ��8-8-8 24λRGB��ʽ
				QImage::Format_RGB444 ͼ��洢ʹ��16λRGB��ʽ��4-4-4��δʹ�õ�λʼ��Ϊ��
				QImage::Format_ARGB4444_Premultiplied ͼ��洢ʹ��һ�������16λARGB��ʽ4-4-4-4
				QImage::Format_RGBX8888 ͼ��洢ʹ��32λ�ֽ�����RGB��x����ʽ8-8-8-8
				QImage::Format_RGBA8888 �洢ʹ��32λ�ֽ�����RGBA��ʽ��8-8-8-8���ĵ�ͼ��
				QImage::Format_RGBA8888_Premultiplied ͼ��洢ʹ��һ�������32λ�ֽ�����RGBA��ʽ8-8-8-8
				QImage::Format_BGR30 �洢ʹ��32λBGR��ʽ��x-10-10-10���ĵ�ͼ��
				QImage::Format_A2BGR30_Premultiplied ͼ��洢ʹ��32λ�����abgr��ʽ2-10-10-10
				QImage::Format_RGB30 �洢ʹ��32λRGB��ʽ��x-10-10-10���ĵ�ͼ��
				QImage::Format_A2RGB30_Premultiplied ͼ��洢ʹ��2-10-10-10 32λ�����ARGB��ʽ
				QImage::Format_Alpha8 ��ͼ����ʹ��һ��8λ�İ�������ʽ�洢
				QImage::Format_Grayscale8 ͼ����ʹ��һ��8λ�Ҷȸ�ʽ�洢
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
