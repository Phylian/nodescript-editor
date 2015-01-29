#ifndef NODEDRAGGER_H
#define NODEDRAGGER_H

#include <QPoint>

class NodeForm;

class NodeDragger
{
public:
    NodeDragger();
    ~NodeDragger();

    void beginDrag(NodeForm* nodeForm, QPoint offset);
    void drag(QPoint mousePosition);
    void endDrag();

private:
    NodeForm* nodeForm;
    QPoint offset;
};

#endif // NODEDRAGGER_H
