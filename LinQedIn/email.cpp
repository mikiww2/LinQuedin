
#include "email.h"

//test patternMatching.isValid() deve dare true
QString Email::pattern = "\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b";

//costruttore di Email con una stringa, viene scritta in minuscolo
Email::Email(const QString &string) : stringa(string)
{
    stringa.toLower();
    qDebug() << "creata email";
}

bool Email::isEmpty() const { return stringa.isEmpty(); }

bool Email::isValid() const { //valida se soddisfa il pattern
    if(stringa.isEmpty()) return false;

    QRegExp patternMatching(pattern, Qt::CaseInsensitive);
    return patternMatching.exactMatch(stringa);
}

void Email::setEmail(const QString &string) { //cambia l'email solo se soddisfa il pattern
    if(!string.isEmpty()) {
        QRegExp patternMatching(pattern, Qt::CaseInsensitive);
        if(patternMatching.exactMatch(string)) {
            stringa = string;
            qDebug() << "email modificata";
        }
    }
}

const QString & Email::getEmailString() const { return stringa; }

bool Email::operator==(const Email &email) const {
    return stringa == email.stringa;
}

bool Email::operator!=(const Email &email) const {
    return stringa != email.stringa;
}

bool Email::operator<(const Email &email) const {
    return stringa < email.stringa;
}

bool Email::operator>(const Email &email) const {
    return stringa > email.stringa;
}

std::ostream & operator<<(std::ostream &os, const Email &email) {
    if(email.isEmpty())
        return os << "Email vuota\n";
    os << "Email : " << email.getEmailString().toStdString();
    if(!email.isValid()) os << " invalid";
    return os << "\n";
}

QDebug operator<<(const QDebug &dbg, const Email &email) {
    if(email.isValid())
        return dbg << "email valida: " << email.getEmailString();
    return dbg << "email non valida: " << email.getEmailString();
}

uint qHash (const Email &email){
    return qHash(email.getEmailString()); //richiama qHash da QString
}
