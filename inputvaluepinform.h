#ifndef INPUTVALUEPINFORM_H
#define INPUTVALUEPINFORM_H

#include <QWidget>

namespace Ui {
class InputValuePinForm;
}

class InputValuePinForm : public QWidget
{
    Q_OBJECT

public:
    explicit InputValuePinForm(const char* name);
    ~InputValuePinForm();

private:
    Ui::InputValuePinForm *ui;
};

#endif // INPUTVALUEPINFORM_H
