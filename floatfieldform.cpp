#include "floatfieldform.h"
#include "ui_floatfieldform.h"

FloatFieldForm::FloatFieldForm(const char* name, bool showName) :
	ConstantValueFieldForm(name),
	ui(new Ui::FloatFieldForm)
{
	ui->setupUi(this);

	ui->label->setText(name);

	if (!showName)
		ui->label->hide();
}

FloatFieldForm::~FloatFieldForm()
{
	delete ui;
}

void FloatFieldForm::disableField()
{
	ui->doubleSpinBox->setEnabled(false);
}

double FloatFieldForm::getValue() const
{
	return ui->doubleSpinBox->value();
}
