
#include "listaContattiWidget.h"

listaContattiWidget::listaContattiWidget(const QMap<Email, PointerUtente *> &rete, QWidget *parent) :
    QScrollArea(parent), contatti(rete)
{
    noLabel = new QLabel(tr("nessun contatto"), this);
    vBox = new QVBoxLayout(this);

    vBox->addWidget(noLabel);

    if(contatti.isEmpty())
        noLabel->show();
    else {
        noLabel->hide();
        for(QMap<Email,PointerUtente *>::ConstIterator it = contatti.constBegin(); it != contatti.constEnd(); ++it) {
            UserLinkWidget *link = new UserLinkWidget(**it, this);
            link->setFixedHeight(80);

            connect(link, SIGNAL(Open(PointerUtente &)), this, SIGNAL(mostra(PointerUtente &)));

            vBox->addWidget(link, 1, Qt::AlignTop);
        }
    }

    setLayout(vBox);

    setFrameShape(QFrame::Box);
}
