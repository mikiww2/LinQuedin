
#ifndef UTENTE_H
#define UTENTE_H

#include <ostream>

#include <QString>
#include <QList>
#include <QXmlStreamAttribute>
#include <QRegExp>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QMap>

#include "email.h"
#include "infoPersonali.h"
#include "pointerUtente.h"

class PointerUtente;

class Utente
{
private:
    InfoPersonali *informazioni;
    QMap<Email, PointerUtente *> contatti;
    bool hideInfo;

protected:
    explicit Utente(InfoPersonali &);//costruttore utilizzabile sono dalle classi derivate,cioè i tipi di utente

public:
    explicit Utente(const Email &, const QString &, const QString &);
    Utente(const Utente &);
    virtual ~Utente();
    virtual void swap(Utente &); //scambia i puntatori
    void hideInformation();
    void showInformation();
    bool isHide() const;
    const Email & getUsername() const;
    InfoPersonali & getInformazioni() const;
    const QMap<Email, PointerUtente *> & getContatti()const;
    bool haveContatto(const Email &) const;
    bool aggiungiContatto(PointerUtente &);
    void rimuoviContatto(const Email &);
    void rimuoviContatto(PointerUtente &);
    virtual bool isValid() const;
    virtual bool isEmpty() const;
    virtual bool operator==(const Utente &) const;
    virtual bool operator!=(const Utente &) const;
    virtual bool operator<(const Utente &) const;
    virtual bool operator>(const Utente &) const;
    virtual QString toString() const;
    virtual QString getTipo() const =0;

};

#endif // UTENTE_H
