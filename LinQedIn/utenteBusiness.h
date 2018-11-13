//utenteBusiness.h

#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

//Utente con permessi di ricerca:
/*
 * quelli di basic +
 * residenza
 * data nascita
 * luogo nascita
 * sesso
 */

#include <ostream>

#include <QString>
#include <QDate>
#include <QDebug>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "utenteBasic.h"

class UtenteBusiness : public UtenteBasic
{
protected:

public:
    explicit UtenteBusiness(InfoPersonali &);
    explicit UtenteBusiness(const Email & =Email(), const QString & =QString(), const QString & =QString());
    UtenteBusiness(const UtenteBusiness &);
    virtual ~UtenteBusiness();
    virtual QString toString() const;
    static QString tipo;
    virtual QString getTipo() const;

};
std::ostream & operator<<(std::ostream &, const UtenteBusiness &);
QDebug operator<<(const QDebug &, const UtenteBusiness &);

#endif // UTENTEBUSINESS_H
