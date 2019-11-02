#include "dialoggraphtime.h"
#include "ui_dialoggraphtime.h"

DialogGraphTime::DialogGraphTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGraphTime)
{
    ui->setupUi(this);

    double graphicsViewSizeY = 200;
    double graphicsViewSizeX = 400;

    ui->graphicsView->setScene(new QGraphicsScene(-20,-20,graphicsViewSizeX*2,graphicsViewSizeY*2,this));

    QPen PenBlack = QPen(Qt::black);
    ui->graphicsView->scene()->addLine(0,-1000,0,1000,PenBlack);
    ui->graphicsView->scene()->addLine(-1000,graphicsViewSizeY*2-40,1000,graphicsViewSizeY*2-40,PenBlack);
}

DialogGraphTime::~DialogGraphTime()
{
    delete ui;
}

void DialogGraphTime::Init(int S, int K, double lambda, double mu)
{
    QVector<double> Results = QVector<double>();
    double MaxResult = 0;
    int MaxTime = 10/(mu+lambda);

    QPen PenBlue = QPen(QColor(100,100,255,100));

    // Création de la table des résultats et récupèration du max
    for(int t=0; t<MaxTime; t+=1)
    {
        double result = Calculation::P(S, K, lambda, mu, t) - Calculation::P(S, K, lambda, mu, t+1);

        if(result > 0.0000001)
        {
            Results.append(result);
        }

        if(result>MaxResult)
        {
            MaxResult = result;
        }
    }

    qDebug() << "a";

    // Affichage es résultats
    for(int t=0; t<Results.size()-1; t++)
    {
        ui->graphicsView->scene()->addRect(t*1000/Results.size(),360,1,-Results.at(t)*360/MaxResult,PenBlue);
    }

}


