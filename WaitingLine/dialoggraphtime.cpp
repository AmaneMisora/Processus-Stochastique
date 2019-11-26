#include "dialoggraphtime.h"
#include "ui_dialoggraphtime.h"

DialogGraphTime::DialogGraphTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGraphTime)
{
    ui->setupUi(this);

    double graphicsViewSizeY = 400;
    double graphicsViewSizeX = 800;

    ui->graphicsView->setScene(new QGraphicsScene(-20,-20,graphicsViewSizeX,graphicsViewSizeY,this));

    QPen PenBlack = QPen(Qt::black);
    ui->graphicsView->scene()->addLine(0,-1000,0,1000,PenBlack);
    ui->graphicsView->scene()->addLine(-1000,graphicsViewSizeY-40,1000,graphicsViewSizeY-40,PenBlack);
}

DialogGraphTime::~DialogGraphTime()
{
    delete ui;
}

void DialogGraphTime::Init(int S, int K, double lambda, double mu)
{

    QVector<double> Results = QVector<double>();
    double MaxResult = 0;
    double TimeScale;

    QPen PenBlue = QPen(QColor(100,100,255,100), 2);

    QGraphicsTextItem* tmpTxt;

    // Recherche de l'échelle de temps
    if((1/mu) < 10)
    {
        TimeScale = 0.1;
    }
    if((1/mu) < 100)
    {
        TimeScale = 0.3;
    }
    else if((1/mu) < 1000)
    {
        TimeScale = 1;
    }
    else if((1/mu) < 3000)
    {
        TimeScale = 36;
    }
    else if((1/mu) < 10000)
    {
        TimeScale = 86.4;
    }
    else if((1/mu) < 100000)
    {
        TimeScale = 864;
    }
    else if((1/mu) < 1000000)
    {
        TimeScale = 8640;
    }
    else if((1/mu) < 10000000)
    {
        TimeScale = 86400;
    }
    else
    {
        TimeScale = 864000;
    }

    qDebug() << 1/mu;

    // Ajout des tirets horizontaux
    for(int i=0; i<20; i+= 1)
    {
        ui->graphicsView->scene()->addLine(i*40, 360, i*40, 365);
        tmpTxt = ui->graphicsView->scene()->addText(ResultConvertion(i*TimeScale*40));
        tmpTxt->setPos(i*40-5, 360);
    }

    // Création de la table de résultats et recherch du max
    for(int i=0; i<800; i+= 1)
    {
        double result = Calculation::P(S, K, lambda, mu, i*TimeScale) - Calculation::P(S, K, lambda, mu, (i+1)*TimeScale);
        Results.append(result);

        // Mise à jour du max
        if(result>MaxResult)
        {
            MaxResult = result;
        }
    }

    // Affichage des résultats
    if(MaxResult > 0)
    {
        for(int i=0; i<800; i+= 1)
        {
            //Position horizontale du rectangle
            double posx = i;

            // Hauteur du retangle
            double height = -Results.at(i)*360/MaxResult;

            // Création du rectangle
            ui->graphicsView->scene()->addRect(posx,360,1,height,PenBlue);
        }
    }

/*
    // Création de la table des résultats et récupèration du max
    for(double i=0; i<1000; i++)
    {
        double result = Calculation::P(S, K, lambda, mu, i*TimeScale) - Calculation::P(S, K, lambda, mu, i+1*TimeScale);

        Results.append(result);

        // Mise à jour du max
        if(result>MaxResult)
        {
            MaxResult = result;
        }
    }

    // Affichage des résultats
    for(double i=0; i<1000; i++)
    {
        //Position horizontale du rectangle
        double posx = i*100/Results.size();

        // Hauteur du retangle
        double height = -Results.at(i)*360/MaxResult;

        // Création du rectangle
        ui->graphicsView->scene()->addRect(posx,360,1,height,PenBlue);
    }
*/

}


QString DialogGraphTime::ResultConvertion(double resultToConvert)
{
    QString ConvertedResult = "";

    if(resultToConvert < 90) // moins d'1min30
    {
        ConvertedResult.append( QString::number(resultToConvert).mid(0,4) + " s" );
    }
    else if(resultToConvert < 90*60) // moins d'1h30
    {
        ConvertedResult.append( QString::number(resultToConvert / 60).mid(0,4) + " min" );
    }
    else if(resultToConvert < 60*60*72) // moins de 72 heures
    {
        ConvertedResult.append( QString::number(resultToConvert / 60 / 60).mid(0,4) + " h" );
    }
    else // plus de 72 heures
    {
        ConvertedResult.append( QString::number(resultToConvert / 60 / 60 / 24).mid(0,4) + " j" );
    }

    return ConvertedResult;
}
