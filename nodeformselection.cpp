#include "nodeformselection.h"
#include "nodeform.h"

NodeFormSelection::NodeFormSelection() :
	mainWindow(nullptr)
{

}

void NodeFormSelection::add(NodeForm* nodeForm)
{
	if (!nodeForm->isSelected())
	{
		selectedNodes.push_back(nodeForm);
		nodeForm->setSelected(true);
	}
}

void NodeFormSelection::remove(NodeForm* nodeForm)
{
	if (nodeForm->isSelected())
	{
		std::vector<NodeForm*>::iterator it = std::find(selectedNodes.begin(), selectedNodes.end(), nodeForm);
		assert(it != selectedNodes.end());
		selectedNodes.erase(it);
		nodeForm->setSelected(false);
	}
}

void NodeFormSelection::removeAll()
{
	for (NodeForm* nodeForm : selectedNodes)
	{
		nodeForm->setSelected(false);
	}
	selectedNodes.clear();
}

