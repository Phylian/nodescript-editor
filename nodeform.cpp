#include "nodeform.h"
#include "ui_nodeform.h"

#include "inputvaluepinform.h"
#include "inputimpulsepinform.h"
#include "outputvaluepinform.h"
#include "outputimpulsepinform.h"

NodeForm::NodeForm(QWidget *parent, const char* nodeName) :
    QWidget(parent),
    ui(new Ui::NodeForm)
{
    ui->setupUi(this);
    ui->label->setText(nodeName);
}

NodeForm::~NodeForm()
{
    delete ui;
}

void NodeForm::addInputValuePin(const char *name)
{
    InputValuePinForm* inputValuePinForm = new InputValuePinForm(name);
    ui->pinsFrame->layout()->addWidget(inputValuePinForm);
}

void NodeForm::addInputImpulsePin(const char *name)
{
    InputImpulsePinForm* inputImpulsePinForm = new InputImpulsePinForm(name);
    ui->pinsFrame->layout()->addWidget(inputImpulsePinForm);
}

void NodeForm::addOutputValuePin(const char *name)
{
    OutputValuePinForm* outputValuePinForm = new OutputValuePinForm(name);
    ui->pinsFrame->layout()->addWidget(outputValuePinForm);
}

void NodeForm::addOutputImpulsePin(const char *name)
{
    OutputImpulsePinForm* outputImpulsePinForm = new OutputImpulsePinForm(name);
    ui->pinsFrame->layout()->addWidget(outputImpulsePinForm);
}
