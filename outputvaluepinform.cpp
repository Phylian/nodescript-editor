#include "outputvaluepinform.h"
#include "ui_outputvaluepinform.h"

OutputValuePinForm::OutputValuePinForm(const char* name) :
    ui(new Ui::OutputValuePinForm)
{
    ui->setupUi(this);
    ui->label->setText(name);
}

OutputValuePinForm::~OutputValuePinForm()
{
    delete ui;
}

void OutputValuePinForm::mousePressEvent(QMouseEvent *event)
{

}

void OutputValuePinForm::mouseReleaseEvent(QMouseEvent *event)
{

}

void OutputValuePinForm::mouseMoveEvent(QMouseEvent *event)
{

}
