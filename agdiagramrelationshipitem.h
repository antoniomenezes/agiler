#ifndef AGDIAGRAMRELATIONSHIPITEM_H
#define AGDIAGRAMRELATIONSHIPITEM_H

#include <QPolygonF>
#include <QLineF>
#include <QPointF>
#include <QDebug>
#include <QGraphicsLineItem>
#include "agdiagramtableitem.h"

class AgDiagramRelationshipItem: public AgDiagramItem
{
public:
    enum { Type = UserType + 20 };

    int type() const
    {
        return Type;
    }

    AgDiagramRelationshipItem(QMenu *contextMenu, QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    ~AgDiagramRelationshipItem();
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    void setBeginTable(AgDiagramTableItem *tableItem);
    void setEndTable(AgDiagramTableItem *tableItem);
    void setInternalLineItems();
protected:
    AgDiagramTableItem *beginTableItem;
    AgDiagramTableItem *endTableItem;
    QList<QGraphicsLineItem *> lines;

    QGraphicsLineItem *beginLineItem;
    QGraphicsLineItem *centerLineItem;
    QGraphicsLineItem *endLineItem;
    QGraphicsLineItem *footLineItem1;
    QGraphicsLineItem *footLineItem2;
    QGraphicsLineItem *footBaseLineItem;
};

#endif // AGDIAGRAMRELATIONSHIPITEM_H
