#ifndef LAYOUTUSERWIDGET_H
#define LAYOUTUSERWIDGET_H

#include <QWidget>
#include <QScrollArea>

#include "layoutWidget.h"
#include "searchBarWidget.h"

class LayoutUserWidget : public LayoutWidget
{
    Q_OBJECT
private:
    SearchBarWidget *searchBar;
    QVBoxLayout *lay;
    QWidget *widget;

protected:
    void setRightWidgetWithBar(QWidget *);

public:
    explicit LayoutUserWidget(QWidget * =0);

signals:
    void search(QString string);
    void more();

public slots:

};

#endif // LAYOUTUSERWIDGET_H
