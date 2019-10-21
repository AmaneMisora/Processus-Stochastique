#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QStringList>
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

private:
    Ui::MainWindow *ui;
    double convertion(double time, int unit);
};

#endif // MAINWINDOW_H
