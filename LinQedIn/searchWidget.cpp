
#include "searchWidget.h"

SearchWidget::SearchWidget(PointerUtente &ut, Database &database, QWidget *parent) :
    QWidget(parent), utente(ut), db(database), risultatiWidget(0)
{
    if(utente->getTipo() == UtenteBasic::tipo) {
        cercaUsernameBool = true;
        cercaNomeCognomeBool = true;
        cercaResidenzaBool = false;
        cercaDataNascitaBool = false;
        cercaLuogoNascitaBool = false;
        cercaSessoBool = false;
        cercaLavoratoBool = false;
        cercaStudiatoBool = false;
        cercaNumeroTelefonicoBool = false;
        cercaConContattoBool = false;
    }
    if(utente->getTipo() == UtenteBusiness::tipo) {
        cercaUsernameBool = true;
        cercaNomeCognomeBool = true;
        cercaResidenzaBool = true;
        cercaDataNascitaBool = true;
        cercaLuogoNascitaBool = true;
        cercaSessoBool = true;
        cercaLavoratoBool = false;
        cercaStudiatoBool = false;
        cercaNumeroTelefonicoBool = false;
        cercaConContattoBool = false;
    }
    if(utente->getTipo() == UtenteExecutive::tipo) {
        cercaUsernameBool = true;
        cercaNomeCognomeBool = true;
        cercaResidenzaBool = true;
        cercaDataNascitaBool = true;
        cercaLuogoNascitaBool = true;
        cercaSessoBool = true;
        cercaLavoratoBool = true;
        cercaStudiatoBool = true;
        cercaNumeroTelefonicoBool = true;
        cercaConContattoBool = true;
    }

    ricercaWidget = new QWidget(this);
    risultatiLabel = new QLabel(tr("RISULTATI"), this);
    noRisultatiLabel = new QLabel(tr("nessun risultato"),this);
    risultatiScroll = new QScrollArea(this);
    cercaButton = new QPushButton(tr("cerca"), this);
    lay = new QVBoxLayout(this);
    ricercaLay = new QVBoxLayout(this);
    ricercaScroll = new QScrollArea(this);

    if(cercaUsernameBool) {
        cercaUsernameWidget = new QWidget(this);
        cercaUsernameBox = new QCheckBox(tr("cerca username"), this);
        emailEdit = new QLineEdit(this);
        cercaUsernameLayout = new QHBoxLayout(this);
        connect(cercaUsernameBox, SIGNAL(clicked(bool)), this, SLOT(cercaUsernamePressed(bool)));
        cercaUsernameLayout->addWidget(cercaUsernameBox);
        cercaUsernameLayout->addWidget(emailEdit);
        cercaUsernameWidget->setLayout(cercaUsernameLayout);
        ricercaLay->addWidget(cercaUsernameWidget);
        cercaUsernamePressed(false);
    }
    if(cercaNomeCognomeBool) {
        cercaNomeCognomeWidget = new QWidget(this);
        cercaNomeCognomeBox = new QCheckBox(tr("cerca nome e cognome"), this);
        nomeEdit = new QLineEdit(this);
        cognomeEdit = new QLineEdit(this);
        cercaNomeCognomeLayout = new QHBoxLayout(this);
        connect(cercaNomeCognomeBox, SIGNAL(clicked(bool)), this, SLOT(cercaNomeCognomePressed(bool)));
        cercaNomeCognomeLayout->addWidget(cercaNomeCognomeBox);
        cercaNomeCognomeLayout->addWidget(nomeEdit);
        cercaNomeCognomeLayout->addWidget(cognomeEdit);
        cercaNomeCognomeWidget->setLayout(cercaNomeCognomeLayout);
        ricercaLay->addWidget(cercaNomeCognomeWidget);
        cercaNomeCognomePressed(false);
    }
    if(cercaResidenzaBool) {
        cercaResidenzaWidget = new QWidget(this);
        cercaResidenzaBox = new QCheckBox(tr("cerca residenza"), this);
        residenzaEdit = new QLineEdit(this);
        cercaResidenzaLayout = new QHBoxLayout(this);
        connect(cercaResidenzaBox, SIGNAL(clicked(bool)), this, SLOT(cercaResidenzaPressed(bool)));
        cercaResidenzaLayout->addWidget(cercaResidenzaBox);
        cercaResidenzaLayout->addWidget(residenzaEdit);
        cercaResidenzaWidget->setLayout(cercaResidenzaLayout);
        ricercaLay->addWidget(cercaResidenzaWidget);
        cercaResidenzaPressed(false);
    }
    if(cercaDataNascitaBool) {
        cercaDataNascitaWidget = new QWidget(this);
        cercaDataNascitaBox = new QCheckBox(tr("cerca data nascita"), this);
        DataNascitaEdit = new QDateEdit(this);
        cercaDataNascitaLayout = new QHBoxLayout(this);
        connect(cercaDataNascitaBox, SIGNAL(clicked(bool)), this, SLOT(cercaDataNascitaPressed(bool)));
        cercaDataNascitaLayout->addWidget(cercaDataNascitaBox);
        cercaDataNascitaLayout->addWidget(DataNascitaEdit);
        cercaDataNascitaWidget->setLayout(cercaDataNascitaLayout);
        ricercaLay->addWidget(cercaDataNascitaWidget);
        cercaDataNascitaPressed(false);
    }
    if(cercaLuogoNascitaBool) {
        cercaLuogoNascitaWidget = new QWidget(this);
        cercaLuogoNascitaBox = new QCheckBox(tr("cerca luogo nascita"), this);
        LuogoNascitaEdit = new QLineEdit(this);
        cercaLuogoNascitaLayout = new QHBoxLayout(this);
        connect(cercaLuogoNascitaBox, SIGNAL(clicked(bool)), this, SLOT(cercaLuogoNascitaPressed(bool)));
        cercaLuogoNascitaLayout->addWidget(cercaLuogoNascitaBox);
        cercaLuogoNascitaLayout->addWidget(LuogoNascitaEdit);
        cercaLuogoNascitaWidget->setLayout(cercaLuogoNascitaLayout);
        ricercaLay->addWidget(cercaLuogoNascitaWidget);
        cercaLuogoNascitaPressed(false);
    }
    if(cercaSessoBool) {
        cercaSessoWidget = new QWidget(this);
        cercaSessoBox = new QCheckBox(tr("cerca sesso"), this);
        SessoEdit = new QLineEdit(this);
        cercaSessoLayout = new QHBoxLayout(this);
        connect(cercaSessoBox, SIGNAL(clicked(bool)), this, SLOT(cercaSessoPressed(bool)));
        cercaSessoLayout->addWidget(cercaSessoBox);
        cercaSessoLayout->addWidget(SessoEdit);
        cercaSessoWidget->setLayout(cercaSessoLayout);
        ricercaLay->addWidget(cercaSessoWidget);
        cercaSessoPressed(false);
    }
    if(cercaLavoratoBool) {
        cercaLavoratoWidget = new QWidget(this);
        cercaLavoratoBox = new QCheckBox(tr("cerca luogo lavoro"), this);
        LavoratoEdit = new QLineEdit(this);
        cercaLavoratoLayout = new QHBoxLayout(this);
        connect(cercaLavoratoBox, SIGNAL(clicked(bool)), this, SLOT(cercaLavoratoPressed(bool)));
        cercaLavoratoLayout->addWidget(cercaLavoratoBox);
        cercaLavoratoLayout->addWidget(LavoratoEdit);
        cercaLavoratoWidget->setLayout(cercaLavoratoLayout);
        ricercaLay->addWidget(cercaLavoratoWidget);
        cercaLavoratoPressed(false);
    }
    if(cercaStudiatoBool) {
        cercaStudiatoWidget = new QWidget(this);
        cercaStudiatoBox = new QCheckBox(tr("cerca luogo studio"), this);
        StudiatoEdit = new QLineEdit(this);
        cercaStudiatoLayout = new QHBoxLayout(this);
        connect(cercaStudiatoBox, SIGNAL(clicked(bool)), this, SLOT(cercaStudiatoPressed(bool)));
        cercaStudiatoLayout->addWidget(cercaStudiatoBox);
        cercaStudiatoLayout->addWidget(StudiatoEdit);
        cercaStudiatoWidget->setLayout(cercaStudiatoLayout);
        ricercaLay->addWidget(cercaStudiatoWidget);
        cercaStudiatoPressed(false);
    }
    if(cercaNumeroTelefonicoBool) {
        cercaNumeroTelefonicoWidget = new QWidget(this);
        cercaNumeroTelefonicoBox = new QCheckBox(tr("cerca numero di telefono"), this);
        numeroTelefonicoEdit = new QLineEdit(this);
        cercaNumeroTelefonicoLayout = new QHBoxLayout(this);
        connect(cercaNumeroTelefonicoBox, SIGNAL(clicked(bool)), this, SLOT(cercaNumeroTelefonicoPressed(bool)));
        cercaNumeroTelefonicoLayout->addWidget(cercaNumeroTelefonicoBox);
        cercaNumeroTelefonicoLayout->addWidget(numeroTelefonicoEdit);
        cercaNumeroTelefonicoWidget->setLayout(cercaNumeroTelefonicoLayout);
        ricercaLay->addWidget(cercaNumeroTelefonicoWidget);
        cercaNumeroTelefonicoPressed(false);
    }
    if(cercaConContattoBool) {
        cercaConContattoWidget = new QWidget(this);
        cercaConContattoBox = new QCheckBox(tr("cerca contatto"), this);
        contattoEdit = new QLineEdit(this);
        cercaConContattoLayout = new QHBoxLayout(this);
        connect(cercaConContattoBox, SIGNAL(clicked(bool)), this, SLOT(cercaConContattoPressed(bool)));
        cercaConContattoLayout->addWidget(cercaConContattoBox);
        cercaConContattoLayout->addWidget(contattoEdit);
        cercaConContattoWidget->setLayout(cercaConContattoLayout);
        ricercaLay->addWidget(cercaConContattoWidget);
        cercaConContattoPressed(false);
    }


    risultatiLabel->hide();
    noRisultatiLabel->hide();
    risultatiScroll->hide();

    ricercaLay->addWidget(cercaButton);

    ricercaWidget->setLayout(ricercaLay);
    ricercaWidget->setFixedWidth(450);

    ricercaScroll->setWidget(ricercaWidget);

    lay->addWidget(ricercaScroll, 0, Qt::AlignTop);
    lay->addWidget(risultatiLabel);
    lay->addWidget(noRisultatiLabel);
    lay->addWidget(risultatiScroll);

    setLayout(lay);

    connect(this, SIGNAL(search(QString)), this, SLOT(searchFromBar(QString)));
    connect(cercaButton, SIGNAL(clicked()), this, SLOT(cerca()));
}

// slot

void SearchWidget::cerca() {

    QMap<Email,PointerUtente *> *ris = new QMap<Email,PointerUtente *>;

    if(cercaUsernameBool && cercaUsernameBox->isChecked()) {
        Email ema = Email(emailEdit->text());
        if(ema.isValid() && ema != utente->getUsername())
            ris = RicercaUtenteBasic::findWithUsername(db, ema, ris);
    }
    if(cercaNomeCognomeBool && cercaNomeCognomeBox->isChecked()) {
        QString nom = nomeEdit->text();
        QString cogn = cognomeEdit->text();
        if(!nom.isEmpty() || !cogn.isEmpty())
            ris = RicercaUtenteBasic::findWithNomeCognome(utente->getUsername(), db, nom, cogn, ris);
    }
    if(cercaResidenzaBool && cercaResidenzaBox->isChecked()) {
        QString res = residenzaEdit->text();
        if(!res.isEmpty())
            ris = RicercaUtenteBusiness::findWithResidenza(utente->getUsername(), db, res, ris);
    }
    if(cercaDataNascitaBool && cercaDataNascitaBox->isChecked()) {
        QDate dat = DataNascitaEdit->date();
        if(dat.isValid())
            ris = RicercaUtenteBusiness::findWithDataNascita(utente->getUsername(), db, dat, ris);
    }
    if(cercaLuogoNascitaBool && cercaLuogoNascitaBox->isChecked()) {
        QString luo = LuogoNascitaEdit->text();
        if(!luo.isEmpty())
            ris = RicercaUtenteBusiness::findWithLuogoNascita(utente->getUsername(), db, luo, ris);
    }
    if(cercaSessoBool && cercaSessoBox->isChecked()) {
        QString ses = SessoEdit->text();
        if(!ses.isEmpty())
            ris = RicercaUtenteBusiness::findWithSesso(utente->getUsername(), db, ses, ris);
    }
    if(cercaLavoratoBool && cercaLavoratoBox->isChecked()) {
        QString luo = LavoratoEdit->text();
        if(!luo.isEmpty())
            ris = RicercaUtenteExecutive::findWithLavorato(utente->getUsername(), db, luo, ris);
    }
    if(cercaStudiatoBool && cercaStudiatoBox->isChecked()) {
        QString luo = StudiatoEdit->text();
        if(!luo.isEmpty())
            ris = RicercaUtenteExecutive::findWithStudiato(utente->getUsername(), db, luo, ris);
    }
    if(cercaNumeroTelefonicoBool && cercaNumeroTelefonicoBox->isChecked()) {
        NumeroTelefonico num = NumeroTelefonico(numeroTelefonicoEdit->text());
        if(num.isValid())
            ris = RicercaUtenteExecutive::findWithNumeroTelefono(utente->getUsername(), db, num, ris);
    }
    if(cercaConContattoBool && cercaConContattoBox->isChecked()) {
        Email ema = Email(contattoEdit->text());
        if(ema.isValid())
            ris = RicercaUtenteExecutive::findWithContatto(utente->getUsername(), db, ema, ris);
    }
    if(ris->isEmpty()) {
        risultatiLabel->hide();
        noRisultatiLabel->show();
        risultatiScroll->hide();
    }
    else {
        vBox = new QVBoxLayout(this);
        for(QMap<Email,PointerUtente *>::const_iterator it = ris->constBegin(); it != ris->constEnd(); ++it) {
            UserLinkWidget *user = new UserLinkWidget(*it.value(), risultatiWidget);
            connect(user, SIGNAL(Open(PointerUtente&)), this, SIGNAL(open(PointerUtente&)));
            vBox->addWidget(user);
        }
        QWidget *wi = new QWidget(this);
        wi->setLayout(vBox);
        QScrollArea *s = new QScrollArea(this);
        s->setWidget(wi);
        lay->replaceWidget(risultatiScroll, s);
        delete risultatiScroll;
        risultatiScroll = s;
        risultatiLabel->show();
        noRisultatiLabel->hide();
        risultatiScroll->show();
    }

}

void SearchWidget::searchFromBar(QString string) {
    cercaUsernamePressed(true);

    emailEdit->setText(string);

    cercaUsernameBox->setChecked(true);
    cerca();
}

void SearchWidget::cercaUsernamePressed(bool b) {
    emailEdit->setVisible(b);
    emailEdit->setEnabled(b);
    if(!b)
        emailEdit->clear();
}

void SearchWidget::cercaNomeCognomePressed(bool b) {
    nomeEdit->setVisible(b);
    cognomeEdit->setVisible(b);
    nomeEdit->setEnabled(b);
    cognomeEdit->setEnabled(b);
    if(!b) {
        nomeEdit->clear();
        cognomeEdit->clear();
    }
}

void SearchWidget::cercaResidenzaPressed(bool b) {
    residenzaEdit->setVisible(b);
    residenzaEdit->setEnabled(b);
    if(!b)
        residenzaEdit->clear();
}

void SearchWidget::cercaDataNascitaPressed(bool b) {
    DataNascitaEdit->setVisible(b);
    DataNascitaEdit->setEnabled(b);
    if(!b)
        DataNascitaEdit->clear();
}

void SearchWidget::cercaLuogoNascitaPressed(bool b) {
    LuogoNascitaEdit->setVisible(b);
    LuogoNascitaEdit->setEnabled(b);
    if(!b)
        LuogoNascitaEdit->clear();
}

void SearchWidget::cercaSessoPressed(bool b) {
    SessoEdit->setVisible(b);
    SessoEdit->setEnabled(b);
    if(!b)
        SessoEdit->clear();
}

void SearchWidget::cercaLavoratoPressed(bool b) {
    LavoratoEdit->setVisible(b);
    LavoratoEdit->setEnabled(b);
    if(!b)
        LavoratoEdit->clear();
}

void SearchWidget::cercaStudiatoPressed(bool b) {
    StudiatoEdit->setVisible(b);
    StudiatoEdit->setEnabled(b);
    if(!b)
        StudiatoEdit->clear();
}

void SearchWidget::cercaNumeroTelefonicoPressed(bool b) {
    numeroTelefonicoEdit->setVisible(b);
    numeroTelefonicoEdit->setEnabled(b);
    if(!b)
        numeroTelefonicoEdit->clear();
}

void SearchWidget::cercaConContattoPressed(bool b) {
    contattoEdit->setVisible(b);
    contattoEdit->setEnabled(b);
    if(!b)
        contattoEdit->clear();
}
