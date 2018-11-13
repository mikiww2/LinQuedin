
#include "searchBarWidget.h"

SearchBarWidget::SearchBarWidget(QWidget *parent) :
    QFrame(parent)
{
    testoEdit = new QLineEdit(this);
    aiutoLabel = new QLabel(tr("cerca email"), this);
    cercaButton = new QPushButton(tr("cerca"), this);
    altroButton = new QPushButton(tr("opzioni"), this);
    lay = new QGridLayout(this);

    testoEdit->setContentsMargins(30,10,10,10);
    testoEdit->setFixedWidth(400);

    QFont aiutoFont;
    aiutoFont.setItalic(true);
    aiutoLabel->setFont(aiutoFont);

    cercaButton->setEnabled(false);

    connect(cercaButton, SIGNAL(clicked()), this, SLOT(searchUser()));
    connect(altroButton, SIGNAL(clicked()), this, SIGNAL(altro()));
    connect(testoEdit, SIGNAL(textEdited(QString)), this, SLOT(changeButton(QString)));
    connect(testoEdit, SIGNAL(returnPressed()), cercaButton, SIGNAL(clicked()));

    lay->addWidget(testoEdit, 0, 0);
    lay->addWidget(aiutoLabel, 1, 0);
    lay->addWidget(cercaButton, 0, 1);
    lay->addWidget(altroButton, 1, 1);

    lay->setAlignment(Qt::AlignCenter);

    setLayout(lay);
    setFrameShape(QFrame::Box);
}

//slot

void SearchBarWidget::searchUser() {
    emit cerca(testoEdit->text());
}

void SearchBarWidget::changeButton(QString string) {
    if(string.isEmpty())
        cercaButton->setEnabled(false);
    else
        cercaButton->setEnabled(true);
}
