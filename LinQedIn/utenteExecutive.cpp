
#include "utenteExecutive.h"

UtenteExecutive::UtenteExecutive(InfoPersonali &info) : //costruttore pericoloso
    UtenteBusiness(info)
{ }

UtenteExecutive::UtenteExecutive(const Email &ema, const QString &nom, const QString &cogn) :
    UtenteBusiness(ema, nom, cogn)
{
    qDebug() << "creato utente Executive";
}

UtenteExecutive::UtenteExecutive(const UtenteExecutive &ut) : UtenteBusiness (ut)
{ }

UtenteExecutive::~UtenteExecutive() { }

QString UtenteExecutive::toString() const {
    if(isEmpty())
        return QString("Utente Executive vuoto");
    QString str;
    str.append("Utente Executive ");
    str.append(UtenteBusiness::toString());
    return str;
}

QString UtenteExecutive::tipo = QString("Executive");

QString UtenteExecutive::getTipo() const {
    return tipo;
}

std::ostream & operator<<(std::ostream &os, const UtenteExecutive &ut) {
    if(ut.isValid())
        return os << "Utente valido " << ut.toString().toStdString();
    return os << "Utente non valido " << ut.toString().toStdString();
}

QDebug operator<<(const QDebug &dbg, const UtenteExecutive &ut) {
    if(ut.isValid())
        return dbg << "Utente Executive valido " << ut.toString();
    return dbg << "Utente Executive non valido " << ut.toString();
}
