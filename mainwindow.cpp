#include "mainwindow.h"
#include "nodeform.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NodeForm* nodeForm = addNodeForm("My Node");
    nodeForm->addInputValuePin("In Value Pin 1");
    nodeForm->addInputValuePin("In Value Pin 2");
    nodeForm->addInputImpulsePin("In Impulse Pin 1");
    nodeForm->addInputImpulsePin("In Impulse Pin 2");
    nodeForm->addOutputValuePin("Out Value Pin 1");
    nodeForm->addOutputValuePin("Out Value Pin 2");
    nodeForm->addOutputImpulsePin("Out Impulse Pin 1");
    nodeForm->addOutputImpulsePin("Out Impulse Pin 2");
    nodeForm->resize(nodeForm->sizeHint());
    //nodeForm->adjustSize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

NodeForm* MainWindow::addNodeForm(const char *name)
{
    return new NodeForm(ui->nodesFrame, name, nodeDragger);
}
