#ifndef AGDIAGRAMWINDOW_H
#define AGDIAGRAMWINDOW_H

#include <QWidget>

namespace Ui {
class AgDiagramWindow;
}

class AgDiagramWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AgDiagramWindow(QWidget *parent = 0);
    ~AgDiagramWindow();

private slots:
    void on_actionSelect_triggered();

    void on_actionNew_Table_triggered();

    void on_actionNew_Relationship_triggered();

    void on_actionNew_Label_triggered();

private:
    Ui::AgDiagramWindow *ui;
};

#endif // AGDIAGRAMWINDOW_H
