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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgDiagramWindow
{
public:
    QAction *actionSelect;
    QAction *actionNew_Table;
    QAction *actionNew_Relationship;
    QAction *actionNew_Label;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QToolBar *widget;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *AgDiagramWindow)
    {
        if (AgDiagramWindow->objectName().isEmpty())
            AgDiagramWindow->setObjectName(QStringLiteral("AgDiagramWindow"));
        AgDiagramWindow->resize(739, 494);
        actionSelect = new QAction(AgDiagramWindow);
        actionSelect->setObjectName(QStringLiteral("actionSelect"));
        actionSelect->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/ui/png/pointer_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect->setIcon(icon);
        actionNew_Table = new QAction(AgDiagramWindow);
        actionNew_Table->setObjectName(QStringLiteral("actionNew_Table"));
        actionNew_Table->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/ui/png/ic_table_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Table->setIcon(icon1);
        actionNew_Relationship = new QAction(AgDiagramWindow);
        actionNew_Relationship->setObjectName(QStringLiteral("actionNew_Relationship"));
        actionNew_Relationship->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/ui/png/ic_crossfoot_black_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Relationship->setIcon(icon2);
        actionNew_Label = new QAction(AgDiagramWindow);
        actionNew_Label->setObjectName(QStringLiteral("actionNew_Label"));
        actionNew_Label->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/ui/png/ic_text_format_black_24dp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Label->setIcon(icon3);
        horizontalLayout = new QHBoxLayout(AgDiagramWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(AgDiagramWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 0, 0, 0);
        widget = new QToolBar(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setOrientation(Qt::Vertical);
        widget->setIconSize(QSize(16, 16));

        horizontalLayout_2->addWidget(widget);

        graphicsView = new QGraphicsView(frame);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout_2->addWidget(graphicsView);


        horizontalLayout->addWidget(frame);


        widget->addAction(actionSelect);
        widget->addAction(actionNew_Table);
        widget->addAction(actionNew_Relationship);
        widget->addAction(actionNew_Label);

        retranslateUi(AgDiagramWindow);

        QMetaObject::connectSlotsByName(AgDiagramWindow);
    } // setupUi

    void retranslateUi(QWidget *AgDiagramWindow)
    {
        AgDiagramWindow->setWindowTitle(QApplication::translate("AgDiagramWindow", "Form", Q_NULLPTR));
        actionSelect->setText(QApplication::translate("AgDiagramWindow", "Select", Q_NULLPTR));
        actionNew_Table->setText(QApplication::translate("AgDiagramWindow", "New Table", Q_NULLPTR));
        actionNew_Relationship->setText(QApplication::translate("AgDiagramWindow", "New Relationship", Q_NULLPTR));
        actionNew_Label->setText(QApplication::translate("AgDiagramWindow", "New Label", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AgDiagramWindow: public Ui_AgDiagramWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGDIAGRAMWINDOW_H
