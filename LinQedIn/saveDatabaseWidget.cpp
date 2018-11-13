
#include "saveDatabaseWidget.h"

SaveDatabaseWidget::SaveDatabaseWidget(Admin &adm, QWidget *parent) :
    QWidget(parent), admin(adm)
{
    errorLabel = new QLabel(this);
    salvaButton = new QPushButton(tr("salva database"), this);
    lay = new QVBoxLayout(this);

    QFont errorFont;
    errorFont.setItalic(true);
    errorLabel->setFont(errorFont);
    errorLabel->hide();

    salvaButton->setDefault(true);

    connect(salvaButton, SIGNAL(clicked()), this, SLOT(salvaDatabase()));

    lay->addWidget(errorLabel);
    lay->addWidget(salvaButton);

    lay->setAlignment(Qt::AlignCenter);

    setLayout(lay);
}

//slot

void SaveDatabaseWidget::salvaDatabase() {
    if(admin.writeDatabase())
        setLabel(tr("database salvato con successo"));
    else
        setLabel(tr("database vuoto"));
}

void SaveDatabaseWidget::setLabel(const QString &str) {
    errorLabel->setText(str);
    errorLabel->show();
}
