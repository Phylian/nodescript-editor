#ifndef INPUTPINFORM_H
#define INPUTPINFORM_H

#include <QFrame>
#include <QMouseEvent>
#include <cassert>
#include "nodescript/src/nodescript.h"

class ScriptPaintForm;
class NodeLink;
class NodeForm;
class OutputPinForm;

class InputPinForm : public QFrame
{
public:
	InputPinForm(QWidget* parent = 0);
	~InputPinForm();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

	OutputPinForm* getOutputPinFormUnderCursor(QMouseEvent* event) const;
	void abortLinkDragging();

	ScriptPaintForm* getScriptPaintForm() const;
	NodeForm* getNodeForm() const;

	Script* getScript() const;

	inline void setLink(NodeLink* link) { assert(!this->link); assert(link); this->link = link; }
	inline NodeLink* getLink() const { return link; }

	void setLinkDirty();

	inline void setPinIndex(PinIndex pinIndex) { assert(pinIndex != INVALID_PIN_INDEX); assert(this->pinIndex == INVALID_PIN_INDEX); this->pinIndex = pinIndex; }
	inline PinIndex getPinIndex() const { return pinIndex; }

private:
	NodeLink* link;
	PinIndex pinIndex;
};

#endif // INPUTPINFORM_H
