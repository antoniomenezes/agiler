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

private:
    Ui::AgDiagramWindow *ui;
};

#endif // AGDIAGRAMWINDOW_H
