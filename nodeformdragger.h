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

    inline void setSnapToGrid(bool snapToGrid) { this->snapToGrid = snapToGrid; }

private:
    NodeForm* nodeForm;
    QPoint offset;
    bool snapToGrid;
};

#endif // NODEFORMDRAGGER_H
