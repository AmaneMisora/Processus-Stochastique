#include "dialoggraphquene.h"
#include "ui_dialoggraphquene.h"




DialogGraphQuene::DialogGraphQuene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGraphQuene)
{
    ui->setupUi(this);
}

DialogGraphQuene::~DialogGraphQuene()
{
    delete ui;
}

/**
 * @brief DialogGraphQuene::TimeConvert
 * @param t
 * @return s, min; h; j; sem; mois; an
 * Décider l'unité de temps pour la graphe
 */
QString DialogGraphQuene::DecideTimeUnity(double t)
{
    if(t <= 60) // moin de 1 minute présenté par seconde
    {
        return QString("seconde");
    }
    else if(t <= 3600 && t > 60) // 1 heure, par minute
    {
        return QString("minute");
    }
    else if(t <= 86400 && t > 3600) // 1 jour, par heure
    {
        return QString("heure");
    }
    else if(t <= 60*60*24*7 && t > 86400) // 1 semaine, par jour
    {
        return QString("jour");
    }
    else if (t <= 60*60*24*7*4 && t > 60*60*24*7) // 1 mois, par semaine
    {
        return QString("semaine");
    }
    else if (t <= 60*60*24*7*4*12 && t > 60*60*24*7*4 ) // 1 an, par mois
    {
        return QString("mois");
    }
    else
    {
        return QString("an");
    }

}

/**
 * @brief DialogGraphQuene::ConvertTime
 * @param t
 * @return
 */
double DialogGraphQuene::ConvertTime(double t)
{
    if(t <= 60) // moins de 1 minute, convertir au seconde
    {
        return t;
    }
    else if(t <= 3600 && t > 60) // 1 heure, au minute
    {
        return t/60;
    }
    else if(t <= 86400 && t > 3600) // 1 jour, au heure
    {
        return t/3600;
    }
    else if(t <= 60*60*24*7 && t > 86400) // 1 semaine, au jour
    {
        return t/86400;
    }
    else if (t <= 60*60*24*7*4 && t > 60*60*24*7) // 1 mois au semaine
    {
        return t/(86400*7);
    }
    else if (t <= 60*60*24*7*4*12 && t > 60*60*24*7*4 ) // 1 an, au mois
    {
        return t/(86400*7*4);
    }
    else
    {
        return t/(86400*7*4*12);
    }


}

/**
 * @brief DialogGraphQuene::Init
 * @param S
 * @param K
 * @param lambda
 * @param mu
 * Initilizer la graphe pour analyser le temps la longueur de la queue
 */
void DialogGraphQuene::Init(int S, int K, double lambda, double mu)
{
    //Wq
    double Wq = Calculation::Wq(S,K,lambda,mu);
    QString unity = DecideTimeUnity(Wq);

    //Ajouter les données
    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    int range;
    if(unity == QString("seconde"))
    {
        int t = 0;
        for (int i=0; i<10; i++) {
            int rand_t = QRandomGenerator::global()->bounded(t, t+5);
            double Pt = Calculation::P(S,K,lambda,mu,rand_t);
            series->append(rand_t,Pt);
            t += 6;
        }
        range = 60;
    }
    else if(unity == QString("minute"))
    {
        int t = 0;
        for (int i=0; i<10; i++) {
            int rand_t = QRandomGenerator::global()->bounded(t, t+5);
            double Pt = Calculation::P(S,K,lambda,mu,rand_t);
            series->append(rand_t,Pt);
            t += 6;
        }
        range = 60;
    }
    else if(unity == QString("heure"))
    {
        int t = 0;
        for (int i=0; i<12; i++) {
            double rand_t = QRandomGenerator::global()->generateDouble() + t;
            double Pt = Calculation::P(S,K,lambda,mu,rand_t);
            series->append(rand_t,Pt);
            t += 2;
        }
        range = 24;
    }
    else if(unity == QString("semaine"))
    {
        int t = 0;
        for (int i=0; i<7; i++) {
            double rand_t = QRandomGenerator::global()->generateDouble() + t;
            double Pt = Calculation::P(S,K,lambda,mu,rand_t);
            series->append(rand_t,Pt);
            t += 1;
        }
        range = 7;
    }
    else if(unity == QString("mois"))
    {
        int t = 0;
        for (int i=0; i<12; i++) {
            double rand_t = QRandomGenerator::global()->generateDouble() + t;
            double Pt = Calculation::P(S,K,lambda,mu,rand_t);
            series->append(rand_t,Pt);
            t += 1;
        }
        range = 12;
    }
    else if(unity == QString("an"))
    {
        int t = 0;
        for (int i=0; i<10; i++) {
            double rand_t = QRandomGenerator::global()->generateDouble() + t;
            double Pt = Calculation::P(S,K,lambda,mu,rand_t);
            series->append(rand_t,Pt);
            t += 1;
        }
        range = 10;
    } else {
        range = -2;
    }

    //créer chart
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    chart->axisX()->setRange(0,range);
    chart->axisX()->setTitleText(unity);
    chart->axisY()->setRange(0,1);
    chart->axisY()->setTitleText("Probabilité");
    chart->setTitle("Analyser le temps la longueur de la queue par "+unity);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // montrer le chart
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartView,1,0);
    setLayout(mainLayout);



}
