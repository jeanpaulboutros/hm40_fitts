#include "GraphicWidget.h"

GraphicWidget::GraphicWidget()
{

}
GraphicWidget::~GraphicWidget() {}

void GraphicWidget::mousePressEvent(QMouseEvent *event) {
    emit mouseClicked(event->x(), event->y());
}
