#ifndef OUTPUTVALUEPINFORM_H
#define OUTPUTVALUEPINFORM_H

#include <QWidget>
#include "nodescript/src/nodescript.h"
#include "outputpinlineform.h"

namespace Ui {
class OutputValuePinForm;
}

class ScriptPaintForm;

class OutputValuePinForm : public QWidget, public OutputPinLineForm
{
	Q_OBJECT

public:
	explicit OutputValuePinForm(const char* name, PinIndex pinIndex);
	~OutputValuePinForm();

	void setLinksDirty();

	OutputPinForm* getOutputPinForm() const override;

private:
	Ui::OutputValuePinForm *ui;
};

#endif // OUTPUTVALUEPINFORM_H
