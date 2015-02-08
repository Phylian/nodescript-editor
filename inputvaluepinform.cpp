#include "inputvaluepinform.h"
#include "nodelink.h"
#include "ui_inputvaluepinform.h"

InputValuePinForm::InputValuePinForm(const char* name, PinIndex pinIndex) :
	ui(new Ui::InputValuePinForm)
{
	ui->setupUi(this);
	ui->label->setText(name);
	ui->pin->setPinIndex(pinIndex);
}

InputValuePinForm::~InputValuePinForm()
{
	delete ui;
}

void InputValuePinForm::setLinkDirty()
{
	ui->pin->setLinkDirty();
}

InputPinForm*InputValuePinForm::getInputPinForm() const
{
	return ui->pin;
}

