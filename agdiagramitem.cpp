#include "agdiagramitem.h"

AgDiagramItem::AgDiagramItem(QMenu *contextMenu, QGraphicsItem *parent, QGraphicsScene *scene): QGraphicsItemGroup(parent)
{
    controler = new AgDiagramControler();
    nameTextItem = 0;
    currentItemMargin = 10;
    setVisibleName(false);
    setItemState(AgDiagramItem::Stay);
    itemContextMenu = contextMenu;
    itemPolygon << QPointF(10, 10) << QPointF(50, 10)
                << QPointF(50, 50) << QPointF(10, 50);
    if (internalItem)
        internalItem->setPolygon(itemPolygon);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    scene->addItem(this);
}

AgDiagramItem::~AgDiagramItem()
{
    controler->setDeleted(id());

    delete controler;
}

QString AgDiagramItem::name()
{
    return data(0).toString();
}

void AgDiagramItem::setName(QString name)
{
    setData(0, name);
    if (visibleName) {
        if (! nameTextItem) {
            nameTextItem = new QGraphicsTextItem(this);
        }
        nameTextItem->setPlainText(name);
        itemPolygon = QPolygonF( nameTextItem->boundingRect() );
        addToGroup(nameTextItem);
        if (internalItem)
            internalItem->setPolygon(itemPolygon);
    }
}

void AgDiagramItem::setId(QString value)
{
    itemId = value;
}

QString AgDiagramItem::id()
{
    return itemId;
}

QGraphicsPolygonItem *AgDiagramItem::polygon()
{
    return internalItem;
}

void AgDiagramItem::setVisibleName(bool value)
{
    visibleName = value;
    if (value) {
        if (! nameTextItem) {
            nameTextItem = new QGraphicsTextItem(name(), this);
            QObject::connect(nameTextItem, SIGNAL(widthChanged()), controler, SLOT(setChanged()));
            nameTextItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
            nameTextItem->setTextInteractionFlags(Qt::TextEditorInteraction);
            itemPolygon = QPolygonF( nameTextItem->boundingRect().adjusted(-currentItemMargin, -currentItemMargin, currentItemMargin, currentItemMargin) );
            addToGroup(nameTextItem);
            if (internalItem)
                internalItem->setPolygon(itemPolygon);
        }
        QPointF itemPos = this->pos();
        itemPos.setX(itemPos.x());
        itemPos.setY(itemPos.y());
        nameTextItem->setPos(itemPos);
    }
    else {
        delete nameTextItem;
        nameTextItem = 0;
    }
}

bool AgDiagramItem::hasVisibleName()
{
    return visibleName;
}

void AgDiagramItem::setItemMargin(int value)
{
    currentItemMargin = value;
}

int AgDiagramItem::itemMargin()
{
    return currentItemMargin;
}

void AgDiagramItem::setItemState(AgDiagramItem::State state)
{
    if (state = AgDiagramItem::Resizing) {
        setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    }
    else {
        setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    }
}

void AgDiagramItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if (hasVisibleName() && (childItems().count() == 1)) {
        itemPolygon = QPolygonF( nameTextItem->boundingRect().adjusted(-currentItemMargin, -currentItemMargin, currentItemMargin, currentItemMargin) );
        if (internalItem)
            internalItem->setPolygon(itemPolygon);
    }

    QGraphicsItemGroup::paint(painter, option, widget);
}

void AgDiagramItem::setFont(QFont font)
{
    currentFont = font;
    nameTextItem->setFont(currentFont);
}

QFont AgDiagramItem::font()
{
    return currentFont;
}

void AgDiagramItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    itemContextMenu->exec(event->screenPos());
}

QPainterPath AgDiagramItem::roundRectPath(qreal radiusdiv)
{
    QPolygonF thisPolygon = this->boundingRect();
    QRectF rect = thisPolygon.boundingRect();
    int radius = qMin(rect.width(), rect.height()) / radiusdiv;
    int diam = 2 * radius;

    qreal x1, y1, x2, y2;
    rect.getCoords(&x1, &y1, &x2, &y2);

    QPainterPath path;
    path.moveTo(x2, y1 + radius);
    path.arcTo(QRect(x2 - diam, y1, diam, diam), 0.0, +90.0);
    path.lineTo(x1 + radius, y1);
    path.arcTo(QRect(x1, y1, diam, diam), 90.0, +90.0);
    path.lineTo(x1, y2 - radius);
    path.arcTo(QRect(x1, y2 - diam, diam, diam), 180.0, +90.0);
    path.lineTo(x1 + radius, y2);
    path.arcTo(QRect(x2 - diam, y2 - diam, diam, diam), 270.0, +90.0);
    path.closeSubpath();
    return path;
}
