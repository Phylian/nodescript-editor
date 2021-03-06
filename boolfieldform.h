#ifndef BOOLFIELDFORM_H
#define BOOLFIELDFORM_H

#include "constantvaluefieldform.h"

#include <QWidget>

namespace Ui {
class BoolFieldForm;
}

class BoolFieldForm : public QWidget, public ConstantValueFieldForm
{
	Q_OBJECT

public:
	explicit BoolFieldForm(const char* name, bool showName = false);
	~BoolFieldForm();

	void disableField() override;

	bool getValue() const;

private slots:
	void on_checkBox_toggled(bool checked);

private:
	Ui::BoolFieldForm *ui;
};

#endif // BOOLFIELDFORM_H
