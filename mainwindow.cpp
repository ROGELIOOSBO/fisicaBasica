#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <math.h>
#include <QMessageBox>

using namespace std;
float gravedad = 9.81;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    ui->imagen_proy->setStyleSheet("background-image: url(:/05.jpg)");
    delete ui;
}


void MainWindow::on_bt_calularFuerzaminima_clicked()
{
    double vmasa   = ui->masa->text().toDouble();
    double vangulo = (ui->angulo->text().toDouble());
    double vfus    = ui->fUS->text().toDouble();
    double rf,rfm;

    if (vangulo>90 || vangulo<0) {
        QMessageBox msgBox;
        msgBox.setText("Solo se permite Grados de1 al 90, si se excede grados la formula no funciona.");
        msgBox.exec();
        return;
    }

    vangulo = (ui->angulo->text().toDouble())*M_PI/180;

    rf=(vfus*vmasa*gravedad)/(cos(vangulo)+vfus*sin(vangulo));
    rfm=vfus*rf;
    QString srfm = QString::number(rfm);
    ui->resFuerzaMinima->setText(srfm +" Newtons");
}

void MainWindow::on_bt_calculaFuerza_clicked()
{
    double vmasa   = ui->masa->text().toDouble();
    double vangulo = (ui->angulo->text().toDouble());
    double vfus    = ui->fUS->text().toDouble();
    double rf;

    if (vangulo>90 || vangulo<0) {
        QMessageBox msgBox;
        msgBox.setText("Solo se permite Grados de1 al 90, si se excede grados la formula no funciona.");
        msgBox.exec();
        return;
    }

    vangulo = (ui->angulo->text().toDouble())*M_PI/180;


    rf=(vfus*vmasa*gravedad)/(cos(vangulo)+vfus*sin(vangulo));
    QString srf = QString::number(rf);
    ui->resFuerza->setText(srf+" Newtons");

}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_bt_verificaLey_clicked()
{
    double vmasa   = ui->masa->text().toDouble();
    double vangulo = (ui->angulo->text().toDouble());
    double vfus    = ui->fUS->text().toDouble();
    double rf, ley;

    if (vangulo>90 || vangulo<0) {
        QMessageBox msgBox;
        msgBox.setText("Solo se permite Grados de1 al 90, si se excede grados la formula no funciona.");
        msgBox.exec();
        return;
    }

    vangulo = (ui->angulo->text().toDouble())*M_PI/180;


    rf=(vfus*vmasa*gravedad)/(cos(vangulo)+vfus*sin(vangulo));
    ley=rf*cos(vangulo)-vmasa*gravedad+rf*sin(vangulo)*vfus;

    QString sley = QString::number(ley);
    ui->resLey->setText(sley);

    if (ley==0) {
        QMessageBox msgBox;
        msgBox.setText("Se cumple primera ley de NEWTON.");
        msgBox.exec();
    }

}
