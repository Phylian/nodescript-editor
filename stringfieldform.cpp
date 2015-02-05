#include "stringfieldform.h"
#include "ui_stringfieldform.h"

StringFieldForm::StringFieldForm(const char* name) :
	ui(new Ui::StringFieldForm)
{
	ui->setupUi(this);

	if (name)
		ui->label->setText(name);

	else
		ui->label->hide();
}

StringFieldForm::~StringFieldForm()
{
	delete ui;
}
