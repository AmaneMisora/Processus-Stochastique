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
