#include "intfieldform.h"
#include "ui_intfieldform.h"

IntFieldForm::IntFieldForm(const char* name) :
	ui(new Ui::IntFieldForm)
{
	ui->setupUi(this);

	if (name)
		ui->label->setText(name);

	else
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
