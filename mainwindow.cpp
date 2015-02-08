#include <cassert>
#include <QKeyEvent>
#include "mainwindow.h"
#include "nodeform.h"
#include "nodeformbuilders/nodeformbuilders.h"
#include "inputpinform.h"
#include "outputpinform.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	const std::map<std::string, Node*>& registeredNodes = scriptEngine.getAllRegisteredNodes();
	script = scriptEngine.newScript();

	for (const std::pair<std::string, Node*>& node : registeredNodes)
	{
		NodeForm* nodeForm = buildNodeFormFromNode(node.second);
		addNodeFormTemplate(nodeForm);
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

NodeForm* MainWindow::buildNodeFormFromNode(Node* node)
{
	const NodeFormBuilder& nodeFormBuilder = nodeFormBuilders.getNodeFormBuilder(node->getNodeName());
	NodeForm* nodeForm = nodeFormBuilder.buildNodeForm(node);
	assert(nodeForm != nullptr);
	nodeFormBuilder.resetSize(nodeForm);
	return nodeForm;
}

void MainWindow::addNodeFormInstance(NodeForm *nodeForm)
{
	nodeForm->setNodeDragger(&nodeFormDragger);
	nodeForm->setParent(ui->scriptFrame);
	nodeForm->move(100, 100);
	nodeForm->show();

	NodeCall nodeCall = script->addNode(nodeForm->getNode());
	nodeForm->setNodeCall(nodeCall);
}

void MainWindow::addNodeFormTemplate(NodeForm *nodeForm)
{
	nodeForm->disableFields();
	ui->nodeTemplatesFrame->layout()->addWidget(nodeForm);
}

NodeLink* MainWindow::addLink(NodeCall nodeCall1, PinIndex outputPinIndex, NodeCall nodeCall2, PinIndex inputPinIndex)
{
	script->addLink(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex);
	NodeLink* link = new NodeLink(ui->scriptFrame);
	NodeForm* outputNodeForm = getNodeInstanceForm(nodeCall1);
	assert(outputNodeForm);
	NodeForm* inputNodeForm = getNodeInstanceForm(nodeCall2);
	assert(inputNodeForm);
	OutputPinForm* outputPinForm = outputNodeForm->getOutputPinForm(outputPinIndex);
	assert(outputPinForm);
	InputPinForm* inputPinForm = inputNodeForm->getInputPinForm(inputPinIndex);
	assert(inputPinForm);
	link->setBeginPin(outputPinForm);
	link->setEndPin(inputPinForm);
	ui->scriptFrame->addLink(link);
	return link;
}

void MainWindow::removeLink(NodeLink* link)
{
	NodeCall nodeCall1 = link->getBeginPinNodeCall();
	NodeCall nodeCall2 = link->getEndPinNodeCall();
	PinIndex outputPinIndex = link->getBeginPinIndex();
	PinIndex inputPinIndex = link->getEndPinIndex();
	script->removeLink(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex);
	ui->scriptFrame->removeLink(link);
	delete link;
}

NodeForm* MainWindow::getNodeInstanceForm(NodeCall nodeCall)
{
	NodeForm* nodeInstanceForm = nullptr;
	for (QObject* child : ui->scriptFrame->children())
	{
		NodeForm* nodeForm = static_cast<NodeForm*>(child);
		if (nodeForm->getNodeCall() == nodeCall)
		{
			nodeInstanceForm = nodeForm;
			break;
		}
	}
	return nodeInstanceForm;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Shift)
		nodeFormDragger.setSnapToGrid(true);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Shift)
		nodeFormDragger.setSnapToGrid(false);
}


