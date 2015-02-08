#include "stringfieldform.h"
#include "ui_stringfieldform.h"

StringFieldForm::StringFieldForm(const char* name, bool showName) :
	ConstantValueFieldForm(name),
	ui(new Ui::StringFieldForm)
{
	ui->setupUi(this);

	ui->label->setText(name);

	if (!showName)
		ui->label->hide();
}

StringFieldForm::~StringFieldForm()
{
	delete ui;
}

void StringFieldForm::disableField()
{
	ui->lineEdit->setEnabled(false);
}

std::string StringFieldForm::getValue() const
{
	return ui->lineEdit->text().toStdString();
}
