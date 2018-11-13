#ifndef LAYOUTWIDGET_H
#define LAYOUTWIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QFrame>

class LayoutWidget : public QWidget
{
    Q_OBJECT
protected:
    QWidget *rightWidget;
    QFrame *leftWidget;
    QHBoxLayout *hBox;
    void setRightWidget(QWidget *); //elimina il precedente widget e inserisce il nuovo

public:
    explicit LayoutWidget(QWidget * =0);

signals:
    void returnClose();

public slots:
    void closeEvent(QCloseEvent *);
};

#endif // LAYOUTWIDGET_H
