#include "agdiagramcontroler.h"

AgDiagramControler::AgDiagramControler(QObject *parent) :
    QObject(parent)
{
    objectResized = false;
}

void AgDiagramControler::setResized(bool value)
{
    objectResized = value;
}

bool AgDiagramControler::isResized() {
    return objectResized;
}

void AgDiagramControler::setChanged()
{
    setResized(true);
}

void AgDiagramControler::setNotation(AgDiagramNotation::Notation notation)
{
    myNotation = notation;
}

void AgDiagramControler::setDeleted(QString id)
{
    emit onDelete(id);
}
