#ifndef NODEFORMDRAGGER_H
#define NODEFORMDRAGGER_H

#include <QPoint>

class MainWindow;
class NodeForm;
class NodeFormSelection;
class ScriptPaintForm;

class NodeFormDragger
{
public:
	NodeFormDragger();

	inline void setMainWindow(MainWindow* mainWindow) { this->mainWindow = mainWindow; }
	NodeFormSelection& getNodeFormSelection();
	ScriptPaintForm* getScriptPaintForm();

	void beginDrag(QPoint mousePosition);
	void drag(QPoint mousePosition);
	void endDrag();

	inline void setSnapToGrid(bool snapToGrid) { this->snapToGrid = snapToGrid; }

	inline bool getMouseMoved() const { return mouseMoved; }

private:
	MainWindow* mainWindow;
	std::vector<QPoint> offsets;
	bool snapToGrid : 1;
	bool mouseMoved : 1;
};

#endif // NODEFORMDRAGGER_H
