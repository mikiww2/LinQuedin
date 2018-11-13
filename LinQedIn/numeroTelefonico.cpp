
#include "numeroTelefonico.h"

QString NumeroTelefonico::patternSuffisso = "\\b[0-9]{9,10}\\b";

//verifica il numero inserito, accetta anche un solo numero di 12 o 14 cifre
NumeroTelefonico::NumeroTelefonico(const QString &suf) :
    suffisso(suf)
{
    suffisso.remove(" ");

    if(suffisso.length() > 10)
        suffisso.right(10);
    qDebug() << "creato numero telefonico";
}

bool NumeroTelefonico::isValid() const {
    QRegExp patternMatching(patternSuffisso, Qt::CaseInsensitive);
    return patternMatching.exactMatch(suffisso);
}

QString NumeroTelefonico::getNumeroTelefonico() const {
    return suffisso;
}

void NumeroTelefonico::changeNumeroTelefonico(const NumeroTelefonico &num) { //delega il controllo al costruttore
    if(num.isValid()) {
        suffisso = num.suffisso;
        qDebug() << "modificato numero telefonico";
    }
}

bool NumeroTelefonico::operator ==(const NumeroTelefonico &num) const {
    return suffisso == num.suffisso;
}

bool NumeroTelefonico::operator !=(const NumeroTelefonico &num) const {
    return suffisso != num.suffisso;
}

bool NumeroTelefonico::isEmpty() const {
    return suffisso == "0000000000";
}

std::ostream & operator<<(std::ostream &os, const NumeroTelefonico &num) {
    if(num.isEmpty())
        return os << "NumeroTelefonico vuoto";
    os << "Numero Telefonico : " << num.getNumeroTelefonico().toStdString();
    if(!num.isValid()) os << " invalido";
    return os;
}

QDebug operator<<(const QDebug &dbg, const NumeroTelefonico &numero) {
    if(numero.isEmpty())
        return dbg << "NumeroTelefonico vuoto";
    if(numero.isValid())
        return dbg << "NumeroTelefonico valido: " << numero.getNumeroTelefonico();
    return dbg << "NumeroTelefonico non valido: " << numero.getNumeroTelefonico();
}
