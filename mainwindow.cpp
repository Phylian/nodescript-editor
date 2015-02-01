#include <cassert>
#include "mainwindow.h"
#include "nodeform.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const std::map<std::string, Node*>& registeredNodes = scriptEngine.getAllRegisteredNodes();
    for (const std::pair<std::string, Node*>& node : registeredNodes)
    {
        {
            NodeForm* nodeForm = buildNodeFormFromNode(node.second);
            addNodeFormInstance(nodeForm);
        }

        {
            NodeForm* nodeForm = buildNodeFormFromNode(node.second);
            addNodeFormTemplate(nodeForm);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

NodeForm* MainWindow::buildNodeFormFromNode(Node* node)
{
    NodeForm* nodeForm = new NodeForm(node->getNodeName());
    int numPins = node->getNumPins();
    for (int i = 0; i < numPins; ++i)
    {
        const char* pinName = node->getPinName(i);
        switch (node->getPinArchetype(i))
        {
        case PinArchetype::INPUT_VALUE:
            nodeForm->addInputValuePin(pinName);
            break;
        case PinArchetype::INPUT_IMPULSE:
            nodeForm->addInputImpulsePin(pinName);
            break;
        case PinArchetype::OUTPUT_VALUE:
            nodeForm->addOutputValuePin(pinName);
            break;
        case PinArchetype::OUTPUT_IMPULSE:
            nodeForm->addOutputImpulsePin(pinName);
            break;
        default:
            assert(false);
        }
    }
    nodeForm->resize(nodeForm->sizeHint());
    return nodeForm;
}

void MainWindow::addNodeFormInstance(NodeForm *nodeForm)
{
    nodeForm->setNodeDragger(&nodeDragger);
    nodeForm->setParent(ui->scriptFrame);
}

void MainWindow::addNodeFormTemplate(NodeForm *nodeForm)
{
    ui->nodeTemplatesFrame->layout()->addWidget(nodeForm);
}
