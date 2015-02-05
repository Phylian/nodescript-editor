#ifndef NODEFORMDRAGGER_H
#define NODEFORMDRAGGER_H

#include <QPoint>

class NodeForm;

class NodeFormDragger
{
public:
    NodeFormDragger();
    ~NodeFormDragger();

    void beginDrag(NodeForm* nodeForm, QPoint offset);
    void drag(QPoint mousePosition);
    void endDrag();

private:
    NodeForm* nodeForm;
    QPoint offset;
};

#endif // NODEFORMDRAGGER_H
