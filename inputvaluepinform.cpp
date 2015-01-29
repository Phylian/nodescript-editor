#include "inputvaluepinform.h"
#include "ui_inputvaluepinform.h"

InputValuePinForm::InputValuePinForm(const char* name) :
    ui(new Ui::InputValuePinForm)
{
    ui->setupUi(this);
    ui->label->setText(name);
}

InputValuePinForm::~InputValuePinForm()
{
    delete ui;
}
