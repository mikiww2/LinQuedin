
#include "ricercaUtenteExecutive.h"


QMap<Email, PointerUtente *> * RicercaUtenteExecutive::findWithLavorato(const Email &user, Database &db, const QString &luoLav, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getUsername() != user) {
            if((**it)->getInformazioni().getLavoro() == luoLav)
                result->insert((**it)->getUsername(),it.value());
        }
    }
    return result;
}

QMap<Email, PointerUtente *> * RicercaUtenteExecutive::findWithStudiato(const Email &user, Database &db, const QString &luoStu, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getUsername() != user) {
            if((**it)->getInformazioni().getTitoloDiStudio() == luoStu)
                result->insert((**it)->getUsername(),it.value());
        }
    }
    return result;
}

QMap<Email, PointerUtente *> * RicercaUtenteExecutive::findWithNumeroTelefono(const Email &user, Database &db, const NumeroTelefonico &num, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    bool find = false;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd() && !find; it++) {
        if((**it)->getUsername() != user && (**it)->getInformazioni().getNumeroTelefono() ==  num) {
                result->insert((**it)->getUsername(),it.value());
                find = true;
        }
    }
    return result;
}

QMap<Email, PointerUtente *> * RicercaUtenteExecutive::findWithContatto (const Email &user, Database &db, const Email &contatto, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); it++) {
        if((**it)->getUsername() != user && (**it)->haveContatto(contatto))
            result->insert((**it)->getUsername(),it.value());
    }
    return result;
}
