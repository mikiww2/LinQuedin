
#include "clientWidget.h"

ClientWidget::ClientWidget(PointerUtente &user, Database &database, QWidget *parent) :
    LayoutUserWidget(parent), client(Client(user,database)), contatto(0)
{
    setWindowTitle(creaTitolo());
    profiloButton = new QPushButton(tr("profilo"), this);
    vBoxleft = new QVBoxLayout(this);
    listaContatti = new listaContattiWidget(client.getUtente()->getContatti(), this);

    connect(profiloButton, SIGNAL(clicked()), this, SLOT(profilo()));
    connect(listaContatti, SIGNAL(mostra(PointerUtente&)), this, SLOT(mostraContatto(PointerUtente&)));
    connect(this, SIGNAL(reloadContatto()), this, SLOT(reloadListaContatti()));

    profiloButton->setFixedHeight(50);

    vBoxleft->addWidget(profiloButton);
    vBoxleft->addWidget(listaContatti);

    leftWidget->setLayout(vBoxleft);

    profilo();
}

QString ClientWidget::creaTitolo() const {
    QString str;
    str.append(client.getUtente()->getInformazioni().getNome());
    str.append((" "));
    str.append(client.getUtente()->getInformazioni().getCognome());
    str.append(" - LinQuedIn");
    return str;
}

//slot

void ClientWidget::enableProfiloButton() {
    profiloButton->setEnabled(true);
}

void ClientWidget::disableProfiloButton() {
    profiloButton->setEnabled(false);
}

void ClientWidget::searchFromBar(QString string) {
    ricerca(string, true);
}

void ClientWidget::moreFromBar() {
    ricerca(QString(), false);
}

void ClientWidget::ricerca(QString string, bool cerca) {
    enableProfiloButton();

    SearchWidget *widget = new SearchWidget(client.getUtente(), client.getDb(), this);
    setRightWidget(widget);

    connect(widget, SIGNAL(open(PointerUtente&)), this, SLOT(mostraContatto(PointerUtente&)));

    if(cerca)
        emit widget->search(string);
}

void ClientWidget::profilo() {
    disableProfiloButton();

    ProfiloWidget *widget = new ProfiloWidget(client.getUtente(), this);

    setRightWidgetWithBar(widget);

    connect(this, SIGNAL(search(QString)), this, SLOT(searchFromBar(QString)));
    connect(this, SIGNAL(more()), this, SLOT(moreFromBar()));
}

void ClientWidget::mostraContatto(PointerUtente &utente) {
    mostraUser(utente, true);
}

void ClientWidget::mostraUser(PointerUtente &cont, bool b) {
    enableProfiloButton();
    contatto = &cont;

    MostraUtenteWidget *widget = new MostraUtenteWidget(cont, client.getUtente()->getTipo(), b, this); //creo widget = mostraContatto widget

    connect(widget, SIGNAL(contatto(bool)), this, SLOT(modificaContatto(bool)));
    connect(this, SIGNAL(reloadContatto()), widget, SLOT(reloadButton()));

    setRightWidgetWithBar(widget);

    connect(this, SIGNAL(search(QString)), this, SLOT(searchFromBar(QString)));
    connect(this, SIGNAL(more()), this, SLOT(moreFromBar()));
}

void ClientWidget::modificaContatto(bool connetti) {
    if(connetti)
        client.addContatto(*contatto);
    else
        client.removeContatto(*contatto);
    emit reloadContatto();
}

void ClientWidget::reloadListaContatti() {
    listaContattiWidget *aux = new listaContattiWidget(client.getUtente()->getContatti(), this);

    vBoxleft->replaceWidget(listaContatti, aux);

    delete listaContatti;
    listaContatti = aux;

    connect(listaContatti, SIGNAL(mostra(PointerUtente&)), this, SLOT(mostraContatto(PointerUtente&)));
    listaContatti->show();

}
