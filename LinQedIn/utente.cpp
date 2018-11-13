
#include "utente.h"


Utente::Utente(InfoPersonali &info) : //costruttore pericoloso
    informazioni(&info), hideInfo(false)
{ }

Utente::Utente(const Email &ema, const QString &nom, const QString &cogn) :
    hideInfo(false)
{
    informazioni = new InfoPersonali(ema, nom,cogn);
}

Utente::Utente(const Utente &ut) : // costruttore di copia profonda
    hideInfo(ut.hideInfo)
{
    informazioni = new InfoPersonali(*ut.informazioni);
}

Utente::~Utente() { //distruttore profondo
    delete informazioni;
}

void Utente::swap(Utente &ut) {
    InfoPersonali *i = ut.informazioni; // non mi piace, forse swap per infoPersonali
    ut.informazioni = informazioni;
    informazioni = i;

    contatti.swap(ut.contatti);

    bool h = ut.hideInfo;
    ut.hideInfo = hideInfo;
    hideInfo = h;
}

void Utente::hideInformation() {
    hideInfo = true;
    qDebug() << "informazioni nascoste";
}

void Utente::showInformation() {
    hideInfo = false;
    qDebug() << "informazioni visibili";
}

bool Utente::isHide() const { return hideInfo; }

const Email & Utente::getUsername() const {
    return informazioni->getEmail();
}

InfoPersonali & Utente::getInformazioni() const { return *informazioni; }

const QMap<Email, PointerUtente *> & Utente::getContatti() const { return contatti; }

bool Utente::haveContatto(const Email &username) const{
    return contatti.contains(username);
}

bool Utente::aggiungiContatto(PointerUtente &punt) {
    if(contatti.contains(punt->getUsername()))
        return false;
    contatti.insert(punt->getUsername(), &punt);
    return true;
}

void Utente::rimuoviContatto(const Email &username) {
    contatti.remove(username);
}

void Utente::rimuoviContatto(PointerUtente &punt) {
    contatti.remove(punt->getUsername());
}

bool Utente::isValid() const {
    return informazioni->isValid();
}

bool Utente::isEmpty() const {
    return informazioni->isEmpty();
}

//ritorna true se hanno lo stesso username, altrimenti false
bool Utente::operator ==(const Utente &ut) const {
    return !isEmpty() && !ut.isEmpty() && getUsername() == ut.getUsername();
}

bool Utente::operator !=(const Utente &ut) const {
    return !(*this == ut);
}

bool Utente::operator <(const Utente &ut) const {
    if(isEmpty()) {
        if(ut.isEmpty()) return false;
        return true;
    }
    if(ut.isEmpty()) return false;
    return getUsername() < ut.getUsername();
}

bool Utente::operator >(const Utente &ut) const {
    if(isEmpty()) return false;
    if(ut.isEmpty()) return true;
    return getUsername() < ut.getUsername();
}

QString Utente::toString() const {
    if(isEmpty())
        return QString("Utente vuoto");
    QString str;
    str.append(" hide: ");
    if(hideInfo)
        str.append("true ");
    else
        str.append("false ");
    str.append(informazioni->toString());
    return str;
}
