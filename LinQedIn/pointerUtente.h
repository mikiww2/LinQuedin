// pointerUtente.h

#ifndef POINTERUTENTE_H
#define POINTERUTENTE_H

// classe che semplifica il salvataggio dei vari tipi di utente mettendosi in mezzo

#include <QDebug>

#include "utente.h"

class Utente;

class PointerUtente
{
private:
    Utente *utente;
    int in; // persone che ti hanno nella loro rete
    int out; // persone che hai nella rete

public:
    explicit PointerUtente(Utente &);
    ~PointerUtente();
    int getEntranti() const;
    int getUscenti() const;
    void addEntrante();
    void removeEntrante();
    void addUscente();
    void removeUscente();
    void sostituisci(Utente &);
    Utente * operator->() const;
    Utente & operator*() const;
};

#endif // POINTERUTENTE_H
