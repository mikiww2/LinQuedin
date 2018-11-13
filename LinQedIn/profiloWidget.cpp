
#include "profiloWidget.h"

ProfiloWidget::ProfiloWidget(PointerUtente &ut, QWidget *parent) :
    QWidget(parent), utente(ut)
{
    modificaButton = new QPushButton(tr("modifica"), this);
    infoWidget = new InformazioniWidget(utente, this);
    lay = new QVBoxLayout(this);

    connect(modificaButton, SIGNAL(clicked()), infoWidget, SIGNAL(viewModifica()));
    connect(modificaButton, SIGNAL(clicked()), modificaButton, SLOT(hide()));
    connect(infoWidget, SIGNAL(nascondiModifica()), modificaButton, SLOT(show()));

    lay->addWidget(modificaButton, 0, Qt::AlignTop);
    lay->addWidget(infoWidget);

    setLayout(lay);
}
