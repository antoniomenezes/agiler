/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Table;
    QAction *actionNew_Diagram;
    QAction *action_Save_Diagram;
    QAction *actionNew_Relationship;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *modelDockWidget;
    QWidget *dockWidgetContents;
    QDockWidget *subjectDockWidget;
    QWidget *dockWidgetContents_2;
    QDockWidget *patternsDockWidget;
    QWidget *dockWidgetContents_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(819, 539);
        actionNew_Table = new QAction(MainWindow);
        actionNew_Table->setObjectName(QStringLiteral("actionNew_Table"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/ui/png/ic_table_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Table->setIcon(icon);
        actionNew_Diagram = new QAction(MainWindow);
        actionNew_Diagram->setObjectName(QStringLiteral("actionNew_Diagram"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/ui/png/ic_add_circle_outline_black_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Diagram->setIcon(icon1);
        action_Save_Diagram = new QAction(MainWindow);
        action_Save_Diagram->setObjectName(QStringLiteral("action_Save_Diagram"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/ui/png/ic_save_black_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save_Diagram->setIcon(icon2);
        actionNew_Relationship = new QAction(MainWindow);
        actionNew_Relationship->setObjectName(QStringLiteral("actionNew_Relationship"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/ui/png/ic_crossfoot_black_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Relationship->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        QBrush brush(QColor(85, 87, 83, 255));
        brush.setStyle(Qt::SolidPattern);
        mdiArea->setBackground(brush);
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setOrientation(Qt::Horizontal);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        modelDockWidget = new QDockWidget(MainWindow);
        modelDockWidget->setObjectName(QStringLiteral("modelDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        modelDockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), modelDockWidget);
        subjectDockWidget = new QDockWidget(MainWindow);
        subjectDockWidget->setObjectName(QStringLiteral("subjectDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        subjectDockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), subjectDockWidget);
        patternsDockWidget = new QDockWidget(MainWindow);
        patternsDockWidget->setObjectName(QStringLiteral("patternsDockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        patternsDockWidget->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), patternsDockWidget);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(actionNew_Diagram);
        menu_File->addAction(action_Save_Diagram);
        menu_File->addSeparator();
        menu_File->addAction(actionNew_Table);
        menu_File->addAction(actionNew_Relationship);
        mainToolBar->addAction(actionNew_Diagram);
        mainToolBar->addAction(action_Save_Diagram);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNew_Table);
        mainToolBar->addAction(actionNew_Relationship);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Agile-ER", Q_NULLPTR));
        actionNew_Table->setText(QApplication::translate("MainWindow", "New &Table", Q_NULLPTR));
        actionNew_Diagram->setText(QApplication::translate("MainWindow", "New &Diagram", Q_NULLPTR));
        action_Save_Diagram->setText(QApplication::translate("MainWindow", "&Save Diagram", Q_NULLPTR));
        actionNew_Relationship->setText(QApplication::translate("MainWindow", "New Relationship", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&Diagram", Q_NULLPTR));
        modelDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Model", Q_NULLPTR));
        subjectDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Subject Areas", Q_NULLPTR));
        patternsDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Patterns", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
