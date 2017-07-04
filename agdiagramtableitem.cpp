#include "agdiagramtableitem.h"

AgDiagramTableItem::AgDiagramTableItem(QMenu *contextMenu, QGraphicsItem *parent, QGraphicsScene *scene) : AgDiagramItem(contextMenu, parent, scene)
{
    relationships = QSet<QGraphicsItem *>();
}

AgDiagramTableItem::~AgDiagramTableItem()
{
    foreach (QGraphicsItem *item, relationships) {
        //relationships.remove(item);
        delete item;
    }
}

void AgDiagramTableItem::addColumn(QString columnDefition)
{
    QGraphicsTextItem *columnTextItem = new QGraphicsTextItem(columnDefition, this);
    // QObject::connect(nameTextItem, SIGNAL(widthChanged()), controler, SLOT(setChanged()));
    columnTextItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    columnTextItem->setTextInteractionFlags(Qt::TextEditorInteraction);
    columnTextItem->setPos(columnsPos());
    columnTextItem->setData(0, "COLUMN");
    columnTextItem->setFont(font());
}

void AgDiagramTableItem::addRelationship(QGraphicsItem *item)
{
    relationships.insert(item);
}

void AgDiagramTableItem::removeRelationship(QGraphicsItem *item)
{
    relationships.remove(item);
}

void AgDiagramTableItem::reconfigureColumns()
{
    int maxItemWidth = 0;
    foreach(QGraphicsItem *item, childItems()) {
        if (item->data(0).toString().compare("COLUMN", Qt::CaseInsensitive) == 0) {
            if (maxItemWidth < item->boundingRect().width())
                maxItemWidth = item->boundingRect().width();
        }
    }

    QPointF newPos = columnsPos();
    int nameWidth = nameTextItem->boundingRect().width();
    for(int i=0; i<childItems().count(); i++) {
        QGraphicsItem *item = childItems().at(i);
        if (item->data(0).toString().compare("COLUMN", Qt::CaseInsensitive) == 0) {
            QGraphicsTextItem * textItem = (QGraphicsTextItem *) item;
            int textItemWidth = textItem->boundingRect().width();
            QPointF newTextPos = textItem->pos();
            int diffWidth = abs(nameWidth - maxItemWidth);

            if (nameWidth < maxItemWidth) {
                textItem->setX(nameTextItem->x()-(diffWidth/2));
            }
            else {
                textItem->setX(nameTextItem->x()+(diffWidth/2));
            }
        }
    }
    itemPolygon = QPolygonF( childrenBoundingRect().adjusted(-currentItemMargin, -currentItemMargin, currentItemMargin, currentItemMargin) );

    setPolygon(itemPolygon);
}

QPointF AgDiagramTableItem::columnsPos()
{

    QPointF columnAreaPos = nameTextItem->pos();
    columnAreaPos.setX( columnAreaPos.x() - (nameTextItem->boundingRect().width()/3) );
    if (childItems().count() <= 1)
        columnAreaPos.setY( columnAreaPos.y() + nameTextItem->boundingRect().height() );
    else {
        QFontMetricsF metrics = QFontMetricsF(font());
        int newHeight = nameTextItem->boundingRect().height() + (metrics.height() * (childItems().count()-2));
        columnAreaPos.setY( columnAreaPos.y() + newHeight);
    }
    return columnAreaPos;
}

void AgDiagramTableItem::setPos(const QPointF &pos)
{
    QGraphicsItem::setPos(pos);
    if (relationships.count() > 0) {
        foreach(QGraphicsItem *item, relationships)
            item->update();
    }
}

void AgDiagramTableItem::setPos ( qreal x, qreal y )
{
    QGraphicsItem::setPos(x, y);
    if (relationships.count() > 0) {
        foreach(QGraphicsItem *item, relationships)
            item->update();
    }
}

void AgDiagramTableItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if (childItems().count() > 1) {
        reconfigureColumns();
    }

    if (relationships.count() > 0) {
        foreach(QGraphicsItem *item, relationships)
            item->paint(painter, option, widget);
    }

    QPainterPath path = roundRectPath(32);
    setPolygon(path.toFillPolygon());

    AgDiagramItem::paint(painter, option, widget);

    QPointF p1, p2;
    QFontMetricsF metrics = QFontMetricsF(font());
    p1 = QPointF(boundingRect().topLeft().x(), nameTextItem->y()+(1.7*metrics.height()));
    p2 = QPointF(boundingRect().topRight().x(), nameTextItem->y()+(1.7*metrics.height()));
    painter->drawLine(p1, p2);
}

void AgDiagramTableItem::setFont(QFont font)
{
    AgDiagramItem::setFont(font);
    foreach(QGraphicsItem *item, childItems()) {
        if (item->type() == QGraphicsTextItem::Type) {
            QGraphicsTextItem *textItem = (QGraphicsTextItem *) item;
            textItem->setFont(font);
        }
    }
}
