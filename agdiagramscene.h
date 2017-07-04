#ifndef AGDIAGRAMSCENE_H
#define AGDIAGRAMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QPrinter>
#include <QPainter>
#include <QSvgGenerator>
#include <QTime>
#include "agdiagramitem.h"
#include "agdiagramtableitem.h"
#include "agdiagramrelationshipitem.h"
#include "agdiagramnotation.h"

class AgDiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode { InsertTable, InsertRelation, MoveItem };

    AgDiagramScene(QMenu *itemMenu, QObject *parent = 0);
    QFont font() const { return myFont; }
    QColor textColor() const { return myTextColor; }
    QColor itemColor() const { return myItemColor; }
    QColor lineColor() const { return myLineColor; }
    int itemMargin() { return currentItemMargin; }

    void setLineColor(const QColor &color);
    void setTextColor(const QColor &color);
    void setItemColor(const QColor &color);
    void setFont(const QFont &font);
    void setItemMargin(int value);
    void bringToFront();
    void sendToBack();
    void setNotation(AgDiagramNotation::Notation notation);
    AgDiagramNotation::Notation notation() const { return myNotation; }
    void saveToPdf(QString fileName);
    void saveToSvg(QString fileName);
    AgDiagramTableItem *addTableItem(QString tableName, QMenu *contextMenu);
    AgDiagramRelationshipItem *addRelationshipItem(AgDiagramTableItem *beginTableItem, AgDiagramTableItem *endTableItem, QMenu *contextMenu);
    int idGenerator;

public slots:
    void setMode(Mode mode);
    //void setItemType(DiagramItem::DiagramType type);
    //void editorLostFocus(DiagramTextItem *item);

signals:
    void itemInserted(AgDiagramItem *item);
    void textInserted(QGraphicsTextItem *item);
    void itemSelected(QGraphicsItem *item);
    void mouseClicked(QPointF point);
    void notationChanged(AgDiagramNotation::Notation notation);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    bool isItemChange(QString name);
    int currentItemMargin;

    //AgDiagramItem::DiagramType myItemType;
    QMenu *myItemMenu;
    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    QFont myFont;
    //AgDiagramTextItem *textItem;
    QColor myTextColor;
    QColor myItemColor;
    QColor myLineColor;
    AgDiagramNotation::Notation myNotation;
};

#endif // AGDIAGRAMSCENE_H
