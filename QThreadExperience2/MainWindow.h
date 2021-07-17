#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <qthread.h>
#include"Mession.h"
#include <qdebug.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
	QThread* _t1;
	//Mession* _m1;
private:
    Ui::MainWindowClass ui;
private slots:
	void on_pushButton_clicked();
signals:
	void sendData(double a);
};
