#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>

#include <iostream>



#include<Magick++.h>

using namespace Magick;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitializeMagick(NULL);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    QString path = QFileDialog::getOpenFileName (this, tr("Directory"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    //QString fileName = QFileDialog.getOpenFileName(this, tr("Open Image"),
    fname = path;
    ui->pictureLabel->setPixmap(path);
}

void MainWindow::on_tValueSlider_valueChanged(int value)
{
    QLabel *l = ui->tValueLabel;
    QSlider *s = ui->tValueSlider;
    double val = ((double)s->value())/((double)s->maximum());
    char txt[100];
    sprintf(txt, "%.2f", val);
    QString txtString = QString::fromAscii(txt);
    l->setText(txtString);
}

void MainWindow::on_pushButton_clicked()
{
  //copy the top till val;
   double val;
    double ptx, pty;
    ptx = points.back().x() / ((double)ui->pictureLabel->width());
    pty = point.back().y() / ((double) ui->pictureLabel->height());

   //all done
   points.clear();

}


void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pt = event->pos();
    QLabel *l = ui->pictureLabel;
    QPoint orig = l->pos();
    int wdth = l->width();
    int ht = l->height();

    if (((pt.x() >= orig.x()) && (pt.x() <= (orig.x()+wdth))) && ((pt.y() >= orig.y()) && (pt.y() <= (orig.y() + ht)))){

        points.push_back(QPoint(pt.x()-orig.x(), pt.y()-orig.y()));
        char tmp[100];
        sprintf(tmp, "%d: (%d,%d)", points.size(), points.back().x(), points.back().y());
        QString txtString = QString::fromAscii(tmp);
        ui->positionLabel->setText(txtString);
    }
}


