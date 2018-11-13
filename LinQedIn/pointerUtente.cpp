
#include "pointerUtente.h"

PointerUtente::PointerUtente(Utente &ut) : utente(&ut), in(0),
    out(0) { }

PointerUtente::~PointerUtente() {
    delete utente;
}

int PointerUtente::getEntranti() const {
    return in;
}

int PointerUtente::getUscenti() const {
    return out;
}

void PointerUtente::addEntrante() {
    in++;
}

void PointerUtente::removeEntrante() {
    in--;
}

void PointerUtente::addUscente() {
    out++;
}

void PointerUtente::removeUscente() {
    out--;
}

void PointerUtente::sostituisci(Utente &ut) {
    utente->swap(ut);
    delete utente;
    utente = &ut;
}

Utente * PointerUtente::operator->() const {
    return utente;
}

Utente & PointerUtente::operator*() const {
    return *utente;
}
