#include "outputimpulsepinform.h"
#include "ui_outputimpulsepinform.h"

OutputImpulsePinForm::OutputImpulsePinForm(const char* name) :
    ui(new Ui::OutputImpulsePinForm)
{
    ui->setupUi(this);
    ui->label->setText(name);
}

OutputImpulsePinForm::~OutputImpulsePinForm()
{
    delete ui;
}
