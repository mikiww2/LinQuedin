
#include "admin.h"

Admin::Admin(Database &database) : db(database)
{ }

Database & Admin::getDatabase() const {
    return db;
}

bool Admin::checkTypeUtente(const QString &type){
    if(type != UtenteBasic::tipo
            && type != UtenteBusiness::tipo
            && type != UtenteExecutive::tipo)
        return false;
    return true;
}

bool Admin::loadDatabase(const QString &file) {
    return db.load(file);
}

bool Admin::writeDatabase(const QString &file) const {
    return db.save(file);
}

bool Admin::cambiaTypeUtente(PointerUtente &punt, const QString &newType) {
    if(!checkTypeUtente(newType)) {
        qDebug() << "tipo utente non riconosciuto, non posso cambiarlo";
        return false;
    }
    if(punt->getTipo() == newType) {
        qDebug() << "utente è già dello stesso tipo";
        return true;
    }
    Utente * ut = 0;
    if(newType == UtenteBasic::tipo)
        ut = new UtenteBasic();
    if(newType == UtenteBusiness::tipo)
        ut = new UtenteBusiness();
    if(newType == UtenteExecutive::tipo)
        ut = new UtenteExecutive();
    if(!ut) {
        qDebug() << "tipo di utente non identificato";
        return false;
    }
    punt.sostituisci(*ut); // ci pensa sostituisci ad eliminare il vecchio utente
    qDebug() << "tipo di utente cambiato con successo";
    return true;
}

bool Admin::rimuoviUtente(const Email &username) {
    return db.removeUtente(username);
}

PointerUtente * Admin::cercaUtente(const QString &nom, const QString &cogn) const {
    //trovare un bel modo per cercare, tipo un iteratore forse
    if(nom.isEmpty() || cogn.isEmpty()) {
        qDebug() << "nome o cognome vuoto, impossibile cercare";
        return 0;
    }
    for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
        if((**it)->getInformazioni().getNome() ==  nom && (**it)->getInformazioni().getCognome() ==  cogn)
            return (*it);
        }
    qDebug() << "utente non trovato";
    return 0;
}

PointerUtente * Admin::cercaUtente(const Email &ema) const {
    return db.utente(ema);
}

void Admin::creaUtente (const QString &nom, const QString &cogn, const Email &ema, const QString &tip) { // non blocca se il tipo è lo stesso
    if(!ema.isValid()) {
        qDebug() << "email non valida";
        return;
    }
    if(nom.isEmpty() || cogn.isEmpty()) {
        qDebug() << "nome o cognome vuoti";
        return ;
    }
    if(db.hasUtente(ema)) {
        qDebug() << "username già presente";
        return;
    }
    if(!checkTypeUtente(tip)) {
        qDebug() << "tipo non riconosciuto";
        return;
    }
    Utente *ut = 0;
    if(tip == UtenteBasic::tipo) {
        qDebug() << "tipo utente" << UtenteBasic::tipo;
        ut = new UtenteBasic(ema,nom,cogn);
    }
    if(tip == UtenteBusiness::tipo) {
        qDebug() << "tipo utente" << UtenteBusiness::tipo;
        ut = new UtenteBusiness(ema,nom,cogn);
    }
    if(tip == UtenteExecutive::tipo) {
        qDebug() << "tipo utente" << UtenteExecutive::tipo;
        ut = new UtenteExecutive(ema,nom,cogn);
    }
    PointerUtente *punt = new PointerUtente(*ut);
    db.addUtente(*punt);
    qDebug() << "inserito utente";
}
