#ifndef INPUTVALUEPINFORM_H
#define INPUTVALUEPINFORM_H

#include <QWidget>
#include "nodescript/src/nodescript.h"

namespace Ui {
class InputValuePinForm;
}

class ScriptPaintForm;

class InputValuePinForm : public QWidget
{
	Q_OBJECT

public:
	explicit InputValuePinForm(const char* name, PinIndex pinIndex);
	~InputValuePinForm();

	void setLinkDirty();

private:
	Ui::InputValuePinForm *ui;
};

#endif // INPUTVALUEPINFORM_H
