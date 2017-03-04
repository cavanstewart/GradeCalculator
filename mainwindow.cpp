#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hw1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int hw1 = ui->spinBox->value();
    ui->label_13->setNum(hw1);
    //connect(ui->spinBox,SIGNAL(valueChanged(int)),calc,SLOT(compute_hw(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
