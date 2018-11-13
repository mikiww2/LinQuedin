#ifndef LISTACONTATTIWIDGET_H
#define LISTACONTATTIWIDGET_H

#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>

#include "pointerUtente.h"

#include "userLinkWidget.h"

class listaContattiWidget : public QScrollArea
{
    Q_OBJECT
private:
    const QMap<Email, PointerUtente *>  &contatti;
    QLabel *noLabel;
    QVBoxLayout *vBox;
public:
    explicit listaContattiWidget(const QMap<Email, PointerUtente *> &, QWidget * =0);

signals:
    void mostra(PointerUtente &);

public slots:

};

#endif // LISTACONTATTIWIDGET_H
