#ifndef LISTAUSERWIDGET_H
#define LISTAUSERWIDGET_H

#include <QWidget>
#include <QMap>
#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>

#include "email.h"
#include "pointerUtente.h"
#include "database.h"

class ListaUserWidget : public QWidget
{
    Q_OBJECT
private:
    Database &db;
    QGridLayout *grid, *lay;
    QWidget *widget;
    QScrollArea *scrollArea;

public:
    explicit ListaUserWidget(Database &, QWidget * =0);

signals:

private slots:

public slots:

};

#endif // LISTAUSERWIDGET_H
