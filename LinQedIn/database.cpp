
#include "database.h"

Database::Database()
{ }

Database::~Database() {
    db.clear();
}

bool Database::isEmpty() const {
    return db.isEmpty();
}

void Database::addUtente(PointerUtente &punt) { //controlli già eseguiti : utente valido non presente nel db
    db.insert(punt->getUsername(),&punt);
    qDebug() << "inserito utente";
}

bool Database::hasUtente(const Email &username) const {
    return db.contains(username);
}

PointerUtente * Database::takeUtente(const Email &username) {
    PointerUtente * punt = db.take(username);
    if(!punt)
        qDebug() << "utente non trovato ";
    else
        qDebug() << "utente estratto e ritornato ";
    return punt;
}

PointerUtente * Database::utente(const Email &username) const {
    QMap<Email, PointerUtente *>::const_iterator it = db.constFind(username);
    if (it == db.end())
        return 0;
    return *it;
}

bool Database::removeUtente(const Email &username) {
    int aux = db.remove(username);
    if(!aux)
        qDebug() << "non ho trovato l\'utente" << username;
    else
        qDebug() << "rimosso l\'utente" << username;
    return aux;
}

QMap<Email, PointerUtente *>::const_iterator Database::getCIFirst() const {
    return db.cbegin();
}

QMap<Email, PointerUtente *>::const_iterator Database::getCIEnd() const {
    return db.cend();
}

bool Database::load(const QString &linkDbXml) {
    if(!QFile::exists(linkDbXml)) {
        qDebug() << "database non trovato, impossibile caricarlo";
        return false;
    }
    QFile file(linkDbXml);
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader xmlReader(&file);
    xmlReader.setNamespaceProcessing(false); //tolgo il namespace
    xmlReader.readNextStartElement();
    if(xmlReader.name() == "database") {
        while(!(xmlReader.name() == "database" && xmlReader.tokenType() == QXmlStreamReader::EndElement)) {
            if(xmlReader.name()=="utenti" && xmlReader.tokenType() == QXmlStreamReader::StartElement) {
                while(!(xmlReader.name()=="utenti" && xmlReader.tokenType() == QXmlStreamReader::EndElement)) {
                    Utente *utente = 0;
                    QString tipo, hide;
                    InfoPersonali *info = 0;
                    while(!(xmlReader.name()=="utente" && xmlReader.tokenType() == QXmlStreamReader::EndElement)) {
                        if(xmlReader.name()=="utente" && xmlReader.tokenType() == QXmlStreamReader::StartElement) {
                            tipo = xmlReader.attributes().value("tipo").toString();
                            hide = xmlReader.attributes().value("hide").toString();
                        }
                        if(xmlReader.name()=="infopersonali" && xmlReader.tokenType() == QXmlStreamReader::StartElement) {
                            Email email;
                            QString nome, cognome, residenza, luogonascita, sesso, titolodistudio, lavoro;
                            NumeroTelefonico numerotelefonico;
                            QDate datanascita;
                            while(!(xmlReader.name() == "infopersonali" && xmlReader.tokenType() == QXmlStreamReader::EndElement)) {
                                if(xmlReader.name() == "email") {
                                    email = Email(xmlReader.readElementText());
                                }
                                if(xmlReader.name() == "nome") {
                                    nome = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "cognome") {
                                    cognome = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "residenza") {
                                    residenza = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "luogonascita") {
                                    luogonascita = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "sesso") {
                                    sesso = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "numerotelefonico") {
                                    numerotelefonico = NumeroTelefonico(xmlReader.readElementText());
                                }
                                if(xmlReader.name() == "datanascita") {
                                    datanascita = QDate::fromString(xmlReader.readElementText(),"dd MM yyyy");
                                }
                                if(xmlReader.name() == "lavoro") {
                                    lavoro = xmlReader.readElementText();
                                }
                                if(xmlReader.name() == "titolodistudio") {
                                    titolodistudio = xmlReader.readElementText();
                                }
                                xmlReader.readNextStartElement();
                            }
                            if(email.isValid() && !nome.isEmpty() && !cognome.isEmpty()) {
                                info = new InfoPersonali(email, nome, cognome);
                                if(!residenza.isEmpty())
                                    info->setResidenza(residenza);
                                if(!luogonascita.isEmpty())
                                    info->setLuogoNascita(luogonascita);
                                if(!sesso.isEmpty())
                                    info->setSesso(sesso);
                                if(numerotelefonico.isValid())
                                    info->setNumeroTelefono(numerotelefonico);
                                if(datanascita.isValid())
                                    info->setDataNascita(datanascita);
                                if(!lavoro.isEmpty())
                                    info->setLavoro(lavoro);
                                if(!titolodistudio.isEmpty())
                                    info->setTitoloDiStudio(titolodistudio);
                            }
                            else {
                                qDebug() << "infopersonali non valide, non le carico";
                            }
                        }
                        xmlReader.readNextStartElement();
                    }
                    if(tipo != UtenteBasic::tipo && tipo != UtenteBusiness::tipo && tipo != UtenteExecutive::tipo) {
                        qDebug() << "tipo utente non riconosciuto, lo salto";
                        delete info;
                    }
                    if(info && tipo == UtenteBasic::tipo)
                        utente = new UtenteBasic(*info);
                    if(info && tipo == UtenteBusiness::tipo)
                        utente = new UtenteBusiness(*info);
                    if(info && tipo == UtenteExecutive::tipo)
                        utente = new UtenteExecutive(*info);
                    if(utente) {
                        if(hide == "true")
                            utente->hideInformation();
                    }
                    if(db.contains(utente->getUsername())) {
                        qDebug() << "utente già presente nel database, lo salto";
                        delete utente;
                    }
                    else {
                        PointerUtente *punt = new PointerUtente(*utente);
                        addUtente(*punt);
                    }
                    xmlReader.readNextStartElement();
                }
            }
            if(xmlReader.name()=="rete" && xmlReader.tokenType() == QXmlStreamReader::StartElement) {
                xmlReader.readNextStartElement();
                while(!(xmlReader.name() == "rete" && xmlReader.tokenType() == QXmlStreamReader::EndElement)) {
                    if(xmlReader.name() == "contatto") {
                        QStringList coppia = xmlReader.readElementText().split(" ");
                        PointerUtente *puntA = utente(Email(coppia.at(0)));
                        PointerUtente *puntB = utente(Email(coppia.at(1)));

                        if(!puntA || !puntB)
                            qDebug() << "inserimento contatto non riuscito, lo salto"<< Email(coppia.at(0)) <<Email(coppia.at(1));
                        else
                            (*puntA)->aggiungiContatto(*puntB);
                    }
                    xmlReader.readNextStartElement();
                }
            }
            xmlReader.readNextStartElement();
        }
    }
    else {
        qDebug() << "database non trovato";
        return false;
    }
    return true;
}

bool Database::save(const QString &linkDbXml) const {
    if(db.isEmpty()) {
        qDebug() << "database vuoto, nulla da scrivere";
        return false;
    }
    if(QFile::exists(linkDbXml)) {
        qDebug() << "database trovato, viene sovrascritto";
    }
    QFile file(linkDbXml);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("database"); // <database>
    xmlWriter.writeStartElement("utenti"); // <utenti>

    for(QMap<Email,PointerUtente *>::const_iterator it = db.begin(); it != db.end(); ++it) {
        PointerUtente *utente = *it;
        if(utente && (*utente)->isValid()) {
            xmlWriter.writeStartElement("utente"); // <utente>
            xmlWriter.writeAttribute("tipo", (*utente)->getTipo());
            if((*utente)->isHide())
                xmlWriter.writeAttribute("hide", "true");
            else
                xmlWriter.writeAttribute("hide", "false");
            InfoPersonali &info = (*utente)->getInformazioni();
            xmlWriter.writeStartElement("infopersonali"); // <infopersonali>
            xmlWriter.writeTextElement("email", info.getEmail().getEmailString()); // <email/>
            xmlWriter.writeTextElement("nome", info.getNome()); // <nome/>
            xmlWriter.writeTextElement("cognome", info.getCognome()); // <cognome/>
            if(!info.getResidenza().isEmpty())
                xmlWriter.writeTextElement("residenza", info.getResidenza()); // <residenza/>
            if(!info.getLuogoNascita().isEmpty())
                xmlWriter.writeTextElement("luogonascita", info.getLuogoNascita()); // <luogonascita/>
            if(!info.getSesso().isEmpty())
                xmlWriter.writeTextElement("sesso", info.getSesso()); // <sesso/>
            if(info.getNumeroTelefono().isValid())
                xmlWriter.writeTextElement("numerotelefonico", info.getNumeroTelefono().getNumeroTelefonico()); // <numerotelefonico/>
            if(info.getDataNascita().isValid())
                xmlWriter.writeTextElement("datanascita", info.getDataNascita().toString("dd MM yyyy")); // <datanascita/>
            if(!info.getLavoro().isEmpty())
                xmlWriter.writeTextElement("lavoro", info.getLavoro()); // <lavoro/>
            if(!info.getTitoloDiStudio().isEmpty())
                xmlWriter.writeTextElement("titolodistudio", info.getTitoloDiStudio()); // <titolodistudio/>
            xmlWriter.writeEndElement(); // </infopersonali>
            xmlWriter.writeEndElement(); // </utente>
        }
        else
            qDebug() << "trovato utente non valido, lo salto";
    }
    xmlWriter.writeEndElement(); // </utenti>
    xmlWriter.writeStartElement("rete"); // <rete>

    for(QMap<Email,PointerUtente *>::const_iterator it = db.begin(); it != db.end(); ++it) {
        PointerUtente *utente = *it;
        if(utente && !(*utente)->getContatti().isEmpty()) {
            for(QMap<Email,PointerUtente *>::const_iterator itC = (*utente)->getContatti().constBegin(); itC != (*utente)->getContatti().constEnd(); ++itC) {
              QString string;
              string.append((*utente)->getUsername().getEmailString());
              string.append(" ");
              string.append(itC.key().getEmailString());
              xmlWriter.writeTextElement("contatto", string); // <contatto/>
            }
        }
        else
            qDebug() << "nessun contatto dell'utente da salvare, lo salto";
    }
    xmlWriter.writeEndDocument();// </rete></database>
    file.flush();
    qDebug() << "database salvato correttamente";
    return true;
}
