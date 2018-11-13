#ifndef INFORMAZIONIWIDGET_H
#define INFORMAZIONIWIDGET_H

#include <QFrame>
#include <QLineEdit>
#include <QDateEdit>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>

#include "email.h"
#include "numeroTelefonico.h"
#include "infoPersonali.h"
#include "pointerUtente.h"

class InformazioniWidget : public QFrame
{
    Q_OBJECT
private:
    PointerUtente &utente;
    QLineEdit *nomEdit, *cognEdit, *resEdit, *sesEdit, *luoNascEdit, *numTelEdit, *lavEdit, *titEdit;
    QDateEdit *datNascEdit;
    QLabel *errorLabel, *emailLabel, *nomLabel, *cognLabel, *resLabel, *sesLabel, *luoNascLabel, *numTelLabel;
    QLabel *datNascLabel, *lavLabel, *titLabel;
    QFrame *widget;
    QCheckBox *hideInfoBox;
    QPushButton *salvaButton, *scartaButton;
    QFormLayout *form;

public:
    explicit InformazioniWidget(PointerUtente &, QWidget * =0);

signals:
    void viewModifica();
    void nascondiModifica();

private slots:
    void vediModifica();
    void setLabel(const QString &);
    void mostraModifica(bool);
    void modifica();
    void scartaModifiche();

};

#endif // INFORMAZIONIWIDGET_H
