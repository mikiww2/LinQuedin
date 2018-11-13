
#include "userLinkWidget.h"

UserLinkWidget::UserLinkWidget(PointerUtente &ut, QWidget *parent) :
    QWidget(parent), utente(ut)
{
    openButton = new QPushButton(tr("apri"), this);
    userLabel = new QLabel(utente->getUsername().getEmailString(), this);
    vBox = new QVBoxLayout(this);

    connect(openButton, SIGNAL(clicked()), this, SLOT(pressed()));

    vBox->addWidget(userLabel);
    vBox->addWidget(openButton);

    setLayout(vBox);
}

// slot

void UserLinkWidget::pressed() {
    emit Open(utente);
}

