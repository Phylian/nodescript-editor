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

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    Ui::InputValuePinForm *ui;
};

#endif // INPUTVALUEPINFORM_H
