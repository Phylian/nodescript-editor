#include "floatfieldform.h"
#include "ui_floatfieldform.h"

FloatFieldForm::FloatFieldForm(const char* name) :
	ui(new Ui::FloatFieldForm)
{
	ui->setupUi(this);

	if (name)
		ui->label->setText(name);

	else
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
