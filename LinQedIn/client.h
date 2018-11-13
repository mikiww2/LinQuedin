// client.h

#ifndef CLIENT_H
#define CLIENT_H

/*
 * LinkedIn lato utente
 * 1. Aggiornamento del proprio profilo.
 * 2. Inserimento di un nuovo contatto nella propria rete.
 * 3. Rimozione di un contatto dalla propria rete.
 * 4. Funzionalità di ricerca sul DB LinkedIn, come autorizzate dalla propria tipologia di account.
*/

#include "pointerUtente.h"
#include "database.h"

class Client
{
private:
    PointerUtente &ut;
    Database &db;

public:
    explicit Client(PointerUtente &, Database &);

    PointerUtente & getUtente() const;
    Database & getDb() const;

    bool addContatto(PointerUtente &);
    void removeContatto(PointerUtente &);

};

#endif // CLIENT_H
