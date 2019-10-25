#include "dialogresume.h"
#include "ui_dialogresume.h"

DialogResume::DialogResume(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResume)
{
    ui->setupUi(this);
    this->setFont(QFont("Georgia", 14));
    ui->label_title->setFont(QFont("Georgia", 16, QFont::Bold));

}

DialogResume::~DialogResume()
{
    delete ui;
}

/**
 * @brief DialogResume::InitializeProblem
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * Initialiser et calculer toutes les probleme par defaut
 */
void DialogResume::Initialization(int S, int K, double lambda, double mu)
{
    if(S!= 1 && K != 0) {
        //L
        ui->label_q1_answer->setText(QString("Personne!"));
        ui->label_q1_explain->setText(QString("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service."));
        ui->label_q1_explain->setStyleSheet("color:red;");
        //Lq
        ui->label_q2_answer->setText(QString("Personne!"));
        ui->label_q2_explain->setText(QString("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service."));
        ui->label_q2_explain->setStyleSheet("color:red;");
        //W
        ui->label_q3_answer->setText("Pas de solution!");
        ui->label_q3_explain->setText(QString("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service."));
        ui->label_q3_explain->setStyleSheet("color:red;");
        //Wq
        ui->label_q3_answer->setText("Pas de solution!");
        ui->label_q3_explain->setText(QString("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service."));
        ui->label_q3_explain->setStyleSheet("color:red;");


    } else {
        //label_q1(L)
        double L = Calculation::L(S,K,lambda,mu);
        if(L == -1) {
            ui->label_q1_answer->setText(QString("Personne!"));
            ui->label_q1_explain->setText(QString("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service."));
            ui->label_q1_explain->setStyleSheet("color:red;");

        } else if(L>0 && L <= 1.0) {
            ui->label_q1_answer->setText(QString::number(L) + QString(" Client"));
        } else {
            ui->label_q1_answer->setText(QString::number(L) + QString(" Clients"));
        }

        //label_q2(Lq)
        double Lq = Calculation::Lq(S,K,lambda,mu);
        if(Lq == -1) {
            ui->label_q2_answer->setText(QString("Personne!"));
            ui->label_q2_explain->setText(QString("Il y aura blocage de la queue, le taux d'arrivée des clients est supérieur à la vitesse de service."));
            ui->label_q2_explain->setStyleSheet("color:red;");
        } else if(Lq>0 && Lq <= 1.0){
            ui->label_q2_answer->setText(QString::number(Lq) + QString(" Client"));
        } else {
            ui->label_q2_answer->setText(QString::number(Lq) + QString(" Clients"));
        }

        //label_q3(W)
        double W = Calculation::W(S,K,lambda,mu);
        ui->label_q3_answer->setText(this->MofidyTimeResult(W) + QString(" par client"));

        //label_q4(Wq)
        double Wq = Calculation::Wq(S,K,lambda,mu);
        ui->label_q4_answer->setText(this->MofidyTimeResult(Wq) + QString(" par client"));

    }
}

/**
 * @brief DialogResume::MofidyTimeResult
 * @param res
 * @return
 * Modify la forme du resultat de W,Wq
 */
QString DialogResume::MofidyTimeResult(double resultToConvert)
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

