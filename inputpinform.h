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

	inline void setLink(NodeLink* link) { assert(!isConnected()); assert(link); this->link = link; }
	inline void removeLink() { link = nullptr; }
	inline NodeLink* getLink() const { return link; }
	inline bool isConnected() const { return link != nullptr; }

	void setLinkDirty();

private:
	NodeLink* link;
};

#endif // INPUTPINFORM_H
