#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QStringList>
#include <QFontDatabase>
#include "calculation.h"
#include "dialogresume.h"
#include "dialoggraphtime.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ComboBoxQuestion_currentIndexChanged(int index);
    void update_result();

    void on_SpinBoxFont_valueChanged(int arg1);

    void on_SpinBoxNbMaxPers_valueChanged(int arg1);

    void on_PushButtonGlobalResult_clicked();

    void on_ComboBoxQ5_currentIndexChanged(int index);

    void on_PushButtonGraphTime_clicked();

private:
    Ui::MainWindow *ui;
    double FrequencyConvertion(double frequency, int unit);
    double TimeConvertion(double frequency, int unit);
    QString ResultConvertion(double resultToConvert);
    QString SolutionQuestionFour(int n, int max_per, int fre_arr_cli, int fre_ser_cli);
};

#endif // MAINWINDOW_H
