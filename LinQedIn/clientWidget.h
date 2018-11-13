#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>

#include "pointerUtente.h"
#include "database.h"
#include "client.h"
#include "layoutUserWidget.h"
#include "searchWidget.h"
#include "profiloWidget.h"
#include "mostraUtenteWidget.h"
#include "listaContattiWidget.h"


class ClientWidget : public LayoutUserWidget
{
    Q_OBJECT
private:
    Client client;
    QPushButton *profiloButton;
    QVBoxLayout *vBoxleft;
    listaContattiWidget *listaContatti;
    QString creaTitolo() const;
    PointerUtente *contatto;

public:
    explicit ClientWidget(PointerUtente &, Database &, QWidget * =0);

signals:
    void reloadContatto();

private slots:
    void enableProfiloButton();
    void disableProfiloButton();
    void searchFromBar(QString);
    void moreFromBar();
    void ricerca(QString, bool);
    void profilo();
    void mostraContatto(PointerUtente &);
    void mostraUser(PointerUtente &, bool);
    void modificaContatto(bool);
    void reloadListaContatti();
};

#endif // CLIENTWIDGET_H
