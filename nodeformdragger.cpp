#include "nodeformdragger.h"
#include "scriptpaintform.h"
#include "nodeform.h"
#include "mainwindow.h"

#include <cassert>


NodeFormDragger::NodeFormDragger() :
	mainWindow(nullptr),
	snapToGrid(false),
	mouseMoved(false)
{

}

NodeFormSelection& NodeFormDragger::getNodeFormSelection()
{
	return mainWindow->getNodeFormSelection();
}

ScriptPaintForm* NodeFormDragger::getScriptPaintForm()
{
	return mainWindow->getScriptPaintForm();
}

void NodeFormDragger::beginDrag(QPoint mousePosition)
{
	mouseMoved = false;
	NodeFormSelection& nodeFormSelection = getNodeFormSelection();
	const std::vector<NodeForm*>& selectedNodes = nodeFormSelection.getSelectedNodes();
	offsets.clear();
	offsets.reserve(selectedNodes.size());
	for (NodeForm* nodeForm : selectedNodes)
	{
		offsets.push_back(nodeForm->pos() - mousePosition);
	}
	std::cout << "beginDrag/" << offsets.size() << std::endl;
}

void NodeFormDragger::drag(QPoint mousePosition)
{
	if (!offsets.empty())
	{
		mouseMoved = true;
		NodeFormSelection& nodeFormSelection = getNodeFormSelection();
		const std::vector<NodeForm*> selectedNodes = nodeFormSelection.getSelectedNodes();
		assert(offsets.size() == selectedNodes.size());
		if (snapToGrid)
		{
			const int gridCellSize = 20;
			mousePosition = QPoint(
						round(static_cast<float>(mousePosition.x()) / gridCellSize) * gridCellSize,
						round(static_cast<float>(mousePosition.y()) / gridCellSize) * gridCellSize
						);
		}
		for (unsigned int i = 0; i < selectedNodes.size(); ++i)
		{
			NodeForm* nodeForm = selectedNodes[i];
			nodeForm->move(mousePosition + offsets[i]);
			nodeForm->setLinksDirty();
		}

		getScriptPaintForm()->repaint();
	}
}

void NodeFormDragger::endDrag()
{
	offsets.clear();
}

