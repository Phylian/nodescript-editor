#ifndef FLOATFIELDFORM_H
#define FLOATFIELDFORM_H

#include "constantvaluefieldform.h"

#include <QWidget>

namespace Ui {
class FloatFieldForm;
}

class FloatFieldForm : public QWidget, public ConstantValueFieldForm
{
	Q_OBJECT

public:
	explicit FloatFieldForm(const char* name = nullptr);
	~FloatFieldForm();

	void disableField() override;

private:
	Ui::FloatFieldForm *ui;
};

#endif // FLOATFIELDFORM_H
