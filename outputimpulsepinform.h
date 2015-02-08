#ifndef OUTPUTIMPULSEPINFORM_H
#define OUTPUTIMPULSEPINFORM_H

#include <QWidget>
#include "nodescript/src/nodescript.h"
#include "outputpinlineform.h"

namespace Ui {
class OutputImpulsePinForm;
}

class ScriptPaintForm;

class OutputImpulsePinForm : public QWidget, public OutputPinLineForm
{
	Q_OBJECT

public:
	explicit OutputImpulsePinForm(const char* name, PinIndex pinIndex);
	~OutputImpulsePinForm();

	void setLinksDirty();

	OutputPinForm* getOutputPinForm() const override;

private:
	Ui::OutputImpulsePinForm *ui;
};

#endif // OUTPUTIMPULSEPINFORM_H
