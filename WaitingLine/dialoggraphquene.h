#ifndef DIALOGGRAPHQUENE_H
#define DIALOGGRAPHQUENE_H

#include <QDialog>

namespace Ui {
class DialogGraphQuene;
}

class DialogGraphQuene : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGraphQuene(QWidget *parent = nullptr);
    ~DialogGraphQuene();

private:
    Ui::DialogGraphQuene *ui;
};

#endif // DIALOGGRAPHQUENE_H
