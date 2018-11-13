
#include "adminWidget.h"

AdminWidget::AdminWidget(Database &db, QWidget *parent) :
    LayoutWidget(parent), adm(db)
{
    setWindowTitle(tr("Amministrazione - LinQuedIn"));

    listaUserButton = new QPushButton(tr("lista utenti"),this);
    loadDatabaseButton = new QPushButton(tr("carica database"),this);
    saveDatabaseButton = new QPushButton(tr("salva database"),this);
    newUserButton = new QPushButton(tr("nuovo utente"),this);
    changeUserButton = new QPushButton(tr("cambia tipo utente"),this);
    deleteUserButton = new QPushButton(tr("elimina utente"),this);
    vBoxleft = new QVBoxLayout(leftWidget);

    connect(listaUserButton, SIGNAL(clicked()), this, SLOT(listaUser()));
    connect(loadDatabaseButton, SIGNAL(clicked()), this, SLOT(loadDatabase()));
    connect(saveDatabaseButton, SIGNAL(clicked()), this, SLOT(saveDatabase()));
    connect(newUserButton, SIGNAL(clicked()), this, SLOT(newUser()));
    connect(changeUserButton, SIGNAL(clicked()), this, SLOT(changeUser()));
    connect(deleteUserButton, SIGNAL(clicked()), this, SLOT(deleteUser()));

    vBoxleft->addWidget(listaUserButton);
    vBoxleft->addWidget(loadDatabaseButton);
    vBoxleft->addWidget(saveDatabaseButton);
    vBoxleft->addWidget(newUserButton);
    vBoxleft->addWidget(changeUserButton);
    vBoxleft->addWidget(deleteUserButton);

    leftWidget->setLayout(vBoxleft);
}

void AdminWidget::enableButtons() {
    listaUserButton->setEnabled(true);
    loadDatabaseButton->setEnabled(true);
    saveDatabaseButton->setEnabled(true);
    newUserButton->setEnabled(true);
    changeUserButton->setEnabled(true);
    deleteUserButton->setEnabled(true);
}

//slot

void AdminWidget::listaUser() {
    enableButtons();
    listaUserButton->setEnabled(false);

    QWidget * widget= new ListaUserWidget(adm.getDatabase(), this);

    setRightWidget(widget);
}

void AdminWidget::loadDatabase() {
    enableButtons();
    loadDatabaseButton->setEnabled(false);

    QWidget * widget= new LoadDatabaseWidget(adm, this);

    setRightWidget(widget);
}

void AdminWidget::saveDatabase() {
    enableButtons();
    saveDatabaseButton->setEnabled(false);

    QWidget * widget= new SaveDatabaseWidget(adm, this);

    setRightWidget(widget);
}

void AdminWidget::newUser() {
    enableButtons();
    newUserButton->setEnabled(false);

    QWidget * widget= new NewUserWidget(adm, this);

    setRightWidget(widget);
}

void AdminWidget::changeUser() {
    enableButtons();
    changeUserButton->setEnabled(false);

    QWidget * widget= new ChangeUserWidget(adm, this);

    setRightWidget(widget);
}

void AdminWidget::deleteUser() {
    enableButtons();
    deleteUserButton->setEnabled(false);

    QWidget * widget= new DeleteUserWidget(adm, this);

    setRightWidget(widget);
}
