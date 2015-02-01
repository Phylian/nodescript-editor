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

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    Ui::OutputValuePinForm *ui;
};

#endif // OUTPUTVALUEPINFORM_H
