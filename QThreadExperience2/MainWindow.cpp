#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	_t1 = new QThread;
	Mession* _m1 = new Mession();
	_m1->_labelM = ui.label;
	_m1->moveToThread(_t1);
	connect(_t1, &QThread::started, _m1, &Mession::printInfo,Qt::QueuedConnection);
	//connect(this, &MainWindow::sendData,_m1, &Mession::printInfo);
	//_t1->start();

}
void MainWindow::on_pushButton_clicked()
{
	qDebug() << "mainWindow thread:" << QThread::currentThread() << endl;
	_t1->start();
	//emit sendData(1);
}