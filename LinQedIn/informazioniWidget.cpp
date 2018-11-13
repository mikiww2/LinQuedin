
#include "informazioniWidget.h"

InformazioniWidget::InformazioniWidget(PointerUtente &ut, QWidget *parent) :
    QFrame(parent), utente(ut)
{
    errorLabel = new QLabel(this);
    emailLabel = new QLabel(utente->getUsername().getEmailString(), this);
    nomLabel = new QLabel(utente->getInformazioni().getNome(), this);
    cognLabel = new QLabel(utente->getInformazioni().getCognome(), this);
    resLabel = new QLabel(utente->getInformazioni().getResidenza(), this);
    sesLabel = new QLabel(utente->getInformazioni().getSesso(), this);
    luoNascLabel = new QLabel(utente->getInformazioni().getLuogoNascita(), this);
    numTelLabel = new QLabel(utente->getInformazioni().getNumeroTelefono().getNumeroTelefonico(), this);
    if(utente->getInformazioni().getNumeroTelefono().isEmpty())
        numTelLabel->clear();
    datNascLabel = new QLabel(utente->getInformazioni().getDataNascitaQString(), this);
    lavLabel = new QLabel(utente->getInformazioni().getLavoro(), this);
    titLabel = new QLabel(utente->getInformazioni().getTitoloDiStudio(), this);

    nomEdit = new QLineEdit(this);
    cognEdit = new QLineEdit(this);
    resEdit = new QLineEdit(this);
    sesEdit = new QLineEdit(this);
    luoNascEdit = new QLineEdit(this);
    numTelEdit = new QLineEdit(this);
    lavEdit = new QLineEdit(this);
    titEdit = new QLineEdit(this);
    datNascEdit = new QDateEdit(this);
    hideInfoBox = new QCheckBox(this);
    salvaButton = new QPushButton(tr("salva"), this);
    scartaButton = new QPushButton(tr("scarta"), this);
    form = new QFormLayout(this);

    errorLabel->hide();

    connect(this, SIGNAL(viewModifica()), this, SLOT(vediModifica()));

    hideInfoBox->setChecked(utente->isHide());

    connect(salvaButton, SIGNAL(clicked()), this, SLOT(modifica()));
    connect(scartaButton, SIGNAL(clicked()), this, SLOT(scartaModifiche()));

    nomEdit->hide();
    cognEdit->hide();
    resEdit->hide();
    sesEdit->hide();
    luoNascEdit->hide();
    numTelEdit->hide();
    datNascEdit->hide();
    lavEdit->hide();
    titEdit->hide();

    connect(nomEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));
    connect(cognEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));
    connect(resEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));
    connect(sesEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));
    connect(luoNascEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));
    connect(numTelEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));
    connect(lavEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));
    connect(titEdit, SIGNAL(returnPressed()), this, SLOT(modifica()));

    form->addWidget(errorLabel);
    form->addRow(tr("email: "), emailLabel);
    form->addRow(tr("nome: "), nomLabel);
    form->addRow(tr("cognome: "), cognLabel);
    form->addRow(tr("residenza: "), resLabel);
    form->addRow(tr("sesso:"), sesLabel);
    form->addRow(tr("luogo di nascita: "), luoNascLabel);
    form->addRow(tr("numero di telefono: "), numTelLabel);
    form->addRow(tr("data di nascita: "), datNascLabel);
    form->addRow(tr("lavoro: "), lavLabel);
    form->addRow(tr("titolo di studio: "), titLabel);
    form->addRow(tr("nascondi informazioni profilo: "), hideInfoBox);
    form->addWidget(salvaButton);
    form->addWidget(scartaButton);

    hideInfoBox->setCheckable(false);

    salvaButton->hide();
    scartaButton->hide();

    setLayout(form);
    setFrameShape(QFrame::Box);
}

//slot

void InformazioniWidget::vediModifica() {
    mostraModifica(true);
}

void InformazioniWidget::setLabel(const QString &str) {
    errorLabel->setText(str);
    errorLabel->show();
}

void InformazioniWidget::mostraModifica(bool mod) {
    if(mod) {
        nomEdit->setText(utente->getInformazioni().getNome());
        cognEdit->setText(utente->getInformazioni().getCognome());
        resEdit->setText(utente->getInformazioni().getResidenza());
        sesEdit->setText(utente->getInformazioni().getSesso());
        luoNascEdit->setText(utente->getInformazioni().getLuogoNascita());
        numTelEdit->setText(utente->getInformazioni().getNumeroTelefono().getNumeroTelefonico());
        if(utente->getInformazioni().getNumeroTelefono().isEmpty())
            numTelEdit->clear();
        datNascEdit->setDate(utente->getInformazioni().getDataNascita());
        lavEdit->setText(utente->getInformazioni().getLavoro());
        titEdit->setText(utente->getInformazioni().getTitoloDiStudio());

        nomEdit->show();
        cognEdit->show();
        resEdit->show();
        sesEdit->show();
        luoNascEdit->show();
        numTelEdit->show();
        datNascEdit->show();
        lavEdit->show();
        titEdit->show();

        form->replaceWidget(nomLabel, nomEdit);
        form->replaceWidget(cognLabel, cognEdit);
        form->replaceWidget(resLabel, resEdit);
        form->replaceWidget(sesLabel, sesEdit);
        form->replaceWidget(luoNascLabel, luoNascEdit);
        form->replaceWidget(numTelLabel, numTelEdit);
        form->replaceWidget(datNascLabel, datNascEdit);
        form->replaceWidget(lavLabel, lavEdit);
        form->replaceWidget(titLabel, titEdit);

        nomLabel->hide();
        cognLabel->hide();
        resLabel->hide();
        sesLabel->hide();
        luoNascLabel->hide();
        numTelLabel->hide();
        datNascLabel->hide();
        lavLabel->hide();
        titLabel->hide();

    }
    else  {
        nomLabel->setText(utente->getInformazioni().getNome());
        cognLabel->setText(utente->getInformazioni().getCognome());
        resLabel->setText(utente->getInformazioni().getResidenza());
        sesLabel->setText(utente->getInformazioni().getSesso());
        luoNascLabel->setText(utente->getInformazioni().getLuogoNascita());
        numTelLabel->setText(utente->getInformazioni().getNumeroTelefono().getNumeroTelefonico());
        if(utente->getInformazioni().getNumeroTelefono().isEmpty())
            numTelLabel->clear();
        datNascLabel->setText(utente->getInformazioni().getDataNascitaQString());
        lavLabel->setText(utente->getInformazioni().getLavoro());
        titLabel->setText(utente->getInformazioni().getTitoloDiStudio());

        nomLabel->show();
        cognLabel->show();
        resLabel->show();
        sesLabel->show();
        luoNascLabel->show();
        numTelLabel->show();
        datNascLabel->show();
        lavLabel->show();
        titLabel->show();

        form->replaceWidget(nomEdit, nomLabel);
        form->replaceWidget(cognEdit, cognLabel);
        form->replaceWidget(resEdit, resLabel);
        form->replaceWidget(sesEdit, sesLabel);
        form->replaceWidget(luoNascEdit, luoNascLabel);
        form->replaceWidget(numTelEdit, numTelLabel);
        form->replaceWidget(datNascEdit, datNascLabel);
        form->replaceWidget(lavEdit, lavLabel);
        form->replaceWidget(titEdit, titLabel);

        nomEdit->hide();
        cognEdit->hide();
        resEdit->hide();
        sesEdit->hide();
        luoNascEdit->hide();
        numTelEdit->hide();
        datNascEdit->hide();
        lavEdit->hide();
        titEdit->hide();

    }
    hideInfoBox->setCheckable(mod);

    emit salvaButton->setVisible(mod);
    emit scartaButton->setVisible(mod);

    if(!mod)
        emit nascondiModifica();
}

void InformazioniWidget::modifica() {

    if(nomEdit->text().isEmpty()) {
        setLabel(tr("non si può cancellare il nome"));
        return;
    }
    if(nomEdit->text() != utente->getInformazioni().getNome())
        utente->getInformazioni().setNome(nomEdit->text());
    if(cognEdit->text().isEmpty()) {
        setLabel(tr("non si può cancellare il cognome"));
        return;
    }
    if(cognEdit->text() != utente->getInformazioni().getCognome())
        utente->getInformazioni().setCognome(cognEdit->text());
    if(resEdit->text() != utente->getInformazioni().getResidenza())
        utente->getInformazioni().setResidenza(resEdit->text());
    if(sesEdit->text() != utente->getInformazioni().getSesso())
        utente->getInformazioni().setSesso(sesEdit->text());
    if(luoNascEdit->text() != utente->getInformazioni().getLuogoNascita())
        utente->getInformazioni().setLuogoNascita(luoNascEdit->text());
    if(!numTelEdit->text().isEmpty() && numTelEdit->text() != utente->getInformazioni().getNumeroTelefono().getNumeroTelefonico())
        utente->getInformazioni().setNumeroTelefono(NumeroTelefonico(numTelEdit->text()));
    if(lavEdit->text() != utente->getInformazioni().getLavoro())
        utente->getInformazioni().setLavoro(lavEdit->text());
    if(titEdit->text() != utente->getInformazioni().getTitoloDiStudio())
        utente->getInformazioni().setTitoloDiStudio(titEdit->text());

    if(hideInfoBox->isChecked())
        utente->hideInformation();
    else
        utente->showInformation();

    mostraModifica(false);
}

void InformazioniWidget::scartaModifiche() {
    mostraModifica(false);
}
