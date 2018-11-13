
#include "deleteUserWidget.h"

DeleteUserWidget::DeleteUserWidget(Admin &adm, QWidget *parent) :
    QWidget(parent), admin(adm)
{
    errorLabel = new QLabel(this);
    emailEdit = new QLineEdit(this);
    eliminaButton = new QPushButton(tr("elimina utente"), this);
    form = new QFormLayout(this);

    QFont errorFont;
    errorFont.setItalic(true);
    errorLabel->setFont(errorFont);
    errorLabel->hide();

    eliminaButton->setDefault(true);

    connect(eliminaButton, SIGNAL(clicked()), this, SLOT(eliminaUser()));

    form->addWidget(errorLabel);
    form->addRow(tr("email: "), emailEdit);
    form->addWidget(eliminaButton);

    form->setAlignment(Qt::AlignCenter);

    setLayout(form);


}

//slot

void DeleteUserWidget::eliminaUser() {
    if(emailEdit->text().isEmpty()) {
        setLabel(tr("devi inserire un\'email per trovare l\'utente"));
        return;
    }
    Email ema = Email(emailEdit->text());
    if(!ema.isValid()) {
        setLabel(tr("devi inserire un\'email valida"));
        return;
    }
    if(!admin.cercaUtente(ema)) {
        setLabel(tr("l\'email non corrisponde a nessun utente"));
        return;
    }
    if(admin.rimuoviUtente(ema))
        setLabel(tr("l\'utente è stato rimosso con successo"));
    else
        setLabel(tr("si è verificato un errore non previsto"));
}

void DeleteUserWidget::setLabel(const QString &str) {
    errorLabel->setText(str);
    errorLabel->show();
}
