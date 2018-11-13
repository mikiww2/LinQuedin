
#include "layoutUserWidget.h"

LayoutUserWidget::LayoutUserWidget(QWidget *parent) :
    LayoutWidget(parent)
{
}

void LayoutUserWidget::setRightWidgetWithBar(QWidget *rigWidget) {
    if(rightWidget) {
        QWidget *oldWidget = rightWidget;
        rightWidget = new QWidget(this);
        hBox->replaceWidget(oldWidget, rightWidget);
        delete oldWidget;
    }
    else  {
        rightWidget = new QWidget(this);
        hBox->addWidget(rightWidget);
    }

    QScrollArea *scrollArea = new QScrollArea(rightWidget);
    scrollArea->setWidgetResizable(true);

    scrollArea->setWidget(rigWidget);

    searchBar = new SearchBarWidget(this);
    searchBar->setFixedHeight(100);

    connect(searchBar, SIGNAL(cerca(QString)), this, SIGNAL(search(QString)));
    connect(searchBar, SIGNAL(altro()), this, SIGNAL(more()));

    lay = new QVBoxLayout(rightWidget);
    lay->addWidget(searchBar);
    lay->addWidget(scrollArea);

    rightWidget->setLayout(lay);
    rightWidget->setFixedHeight(450);
    rightWidget->setFixedWidth(550);
}
