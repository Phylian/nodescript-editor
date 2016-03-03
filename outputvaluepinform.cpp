#include "nodelink.h"
#include "outputvaluepinform.h"
#include "ui_outputvaluepinform.h"

OutputValuePinForm::OutputValuePinForm(const char* name, PinIndex pinIndex) :
	ui(new Ui::OutputValuePinForm)
{
	ui->setupUi(this);
	ui->outputLabel->setText(name);
	ui->pin->setPinIndex(pinIndex);
}

OutputValuePinForm::~OutputValuePinForm()
{
	delete ui;
}

void OutputValuePinForm::setLinksDirty()
{
	ui->pin->setLinksDirty();
}

OutputPinForm* OutputValuePinForm::getOutputPinForm() const
{
	return ui->pin;
}


