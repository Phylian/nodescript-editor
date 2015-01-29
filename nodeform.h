#ifndef NODEFORM_H
#define NODEFORM_H

#include <QWidget>

namespace Ui {
class NodeForm;
}

class NodeForm : public QWidget
{
    Q_OBJECT

public:
    explicit NodeForm(QWidget *parent, const char* nodeName);
    ~NodeForm();

    void addInputValuePin(const char* name);
    void addInputImpulsePin(const char* name);
    void addOutputValuePin(const char* name);
    void addOutputImpulsePin(const char* name);

private:
    Ui::NodeForm *ui;
};

#endif // NODEFORM_H
