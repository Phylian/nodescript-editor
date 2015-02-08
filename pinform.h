#ifndef PINFORM_H
#define PINFORM_H

#include "nodescript/src/nodescript.h"

#include <QFrame>

class MainWindow;
class NodeForm;
class ScriptPaintForm;
class InputPinForm;
class OutputPinForm;
class NodeLink;

class PinForm : public QFrame
{
public:
	PinForm(QWidget* parent = 0);
	virtual ~PinForm();

	void moveMouseFromBeginPin(QMouseEvent* event);
	void moveMouseFromEndPin(QMouseEvent* event);

	void releaseMouseFromBeginPin(QMouseEvent* event);
	void releaseMouseFromEndPin(QMouseEvent* event);

	InputPinForm* getInputPinFormUnderCursor(QMouseEvent* event) const;
	OutputPinForm* getOutputPinFormUnderCursor(QMouseEvent* event) const;

	void abortLinkDragging();

	MainWindow* getMainWindow() const;

	ScriptPaintForm* getScriptPaintForm() const;
	NodeForm* getNodeForm() const;

	Script* getScript() const;
	NodeCall getNodeCall() const;

	inline void setPinIndex(PinIndex pinIndex) { assert(pinIndex != INVALID_PIN_INDEX); assert(this->pinIndex == INVALID_PIN_INDEX); this->pinIndex = pinIndex; }
	inline PinIndex getPinIndex() const { return pinIndex; }

protected:
	PinIndex pinIndex;
};

#endif // PINFORM_H
