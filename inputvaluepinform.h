#ifndef INPUTVALUEPINFORM_H
#define INPUTVALUEPINFORM_H

#include <QWidget>
#include "nodescript/src/nodescript.h"
#include "inputpinlineform.h"

namespace Ui {
class InputValuePinForm;
}

class ScriptPaintForm;

class InputValuePinForm : public QWidget, public InputPinLineForm
{
	Q_OBJECT

public:
	explicit InputValuePinForm(const char* name, PinIndex pinIndex);
	~InputValuePinForm();

	void setLinkDirty();

	InputPinForm* getInputPinForm() const override;

private:
	Ui::InputValuePinForm *ui;
};

#endif // INPUTVALUEPINFORM_H
