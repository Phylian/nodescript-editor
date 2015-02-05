#ifndef STRINGFIELDFORM_H
#define STRINGFIELDFORM_H

#include <QWidget>

namespace Ui {
class StringFieldForm;
}

class StringFieldForm : public QWidget
{
	Q_OBJECT

public:
	explicit StringFieldForm(const char* name = nullptr);
	~StringFieldForm();

private:
	Ui::StringFieldForm *ui;
};

#endif // STRINGFIELDFORM_H
