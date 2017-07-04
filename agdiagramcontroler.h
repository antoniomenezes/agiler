#ifndef AGDIAGRAMCONTROLER_H
#define AGDIAGRAMCONTROLER_H

#include <QObject>
#include "agdiagramnotation.h"

class AgDiagramControler : public QObject
{
    Q_OBJECT
public:
    explicit AgDiagramControler(QObject *parent = 0);
    bool isResized();
    AgDiagramNotation::Notation notation() { return myNotation; }
signals:
    void onDelete(QString);

public slots:
    void setResized(bool value);
    void setChanged();
    void setNotation(AgDiagramNotation::Notation notation);
    void setDeleted(QString id);

private:
    bool objectResized;
    AgDiagramNotation::Notation myNotation;

};

#endif // AGDIAGRAMCONTROLER_H
