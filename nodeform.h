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
    explicit NodeForm(const char* nodeName);
    ~NodeForm();

    void addInputValuePin(const char* name);
    void addInputImpulsePin(const char* name);
    void addOutputValuePin(const char* name);
    void addOutputImpulsePin(const char* name);

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

    inline void setNodeDragger(NodeDragger* nodeDragger) { this->nodeDragger = nodeDragger; }

private:
    Ui::NodeForm *ui;
    NodeDragger* nodeDragger;
};

#endif // NODEFORM_H
