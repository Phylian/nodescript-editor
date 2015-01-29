#ifndef NODEFORM_H
#define NODEFORM_H

#include <QWidget>

namespace Ui {
class NodeForm;
}

class NodeDragger;

class NodeForm : public QWidget
{
    Q_OBJECT

public:
    explicit NodeForm(QWidget *parent, const char* nodeName, NodeDragger& nodeDragger);
    ~NodeForm();

    void addInputValuePin(const char* name);
    void addInputImpulsePin(const char* name);
    void addOutputValuePin(const char* name);
    void addOutputImpulsePin(const char* name);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);

private:
    Ui::NodeForm *ui;
    NodeDragger& nodeDragger;
};

#endif // NODEFORM_H
