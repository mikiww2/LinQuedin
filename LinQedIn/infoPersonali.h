// infoPersonali.h

#ifndef INFOPERSONALI_H
#define INFOPERSONALI_H

//classe delle informazioni personali dell'utente

#include <ostream>

#include <QString>
#include <QDate>
#include <QDebug>

#include "email.h"
#include "numeroTelefonico.h"

class InfoPersonali
{
private:
    Email email;
    QString nome, cognome, residenza, sesso, luogoNascita, lavoro, titoloDiStudio;
    NumeroTelefonico numeroTelefono;
    QDate dataNascita;

public:
    explicit InfoPersonali(const Email & =Email(), const QString & =QString(), const QString & =QString());
    void setNome(const QString &);
    void setCognome(const QString &);
    void setNumeroTelefono(const NumeroTelefonico &);
    void setDataNascita(const QDate &);
    void setSesso(const QString &);
    void setLuogoNascita(const QString &);
    void setResidenza(const QString &);
    void setLavoro(const QString &);
    void setTitoloDiStudio(const QString &);
    const Email & getEmail() const;
    const QString & getNome() const;
    const QString & getCognome() const;
    const NumeroTelefonico & getNumeroTelefono() const;
    const QDate & getDataNascita() const;
    QString getDataNascitaQString() const;
    const QString & getSesso() const;
    const QString & getLuogoNascita() const;
    const QString & getResidenza() const;
    const QString & getLavoro() const;
    const QString & getTitoloDiStudio() const;
    bool isValid() const;
    bool isEmpty() const;
    QString toString() const;
};
std::ostream & operator<<(std::ostream &, const InfoPersonali &);
QDebug operator<<(const QDebug &, const InfoPersonali &);

#endif // INFOPERSONALI_H
