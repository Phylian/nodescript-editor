#ifndef INTFIELDFORM_H
#define INTFIELDFORM_H

#include <QWidget>

namespace Ui {
class IntFieldForm;
}

class IntFieldForm : public QWidget
{
    Q_OBJECT

public:
	explicit IntFieldForm(const char* name = nullptr);
    ~IntFieldForm();

private:
    Ui::IntFieldForm *ui;
};

#endif // INTFIELDFORM_H
