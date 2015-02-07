#ifndef NODELINK_H
#define NODELINK_H

#include <QFrame>
#include <QPainter>

class ScriptPaintForm;
class OutputPinForm;
class InputPinForm;

class NodeLink
{
public:
	NodeLink(ScriptPaintForm* scriptPaintForm);
	NodeLink(const NodeLink& nodeLink);

	void paint(QPainter& painter);

	inline void setBeginPin(OutputPinForm* beginPin) { this->beginPin = beginPin; setDirty(); }
	inline void setBeginPosition(QPoint beginPosition) { this->beginPosition = beginPosition; beginPin = nullptr; setDirty(); }

	inline void setEndPin(InputPinForm* endPin) { this->endPin = endPin; setDirty(); }
	inline void setEndPosition(QPoint endPosition) { this->endPosition = endPosition; endPin = nullptr; setDirty(); }

	void connectToBeginPin();
	void connectToEndPin();

	inline void setDirty() { dirty = true; }

private:
	void updatePath();
	void updateBeginPosition();
	void updateEndPosition();

	QPainterPath path;
	QPoint beginPosition;
	QPoint endPosition;
	ScriptPaintForm* scriptPaintForm;
	OutputPinForm* beginPin;
	InputPinForm* endPin;
	bool dirty;
};

#endif // NODELINK_H
