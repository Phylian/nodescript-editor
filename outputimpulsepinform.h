#ifndef OUTPUTIMPULSEPINFORM_H
#define OUTPUTIMPULSEPINFORM_H

#include <QWidget>

namespace Ui {
class OutputImpulsePinForm;
}

class OutputImpulsePinForm : public QWidget
{
    Q_OBJECT

public:
    explicit OutputImpulsePinForm(const char* name);
    ~OutputImpulsePinForm();

private:
    Ui::OutputImpulsePinForm *ui;
};

#endif // OUTPUTIMPULSEPINFORM_H
