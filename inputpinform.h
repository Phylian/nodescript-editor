#ifndef INPUTPINFORM_H
#define INPUTPINFORM_H

#include <QFrame>
#include <QMouseEvent>
#include <cassert>
#include "nodescript/src/nodescript.h"
#include "pinform.h"

class ScriptPaintForm;
class NodeLink;
class NodeForm;
class OutputPinForm;
class MainWindow;

class InputPinForm : public PinForm
{
public:
	InputPinForm(QWidget* parent = 0);
	~InputPinForm();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

	inline void setLink(NodeLink* link) { assert(!this->link); assert(link); this->link = link; }
	inline void removeLink() { link = nullptr; }
	inline NodeLink* getLink() const { return link; }

	void setLinkDirty();

	void plugLink(NodeLink* link) override;
	void unplugLink(NodeLink* link) override;

private:
	NodeLink* link;
};

#endif // INPUTPINFORM_H
