#ifndef OUTPUTPINFORM_H
#define OUTPUTPINFORM_H

#include <QFrame>
#include "nodescript/src/nodescript.h"
#include "pinform.h"

class ScriptPaintForm;
class NodeLink;
class InputPinForm;
class NodeForm;
class MainWindow;

class OutputPinForm : public PinForm
{
	Q_OBJECT
public:
	explicit OutputPinForm(QWidget *parent = 0);
	~OutputPinForm();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

	void addLink(NodeLink* link);
	void removeLink(NodeLink* link);
	inline const std::vector<NodeLink*>& getLinks() const { return links; }

	void setLinksDirty();

	void plugLink(NodeLink* link) override;
	void unplugLink(NodeLink* link) override;

private:
	std::vector<NodeLink*> links;
};

#endif // OUTPUTPINFORM_H
