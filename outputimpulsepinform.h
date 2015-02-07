#ifndef OUTPUTIMPULSEPINFORM_H
#define OUTPUTIMPULSEPINFORM_H

#include <QWidget>

namespace Ui {
class OutputImpulsePinForm;
}

class ScriptPaintForm;

class OutputImpulsePinForm : public QWidget
{
	Q_OBJECT

public:
	explicit OutputImpulsePinForm(const char* name);
	~OutputImpulsePinForm();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

	void setScriptPaintForm(ScriptPaintForm* scriptPaintForm) const;

private:
	Ui::OutputImpulsePinForm *ui;
};

#endif // OUTPUTIMPULSEPINFORM_H
