#include "inputimpulsepinform.h"
#include "ui_inputimpulsepinform.h"

InputImpulsePinForm::InputImpulsePinForm(const char* name) :
    ui(new Ui::InputImpulsePinForm)
{
    ui->setupUi(this);
    ui->label->setText(name);
}

InputImpulsePinForm::~InputImpulsePinForm()
{
    delete ui;
}

