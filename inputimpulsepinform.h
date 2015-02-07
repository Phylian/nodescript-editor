#ifndef INPUTIMPULSEPINFORM_H
#define INPUTIMPULSEPINFORM_H

#include <QWidget>

namespace Ui {
class InputImpulsePinForm;
}

class ScriptPaintForm;

class InputImpulsePinForm : public QWidget
{
	Q_OBJECT

public:
	explicit InputImpulsePinForm(const char* name);
	~InputImpulsePinForm();

private:
	Ui::InputImpulsePinForm *ui;
};

#endif // INPUTIMPULSEPINFORM_H
