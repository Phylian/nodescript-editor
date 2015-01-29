#ifndef OUTPUTVALUEPINFORM_H
#define OUTPUTVALUEPINFORM_H

#include <QWidget>

namespace Ui {
class OutputValuePinForm;
}

class OutputValuePinForm : public QWidget
{
    Q_OBJECT

public:
    explicit OutputValuePinForm(const char* name);
    ~OutputValuePinForm();

private:
    Ui::OutputValuePinForm *ui;
};

#endif // OUTPUTVALUEPINFORM_H
