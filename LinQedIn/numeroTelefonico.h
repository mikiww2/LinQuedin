//numeroTelefonico.h

#ifndef NUMEROTELEFONICO_H
#define NUMEROTELEFONICO_H

//classe che implementa un numero telefonico, controllo con un pattern

#include <ostream>

#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

class NumeroTelefonico
{
private:
    QString suffisso;

public:
    explicit NumeroTelefonico(const QString & ="0000000000");
    static QString patternSuffisso;
    bool isValid() const;
    QString getNumeroTelefonico() const;
    void changeNumeroTelefonico(const NumeroTelefonico &);
    bool operator==(const NumeroTelefonico &) const;
    bool operator!=(const NumeroTelefonico &) const;
    bool isEmpty() const;
};
std::ostream & operator<<(std::ostream &, const NumeroTelefonico &);
QDebug operator<<(const QDebug &, const NumeroTelefonico &);

#endif // NUMEROTELEFONICO_H
