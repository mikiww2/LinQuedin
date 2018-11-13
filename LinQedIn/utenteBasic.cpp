
#include "utenteBasic.h"

UtenteBasic::UtenteBasic(InfoPersonali &info) : //costruttore pericoloso
    Utente(info)
{ }

UtenteBasic::UtenteBasic(const Email &ema, const QString &nom, const QString &cogn) :
    Utente(ema, nom, cogn)
{
    qDebug() << "creato utente Basic";
}

UtenteBasic::UtenteBasic(const UtenteBasic &ut) : Utente (ut)
{ }

UtenteBasic::~UtenteBasic() { }

QString UtenteBasic::toString() const {
    if(isEmpty())
        return QString("Utente Basic vuoto");
    QString str;
    str.append("Utente Basic ");
    str.append(Utente::toString());
    return str;
}

QString UtenteBasic::tipo = QString("Basic");

QString UtenteBasic::getTipo() const {
    return tipo;
}

std::ostream & operator<<(std::ostream &os, const UtenteBasic &ut) {
    if(ut.isValid())
        return os << "Utente valido " << ut.toString().toStdString();
    return os << "Utente non valido " << ut.toString().toStdString();
}

QDebug operator<<(const QDebug &dbg, const UtenteBasic &ut) {
    if(ut.isValid())
        return dbg << "Utente Basic valido " << ut.toString();
    return dbg << "Utente Basic non valido " << ut.toString();
}
