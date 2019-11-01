#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculation.h"
#include "dialogresume.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFont(QFont("Georgia", 14));
    ui->SpinBoxFont->hide();

// init GroupBoxProblem

    // Question
    ui->ComboBoxQuestion->setFont(QFont("Georgia", 14));
    ui->ComboBoxQuestion->addItem(" ");
    ui->ComboBoxQuestion->addItem("Combien de client en moyenne seront présents?");
    ui->ComboBoxQuestion->addItem("Combien de temps en moyenne le client sera présent?");
    ui->ComboBoxQuestion->addItem("Combien de client seront perdus?");
    ui->ComboBoxQuestion->addItem("Quelle est la probilité d'avoir ce nombre de clients dans la boutique?");
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
    TimeStringList.append("mois");
    TimeStringList.append("année");
    ui->ComboBoxFrequenceArrivee->addItems(TimeStringList);
    ui->ComboBoxFrequenceArrivee->setCurrentIndex(2);
    ui->ComboBoxFrequenceService->addItems(TimeStringList);
    ui->ComboBoxFrequenceService->setCurrentIndex(2);
    ui->ComboBoxTimeQ5->addItems(TimeStringList);
    ui->ComboBoxTimeQ5->setCurrentIndex(2);
    ui->ComboBoxTimeQ5_2->addItems(TimeStringList);
    ui->ComboBoxTimeQ5_2->setCurrentIndex(2);

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

/**
 * @brief MainWindow::on_ComboBoxQuestion_currentIndexChanged
 * @param index
 * Modifie l'interface en fonction de la question sélectionnée
 */
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
        ui->GroupBox3->hide();
        ui->GroupBox4->hide();
        ui->GroupBox5->hide();

        ui->GroupBox12->show();
        ui->RadioButtonQueue->click();
    }

    if(index == 3)
    {
        ui->GroupBox12->hide();
        ui->GroupBox4->hide();
        ui->GroupBox5->hide();

        if(ui->SpinBoxNbMaxPers->value() == 0)
        {
            ui->GroupBox3->show();
        }
        else
        {
            ui->GroupBox3->hide();
        }
    }

    if(index == 4)
    {
        ui->GroupBox12->hide();
        ui->GroupBox3->hide();
        ui->GroupBox5->hide();

        ui->GroupBox4->show();
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
 */
void MainWindow::update_result()
{
    QString Answer = "";
    double Result;

    int S = ui->SpinBoxNbServer->value();
    int K = ui->SpinBoxNbMaxPers->value();
    double lamdba = FrequencyConvertion(ui->DoubleSpinBoxFrequenceArrivee->value(), ui->ComboBoxFrequenceArrivee->currentIndex());
    double mu = FrequencyConvertion(ui->DoubleSpinBoxFrequenceService->value(), ui->ComboBoxFrequenceService->currentIndex());

    if(S != 1 && K != 0 )
    {
        Result = -2;
    }
    else
    {

// Question 1 (L et Lq)
        if(ui->ComboBoxQuestion->currentIndex() == 1)
        {
            // Calcul
            if(ui->RadioButtonSystem->isChecked()) // Dans le système (L)
            {
                Result = Calculation::L(S,K,lamdba, mu);
            }
            else // Dans la queue (Lq)
            {
                Result = Calculation::Lq(S,K,lamdba, mu);
            }

            // Affichage du résultat
            if(Result >= 0)
            {
                Answer.append("Il y aura en moyenne ");
                Answer.append(QString::number(Result));
                Answer.append(" client(s) dans la queue.");
            }

            ui->LabelAnswer->setText(Answer);
        }


// Question 2 (W et Wq)
        if(ui->ComboBoxQuestion->currentIndex() == 2)
        {

            // Calcul
            if(ui->RadioButtonSystem->isChecked()) // Dans le système (W)
            {
                Result = Calculation::W(S,K,lamdba, mu);
            }
            else // Dans la queue (Wq)
            {
                Result = Calculation::Wq(S,K,lamdba, mu);
            }

            // Affichage du résultat
            if(Result >= 0)
            {
                Answer.append("Un client restera en moyenne ");
                Answer.append(ResultConvertion(Result));
                Answer.append(" dans la boutique.");
            }
        }


// Question 3 (Q)
        if(ui->ComboBoxQuestion->currentIndex() == 3)
        {
            if(K == 0)
            {
                Result = 1;

                for(int j = 0; j <= ui->SpinBoxQ3->value(); j++)
                {
                    Result = Result - Calculation::Q(S, K, lamdba, mu, j);
                }
            }
            else
            {
                Result = Calculation::Q(S, K, lamdba, mu, K);
            }

            // Affichage du résultat
            if(Result >= 0)
            {
                Answer.append(QString::number(Result * 100));
                Answer.append(" % des clients seront perdus.");
            }
        }


// Question 4 (Qj)
        if(ui->ComboBoxQuestion->currentIndex() == 4)
        {
            if(ui->ComboBoxQ4->currentIndex() == 0) // plus de
            {

            }
            else if(ui->ComboBoxQ4->currentIndex() == 1) // moins de
            {

            }
            else if(ui->ComboBoxQ4->currentIndex() == 2) // entre
            {

            }
            else
            {
                Result = -2;
            }

        }


// Question 5 (P)
        if(ui->ComboBoxQuestion->currentIndex() == 5)
        {
            if(ui->ComboBoxQ5->currentIndex() == 0) // plus de
            {
                double t = TimeConvertion(ui->SpinBoxQ5->value(), ui->ComboBoxTimeQ5->currentIndex());

                Result = Calculation::P(S, K, lamdba, mu, t);

                // Affichage du résultat
                if(Result >= 0)
                {
                    Answer.append("Il y a ");
                    Answer.append(QString::number(Result * 100));
                    Answer.append("% de chances pour que le client attende plus de ");
                    Answer.append(ResultConvertion(t));
                }
            }
            else if(ui->ComboBoxQ5->currentIndex() == 1) // moins de
            {
                double t = TimeConvertion(ui->SpinBoxQ5->value(), ui->ComboBoxTimeQ5->currentIndex());

                Result = 1 - Calculation::P(S, K, lamdba, mu, t);

                // Affichage du résultat
                if(Result >= 0)
                {
                    Answer.append("Il y a ");
                    Answer.append(QString::number(Result * 100));
                    Answer.append("% de chances pour que le client attende moins de ");
                    Answer.append(ResultConvertion(t));
                }
            }
            else if(ui->ComboBoxQ5->currentIndex() == 2) // entre
            {
                double t1 = TimeConvertion(ui->SpinBoxQ5->value(), ui->ComboBoxTimeQ5->currentIndex());
                double t2 = TimeConvertion(ui->SpinBoxQ5_2->value(), ui->ComboBoxTimeQ5_2->currentIndex());

                Result = Calculation::P(S, K, lamdba, mu, t1) - Calculation::P(S, K, lamdba, mu, t2);

                // Affichage du résultat
                if(Result >= 0)
                {
                    Answer.append("Il y a ");
                    Answer.append(QString::number(Result * 100));
                    Answer.append("% de chances pour que le client attende entre ");
                    Answer.append(ResultConvertion(t1));
                    Answer.append(" et ");
                    Answer.append(ResultConvertion(t2));
                }
            }
            else
            {
                Result = -2;
            }
        }
    }

    if(Result == -1)
    {
        Answer.append("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service.");
    }
    if(Result == -2)
    {
        Answer.append("Nous ne somme pas en capacité de répondre à la question.");
    }

    ui->LabelAnswer->setText(Answer);
}

/**
 * @brief MainWindow::convertion
 * Convertie une fréquence en nombre d'aucunrrances par seconde
 * @return
 */
double MainWindow::FrequencyConvertion(double frequency, int unit)
{
    switch (unit) {
    case 0:
        return frequency;
        break;
    case 1:
        return frequency / 60;
        break;
    case 2:
        return frequency / 60 / 60;
        break;
    case 3:
        return frequency / 60 / 60 / 24;
        break;
    case 4:
        return frequency / 60 / 60 / 24 / 7;
        break;
    case 5:
        return frequency / 60 / 60 / 24 / 30;
        break;
    case 6:
        return frequency / 60 / 60 / 24 / 365;
        break;
    default:
        break;
    }

    return -1;
}


/**
 * @brief MainWindow::convertion
 * Convertie une durée en une durée en seconde
 * @return
 */
double MainWindow::TimeConvertion(double frequency, int unit)
{
    switch (unit) {
    case 0:
        return frequency;
        break;
    case 1:
        return frequency * 60;
        break;
    case 2:
        return frequency * 60 * 60;
        break;
    case 3:
        return frequency * 60 * 60 * 24;
        break;
    case 4:
        return frequency * 60 * 60 * 24 * 7;
        break;
    case 5:
        return frequency * 60 * 60 * 24 * 30;
        break;
    case 6:
        return frequency * 60 * 60 * 24 * 365;
        break;
    default:
        break;
    }

    return -1;
}

/**
 * @brief MainWindow::ResultConvertion
 * @param resultToConvert
 * @return le resultat convertie
 * Prend en entrée une valeur temporelle en secondes
 * Convertie au mieux le temps en entrée pour afficher le résultat
 * Retourne la concaténation du nombre convertie et de l'unité de temps sous la forme d'un Qstring
 */
QString MainWindow::ResultConvertion(double resultToConvert)
{
    QString ConvertedResult = "";

    // Résultats exactes
    if((int)resultToConvert == 1) // 1 seconde
    {
        ConvertedResult.append( "1 seconde" );
    }
    else if((int)resultToConvert == 60) // 1 minute
    {
        ConvertedResult.append( "1 minute" );
    }
    else if((int)resultToConvert == 3600) // 1 heure
    {
        ConvertedResult.append( "1 heure" );
    }
    else if((int)resultToConvert == 86400) // 1 jour
    {
        ConvertedResult.append( "1 jour" );
    }
    else if((int)resultToConvert == 60*60*24*7) // 1 semaine
    {
        ConvertedResult.append( "1 semaine" );
    }

    // Autres résultats
    else if(resultToConvert < 90) // moins d'1min30
    {
        ConvertedResult.append( QString::number(resultToConvert) + " secondes" );
    }
    else if(resultToConvert < 90*60) // moins d'1h30
    {
        ConvertedResult.append( QString::number(resultToConvert / 60) + " minutes" );
    }
    else if(resultToConvert < 60*60*36) // moins de 36 heures
    {
        ConvertedResult.append( QString::number(resultToConvert / 60 / 60) + " heures" );
    }
    else // plus de 36 heures
    {
        ConvertedResult.append( QString::number(resultToConvert / 60 / 60 / 24) + " jours" );
    }

    return ConvertedResult;
}


/**
 * @brief MainWindow::on_SpinBoxFont_valueChanged
 * @param arg1
 * Met à jour l'écriture
 */
void MainWindow::on_SpinBoxFont_valueChanged(int arg1)
{
    QFontDatabase fdb;
    this->setFont(QFont(fdb.families().at(arg1), 14));
    qDebug() << QFont(fdb.families().at(arg1));
}

/**
 * @brief MainWindow::on_SpinBoxNbMaxPers_valueChanged
 * @param arg1
 * Met à jour l'interface en fonction de la valeur de K
 */
void MainWindow::on_SpinBoxNbMaxPers_valueChanged(int arg1)
{
    if(ui->ComboBoxQuestion->currentIndex() == 3)
    {
        if(arg1 == 0)
        {
            ui->GroupBox3->show();
        }
        else
        {
            ui->GroupBox3->hide();
        }
    }
}

/**
 * @brief MainWindow::on_PushButtonGlobalResult_clicked
 * Appuyer le bouton
 * et puis afficher un résumé des données
 */
void MainWindow::on_PushButtonGlobalResult_clicked()
{
    DialogResume dialog;

    int S = ui->SpinBoxNbServer->value();
    int K = ui->SpinBoxNbMaxPers->value();
    double lamdba = FrequencyConvertion(ui->DoubleSpinBoxFrequenceArrivee->value(), ui->ComboBoxFrequenceArrivee->currentIndex());
    double mu = FrequencyConvertion(ui->DoubleSpinBoxFrequenceService->value(), ui->ComboBoxFrequenceService->currentIndex());

    dialog.Initialization(S,K,lamdba,mu);
    dialog.exec();
}

void MainWindow::on_ComboBoxQ5_currentIndexChanged(int index)
{
    if(index == 2)
    {
        ui->LabelQ5->show();
        ui->SpinBoxQ5_2->show();
        ui->ComboBoxTimeQ5_2->show();
    }
    else
    {
        ui->LabelQ5->hide();
        ui->SpinBoxQ5_2->hide();
        ui->ComboBoxTimeQ5_2->hide();
    }
}
