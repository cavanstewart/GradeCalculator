#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->insertItem(0, "PIC 10B");
    ui->comboBox->insertItem(1, "PIC 10C");

    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeScheme()));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_3,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_4,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_5,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_6,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_7,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_8,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_9,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_10,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));
    connect(ui->spinBox_11,SIGNAL(valueChanged(int)),this,SLOT(calculateGrade()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateGrade(){
    if (ui->comboBox->currentIndex()==0){
        const int ARRAY_SIZE = 8;
        int hw[ARRAY_SIZE] = {ui->spinBox->value(),ui->spinBox_2->value(),
                             ui->spinBox_3->value(),ui->spinBox_4->value(),
                             ui->spinBox_5->value(),ui->spinBox_6->value(),
                             ui->spinBox_7->value(),ui->spinBox_8->value()};
        int min = hw[0];
        for (int i=0;i<ARRAY_SIZE;++i){
            if (hw[i]<min)
             min = hw[i];
        }
        double hwTotal=0;
        for (int i=0;i<ARRAY_SIZE;i++){
            hwTotal += hw[i];
        }
        int numHW = 7;
        int maxHWScore = 20;
        hwTotal = 100 * (hwTotal - min)/(maxHWScore * numHW);
        double midtermTotal = (ui->spinBox_9->value() + ui->spinBox_10->value())/2;
        double finalTotal = ui->spinBox_11->value();

        double grade = (hwTotal * .25) + (midtermTotal * .40) + (finalTotal * .35);
        ui->label_13->setNum(grade);
    }
    else{


    }
  }

void MainWindow::changeScheme(){
    switch(ui->comboBox->currentIndex()){
        case 0 : ui->horizontalSlider_10->setVisible(true);
            ui->spinBox_10->setVisible(true);
            ui->label_10->setVisible(true);
            break;
        case 1 : ui->horizontalSlider_10->setVisible(false);
            ui->spinBox_10->setVisible(false);
            ui->label_10->setVisible(false);
            break;
    }
}
