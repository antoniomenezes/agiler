/********************************************************************************
** Form generated from reading UI file 'agdiagramwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGDIAGRAMWINDOW_H
#define UI_AGDIAGRAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgDiagramWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *AgDiagramWindow)
    {
        if (AgDiagramWindow->objectName().isEmpty())
            AgDiagramWindow->setObjectName(QStringLiteral("AgDiagramWindow"));
        AgDiagramWindow->resize(739, 494);
        verticalLayout = new QVBoxLayout(AgDiagramWindow);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(AgDiagramWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(AgDiagramWindow);

        QMetaObject::connectSlotsByName(AgDiagramWindow);
    } // setupUi

    void retranslateUi(QWidget *AgDiagramWindow)
    {
        AgDiagramWindow->setWindowTitle(QApplication::translate("AgDiagramWindow", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AgDiagramWindow: public Ui_AgDiagramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGDIAGRAMWINDOW_H
