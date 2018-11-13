
#include "mostraUtenteWidget.h"

MostraUtenteWidget::MostraUtenteWidget(PointerUtente &ut, const QString &tipo, bool collegato, QWidget *parent) :
    QWidget(parent), utente(ut), tipologia(tipo), collegato(collegato)
{
    button = new QPushButton(this);
    emailLabel = new QLabel(utente->getUsername().getEmailString(), this);
    nomLabel = new QLabel(utente->getInformazioni().getNome(), this);
    cognLabel = new QLabel(utente->getInformazioni().getCognome(), this);
    resLabel = new QLabel(utente->getInformazioni().getResidenza(), this);
    sesLabel = new QLabel(utente->getInformazioni().getSesso(), this);
    luoNascLabel = new QLabel(utente->getInformazioni().getLuogoNascita(), this);
    numTelLabel = new QLabel(utente->getInformazioni().getNumeroTelefono().getNumeroTelefonico(), this);
    datNascLabel = new QLabel(utente->getInformazioni().getDataNascitaQString(), this);
    lavLabel = new QLabel(utente->getInformazioni().getLavoro(), this);
    titLabel = new QLabel(utente->getInformazioni().getTitoloDiStudio(), this);

    form = new QFormLayout(this);
    leftWidget = new QWidget(this);
    lay = new QVBoxLayout(this);
    vBox = new QVBoxLayout(this);

    connect(button, SIGNAL(clicked()), this, SLOT(changeContatto()));

    loadButton();

    form->addRow(tr("email: "), emailLabel);
    form->addRow(tr("nome: "), nomLabel);
    form->addRow(tr("cognome: "), cognLabel);

    if(collegato || tipologia == UtenteBusiness::tipo || tipologia == UtenteExecutive::tipo) {
        form->addRow(tr("residenza: "), resLabel);
        form->addRow(tr("sesso:"), sesLabel);
        form->addRow(tr("luogo di nascita: "), luoNascLabel);
        form->addRow(tr("data di nascita: "), datNascLabel);

    }
    if(collegato || tipologia == UtenteExecutive::tipo) {
        form->addRow(tr("numero di telefono: "), numTelLabel);
        form->addRow(tr("lavoro: "), lavLabel);
        form->addRow(tr("titolo di studio: "), titLabel);
    }

    leftWidget->setLayout(form);

    lay->addWidget(button);
    lay->addWidget(leftWidget);

    setLayout(lay);
}

void MostraUtenteWidget::loadButton() {
    if(collegato)
        button->setText(tr("rimuovi utente dai contatti"));
    else
        button->setText(tr("aggiungi utente ai contatti"));
}

// slot

void MostraUtenteWidget::changeContatto() {
    if(collegato)
        emit contatto(false);
    else
        emit contatto(true);
}

void MostraUtenteWidget::reloadButton() {
    collegato = !collegato;
    loadButton();
}
