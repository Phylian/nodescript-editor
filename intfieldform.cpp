#include "intfieldform.h"
#include "ui_intfieldform.h"

IntFieldForm::IntFieldForm(const char* name, bool showName) :
	ConstantValueFieldForm(name),
	ui(new Ui::IntFieldForm)
{
	ui->setupUi(this);

	ui->label->setText(name);

	if (!showName)
		ui->label->hide();
}

IntFieldForm::~IntFieldForm()
{
	delete ui;
}

void IntFieldForm::disableField()
{
	ui->spinBox->setEnabled(false);
}

int IntFieldForm::getValue() const
{
	return ui->spinBox->value();
}
