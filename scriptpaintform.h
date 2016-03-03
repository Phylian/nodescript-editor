#ifndef SCRIPTPAINTFORM_H
#define SCRIPTPAINTFORM_H

#include "nodelink.h"

#include <QFrame>

class OutputPinForm;
class NodeForm;
class MainWindow;
class NodeFormSelection;

class ScriptPaintForm : public QFrame
{
	Q_OBJECT
public:
	explicit ScriptPaintForm(QWidget *parent = 0);
	~ScriptPaintForm();

	void paintEvent(QPaintEvent* event) override;

	void setIsDraggingLink(bool isDraggingLink);

	void setCurrentNodeLinkBeginPin(OutputPinForm* beginPin);
	void setCurrentNodeLinkBeginPosition(QPoint beginPosition);

	void setCurrentNodeLinkEndPin(InputPinForm* endPin);
	void setCurrentNodeLinkEndPosition(QPoint endPosition);

	inline bool isCurrentNodeLinkBeginPinConnected() const { return isDraggingLink && currentNodeLink.getBeginPin() != nullptr; }
	inline const NodeLink& getCurrentLink() const { return currentNodeLink; }

	void addLink(NodeLink* link);
	void removeLink(NodeLink* link);
	void removeAllLinks(NodeForm* nodeForm);

	NodeForm* getNodeForm(NodeCall nodeCall) const;

	void mousePressEvent(QMouseEvent* event) override;

private:
	MainWindow& getMainWindow() const;
	NodeFormSelection& getNodeFormSelection() const;

	std::vector<NodeLink*> links;

	NodeLink currentNodeLink;
	bool isDraggingLink;
};

#endif // SCRIPTPAINTFORM_H
