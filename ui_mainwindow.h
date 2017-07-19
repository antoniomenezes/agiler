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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
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
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditSearchModel;
    QTreeWidget *treeWidgetModels;
    QDockWidget *subjectDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEditSearchSubjectArea;
    QTreeWidget *treeWidgetSubjectAreas;
    QDockWidget *patternsDockWidget;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEditSearchPattern;
    QTreeWidget *treeWidgetPatterns;

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
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 2, 2, 2);
        lineEditSearchModel = new QLineEdit(dockWidgetContents);
        lineEditSearchModel->setObjectName(QStringLiteral("lineEditSearchModel"));
        lineEditSearchModel->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(lineEditSearchModel);

        treeWidgetModels = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidgetModels->setHeaderItem(__qtreewidgetitem);
        treeWidgetModels->setObjectName(QStringLiteral("treeWidgetModels"));
        treeWidgetModels->header()->setVisible(false);

        verticalLayout_2->addWidget(treeWidgetModels);

        modelDockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), modelDockWidget);
        subjectDockWidget = new QDockWidget(MainWindow);
        subjectDockWidget->setObjectName(QStringLiteral("subjectDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 2, 2, 2);
        lineEditSearchSubjectArea = new QLineEdit(dockWidgetContents_2);
        lineEditSearchSubjectArea->setObjectName(QStringLiteral("lineEditSearchSubjectArea"));
        lineEditSearchSubjectArea->setClearButtonEnabled(true);

        verticalLayout_3->addWidget(lineEditSearchSubjectArea);

        treeWidgetSubjectAreas = new QTreeWidget(dockWidgetContents_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        treeWidgetSubjectAreas->setHeaderItem(__qtreewidgetitem1);
        treeWidgetSubjectAreas->setObjectName(QStringLiteral("treeWidgetSubjectAreas"));
        treeWidgetSubjectAreas->header()->setVisible(false);

        verticalLayout_3->addWidget(treeWidgetSubjectAreas);

        subjectDockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), subjectDockWidget);
        patternsDockWidget = new QDockWidget(MainWindow);
        patternsDockWidget->setObjectName(QStringLiteral("patternsDockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(4, 2, 2, 2);
        lineEditSearchPattern = new QLineEdit(dockWidgetContents_3);
        lineEditSearchPattern->setObjectName(QStringLiteral("lineEditSearchPattern"));
        lineEditSearchPattern->setClearButtonEnabled(true);

        verticalLayout_4->addWidget(lineEditSearchPattern);

        treeWidgetPatterns = new QTreeWidget(dockWidgetContents_3);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        treeWidgetPatterns->setHeaderItem(__qtreewidgetitem2);
        treeWidgetPatterns->setObjectName(QStringLiteral("treeWidgetPatterns"));
        treeWidgetPatterns->header()->setVisible(false);

        verticalLayout_4->addWidget(treeWidgetPatterns);

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
        lineEditSearchModel->setPlaceholderText(QApplication::translate("MainWindow", "Search Model Element", Q_NULLPTR));
        subjectDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Subject Areas", Q_NULLPTR));
        lineEditSearchSubjectArea->setPlaceholderText(QApplication::translate("MainWindow", "Search Subject Area", Q_NULLPTR));
        patternsDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Patterns", Q_NULLPTR));
        lineEditSearchPattern->setPlaceholderText(QApplication::translate("MainWindow", "Search Pattern", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
