
#include "ricercaUtenteBusiness.h"

QMap<Email, PointerUtente *> * RicercaUtenteBusiness::findWithResidenza(const Email &user, Database &db, const QString &res, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getUsername() != user && (**it)->getInformazioni().getResidenza() ==  res)
                result->insert((**it)->getUsername(),it.value());
    }
    return result;
}

QMap<Email, PointerUtente *> * RicercaUtenteBusiness::findWithDataNascita(const Email &user, Database &db, const QDate &dat, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getUsername() != user && (**it)->getInformazioni().getDataNascita() ==  dat)
                result->insert((**it)->getUsername(),it.value());
    }
    return result;
}

QMap<Email, PointerUtente *> * RicercaUtenteBusiness::findWithLuogoNascita(const Email &user, Database &db, const QString &luo, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getUsername() != user && (**it)->getInformazioni().getLuogoNascita() ==  luo)
                result->insert((**it)->getUsername(),it.value());
    }
    return result;
}

QMap<Email, PointerUtente *> * RicercaUtenteBusiness::findWithSesso(const Email &user, Database &db, const QString &ses, QMap<Email, PointerUtente *> *result) {
    if(!result)
        result = new QMap<Email, PointerUtente *>;
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getUsername() != user && (**it)->getInformazioni().getSesso() ==  ses)
                result->insert((**it)->getUsername(),it.value());
    }
    return result;
}
