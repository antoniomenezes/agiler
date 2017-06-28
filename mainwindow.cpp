#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lastSubWindowId = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Diagram_triggered()
{
    lastSubWindowId++;
    QMdiSubWindow *subWindow = new QMdiSubWindow;
    //subWindow->setWidget(internalWidget1);
    QWidget *widget = new QWidget;
    widget->setWindowTitle("Diagram "+QString::number(lastSubWindowId));
    subWindow->setWidget(widget);
    subWindow->setWindowTitle("Diagram "+QString::number(lastSubWindowId));
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->showMaximized();
}
