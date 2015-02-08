#include "boolfieldform.h"
#include "ui_boolfieldform.h"

BoolFieldForm::BoolFieldForm(const char* name) :
	ui(new Ui::BoolFieldForm)
{
	ui->setupUi(this);

	if (name)
		ui->label->setText(name);

	else
		ui->label->hide();
}

BoolFieldForm::~BoolFieldForm()
{
	delete ui;
}

void BoolFieldForm::disableField()
{
	ui->checkBox->setEnabled(false);
}

void BoolFieldForm::on_checkBox_toggled(bool checked)
{
	if (checked)
		ui->checkBox->setText("True");

	else
		ui->checkBox->setText("False");
}
