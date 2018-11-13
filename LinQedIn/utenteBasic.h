// utenteBasic.h

#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

//Utente con permessi di ricerca:
/*
 * email
 * nome
 * cognome
 */

#include <ostream>


#include <QString>
#include <QDebug>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "utente.h"

class UtenteBasic : public Utente
{
protected:

public:
    explicit UtenteBasic(InfoPersonali &);
    explicit UtenteBasic(const Email & =Email(), const QString & =QString(), const QString & =QString());
    UtenteBasic(const UtenteBasic &);
    virtual ~UtenteBasic();
    virtual QString toString() const;
    static QString tipo;
    virtual QString getTipo() const;
};
std::ostream & operator<<(std::ostream &, const UtenteBasic &);
QDebug operator<<(const QDebug &, const UtenteBasic &);
#endif // UTENTEBASIC_H
