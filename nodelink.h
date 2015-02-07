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

	void paint(QPainter& painter);

	inline void setBeginPin(OutputPinForm* beginPin) { this->beginPin = beginPin; updateBeginPosition(); }
	inline void setBeginPosition(QPoint beginPosition) { this->beginPosition = beginPosition; beginPin = nullptr; }

	inline void setEndPin(InputPinForm* endPin) { this->endPin = endPin; updateEndPosition(); }
	inline void setEndPosition(QPoint endPosition) { this->endPosition = endPosition; endPin = nullptr; }

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
};

#endif // NODELINK_H
