// utenteExecutive.h

//Utente con permessi di ricerca:
/*
 * quelli di business(e basic) +
 * lavorato at *
 * studiato at *
 * lavoro terminato
 * numero di telefono
 * ha come contatto *
 */

#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include <ostream>

#include <QString>
#include <QDate>
#include <QDebug>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMap>

#include "utenteBusiness.h"

class UtenteExecutive : public UtenteBusiness
{
protected:
public:
    explicit UtenteExecutive(InfoPersonali &);
    explicit UtenteExecutive(const Email & =Email(), const QString & =QString(), const QString & =QString());
    UtenteExecutive(const UtenteExecutive &);
    virtual ~UtenteExecutive();
    virtual QString toString() const;
    static QString tipo;
    virtual QString getTipo() const;

};
std::ostream & operator<<(std::ostream &, const UtenteExecutive &);
QDebug operator<<(const QDebug &, const UtenteExecutive &);

#endif // UTENTEEXECUTIVE_H
