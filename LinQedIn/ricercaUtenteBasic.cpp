
#include "ricercaUtenteBasic.h"

QMap<Email, PointerUtente *> * RicercaUtenteBasic::findWithUsername(Database &db, const Email &ema, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    PointerUtente *ut = db.utente(ema);
    if(ut)
        result->insert(ema,ut);
    return result;
}

QMap<Email, PointerUtente *> * RicercaUtenteBasic::findWithNomeCognome(const Email &user, Database &db, const QString &nom, const QString &cogn, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getUsername() != user) {
            if(nom.isEmpty() && (**it)->getInformazioni().getNome() ==  nom)
                result->insert((**it)->getUsername(),it.value());
            if(cogn.isEmpty() && (**it)->getInformazioni().getCognome() ==  cogn)
                result->insert((**it)->getUsername(),it.value());
        }
    }
    return result;
}
