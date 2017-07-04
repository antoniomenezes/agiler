#ifndef AGDIAGRAMITEM_H
#define AGDIAGRAMITEM_H

#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QFont>
#include <QFontMetricsF>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QRectF>
#include <QPolygonF>
#include "agdiagramcontroler.h"

class AgDiagramItem : public QGraphicsItemGroup
{
public:
    enum Type { Item, NodeItem, EdgeItem, GroupItem, TextItem, DecorationItem };

    enum State { Stay, Resizing, Editing, Other };

    enum { Type = UserType + 10 };

    int type() const
    {
        return Type;
    }

    AgDiagramItem(QMenu *contextMenu, QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    ~AgDiagramItem();
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    QString name();
    void setName(QString name);
    void setVisibleName(bool value);
    bool hasVisibleName();
    void setItemState(AgDiagramItem::State state);
    void setItemMargin(int value);
    int itemMargin();
    void setFont(QFont font);
    QFont font();
    void setId(QString value);
    QString id();
    QGraphicsPolygonItem *polygon();
    AgDiagramControler *controler;

protected:
    QString itemId;
    QMenu *itemContextMenu;
    QGraphicsPolygonItem *internalItem;
    QPolygonF itemPolygon;
    bool visibleName;
    QGraphicsTextItem *nameTextItem;
    //KvDiagramControler *controler;
    int currentItemMargin;
    QFont currentFont;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    QPainterPath roundRectPath(qreal radiusdiv);
};

#endif // AGDIAGRAMITEM_H
