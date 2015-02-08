#ifndef INTFIELDFORM_H
#define INTFIELDFORM_H

#include "constantvaluefieldform.h"

#include <QWidget>

namespace Ui {
class IntFieldForm;
}

class IntFieldForm : public QWidget, public ConstantValueFieldForm
{
	Q_OBJECT

public:
	explicit IntFieldForm(const char* name = nullptr);
	~IntFieldForm();

	void disableField() override;

private:
	Ui::IntFieldForm *ui;
};

#endif // INTFIELDFORM_H
