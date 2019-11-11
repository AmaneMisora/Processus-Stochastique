#ifndef DIALOGGRAPHQUENE_H
#define DIALOGGRAPHQUENE_H
#include <QtCharts>
#include <QLineSeries>
QT_CHARTS_USE_NAMESPACE
#include <QDialog>
#include"calculation.h"
#include <math.h>
#include <QRandomGenerator>
namespace Ui {
class DialogGraphQuene;
}

class DialogGraphQuene : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGraphQuene(QWidget *parent = nullptr);
    ~DialogGraphQuene();

    void Init(int S, int K, double lambda, double mu);
    QString DecideTimeUnity(double t);
    double ConvertTime(double t);


private:
    Ui::DialogGraphQuene *ui;
};

#endif // DIALOGGRAPHQUENE_H
