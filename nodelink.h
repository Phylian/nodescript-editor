#ifndef NODELINK_H
#define NODELINK_H

#include <QFrame>
#include <QPainter>

#include "nodescript/src/nodescript.h"

class ScriptPaintForm;
class OutputPinForm;
class InputPinForm;

class NodeLink
{
public:
	NodeLink(ScriptPaintForm* scriptPaintForm);
	NodeLink(const NodeLink& nodeLink);
	void operator=(const NodeLink& nodeLink);

	void paint(QPainter& painter);

	inline void setBeginPin(OutputPinForm* beginPin) { this->beginPin = beginPin; setDirty(); }
	inline void setBeginPosition(QPoint beginPosition) { this->beginPosition = beginPosition; beginPin = nullptr; setDirty(); }
	inline OutputPinForm* getBeginPin() const { return beginPin; }

	inline void setEndPin(InputPinForm* endPin) { this->endPin = endPin; setDirty(); }
	inline void setEndPosition(QPoint endPosition) { this->endPosition = endPosition; endPin = nullptr; setDirty(); }
	inline InputPinForm* getEndPin() const { return endPin; }

	void connectToBeginPin();
	void disconnectFromBeginPin();

	void connectToEndPin();
	void disconnectFromEndPin();

	PinIndex getBeginPinIndex() const;
	PinIndex getEndPinIndex() const;

	NodeCall getBeginPinNodeCall() const;
	NodeCall getEndPinNodeCall() const;

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
