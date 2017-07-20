#include "agdiagramwindow.h"
#include "ui_agdiagramwindow.h"

AgDiagramWindow::AgDiagramWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AgDiagramWindow)
{
    ui->setupUi(this);

    ui->actionSelect->setChecked(true);
}

AgDiagramWindow::~AgDiagramWindow()
{
    delete ui;
}

void AgDiagramWindow::on_actionSelect_triggered()
{
    ui->actionSelect->setChecked(true);
    ui->actionNew_Table->setChecked(false);
    ui->actionNew_Relationship->setChecked(false);
    ui->actionNew_Label->setChecked(false);

}

void AgDiagramWindow::on_actionNew_Table_triggered()
{
   ui->actionSelect->setChecked(false);
   ui->actionNew_Table->setChecked(true);
   ui->actionNew_Relationship->setChecked(false);
   ui->actionNew_Label->setChecked(false);
}

void AgDiagramWindow::on_actionNew_Relationship_triggered()
{
    ui->actionSelect->setChecked(false);
    ui->actionNew_Table->setChecked(false);
    ui->actionNew_Relationship->setChecked(true);
    ui->actionNew_Label->setChecked(false);
}

void AgDiagramWindow::on_actionNew_Label_triggered()
{
    ui->actionSelect->setChecked(false);
    ui->actionNew_Table->setChecked(false);
    ui->actionNew_Relationship->setChecked(false);
    ui->actionNew_Label->setChecked(true);
}
