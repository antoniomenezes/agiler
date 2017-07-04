#ifndef AGDIAGRAMTABLEITEM_H
#define AGDIAGRAMTABLEITEM_H

#include "agdiagramitem.h"

class AgDiagramTableItem : public AgDiagramItem
{
public:
    AgDiagramTableItem(QMenu *contextMenu, QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    ~AgDiagramTableItem();
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    void setPos(const QPointF &pos);
    void setPos( qreal x, qreal y );
    void addColumn(QString columnDefition);
    void addRelationship(QGraphicsItem *item);
    void removeRelationship(QGraphicsItem *item);
    void reconfigureColumns();
    QPointF columnsPos();
    void setFont(QFont font);

private:
    QSet<QGraphicsItem *> relationships;
};

#endif // AGDIAGRAMTABLEITEM_H
