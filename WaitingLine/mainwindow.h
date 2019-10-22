#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QStringList>
#include <QFontDatabase>
#include "calculation.h"

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

private:
    Ui::MainWindow *ui;
    double FrequencyConvertion(double frequency, int unit);
    QString ResultConvertion(double resultToConvert);
};

#endif // MAINWINDOW_H
