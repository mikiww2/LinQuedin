
#include "client.h"


Client::Client(PointerUtente &utente, Database &database) :
    ut(utente), db(database)
{ }

PointerUtente & Client::getUtente() const { return ut; }

Database & Client::getDb() const { return db; }

bool Client::addContatto(PointerUtente &ut) {
    return ut->aggiungiContatto(ut);
}

void Client::removeContatto(PointerUtente &ut) {
    ut->rimuoviContatto(ut);
}
