// database.h

#ifndef DATABASE_H
#define DATABASE_H

// classe che implementa il database di pointerUtente

#include <QString>
#include <QDebug>
#include <QXmlStreamAttribute>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QMap>
#include <QList>

#include "email.h"
#include "utenteBasic.h"
#include "utenteBusiness.h"
#include "utenteExecutive.h"
#include "pointerUtente.h"

class PointerUtente;

class Database
{
private:
    QMap<Email,PointerUtente *> db;

public:
    explicit Database();
    ~Database();
    bool isEmpty() const;
    void addUtente(PointerUtente &);
    bool hasUtente(const Email &) const;
    PointerUtente * takeUtente(const Email &);
    PointerUtente * utente(const Email &) const;
    bool removeUtente(const Email &);
    QMap<Email,PointerUtente *>::const_iterator getCIFirst() const;
    QMap<Email,PointerUtente *>::const_iterator getCIEnd() const;
    bool load(const QString &);
    bool save(const QString &) const;
};

#endif // DATABASE_H
