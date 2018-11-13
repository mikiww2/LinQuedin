#ifndef PROFILOWIDGET_H
#define PROFILOWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "pointerUtente.h"
#include "informazioniWidget.h"

class ProfiloWidget : public QWidget
{
    Q_OBJECT
private:
    PointerUtente &utente;
    InformazioniWidget *infoWidget;
    QPushButton *modificaButton;
    QVBoxLayout *lay;
    //widget delle informazioni

public:
    explicit ProfiloWidget(PointerUtente &, QWidget * =0);

signals:

public slots:

};

#endif // PROFILOWIDGET_H
