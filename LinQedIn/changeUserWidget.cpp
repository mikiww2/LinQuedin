
#include "changeUserWidget.h"

ChangeUserWidget::ChangeUserWidget(Admin &adm, QWidget *parent) :
    QWidget(parent), admin(adm)
{
    errorLabel = new QLabel(this);
    emailEdit = new QLineEdit(this);
    findButton = new QPushButton(tr("carica utente"), this);
    form = new QFormLayout(this);

    QFont errorFont;
    errorFont.setItalic(true);
    errorLabel->setFont(errorFont);
    errorLabel->hide();

    findButton->setDefault(true);

    connect(findButton, SIGNAL(clicked()), this, SLOT(loadUser()));

    form->addWidget(errorLabel);
    form->addRow(tr("email: "), emailEdit);
    form->addWidget(findButton);

    form->setAlignment(Qt::AlignCenter);

    setLayout(form);
} 

//slot

void ChangeUserWidget::setLabel(const QString &str) {
    errorLabel->setText(str);
    errorLabel->show();
}


void ChangeUserWidget::loadUser() {
    if(emailEdit->text().isEmpty()) {
        setLabel(tr("devi inserire un\'email"));
        return;
    }

    Email ema = Email(emailEdit->text());
    if(!ema.isValid()) {
        setLabel(tr("devi inserire un\'email valida"));
        return;
    }

    PointerUtente *utente = admin.cercaUtente(ema);
    if(!utente) {
        setLabel(tr("email già utilizzata per registrarsi"));
        return;
    }
    QString tipo =(*utente)->getTipo();
    if(tipo != UtenteBasic::tipo && tipo != UtenteBusiness::tipo && tipo != UtenteExecutive::tipo) {
        setLabel(tr("si è verificato un errore imprevvisto"));
        return;
    }
    emit findButton->hide();

    tipoLabel = new QLabel(tr("tipo utente: "), this);
    basicUserButton = new QRadioButton( this);
    businessUserButton = new QRadioButton( this);
    executiveUserButton = new QRadioButton( this);
    tipoGroup = new QButtonGroup(this);
    changeButton = new QPushButton(tr("modifica tipo utente"), this);

    tipoGroup->addButton(basicUserButton, 0);
    tipoGroup->addButton(businessUserButton, 1);
    tipoGroup->addButton(executiveUserButton, 2);

    if(tipo == UtenteBasic::tipo)
        basicUserButton->setChecked(true);
    if(tipo == UtenteBusiness::tipo)
        businessUserButton->setChecked(true);
    if(tipo == UtenteExecutive::tipo)
        executiveUserButton->setChecked(true);


    emailEdit->setEnabled(false);

    changeButton->setDefault(true);

    connect(changeButton, SIGNAL(clicked()), this, SLOT(changeUser()));

    form->addWidget(tipoLabel);
    form->addRow(tr("utente basic"), basicUserButton);
    form->addRow(tr("utente business"), businessUserButton);
    form->addRow(tr("utente executive"), executiveUserButton);
    form->addWidget(changeButton);
}

void ChangeUserWidget::changeUser() {
    QString str;
    switch(tipoGroup->checkedId()) {
    case 0:
        str = UtenteBasic::tipo;
        break;
    case 1:
        str = UtenteBusiness::tipo;
        break;
    case 2:
        str = UtenteExecutive::tipo;
        break;
    default:
        setLabel(tr("si è verificato un errore inprevisto"));
        return;
    }

    PointerUtente *utente = admin.cercaUtente(Email(emailEdit->text())); // già controllato

    if((*utente)->getTipo() == str ) {
        setLabel(tr("devi scegliere un tipo diverso, l'utente è già di quel tipo"));
        return;
    }
    if(admin.cambiaTypeUtente(*utente, str))
        setLabel(tr("tipo dell'utente cambiato"));
    else
        setLabel(tr("non è stato possibile cambiare il tipo dell'utente"));
}
