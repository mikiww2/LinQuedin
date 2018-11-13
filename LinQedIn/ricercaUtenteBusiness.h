#ifndef RICERCAUTENTEBUSINESS_H
#define RICERCAUTENTEBUSINESS_H

#include "infoPersonali.h"
#include "ricercaUtenteBasic.h"

class Database;

class RicercaUtenteBusiness : public RicercaUtenteBasic
{
public:
    static QMap<Email,PointerUtente *> * findWithResidenza(const Email &, Database &, const QString &, QMap<Email,PointerUtente *> * =0);
    static QMap<Email,PointerUtente *> * findWithDataNascita(const Email &, Database &, const QDate &, QMap<Email,PointerUtente *> * =0);
    static QMap<Email,PointerUtente *> * findWithLuogoNascita(const Email &, Database &, const QString &, QMap<Email,PointerUtente *> * =0);
    static QMap<Email,PointerUtente *> * findWithSesso(const Email &, Database &, const QString &, QMap<Email,PointerUtente *> * =0);
};

#endif // RICERCAUTENTEBUSINESS_H
