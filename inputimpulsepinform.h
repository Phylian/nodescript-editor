#ifndef INPUTIMPULSEPINFORM_H
#define INPUTIMPULSEPINFORM_H

#include <QWidget>
#include "nodescript/src/nodescript.h"

namespace Ui {
class InputImpulsePinForm;
}

class ScriptPaintForm;

class InputImpulsePinForm : public QWidget
{
	Q_OBJECT

public:
	explicit InputImpulsePinForm(const char* name, PinIndex pinIndex);
	~InputImpulsePinForm();

	void setLinkDirty();

private:
	Ui::InputImpulsePinForm *ui;
};

#endif // INPUTIMPULSEPINFORM_H
