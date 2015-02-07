#ifndef OUTPUTPINFORM_H
#define OUTPUTPINFORM_H

#include <QFrame>
#include "nodescript/src/nodescript.h"

class ScriptPaintForm;
class NodeLink;
class InputPinForm;
class NodeForm;

class OutputPinForm : public QFrame
{
	Q_OBJECT
public:
	explicit OutputPinForm(QWidget *parent = 0);
	~OutputPinForm();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

	InputPinForm* getInputPinFormUnderCursor(QMouseEvent* event) const;
	void abortLinkDragging();

	ScriptPaintForm* getScriptPaintForm() const;
	NodeForm* getNodeForm() const;

	Script* getScript() const;

	void addLink(NodeLink* link);
	inline const std::vector<NodeLink*>& getLinks() const { return links; }

	void setLinksDirty();

	inline void setPinIndex(PinIndex pinIndex) { assert(pinIndex != INVALID_PIN_INDEX); assert(this->pinIndex == INVALID_PIN_INDEX); this->pinIndex = pinIndex; }
	inline PinIndex getPinIndex() const { return pinIndex; }

private:
	std::vector<NodeLink*> links;
	PinIndex pinIndex;
};

#endif // OUTPUTPINFORM_H
