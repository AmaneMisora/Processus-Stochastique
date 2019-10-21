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
    QStringList Q45ItemsStringList;
    Q45ItemsStringList.append("plus de");
    Q45ItemsStringList.append("moins de");
    Q45ItemsStringList.append("entre");
    ui->ComboBoxQ4->addItems(Q45ItemsStringList);
    ui->ComboBoxQ5->addItems(Q45ItemsStringList);

    // ComboBox (Time)
    QStringList TimeStringList;
    TimeStringList.append("seconde");
    TimeStringList.append("minute");
    TimeStringList.append("heure");
    TimeStringList.append("jour");
    TimeStringList.append("semaine");
    TimeStringList.append("moi");
    TimeStringList.append("année");
    ui->ComboBoxFrequenceArrivee->addItems(TimeStringList);
    ui->ComboBoxFrequenceArrivee->setCurrentIndex(2);
    ui->ComboBoxFrequenceService->addItems(TimeStringList);
    ui->ComboBoxFrequenceService->setCurrentIndex(2);
    ui->ComboBoxTimeQ5->addItems(TimeStringList);
    ui->ComboBoxTimeQ5->setCurrentIndex(2);

    // GroupBox
    ui->GroupBox3->hide();
    ui->GroupBox4->hide();
    ui->GroupBox5->hide();

// init connections

    // Question
    connect(ui->ComboBoxQuestion, SIGNAL(currentIndexChanged(int)), this, SLOT(update_result()));
    connect(ui->RadioButtonSystem, SIGNAL(clicked()), this, SLOT(update_result()));
    connect(ui->RadioButtonQueue, SIGNAL(clicked()), this, SLOT(update_result()));

    // GroupBoxQ3
    connect(ui->SpinBoxQ3, SIGNAL(valueChanged(int)), this, SLOT(update_result()));

    // GroupBoxQ4
    connect(ui->ComboBoxQ4, SIGNAL(currentIndexChanged(int)), this, SLOT(update_result()));
    connect(ui->SpinBoxQ4, SIGNAL(valueChanged(int)), this, SLOT(update_result()));
    connect(ui->SpinBoxQ4_2, SIGNAL(valueChanged(int)), this, SLOT(update_result()));

    // GroupBoxQ5
    connect(ui->ComboBoxQ5, SIGNAL(currentIndexChanged(int)), this, SLOT(update_result()));
    connect(ui->SpinBoxQ5, SIGNAL(valueChanged(int)), this, SLOT(update_result()));
    connect(ui->SpinBoxQ5_2, SIGNAL(valueChanged(int)), this, SLOT(update_result()));
    connect(ui->ComboBoxTimeQ5, SIGNAL(currentIndexChanged(int)), this, SLOT(update_result()));
    connect(ui->ComboBoxTimeQ5_2, SIGNAL(currentIndexChanged(int)), this, SLOT(update_result()));

    // Data
    connect(ui->SpinBoxNbServer, SIGNAL(valueChanged(int)), this, SLOT(update_result()));
    connect(ui->SpinBoxNbMaxPers, SIGNAL(valueChanged(int)), this, SLOT(update_result()));
    connect(ui->SpinBoxNbServer, SIGNAL(valueChanged(int)), this, SLOT(update_result()));
    connect(ui->DoubleSpinBoxFrequenceArrivee, SIGNAL(valueChanged(double)), this, SLOT(update_result()));
    connect(ui->DoubleSpinBoxFrequenceService, SIGNAL(valueChanged(double)), this, SLOT(update_result()));
    connect(ui->ComboBoxFrequenceArrivee, SIGNAL(currentIndexChanged(int)), this, SLOT(update_result()));
    connect(ui->ComboBoxFrequenceService, SIGNAL(currentIndexChanged(int)), this, SLOT(update_result()));

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

/**
 * @brief MainWindow::update_result
 * Lance le calcul en fonction de la question sélectionnée
 *
 */
void MainWindow::update_result()
{

    int S = ui->SpinBoxNbServer->value();
    int K = ui->SpinBoxNbMaxPers->value();
    double lamdba = convertion(ui->DoubleSpinBoxFrequenceArrivee->value(), ui->ComboBoxFrequenceArrivee->currentIndex());
    double mu = convertion(ui->DoubleSpinBoxFrequenceService->value(), ui->ComboBoxFrequenceService->currentIndex());

    if(ui->ComboBoxQuestion->currentIndex() == 1)
    {
        if(ui->RadioButtonSystem->isChecked())
        {
            QString Answer = "";

<<<<<<< HEAD
            double Result = Calculation::L(S,K,lamdba, mu);


            if(Result != -1)
            {
                Answer.append("Il y aura en moyenne ");
                Answer.append(QString::number(Result));
                Answer.append(" client(s) dans la boutique.");
=======
            if(lamdba < mu)
            {
                Answer.append("Il y aura en moyenne ");
                Answer.append(QString::number(Calculation::L(S,K,lamdba, mu)));
                Answer.append(" client(s) dans la file.");
>>>>>>> master
            }
            else
            {
                Answer.append("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service.");
            }

            ui->LabelAnswer->setText(Answer);
        }
    }
}

/**
 * @brief MainWindow::convertion
 * Convertie le temps en secondes
 * @return
 */
double MainWindow::convertion(double time, int unit)
{
    switch (unit) {
    case 0:
        return time;
        break;
    case 1:
        return time * 60;
        break;
    case 2:
        return time * 60 * 60;
        break;
    case 3:
        return time * 60 * 60 * 24;
        break;
    case 4:
        return time * 60 * 60 * 24 * 7;
        break;
    case 5:
        return time * 60 * 60 * 24 * 30;
        break;
    case 6:
        return time * 60 * 60 * 24 * 365;
        break;
    default:
        break;
    }

    return -1;
}



