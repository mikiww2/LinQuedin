#ifndef MOSTRAUTENTEWIDGET_H
#define MOSTRAUTENTEWIDGET_H

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

#include "email.h"
#include "numeroTelefonico.h"
#include "infoPersonali.h"
#include "pointerUtente.h"
#include "utente.h"
#include "utenteBasic.h"
#include "utenteBusiness.h"
#include "utenteExecutive.h"

class MostraUtenteWidget : public QWidget
{
    Q_OBJECT
private:
    PointerUtente &utente;
    QString tipologia;
    bool collegato;
    QPushButton *button;
    QLabel *emailLabel, *nomLabel, *cognLabel, *resLabel, *sesLabel, *luoNascLabel, *numTelLabel, *datNascLabel;
    QLabel *lavLabel, *titLabel;
    QVBoxLayout *vBox, *lay;
    QFormLayout *form;
    QWidget *leftWidget;
    void loadButton();


public:
    explicit MostraUtenteWidget(PointerUtente &, const QString &, bool, QWidget * =0);

signals:
    void contatto(bool);

private slots:
    void changeContatto();

public slots:
    void reloadButton(); // emesso da fuori dopo aver fatto le modifiche

};

#endif // MOSTRAUTENTEWIDGET_H
