#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "nodedragger.h"
#include "nodescript/src/nodescript.h"

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

    NodeForm* buildNodeFormFromNode(Node* node);
    void addNodeFormInstance(NodeForm* nodeForm);
    void addNodeFormTemplate(NodeForm* nodeForm);

private:
    Ui::MainWindow *ui;
    ScriptEngine scriptEngine;
    NodeDragger nodeDragger;
};

#endif // MAINWINDOW_H
