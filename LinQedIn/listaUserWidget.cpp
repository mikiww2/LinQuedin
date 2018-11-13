
#include "listaUserWidget.h"

ListaUserWidget::ListaUserWidget(Database &database, QWidget *parent) :
    QWidget(parent), db(database)
{
    lay = new QGridLayout(this);
    if(db.isEmpty()) {
        QLabel *label = new QLabel(tr("database vuoto, niente da visualizzare"), this);

        lay->addWidget(label, 0, 0, 0, 0, Qt::AlignCenter);
    }
    else {
        scrollArea = new QScrollArea(this);
        grid = new QGridLayout(this);
        widget = new QWidget(this);
        int i = 0;

        for(QMap<Email, PointerUtente *>::const_iterator it = db.getCIFirst(); it != db.getCIEnd(); ++it) {
            QLabel *userLabel = new QLabel((**it)->getUsername().getEmailString(), this);

            grid->addWidget(userLabel, i/2, i%2, 1, 1);
            ++i;
        }

        widget->setLayout(grid);

        scrollArea->setWidget(widget);

        lay->addWidget(scrollArea, 0, 0, 0, 0, Qt::AlignVertical_Mask);
    }
    lay->setAlignment(Qt::AlignTop);

    setLayout(lay);
}

//slot
