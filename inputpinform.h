#ifndef INPUTPINFORM_H
#define INPUTPINFORM_H

#include <QFrame>
#include <QMouseEvent>

class ScriptPaintForm;

class InputPinForm : public QFrame
{
public:
	InputPinForm(QWidget* parent = 0);
	~InputPinForm();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

	ScriptPaintForm* getScriptPaintForm();
};

#endif // INPUTPINFORM_H
