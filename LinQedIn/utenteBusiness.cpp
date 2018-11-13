
#include "utenteBusiness.h"

UtenteBusiness::UtenteBusiness(InfoPersonali &info) : //costruttore pericoloso
    UtenteBasic(info)
{ }

UtenteBusiness::UtenteBusiness(const Email &ema, const QString &nom, const QString &cogn) :
    UtenteBasic(ema, nom, cogn)
{
    qDebug() << "creato utente Business";
}

UtenteBusiness::UtenteBusiness(const UtenteBusiness &ut) : UtenteBasic (ut)
{ }

UtenteBusiness::~UtenteBusiness() { }

QString UtenteBusiness::toString() const {
    if(isEmpty())
        return QString("Utente Business vuoto");
    QString str;
    str.append("Utente Business ");
    str.append(UtenteBasic::toString());
    return str;
}

QString UtenteBusiness::tipo = QString("Business");

QString UtenteBusiness::getTipo() const {
    return tipo;
}

std::ostream & operator<<(std::ostream &os, const UtenteBusiness &ut) {
    if(ut.isValid())
        return os << "Utente valido " << ut.toString().toStdString();
    return os << "Utente non valido " << ut.toString().toStdString();
}

QDebug operator<<(const QDebug &dbg, const UtenteBusiness &ut) {
    if(ut.isValid())
        return dbg << "Utente Business valido " << ut.toString();
    return dbg << "Utente Business non valido " << ut.toString();
}
