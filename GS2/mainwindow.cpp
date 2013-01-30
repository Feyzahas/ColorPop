#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>

#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    QString path = QFileDialog::getOpenFileName (this, tr("Directory"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    //QString fileName = QFileDialog.getOpenFileName(this, tr("Open Image"),
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
