
#include "newUserWidget.h"

NewUserWidget::NewUserWidget(Admin &adm, QWidget *parent) :
    QWidget(parent), admin(adm)
{
    tipoLabel = new QLabel(tr("tipo utente: "), this);
    errorLabel = new QLabel(this);
    nomeEdit = new QLineEdit(this);
    cognomeEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    basicUserButton = new QRadioButton( this);
    businessUserButton = new QRadioButton( this);
    executiveUserButton = new QRadioButton( this);
    tipoGroup = new QButtonGroup(this);
    creaButton = new QPushButton(tr("registra"), this);
    form = new QFormLayout(this);

    QFont errorFont;
    errorFont.setItalic(true);
    errorLabel->setFont(errorFont);
    errorLabel->hide();

    tipoGroup->addButton(basicUserButton, 0);
    tipoGroup->addButton(businessUserButton, 1);
    tipoGroup->addButton(executiveUserButton, 2);

    basicUserButton->setChecked(true);

    creaButton->setDefault(true);

    connect(creaButton, SIGNAL(clicked()), this, SLOT(creaUser()));

    form->addWidget(errorLabel);
    form->addRow(tr("nome: "),nomeEdit);
    form->addRow(tr("cognome: "), cognomeEdit);
    form->addRow(tr("email: "), emailEdit);
    form->addWidget(tipoLabel);
    form->addRow(tr("utente basic"), basicUserButton);
    form->addRow(tr("utente business"), businessUserButton);
    form->addRow(tr("utente executive"), executiveUserButton);
    form->addWidget(creaButton);

    form->setAlignment(Qt::AlignCenter);

    setLayout(form);
}

//slot

void NewUserWidget::creaUser() {
    if(nomeEdit->text().isEmpty()) {
        setLabel(tr("devi inserire un nome"));
        return;
    }
    if(cognomeEdit->text().isEmpty()) {
        setLabel(tr("devi inserire un cognome"));
        return;
    }
    if(emailEdit->text().isEmpty()) {
        setLabel(tr("devi inserire un\'email"));
        return;
    }
    Email ema = Email(emailEdit->text());
    if(!ema.isValid()) {
        setLabel(tr("devi inserire un\'email valida"));
        return;
    }
    if(admin.cercaUtente(ema)) {
        setLabel(tr("email già utilizzata per registrarsi"));
        return;
    }
    switch(tipoGroup->checkedId()) {
    case 0:
        admin.creaUtente(nomeEdit->text(), cognomeEdit->text(), ema, UtenteBasic::tipo);
        break;
    case 1:
        admin.creaUtente(nomeEdit->text(), cognomeEdit->text(), ema, UtenteBusiness::tipo);
        break;
    case 2:
        admin.creaUtente(nomeEdit->text(), cognomeEdit->text(), ema, UtenteExecutive::tipo);;
        break;
    default:
        setLabel(tr("si è verificato un errore inprevisto"));
        return;
    }
    setLabel(tr("registrato con successo l'utente"));
}

void NewUserWidget::setLabel(const QString &str) {
    errorLabel->setText(str);
    errorLabel->show();
}
