#include "mainwindow.h"
#include "agdiagramwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lastSubWindowId = 0;
    setUnifiedTitleAndToolBarOnMac(true);

    tabifyDockWidget(ui->modelDockWidget, ui->subjectDockWidget);
    tabifyDockWidget(ui->modelDockWidget, ui->patternsDockWidget);
    ui->modelDockWidget->raise();
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
    AgDiagramWindow *widget = new AgDiagramWindow;
    widget->setWindowTitle("Diagram "+QString::number(lastSubWindowId));
    subWindow->setWidget(widget);
    subWindow->setWindowTitle("Diagram "+QString::number(lastSubWindowId));
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->showMaximized();    
}

