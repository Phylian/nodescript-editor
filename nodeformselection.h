#ifndef NODEFORMSELECTION_H
#define NODEFORMSELECTION_H

#include <vector>

class NodeForm;
class MainWindow;

class NodeFormSelection
{
	public:
		NodeFormSelection();

		inline void setMainWindow(MainWindow* mainWindow) { this->mainWindow = mainWindow; }

		void add(NodeForm* nodeForm);
		void remove(NodeForm* nodeForm);

		void removeAll();

		inline const std::vector<NodeForm*>& getSelectedNodes() const { return selectedNodes; }


	private:
		MainWindow* mainWindow;
		std::vector<NodeForm*> selectedNodes;
};

#endif // NODEFORMSELECTION_H
