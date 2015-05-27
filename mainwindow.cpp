#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QInputDialog>
#include <QMessageBox>


#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Okno 1"));

    dialog = new Dialog(this);
    dialog->setModal(true);
    dialog->show();

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
    //Exit button
    this->close();

}

void MainWindow::on_pushButton_3_clicked()
{
    //Insert button
    int row = this->model->rowCount();
    model->insertRows(row,1);
    QModelIndex mi = model->index(row);
}

void MainWindow::on_pushButton_clicked()
{
    //Modify button

    dialog = new Dialog(this);
    connect(dialog,SIGNAL(signal1(QString)),this,SLOT(slot_1(QString)));
    dialog->show();
    //disconnect(dialog,SIGNAL(signal1(QString)),this,SLOT(slot_1(QString)));

}


void MainWindow::slot_1(QString s)
{
    QMessageBox::information(this,"Title",s);
}
