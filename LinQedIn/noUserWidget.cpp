
#include "noUserWidget.h"

NoUserWidget::NoUserWidget(Database &database, QWidget *parent) :
    QFrame(parent), ut(0), db(database)
{
    setWindowTitle(tr("Login - LinQuedIn"));

    userLabel = new QLabel(tr("Nome Utente :"), this);
    userEdit = new QLineEdit(this);
    errorLabel = new QLabel(tr("Username errato o non presente"), this);
    userButton = new QPushButton(tr("Entra"), this);
    QVBoxLayout *vBox = new QVBoxLayout(this);

    QFont errorFont;
    errorFont.setItalic(true);
    errorLabel->setFont(errorFont);
    errorLabel->hide();

    userButton->setEnabled(false);

    connect(userEdit, SIGNAL(textChanged(QString)), this, SLOT(enableButton(QString)));
    connect(userEdit, SIGNAL(returnPressed()), this, SLOT(loadUser()));
    connect(userButton, SIGNAL(clicked()), this, SLOT(loadUser()));
    connect(this, SIGNAL(error()), this, SLOT(mostraErrore()));

    vBox->addWidget(errorLabel);
    vBox->addWidget(userLabel);
    vBox->addWidget(userEdit);
    vBox->addWidget(userButton);

    vBox->setAlignment(Qt::AlignCenter);

    setFixedSize(350, 100);

    setLayout(vBox);
    setFrameShape(QFrame::Box);
}

//slot
void NoUserWidget::loadUser() {
    Email username = Email(userEdit->displayText());
    if(!username.isValid())
        emit error();
    else {
        ut = db.utente(username);
        if(ut)
            emit logged(ut);
        else
            emit error();
    }
}

void NoUserWidget::mostraErrore() {
    errorLabel->show();
    setFixedSize(350, 130);
}

void NoUserWidget::enableButton(QString string) {
    if(string.isEmpty())
        emit userButton->setEnabled(false);
    else
        emit userButton->setEnabled(true);
}
