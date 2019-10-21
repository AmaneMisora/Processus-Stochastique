#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// init GroupBoxProblem

    // Question
    ui->ComboBoxQuestion->addItem(" ");
    ui->ComboBoxQuestion->addItem("Combien de client en moyenne seront présents?");
    ui->ComboBoxQuestion->addItem("Combien de temps en moyenne le client sera présent?");
    ui->ComboBoxQuestion->addItem("Combien de client seront perdus?");
    ui->ComboBoxQuestion->addItem("Quelle est la probilité d'avoir ce nombre de clients dans la file?");
    ui->ComboBoxQuestion->addItem("Quelle est la probilité qu'un client attende ce temps là?");

    // ComboBox (Q4&5)
    ui->ComboBoxQ4->addItem("plus de");
    ui->ComboBoxQ4->addItem("moins de");
    ui->ComboBoxQ4->addItem("entre");
    ui->ComboBoxQ5->addItem("plus de");
    ui->ComboBoxQ5->addItem("moins de");
    ui->ComboBoxQ5->addItem("entre");

    // GroupBox
    ui->GroupBox3->hide();
    ui->GroupBox4->hide();
    ui->GroupBox5->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ComboBoxQuestion_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->GroupBox12->hide();
        ui->GroupBox3->hide();
        ui->GroupBox4->hide();
        ui->GroupBox5->hide();
    }

    if(index == 1 || index == 2)
    {
        ui->GroupBox12->show();
        ui->GroupBox3->hide();
        ui->GroupBox4->hide();
        ui->GroupBox5->hide();

        ui->RadioButtonQueue->click();
    }

    if(index == 3)
    {
        ui->GroupBox12->hide();
        ui->GroupBox3->show();
        ui->GroupBox4->hide();
        ui->GroupBox5->hide();
    }

    if(index == 4)
    {
        ui->GroupBox12->hide();
        ui->GroupBox3->hide();
        ui->GroupBox4->show();
        ui->GroupBox5->hide();

        ui->LabelQ4->hide();
        ui->SpinBoxQ4_2->hide();
    }

    if(index == 5)
    {
        ui->GroupBox12->hide();
        ui->GroupBox3->hide();
        ui->GroupBox4->hide();
        ui->GroupBox5->show();

        ui->LabelQ5->hide();
        ui->SpinBoxQ5_2->hide();
        ui->ComboBoxTimeQ5_2->hide();
    }
}
