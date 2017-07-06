#include "agdiagramwindow.h"
#include "ui_agdiagramwindow.h"

AgDiagramWindow::AgDiagramWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgDiagramWindow)
{
    ui->setupUi(this);
}

AgDiagramWindow::~AgDiagramWindow()
{
    delete ui;
}
