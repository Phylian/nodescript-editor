#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "nodedragger.h"

class NodeForm;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    NodeForm* addNodeForm(const char* name);

private:
    Ui::MainWindow *ui;
    NodeDragger nodeDragger;
};

#endif // MAINWINDOW_H
