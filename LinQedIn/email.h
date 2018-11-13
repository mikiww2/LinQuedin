// email.h

#ifndef EMAIL_H
#define EMAIL_H

//classe che implementa l'email, fornendo un controllo del pattern

#include <ostream>

#include <QString>
#include <QHash> //per poter inizializzare qHash, da problemi con lo smartP
#include <QRegExp> //per pattern
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

class Email
{
private:
    QString stringa;
    
public:
    static QString pattern;
    explicit Email(const QString & =QString());
    bool isEmpty() const;
    bool isValid() const;
    void setEmail(const QString &);
    const QString & getEmailString() const;
    bool operator==(const Email &) const;
    bool operator!=(const Email &) const;
    bool operator<(const Email &) const;
    bool operator>(const Email &) const;
};
std::ostream & operator<<(std::ostream &, const Email &);
QDebug operator<<(const QDebug &, const Email &);

uint qHash (const Email &); //richiesta da QHash, non credo serva

#endif // EMAIL_H
