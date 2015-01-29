#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};

#endif // MAINWINDOW_H
