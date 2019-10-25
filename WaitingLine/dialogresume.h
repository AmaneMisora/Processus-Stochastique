#ifndef DIALOGRESUME_H
#define DIALOGRESUME_H

#include <QDialog>
#include"calculation.h"

namespace Ui {
class DialogResume;
}

class DialogResume : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResume(QWidget *parent = NULL);
    ~DialogResume();

    void Initialization(int S, int K, double lambda, double mu);
    QString MofidyTimeResult(double res);

private:
    Ui::DialogResume *ui;
};

#endif // DIALOGRESUME_H
