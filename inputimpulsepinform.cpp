#include "inputimpulsepinform.h"
#include "nodelink.h"
#include "ui_inputimpulsepinform.h"

InputImpulsePinForm::InputImpulsePinForm(const char* name, PinIndex pinIndex) :
	ui(new Ui::InputImpulsePinForm)
{
	ui->setupUi(this);
	ui->inputLabel->setText(name);
	ui->pin->setPinIndex(pinIndex);
}

InputImpulsePinForm::~InputImpulsePinForm()
{
	delete ui;
}

void InputImpulsePinForm::setLinkDirty()
{
	ui->pin->setLinkDirty();
}

InputPinForm* InputImpulsePinForm::getInputPinForm() const
{
	return ui->pin;
}

