#ifndef RICERCAUTENTEBASIC_H
#define RICERCAUTENTEBASIC_H



#include <QMap>

#include "utenteBasic.h"
#include "infoPersonali.h"
#include "database.h"


class PointerUtente;


class RicercaUtenteBasic
{
public:
    static QMap<Email,PointerUtente *> * findWithUsername(Database &, const Email &, QMap<Email,PointerUtente *> * =0);
    static QMap<Email,PointerUtente *> * findWithNomeCognome(const Email &, Database &, const QString &, const QString &, QMap<Email,PointerUtente *> * =0);
};

#endif // RICERCAUTENTEBASIC_H
