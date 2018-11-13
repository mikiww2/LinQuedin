#ifndef RICERCAUTENTEEXECUTIVE_H
#define RICERCAUTENTEEXECUTIVE_H

#include "ricercaUtenteBusiness.h"
#include "pointerUtente.h"

class RicercaUtenteExecutive : public RicercaUtenteBusiness
{
public:
    static QMap<Email, PointerUtente *> * findWithLavorato(const Email &, Database &, const QString &, QMap<Email, PointerUtente *> * =0);
    static QMap<Email, PointerUtente *> * findWithStudiato(const Email &, Database &, const QString &, QMap<Email, PointerUtente *> * =0);
    static QMap<Email, PointerUtente *> * findWithNumeroTelefono(const Email &, Database &, const NumeroTelefonico &, QMap<Email, PointerUtente *> * =0);
    static QMap<Email, PointerUtente *> * findWithContatto (const Email &, Database &, const Email &, QMap<Email, PointerUtente *> * =0);
};

#endif // RICERCAUTENTEEXECUTIVE_H
