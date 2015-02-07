#ifndef OUTPUTPINFORM_H
#define OUTPUTPINFORM_H

#include <QFrame>

class ScriptPaintForm;

class OutputPinForm : public QFrame
{
	Q_OBJECT
public:
	explicit OutputPinForm(QWidget *parent = 0);
	~OutputPinForm();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

	ScriptPaintForm* getScriptPaintForm();
};

#endif // OUTPUTPINFORM_H
