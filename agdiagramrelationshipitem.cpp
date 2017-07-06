#include "agdiagramrelationshipitem.h"

AgDiagramRelationshipItem::AgDiagramRelationshipItem(QMenu *contextMenu, QGraphicsItem *parent, QGraphicsScene *scene): AgDiagramItem(contextMenu, parent, scene)
{
    beginTableItem = 0;
    endTableItem = 0;

    beginLineItem = 0;
    centerLineItem = 0;
    endLineItem = 0;
    footLineItem1 = 0;
    footLineItem2 = 0;
    footBaseLineItem = 0;

    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    controler->setNotation(AgDiagramNotation::CrowsFoot);
    scene->addItem(this);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    polygonItem()->setPen(pen);
}

AgDiagramRelationshipItem::~AgDiagramRelationshipItem()
{
    beginTableItem->removeRelationship(this);
    endTableItem->removeRelationship(this);
}

void AgDiagramRelationshipItem::setBeginTable(AgDiagramTableItem *tableItem)
{
    QLineF centerLine;
    beginTableItem = tableItem;
    if ((beginTableItem != NULL) && (endTableItem != NULL)) {
        QPolygonF thisPolygon;

        QLineF upperLine;
        QLineF lowerLine;

        centerLine.setP1(beginTableItem->polygonItem()->boundingRect().center());
        centerLine.setP2(endTableItem->polygonItem()->boundingRect().center());

        upperLine = centerLine.translated(10, -10);
        lowerLine = centerLine.translated(-10, 10);

        thisPolygon << upperLine.p1() << upperLine.p2() << lowerLine.p2() << lowerLine.p1();

        setPolygon(thisPolygon);

        if (!centerLineItem)
            centerLineItem = new QGraphicsLineItem(centerLine, this);
        if (!beginLineItem)
            beginLineItem = new QGraphicsLineItem(centerLine, this);
        if (!endLineItem)
            endLineItem = new QGraphicsLineItem(centerLine, this);
        if (!footLineItem1)
            footLineItem1 = new QGraphicsLineItem(centerLine, this);
        if (!footLineItem2)
            footLineItem2 = new QGraphicsLineItem(centerLine, this);
        if (!footBaseLineItem)
            footBaseLineItem = new QGraphicsLineItem(centerLine, this);

        setInternalLineItems();

    }
    tableItem->addRelationship(this);
}

void AgDiagramRelationshipItem::setEndTable(AgDiagramTableItem *tableItem)
{
    QLineF centerLine;
    endTableItem = tableItem;
    if ((beginTableItem != NULL) && (endTableItem != NULL)) {
        QPolygonF thisPolygon;

        QLineF upperLine;
        QLineF lowerLine;

        centerLine.setP1(beginTableItem->scenePos());
        centerLine.setP2(endTableItem->scenePos());

        upperLine = centerLine.translated(10, -10);
        lowerLine = centerLine.translated(-10, 10);

        thisPolygon << upperLine.p1() << upperLine.p2() << lowerLine.p2() << lowerLine.p1();

        setPolygon(thisPolygon);

        if (!centerLineItem)
            centerLineItem = new QGraphicsLineItem(centerLine, this);
        if (!beginLineItem)
            beginLineItem = new QGraphicsLineItem(centerLine, this);
        if (!endLineItem)
            endLineItem = new QGraphicsLineItem(centerLine, this);
        if (!footLineItem1)
            footLineItem1 = new QGraphicsLineItem(centerLine, this);
        if (!footLineItem2)
            footLineItem2 = new QGraphicsLineItem(centerLine, this);
        if (!footBaseLineItem)
            footBaseLineItem = new QGraphicsLineItem(centerLine, this);

        setInternalLineItems();
    }
    tableItem->addRelationship(this);
}

void AgDiagramRelationshipItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    /*
    if (beginTableItem != endTableItem) {
        QPolygonF thisPolygon;
        QLineF centerLine;
        QLineF upperLine;
        QLineF lowerLine;

        if ((beginTableItem != NULL) && (endTableItem != NULL)) {
            centerLine.setP1(beginTableItem->sceneBoundingRect().center());
            centerLine.setP2(endTableItem->sceneBoundingRect().center());

            int updx, updy, lodx, lody;
            if (centerLine.p1().x() < centerLine.p2().x()) {
                updx = 5;
                lodx = -5;
            }
            else {
                updx = -5;
                lodx = 5;
            }
            if (centerLine.p1().y() < centerLine.p2().y()) {
                updy = -5;
                lody = 5;
            }
            else {
                updy = 5;
                lody = -5;
            }

            upperLine = centerLine.translated(updx, updy);
            lowerLine = centerLine.translated(lodx, lody);

            thisPolygon << upperLine.p1() << upperLine.p2() << lowerLine.p2() << lowerLine.p1();

            setPolygon(thisPolygon);

            this->setBrush(Qt::transparent);
            //this->setBrush(Qt::lightGray);
            this->setPen(QPen(Qt::transparent));
            AgDiagramItem::paint(painter, option, widget);

            //QLineF perpendicularCenterLine = centerLine.normalVector().translated(+20,+20);

            QLineF beginBorderLine;
            QLineF endBorderLine;

            QLineF beginLine;
            QLineF endLine;


            // Handling centerLine over Begin Item
            QLineF beginLineTop = QLineF( beginTableItem->sceneBoundingRect().left(),
                                          beginTableItem->sceneBoundingRect().top(),
                                          beginTableItem->sceneBoundingRect().right(),
                                          beginTableItem->sceneBoundingRect().top() );
            QLineF beginLineRight = QLineF( beginTableItem->sceneBoundingRect().right(),
                                            beginTableItem->sceneBoundingRect().top(),
                                            beginTableItem->sceneBoundingRect().right(),
                                            beginTableItem->sceneBoundingRect().bottom() );
            QLineF beginLineBottom = QLineF( beginTableItem->sceneBoundingRect().left(),
                                             beginTableItem->sceneBoundingRect().bottom(),
                                             beginTableItem->sceneBoundingRect().right(),
                                             beginTableItem->sceneBoundingRect().bottom() );
            QLineF beginLineLeft = QLineF( beginTableItem->sceneBoundingRect().left(),
                                           beginTableItem->sceneBoundingRect().top(),
                                           beginTableItem->sceneBoundingRect().left(),
                                           beginTableItem->sceneBoundingRect().bottom() );
            QPointF beginIntersectPoint = centerLine.p1();

            int lastLength = (scene()->width() * scene()->height());

            if (beginLineTop.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineTop;
            }
            if (beginLineRight.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineRight;
            }
            if (beginLineBottom.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineBottom;
            }
            if (beginLineLeft.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineLeft;
            }

            beginBorderLine.setP1(centerLine.p1());
            beginLine = beginBorderLine.normalVector();

            beginLine.setLength(20);

            if (beginTableItem->sceneBoundingRect().contains(beginLine.p2())) {
                beginLine.setLength(-20);
            }
            else {
                beginLine.setLength(20);
            }

            centerLine.setP1(beginLine.p2());

            // Handling centerLine over End Item
            QLineF endLineTop = QLineF( endTableItem->sceneBoundingRect().left(),
                                        endTableItem->sceneBoundingRect().top(),
                                        endTableItem->sceneBoundingRect().right(),
                                        endTableItem->sceneBoundingRect().top() );
            QLineF endLineRight = QLineF( endTableItem->sceneBoundingRect().right(),
                                          endTableItem->sceneBoundingRect().top(),
                                          endTableItem->sceneBoundingRect().right(),
                                          endTableItem->sceneBoundingRect().bottom() );
            QLineF endLineBottom = QLineF( endTableItem->sceneBoundingRect().left(),
                                           endTableItem->sceneBoundingRect().bottom(),
                                           endTableItem->sceneBoundingRect().right(),
                                           endTableItem->sceneBoundingRect().bottom() );
            QLineF endLineLeft = QLineF( endTableItem->sceneBoundingRect().left(),
                                         endTableItem->sceneBoundingRect().top(),
                                         endTableItem->sceneBoundingRect().left(),
                                         endTableItem->sceneBoundingRect().bottom() );
            QPointF endIntersectPoint = centerLine.p2();

            lastLength = (scene()->width() * scene()->height());

            if (endLineTop.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineTop;
            }
            if (endLineRight.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineRight;
            }
            if (endLineBottom.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineBottom;
            }
            if (endLineLeft.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineLeft;
            }

            endBorderLine.setP1(centerLine.p2());
            endLine = endBorderLine.normalVector();
            endLine.setLength(20);
            centerLine.setP2(endLine.p2());
            QPointF tmpP1 = endLine.p1();
            endLine.setP1(centerLine.p2());
            endLine.setP2(tmpP1);


            if (endTableItem->sceneBoundingRect().contains(endLine.p1())) {
                QPointF tmpP1 = endLine.p1();
                QPointF tmpP2 = endLine.p2();
                endLine.setP1(tmpP2);
                endLine.setP2(tmpP1);
                endLine.setLength(-20);
                endLine.setP1(endLine.p2());
                endLine.setP2(tmpP2);
                centerLine.setP2(endLine.p1());
            }

            painter->setPen(Qt::black);

            QLineF beginUpperLine;
            QLineF beginLowerLine;
            QLineF endUpperLine;
            QLineF endLowerLine;

            beginUpperLine = beginLine.translated(updx, updy);
            beginLowerLine = beginLine.translated(lodx, lody);
            upperLine = centerLine.translated(updx, updy);
            lowerLine = centerLine.translated(lodx, lody);
            endUpperLine = endLine.translated(updx, updy);
            endLowerLine = endLine.translated(lodx, lody);

            thisPolygon << beginUpperLine.p1() << beginUpperLine.p2();
            thisPolygon << upperLine.p1() << upperLine.p2();
            thisPolygon << endUpperLine.p1() << endUpperLine.p2();
            thisPolygon << endLowerLine.p2() << endLowerLine.p1();
            thisPolygon << lowerLine.p2() << lowerLine.p1();
            thisPolygon << beginLowerLine.p2() << beginLowerLine.p1();

            setPolygon(thisPolygon);

            if ( (! endTableItem->sceneBoundingRect().contains(centerLine.p1()) ) &&
                 (!beginTableItem->sceneBoundingRect().contains(centerLine.p2())) ) {
                painter->drawLine(beginLine);
                //painter->drawEllipse(beginLine.p2(), 5, 5);
                painter->drawLine(centerLine);
                painter->drawLine(endLine);
                //painter->drawEllipse(endLine.p2(), 5, 5);

                if (controler->notation() == AgDiagramNotation::CrowsFoot) {
                    QLineF lineFoot1, lineFoot2, lineAux, lineFootBase;
                    lineFoot1.setP1(endLine.p2());
                    lineFoot1.setP2(endLine.p1());
                    lineFoot1.setLength(10);
                    lineFoot2.setP1(endLine.p2());
                    lineFoot2.setP2(endLine.p1());
                    lineFoot2.setLength(10);

                    lineFoot1.setP1(lineFoot2.p2());
                    lineFoot1.setP2(lineFoot2.p1());
                    lineFoot2.setP1(lineFoot1.p1());
                    lineFoot2.setP2(lineFoot1.p2());
                    lineFoot2.setAngle(lineFoot2.angle()+30);
                    lineFoot1.setAngle(lineFoot1.angle()-30);

                    lineAux.setP1(lineFoot1.p1());
                    lineAux.setP2(endLine.p2());
                    lineAux = lineAux.normalVector();
                    lineAux.setLength(5);
                    lineFootBase.setP1(lineAux.p2());
                    lineAux.setLength(-5);
                    lineFootBase.setP2(lineAux.p2());
                    painter->drawLine(lineFoot1);
                    painter->drawLine(lineFoot2);
                    painter->drawLine(lineFootBase);

                }
                else if (controler->notation() == AgDiagramNotation::Dependency) {
                    QLineF lineFoot1, lineFoot2;
                    lineFoot1.setP1(beginLine.p1());
                    lineFoot1.setP2(beginLine.p2());
                    lineFoot1.setLength(10);
                    lineFoot2.setP1(beginLine.p1());
                    lineFoot2.setP2(beginLine.p2());
                    lineFoot2.setLength(10);

                    lineFoot1.setP1(lineFoot2.p1());
                    lineFoot1.setP2(lineFoot2.p2());
                    lineFoot2.setP1(lineFoot1.p1());
                    lineFoot2.setP2(lineFoot1.p2());

                    lineFoot2.setAngle(lineFoot2.angle()+30);
                    lineFoot1.setAngle(lineFoot1.angle()-30);

                    painter->drawLine(lineFoot1);
                    painter->drawLine(lineFoot2);
                }
            }
        }
    }*/
    setInternalLineItems();

    setPolygon(boundingRect());
}

void AgDiagramRelationshipItem::setInternalLineItems()
{
    if (beginTableItem != endTableItem) {
        QPolygonF thisPolygon;
        QLineF centerLine;
        QLineF upperLine;
        QLineF lowerLine;

        if ((beginTableItem != NULL) && (endTableItem != NULL)) {
            centerLine.setP1(beginTableItem->sceneBoundingRect().center());
            centerLine.setP2(endTableItem->sceneBoundingRect().center());

            int updx, updy, lodx, lody;
            if (centerLine.p1().x() < centerLine.p2().x()) {
                updx = 5;
                lodx = -5;
            }
            else {
                updx = -5;
                lodx = 5;
            }
            if (centerLine.p1().y() < centerLine.p2().y()) {
                updy = -5;
                lody = 5;
            }
            else {
                updy = 5;
                lody = -5;
            }

            upperLine = centerLine.translated(updx, updy);
            lowerLine = centerLine.translated(lodx, lody);

            thisPolygon << upperLine.p1() << upperLine.p2() << lowerLine.p2() << lowerLine.p1();

            setPolygon(thisPolygon);

            this->polygonItem()->setBrush(Qt::transparent);
            //this->setBrush(Qt::gray);
            this->polygonItem()->setPen(QPen(Qt::transparent));

            //QLineF perpendicularCenterLine = centerLine.normalVector().translated(+20,+20);

            QLineF beginBorderLine;
            QLineF endBorderLine;

            QLineF beginLine;
            QLineF endLine;


            // Handling centerLine over Begin Item
            QLineF beginLineTop = QLineF( beginTableItem->sceneBoundingRect().left(),
                                          beginTableItem->sceneBoundingRect().top(),
                                          beginTableItem->sceneBoundingRect().right(),
                                          beginTableItem->sceneBoundingRect().top() );
            QLineF beginLineRight = QLineF( beginTableItem->sceneBoundingRect().right(),
                                            beginTableItem->sceneBoundingRect().top(),
                                            beginTableItem->sceneBoundingRect().right(),
                                            beginTableItem->sceneBoundingRect().bottom() );
            QLineF beginLineBottom = QLineF( beginTableItem->sceneBoundingRect().left(),
                                             beginTableItem->sceneBoundingRect().bottom(),
                                             beginTableItem->sceneBoundingRect().right(),
                                             beginTableItem->sceneBoundingRect().bottom() );
            QLineF beginLineLeft = QLineF( beginTableItem->sceneBoundingRect().left(),
                                           beginTableItem->sceneBoundingRect().top(),
                                           beginTableItem->sceneBoundingRect().left(),
                                           beginTableItem->sceneBoundingRect().bottom() );
            QPointF beginIntersectPoint = centerLine.p1();

            int lastLength = (scene()->width() * scene()->height());

            // Find beginTable Line Border
            if (beginLineTop.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineTop;
            }
            if (beginLineRight.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineRight;
            }
            if (beginLineBottom.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineBottom;
            }
            if (beginLineLeft.intersect(centerLine, &beginIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(beginIntersectPoint, centerLine.p2()).length() < lastLength)
                    centerLine.setP1( beginIntersectPoint );
                lastLength = centerLine.length();
                beginBorderLine = beginLineLeft;
            }

            beginBorderLine.setP1(centerLine.p1());
            beginLine = beginBorderLine.normalVector();

            beginLine.setLength(10);

            if (beginTableItem->sceneBoundingRect().contains(beginLine.p2())) {
                beginLine.setLength(-10);
            }
            else {
                beginLine.setLength(10);
            }

            centerLine.setP1(beginLine.p2());

            // Handling centerLine over End Item
            QLineF endLineTop = QLineF( endTableItem->sceneBoundingRect().left(),
                                        endTableItem->sceneBoundingRect().top(),
                                        endTableItem->sceneBoundingRect().right(),
                                        endTableItem->sceneBoundingRect().top() );
            QLineF endLineRight = QLineF( endTableItem->sceneBoundingRect().right(),
                                          endTableItem->sceneBoundingRect().top(),
                                          endTableItem->sceneBoundingRect().right(),
                                          endTableItem->sceneBoundingRect().bottom() );
            QLineF endLineBottom = QLineF( endTableItem->sceneBoundingRect().left(),
                                           endTableItem->sceneBoundingRect().bottom(),
                                           endTableItem->sceneBoundingRect().right(),
                                           endTableItem->sceneBoundingRect().bottom() );
            QLineF endLineLeft = QLineF( endTableItem->sceneBoundingRect().left(),
                                         endTableItem->sceneBoundingRect().top(),
                                         endTableItem->sceneBoundingRect().left(),
                                         endTableItem->sceneBoundingRect().bottom() );
            QPointF endIntersectPoint = centerLine.p2();

            lastLength = (scene()->width() * scene()->height());

            // Find endTable Line Border
            if (endLineTop.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineTop;
            }
            if (endLineRight.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineRight;
            }
            if (endLineBottom.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineBottom;
            }
            if (endLineLeft.intersect(centerLine, &endIntersectPoint) == QLineF::BoundedIntersection) {
                if (QLineF(endIntersectPoint, centerLine.p1()).length() < lastLength)
                    centerLine.setP2( endIntersectPoint );
                lastLength = centerLine.length();
                endBorderLine = endLineLeft;
            }

            endBorderLine.setP1(centerLine.p2());
            endLine = endBorderLine.normalVector();
            endLine.setLength(10);
            centerLine.setP2(endLine.p2());
            QPointF tmpP1 = endLine.p1();
            endLine.setP1(centerLine.p2());
            endLine.setP2(tmpP1);


            if (endTableItem->sceneBoundingRect().contains(endLine.p1())) {
                QPointF tmpP1 = endLine.p1();
                QPointF tmpP2 = endLine.p2();
                endLine.setP1(tmpP2);
                endLine.setP2(tmpP1);
                endLine.setLength(-10);
                endLine.setP1(endLine.p2());
                endLine.setP2(tmpP2);
                centerLine.setP2(endLine.p1());
            }

            QLineF beginUpperLine;
            QLineF beginLowerLine;
            QLineF endUpperLine;
            QLineF endLowerLine;

            beginUpperLine = beginLine.translated(updx, updy);
            beginLowerLine = beginLine.translated(lodx, lody);
            upperLine = centerLine.translated(updx, updy);
            lowerLine = centerLine.translated(lodx, lody);
            endUpperLine = endLine.translated(updx, updy);
            endLowerLine = endLine.translated(lodx, lody);

            thisPolygon << beginUpperLine.p1() << beginUpperLine.p2();
            thisPolygon << upperLine.p1() << upperLine.p2();
            thisPolygon << endUpperLine.p1() << endUpperLine.p2();
            thisPolygon << endLowerLine.p2() << endLowerLine.p1();
            thisPolygon << lowerLine.p2() << lowerLine.p1();
            thisPolygon << beginLowerLine.p2() << beginLowerLine.p1();

            setPolygon(thisPolygon);

            if ( (! endTableItem->sceneBoundingRect().contains(centerLine.p1()) ) &&
                 (!beginTableItem->sceneBoundingRect().contains(centerLine.p2())) ) {

                beginLineItem->setLine(beginLine);
                centerLineItem->setLine(centerLine);
                endLineItem->setLine(endLine);

                if (controler->notation() == AgDiagramNotation::CrowsFoot) {
                    QLineF lineFoot1, lineFoot2, lineAux, lineFootBase;
                    lineFoot1.setP1(endLine.p2());
                    lineFoot1.setP2(endLine.p1());
                    lineFoot1.setLength(10);
                    lineFoot2.setP1(endLine.p2());
                    lineFoot2.setP2(endLine.p1());
                    lineFoot2.setLength(10);

                    lineFoot1.setP1(lineFoot2.p2());
                    lineFoot1.setP2(lineFoot2.p1());
                    lineFoot2.setP1(lineFoot1.p1());
                    lineFoot2.setP2(lineFoot1.p2());
                    lineFoot2.setAngle(lineFoot2.angle()+30);
                    lineFoot1.setAngle(lineFoot1.angle()-30);

                    lineAux.setP1(lineFoot1.p1());
                    lineAux.setP2(endLine.p2());
                    lineAux = lineAux.normalVector();
                    lineAux.setLength(5);
                    lineFootBase.setP1(lineAux.p2());
                    lineAux.setLength(-5);
                    lineFootBase.setP2(lineAux.p2());


                    footLineItem1->setLine(lineFoot1);
                    footLineItem2->setLine(lineFoot2);
                    footBaseLineItem->setLine(lineFootBase);

                }
                else if (controler->notation() == AgDiagramNotation::Dependency) {
                    QLineF lineFoot1, lineFoot2;
                    lineFoot1.setP1(beginLine.p1());
                    lineFoot1.setP2(beginLine.p2());
                    lineFoot1.setLength(10);
                    lineFoot2.setP1(beginLine.p1());
                    lineFoot2.setP2(beginLine.p2());
                    lineFoot2.setLength(10);

                    lineFoot1.setP1(lineFoot2.p1());
                    lineFoot1.setP2(lineFoot2.p2());
                    lineFoot2.setP1(lineFoot1.p1());
                    lineFoot2.setP2(lineFoot1.p2());

                    lineFoot2.setAngle(lineFoot2.angle()+30);
                    lineFoot1.setAngle(lineFoot1.angle()-30);

                    footLineItem1->setLine(lineFoot1);
                    footLineItem2->setLine(lineFoot2);

                }
            }
        }
        if ( (endTableItem->sceneBoundingRect().contains(endLineItem->sceneBoundingRect().center())) ||
             (beginTableItem->sceneBoundingRect().contains(beginLineItem->sceneBoundingRect().center()))) {
            QLineF line = QLineF(beginLineItem->line().p1(),beginLineItem->line().p1());

            centerLineItem->setLine(line);
            beginLineItem->setLine(line);
            endLineItem->setLine(line);
            footLineItem1->setLine(line);
            footLineItem2->setLine(line);
            footBaseLineItem->setLine(line);
        }

    }
}
