#include <cassert>
#include <QKeyEvent>
#include "mainwindow.h"
#include "nodeform.h"
#include "nodeformbuilders/nodeformbuilders.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	const std::map<std::string, Node*>& registeredNodes = scriptEngine.getAllRegisteredNodes();
	for (const std::pair<std::string, Node*>& node : registeredNodes)
	{
		/*
		{
			NodeForm* nodeForm = buildNodeFormFromNode(node.second);
			addNodeFormInstance(nodeForm);
		}
		*/

		{
			NodeForm* nodeForm = buildNodeFormFromNode(node.second);
			addNodeFormTemplate(nodeForm);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		NodeForm* nodeForm = buildNodeFormFromNode(scriptEngine.getNodeInstance("Add"));
		addNodeFormInstance(nodeForm);
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
}

void MainWindow::addNodeFormTemplate(NodeForm *nodeForm)
{
	ui->nodeTemplatesFrame->layout()->addWidget(nodeForm);
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


