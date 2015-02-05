#ifndef FLOATFIELDFORM_H
#define FLOATFIELDFORM_H

#include <QWidget>

namespace Ui {
class FloatFieldForm;
}

class FloatFieldForm : public QWidget
{
	Q_OBJECT

public:
	explicit FloatFieldForm(const char* name = nullptr);
	~FloatFieldForm();

private:
	Ui::FloatFieldForm *ui;
};

#endif // FLOATFIELDFORM_H
