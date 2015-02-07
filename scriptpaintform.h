#ifndef SCRIPTPAINTFORM_H
#define SCRIPTPAINTFORM_H

#include "nodelink.h"

#include <QFrame>

class OutputPinForm;

class ScriptPaintForm : public QFrame
{
	Q_OBJECT
public:
	explicit ScriptPaintForm(QWidget *parent = 0);
	~ScriptPaintForm();

	void paintEvent(QPaintEvent* event) override;

	inline void setIsDraggingLink(bool isDraggingLink) { this->isDraggingLink = isDraggingLink; }

	void setCurrentNodeLinkBeginPin(OutputPinForm* beginPin);
	void setCurrentNodeLinkBeginPosition(QPoint beginPosition);

	void setCurrentNodeLinkEndPin(InputPinForm* endPin);
	void setCurrentNodeLinkEndPosition(QPoint endPosition);

	void addCurrentNodeLink();

private:
	std::vector<NodeLink> links;

	NodeLink currentNodeLink;
	bool isDraggingLink;
};

#endif // SCRIPTPAINTFORM_H
