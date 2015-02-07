#ifndef OUTPUTIMPULSEPINFORM_H
#define OUTPUTIMPULSEPINFORM_H

#include <QWidget>
#include "nodescript/src/nodescript.h"

namespace Ui {
class OutputImpulsePinForm;
}

class ScriptPaintForm;

class OutputImpulsePinForm : public QWidget
{
	Q_OBJECT

public:
	explicit OutputImpulsePinForm(const char* name, PinIndex pinIndex);
	~OutputImpulsePinForm();

	void setLinksDirty();

private:
	Ui::OutputImpulsePinForm *ui;
};

#endif // OUTPUTIMPULSEPINFORM_H
