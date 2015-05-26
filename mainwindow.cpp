#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Okno 1"));



    model = new QStringListModel(this);
    QStringList list;
    list << "one" << "two" << "three" << "four";
    model->setStringList(list);
    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{


}
