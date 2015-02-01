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

void InputValuePinForm::mousePressEvent(QMouseEvent *event)
{

}

void InputValuePinForm::mouseReleaseEvent(QMouseEvent *event)
{

}

void InputValuePinForm::mouseMoveEvent(QMouseEvent *event)
{

}
