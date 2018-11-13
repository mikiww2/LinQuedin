#ifndef ADMIN_H
#define ADMIN_H

/*
 * LinkedIn lato amministratore
 * 1. Inserimento nel DB di un nuovo utente LinkedIn:
    i dati per l’inserimento saranno nome, cognome, l’email, tipologia di account.
 * 2. Ricerca nel DB di un utente mediante nome/cognome o codice utente.
 * 3. Rimozione dal DB di un utente LinkedIn.
 * 4. Cambio di tipologia di account (Basic, Business, Executive) per un utente LinkedIn.
 * 5. Salvataggio/lettura su file del DB degli utenti LinkedIn.
 * e altro
*/

#include "database.h"
#include "utenteBasic.h"
#include "utenteBusiness.h"
#include "utenteExecutive.h"
#include "pointerUtente.h"

class Admin
{
private:
    Database &db;
    static QString getTypeUtente (PointerUtente &);
    static bool checkTypeUtente(const QString &);

public:
    explicit Admin(Database &);
    Database & getDatabase() const;
    bool loadDatabase(const QString & ="database.xml");
    bool writeDatabase(const QString & ="database.xml") const;
    bool cambiaTypeUtente(PointerUtente &, const QString &);
    bool rimuoviUtente(const Email &);
    PointerUtente * cercaUtente(const QString &, const QString &) const;
    PointerUtente * cercaUtente(const Email &) const;
    void creaUtente(const QString &, const QString &, const Email &, const QString &);
};

#endif // ADMIN_H
