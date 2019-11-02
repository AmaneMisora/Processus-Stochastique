#ifndef DIALOGGRAPHTIME_H
#define DIALOGGRAPHTIME_H

#include <QDialog>
#include "calculation.h"

namespace Ui {
class DialogGraphTime;
}

class DialogGraphTime : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogGraphTime(QWidget *parent = 0);
    ~DialogGraphTime();
    void Init(int S, int K, double lambda, double mu);
    
private:
    Ui::DialogGraphTime *ui;
};

#endif // DIALOGGRAPHTIME_H
