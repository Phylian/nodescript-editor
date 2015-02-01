#ifndef INPUTIMPULSEPINFORM_H
#define INPUTIMPULSEPINFORM_H

#include <QWidget>

namespace Ui {
class InputImpulsePinForm;
}

class InputImpulsePinForm : public QWidget
{
    Q_OBJECT

public:
    explicit InputImpulsePinForm(const char* name);
    ~InputImpulsePinForm();

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    Ui::InputImpulsePinForm *ui;
};

#endif // INPUTIMPULSEPINFORM_H
