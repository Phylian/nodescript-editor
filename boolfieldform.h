#ifndef BOOLFIELDFORM_H
#define BOOLFIELDFORM_H

#include <QWidget>

namespace Ui {
class BoolFieldForm;
}

class BoolFieldForm : public QWidget
{
	Q_OBJECT

public:
	explicit BoolFieldForm(const char* name = nullptr);
	~BoolFieldForm();

private slots:
	void on_checkBox_toggled(bool checked);

private:
	Ui::BoolFieldForm *ui;
};

#endif // BOOLFIELDFORM_H
