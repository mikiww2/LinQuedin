
#include "infoPersonali.h"

InfoPersonali::InfoPersonali(const Email &ema, const QString &nom, const QString &cogn) :
    email(ema), nome(nom), cognome(cogn)
{
    qDebug() << "create informazioni personali";
}

void InfoPersonali::setNome(const QString &string) { //modifico nome se non vuoto
    if(!string.isEmpty())
        nome = string;
}

void InfoPersonali::setCognome(const QString &string) {
    if(!string.isEmpty())
        cognome = string;
}

void InfoPersonali::setNumeroTelefono(const NumeroTelefonico &numero) {
    if(numero.isValid())
        numeroTelefono = numero;
}

void InfoPersonali::setDataNascita(const QDate &date) {
    if(date.isValid())
        dataNascita = date;
}

void InfoPersonali::setSesso(const QString &string) {
    sesso = string;
}

void InfoPersonali::setLuogoNascita(const QString &string) {
    luogoNascita = string;
}

void InfoPersonali::setResidenza(const QString &string) {
    residenza = string;
}

void InfoPersonali::setLavoro(const QString &string) {
    lavoro = string;
}

void InfoPersonali::setTitoloDiStudio(const QString &string) {
    titoloDiStudio = string;
}

const Email & InfoPersonali::getEmail() const { return email; }

const QString & InfoPersonali::getNome() const { return nome; }

const QString & InfoPersonali::getCognome() const { return cognome; }

const NumeroTelefonico & InfoPersonali::getNumeroTelefono() const {
    return numeroTelefono;
}

const QDate & InfoPersonali::getDataNascita() const { return dataNascita; }

QString InfoPersonali::getDataNascitaQString() const { return dataNascita.toString("dd MM yyyy"); }

const QString & InfoPersonali::getSesso() const { return sesso; }

const QString & InfoPersonali::getLuogoNascita() const { return luogoNascita; }

const QString & InfoPersonali::getResidenza() const { return residenza; }

const QString & InfoPersonali::getLavoro() const { return lavoro; }

const QString & InfoPersonali::getTitoloDiStudio() const { return titoloDiStudio; }

bool InfoPersonali::isValid() const {
    return email.isValid()
            && !nome.isEmpty()
            && !cognome.isEmpty();
}
bool InfoPersonali::isEmpty() const {
    return email.isEmpty()
            && nome.isEmpty()
            && cognome.isEmpty();
}

QString InfoPersonali::toString() const {
    if(isEmpty())
        return QString("InfoPersonali vuote");
    QString str;
    str.append("Info Personali: ");
    str.append("email: ");
    str.append(getEmail().getEmailString());
    str.append("nome: ");
    str.append(getNome());
    str.append(" cognome: ");
    str.append(getCognome());
    if(!getResidenza().isEmpty()) {
        str.append(" residenza: ");
        str.append(getResidenza());
    }
    else
        str.append(" residenza vouta");
    if(!getNumeroTelefono().isEmpty()) {

        str.append(getNumeroTelefono().getNumeroTelefonico());
    }
    else
        str.append(" numero di telefono vouto");
    if(!getDataNascita().isNull()) {
        str.append(" data di nascita: ");
        str.append(getDataNascitaQString());
    }
    else
        str.append(" data di nascita vuota");
    if(!getSesso().isEmpty()) {
        str.append(" sesso: ");
        str.append(getSesso());
    }
    else
        str.append(" sesso vuoto");
    if(!getLuogoNascita().isEmpty()) {
        str.append(" luogo di nascita: ");
        str.append(getLuogoNascita());
    }
    else
        str.append(" luogo di nascita vuoto");
    if(!getTitoloDiStudio().isEmpty()) {
        str.append(" titolo di studio: ");
        str.append(getTitoloDiStudio());
    }
    else
        str.append(" titolo di studio vuoto");
    if(!getLavoro().isEmpty()) {
        str.append(" lavoro: ");
        str.append(getLavoro());
    }
    else
        str.append(" lavoro vuoto");
    return str;
}

std::ostream & operator<<(std::ostream &os, const InfoPersonali &info) {
    return os << info.toString().toStdString();
}

QDebug operator<<(const QDebug &dbg, const InfoPersonali &info) {
    if(info.isValid())
        return dbg << "info personali valide " << info.toString();
    return dbg << "info personali non valide " << info.toString();
}
