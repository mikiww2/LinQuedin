
#include "layoutWidget.h"

LayoutWidget::LayoutWidget(QWidget *parent) :
    QWidget(parent), rightWidget(0)
{
    leftWidget = new QFrame(this);
    hBox = new QHBoxLayout(this);

    leftWidget->setFrameShape(QFrame::Box);

    hBox->addWidget(leftWidget, 0, Qt::AlignLeft);

    leftWidget->setFixedSize(200,550);

    setLayout(hBox);

    show();
}

void LayoutWidget::setRightWidget(QWidget *widget) {
    if(rightWidget) {
        hBox->replaceWidget(rightWidget, widget);
        delete rightWidget;
        rightWidget = widget;
    }
    else {
        rightWidget = widget;
        hBox->addWidget(rightWidget);
    }
    rightWidget->setFixedHeight(450);
    rightWidget->setFixedWidth(550);
}

void LayoutWidget::closeEvent(QCloseEvent *event) {
    emit returnClose();
    event->accept();
}
