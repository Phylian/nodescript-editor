#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "nodescript/src/nodescript.h"

#include "nodeformdragger.h"
#include "nodeformbuilders/nodeformbuilders.h"

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

	NodeForm* buildNodeFormFromNode(Node* node);
	void addNodeFormInstance(NodeForm* nodeForm);
	void addNodeFormTemplate(NodeForm* nodeForm);

	inline Script* getScript() const { return script; }

private:
	void registerNodeFormBuilder(const char* nodeName, NodeFormBuilder* nodeFormBuilder);
	const NodeFormBuilder& getNodeFormBuilder(const char* nodeName);

	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;

	Ui::MainWindow *ui;
	NodeFormDragger nodeFormDragger;
	NodeFormBuilders nodeFormBuilders;
	ScriptEngine scriptEngine;
	Script* script;
};

#endif // MAINWINDOW_H
