#ifndef STRINGFIELDFORM_H
#define STRINGFIELDFORM_H

#include "constantvaluefieldform.h"

#include <QWidget>

namespace Ui {
class StringFieldForm;
}

class StringFieldForm : public QWidget, public ConstantValueFieldForm
{
	Q_OBJECT

public:
	explicit StringFieldForm(const char* name = nullptr);
	~StringFieldForm();

	void disableField() override;

private:
	Ui::StringFieldForm *ui;
};

#endif // STRINGFIELDFORM_H
