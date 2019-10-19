#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // init GroupBoxProblem
    ui->ComboBoxQuestion->addItem("Combien de client en moyenne seront présents?");
    ui->ComboBoxQuestion->addItem("Combien de temps en moyenne le client sera présent?");
    ui->ComboBoxQuestion->addItem("Combien de client seront perdus?");
    ui->ComboBoxQuestion->addItem("Quelle est la probilité d'avoir ce nombre de clients dans la file?");
    ui->ComboBoxQuestion->addItem("Quelle est la probilité qu'un client attende ce temps là?");

    ui->GroupBox3->hide();
    ui->GroupBox45->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ComboBoxQuestion_currentIndexChanged(int index)
{
    if(index == 0 || index == 1)
    {
        ui->GroupBox12->show();
        ui->GroupBox3->hide();
        ui->GroupBox45->hide();
    }

    if(index == 2)
    {
        ui->GroupBox12->hide();
        ui->GroupBox3->show();
        ui->GroupBox45->hide();
    }

    if(index == 3 || index == 4)
    {
        ui->GroupBox12->hide();
        ui->GroupBox3->hide();
        ui->GroupBox45->show();
    }
}
