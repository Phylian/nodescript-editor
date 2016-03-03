#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "nodescript/src/nodescript.h"

#include "nodeformdragger.h"
#include "nodeformselection.h"
#include "nodeformbuilders/nodeformbuilders.h"

class NodeForm;
class NodeLink;
class ScriptPaintForm;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	// node forms
	NodeForm* buildNodeFormFromNode(Node* node);
	void addNodeFormInstance(NodeForm* nodeForm);

	void removeNodeFormInstance(NodeForm* nodeForm);
	void addNodeFormTemplate(NodeForm* nodeForm);

	// node dragging & selection
	inline NodeFormDragger& getNodeFormDragger() { return nodeFormDragger; }
	inline NodeFormSelection& getNodeFormSelection() { return nodeFormSelection; }

	// node links
	NodeLink* addLink(NodeCall nodeCall1, PinIndex outputPinIndex, NodeCall nodeCall2, PinIndex inputPinIndex);
	void removeLink(NodeLink* link);

	// script internals
	void executeScript();
	inline Script* getScript() const { return script; }

	// misc
	ScriptPaintForm* getScriptPaintForm() const;

private slots:
	void on_pushButton_clicked();

private:
	void registerNodeFormBuilder(const char* nodeName, NodeFormBuilder* nodeFormBuilder);
	const NodeFormBuilder& getNodeFormBuilder(const char* nodeName);

	NodeForm* getNodeInstanceForm(NodeCall nodeCall);

	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;

	Ui::MainWindow *ui;
	NodeFormDragger nodeFormDragger;
	NodeFormSelection nodeFormSelection;
	NodeFormBuilders nodeFormBuilders;
	ScriptEngine scriptEngine;
	Script* script;
};

#endif // MAINWINDOW_H
