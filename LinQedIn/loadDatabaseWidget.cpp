
#include "loadDatabaseWidget.h"

LoadDatabaseWidget::LoadDatabaseWidget(Admin &adm, QWidget *parent) :
    QWidget(parent), admin(adm)
{
    errorLabel = new QLabel(this);
    caricaButton = new QPushButton(tr("carica database"), this);
    lay = new QVBoxLayout(this);

    QFont errorFont;
    errorFont.setItalic(true);
    errorLabel->setFont(errorFont);
    errorLabel->hide();

    caricaButton->setDefault(true);

    connect(caricaButton, SIGNAL(clicked()), this, SLOT(caricaDatabase()));

    lay->addWidget(errorLabel);
    lay->addWidget(caricaButton);

    lay->setAlignment(Qt::AlignCenter);

    setLayout(lay);
}

//slot

void LoadDatabaseWidget::caricaDatabase() {
    if(admin.loadDatabase())
        setLabel(tr("database caricato con successo"));
    else
        setLabel(tr("file database.xml non trovato, database non caricato"));
}

void LoadDatabaseWidget::setLabel(const QString &str) {
    errorLabel->setText(str);
    errorLabel->show();
}
