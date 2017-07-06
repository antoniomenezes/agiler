#include "agdiagramscene.h"

AgDiagramScene::AgDiagramScene(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
{
    myItemMenu = itemMenu;
    myMode = MoveItem;
    myNotation = AgDiagramNotation::CrowsFoot;
    //myItemType = DiagramItem::Step;
    line = 0;
    //textItem = 0;
    myItemColor = Qt::white;
    myTextColor = Qt::black;
    myLineColor = Qt::black;
    currentItemMargin = 10;
    idGenerator = 0;
}

void AgDiagramScene::setLineColor(const QColor &color)
{
    myLineColor = color;
    //    if (isItemChange(Arrow::Type)) {
    //        Arrow *item =
    //            qgraphicsitem_cast<Arrow *>(selectedItems().first());
    //        item->setColor(myLineColor);
    //        update();
    //    }
}

void AgDiagramScene::setTextColor(const QColor &color)
{
    myTextColor = color;
    //    if (isItemChange(DiagramTextItem::Type)) {
    //        DiagramTextItem *item =
    //            qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
    //        item->setDefaultTextColor(myTextColor);
    //    }
}

void AgDiagramScene::setItemColor(const QColor &color)
{
    myItemColor = color;
    //    if (isItemChange(DiagramItem::Type)) {
    //        AgDiagramItem *item =
    //            qgraphicsitem_cast<AgDiagramItem *>(selectedItems().first());
    //        item->setBrush(myItemColor);
    //    }
}

void AgDiagramScene::setFont(const QFont &font)
{
    myFont = font;

    //    if (isItemChange(DiagramTextItem::Type)) {
    //        QGraphicsTextItem *item =
    //            qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
    //        //At this point the selection can change so the first selected item might not be a DiagramTextItem
    //        if (item)
    //            item->setFont(myFont);
    //    }
}

void AgDiagramScene::setItemMargin(int value)
{
    currentItemMargin = value;
    foreach(QGraphicsItem *item, items()) {
        if (item->type() == AgDiagramItem::Type) {
            AgDiagramItem *diagramItem = (AgDiagramItem *) item;
            diagramItem->setItemMargin(currentItemMargin);
        }
    }
    update();
}

void AgDiagramScene::setMode(Mode mode)
{
    myMode = mode;
}

void AgDiagramScene::setNotation(AgDiagramNotation::Notation notation)
{
    myNotation = notation;
    emit notationChanged(notation);
    update();
}

//void AgDiagramScene::setItemType(DiagramItem::DiagramType type)
//{
//    myItemType = type;
//}

//void AgDiagramScene::editorLostFocus(AgDiagramTextItem *item)
//{
//    QTextCursor cursor = item->textCursor();
//    cursor.clearSelection();
//    item->setTextCursor(cursor);

//    if (item->toPlainText().isEmpty()) {
//        removeItem(item);
//        item->deleteLater();
//    }
//}

void AgDiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    AgDiagramTableItem *item;
    switch (myMode) {
    case InsertTable:
        item = new AgDiagramTableItem(myItemMenu);
        item->setName("Table");
        item->setVisibleName(true);
        item->setPos(mouseEvent->scenePos());
        item->setFont(myFont);
        item->addColumn("column_name data_type null_option default_option");
        item->setItemMargin(currentItemMargin);
        item->polygonItem()->setBrush(myItemColor);
        connect(this, SIGNAL(notationChanged(AgDiagramNotation::Notation)), item->controler, SLOT(setNotation(AgDiagramNotation::Notation)));
        addItem(item);
        item->setPos(mouseEvent->scenePos());
        emit itemInserted(item);
        break;

    case InsertRelation:
        line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
        line->setPen(QPen(myLineColor, 2));
        addItem(line);

    default:
        ;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);

    emit mouseClicked(mouseEvent->scenePos());
}


void AgDiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (myMode == InsertRelation && line != 0) {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    } else if (myMode == MoveItem) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}

void AgDiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (line != 0 && myMode == InsertRelation) {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;

        if (startItems.count() > 0 && endItems.count() > 0 &&
                startItems.first()->type() == AgDiagramTableItem::Type &&
                endItems.first()->type() == AgDiagramTableItem::Type //&&
                /*startItems.first() != endItems.first()*/ ) {
            AgDiagramTableItem *startItem = qgraphicsitem_cast<AgDiagramTableItem *>(startItems.first());
            AgDiagramTableItem *endItem = qgraphicsitem_cast<AgDiagramTableItem *>(endItems.first());
            AgDiagramRelationshipItem *relationship = new AgDiagramRelationshipItem(myItemMenu, 0, this);
            relationship->setBeginTable(startItem);
            relationship->setEndTable(endItem);
            relationship->polygonItem()->setBrush(Qt::white);
            relationship->polygonItem()->setPen(lineColor());
            relationship->setSelected(true);
            relationship->controler->setNotation(notation());
            connect(this, SIGNAL(notationChanged(AgDiagramNotation::Notation)), relationship->controler, SLOT(setNotation(AgDiagramNotation::Notation)));
            //relationship->setName("relation");
            //relationship->setVisibleName(true);
            //relationship->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);

            //arrow->setColor(myLineColor);
            //startItem->addArrow(arrow);
            //endItem->addArrow(arrow);
            //arrow->setZValue(-1000.0);
            addItem(relationship);
            sendToBack();
            //arrow->updatePosition();
        }
    }
    line = 0;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

bool AgDiagramScene::isItemChange(QString name)
{
    foreach (QGraphicsItem *item, selectedItems()) {
        if (item->data(0).toString() == name)
            return true;
    }
    return false;
}

void AgDiagramScene::bringToFront()
{
    if (selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() >= zValue &&
                item->type() == AgDiagramItem::Type)
            zValue = item->zValue() + 0.1;
    }
    selectedItem->setZValue(zValue);
}

void AgDiagramScene::sendToBack()
{
    if (selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() <= zValue &&
                item->type() == AgDiagramItem::Type)
            zValue = item->zValue() - 0.1;
    }
    selectedItem->setZValue(zValue);
}

void AgDiagramScene::saveToPdf(QString fileName)
{


//    QPrinter *pdfPrinter = new QPrinter;
//    QPainter *pdfPainter = new QPainter;
//    pdfPrinter->setOutputFormat(QPrinter::PdfFormat);
//    pdfPrinter->setPaperSize(sceneRect().size(), QPrinter::Point);
//    pdfPrinter->setFullPage(true);
//    pdfPrinter->setOutputFileName(fileName);
//    pdfPrinter->setResolution(QPrinter::HighResolution);
//    //pdfPrinter->setResolution(QPrinter::ScreenResolution);
//    pdfPainter->begin(pdfPrinter);
//    render(pdfPainter);
//    pdfPainter->end();
//    delete pdfPainter;
//    delete pdfPrinter;

    QPrinter printer(QPrinter::HighResolution);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    printer.setOutputFormat(QPrinter::PdfFormat);
    QPainter painter(&printer);
    render(&painter);

}

void AgDiagramScene::saveToSvg(QString fileName)
{
    QSvgGenerator svgGen;
    svgGen.setFileName(fileName);
    QSize size = sceneRect().size().toSize();
    svgGen.setSize(size);
    svgGen.setViewBox(sceneRect());
    svgGen.setTitle(tr("Diagram exported by Kevora"));
    svgGen.setDescription(tr("An ER Diagram exported by Kevora IDE"));
    QPainter painter( &svgGen );
    render( &painter );
}

AgDiagramTableItem *AgDiagramScene::addTableItem(QString tableName, QMenu *contextMenu)
{
    AgDiagramTableItem *item;
    item = new AgDiagramTableItem(contextMenu);
    item->setName(tableName);
    item->setVisibleName(true);

    QTime midnight(0, 0, 0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    int width = qRound(sceneRect().width()/2);
    int height = qRound(sceneRect().height()/2);
    int x = qRound( (double) (qrand() % width) );
    int y = qRound( (double) (qrand() % height) );

    item->setPos(QPoint(x,y));
    item->setFont(myFont);
    item->setItemMargin(currentItemMargin);
    item->polygonItem()->setBrush(myItemColor);
    connect(this, SIGNAL(notationChanged(AgDiagramNotation::Notation)), item->controler, SLOT(setNotation(AgDiagramNotation::Notation)));
    addItem(item);
    //item->setPos(sceneRect().center());
    emit itemInserted(item);
    return item;
}

AgDiagramRelationshipItem *AgDiagramScene::addRelationshipItem(AgDiagramTableItem *beginTableItem, AgDiagramTableItem *endTableItem, QMenu *contextMenu)
{
    AgDiagramRelationshipItem *relationship = new AgDiagramRelationshipItem(contextMenu, 0, this);
    relationship->setBeginTable(beginTableItem);
    relationship->setEndTable(endTableItem);
    relationship->polygonItem()->setBrush(Qt::white);
    relationship->polygonItem()->setPen(lineColor());
    relationship->setSelected(true);
    relationship->controler->setNotation(notation());
    connect(this, SIGNAL(notationChanged(AgDiagramNotation::Notation)), relationship->controler, SLOT(setNotation(AgDiagramNotation::Notation)));
    addItem(relationship);
    clearSelection();
    relationship->setSelected(true);
    sendToBack();
    clearSelection();
}
