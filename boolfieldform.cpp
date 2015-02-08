#include "boolfieldform.h"
#include "ui_boolfieldform.h"

BoolFieldForm::BoolFieldForm(const char* name, bool showName) :
	ConstantValueFieldForm(name),
	ui(new Ui::BoolFieldForm)
{
	ui->setupUi(this);

	ui->label->setText(name);

	if (!showName)
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

bool BoolFieldForm::getValue() const
{
	return ui->checkBox->isChecked();
}

void BoolFieldForm::on_checkBox_toggled(bool checked)
{
	if (checked)
		ui->checkBox->setText("True");

	else
		ui->checkBox->setText("False");
}
