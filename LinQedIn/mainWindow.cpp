
#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent), utente(0), adminWidget(0), clientWidget(0), noUserWidget(0)
{
    topWidget = new QFrame(this);
    hBox = new QHBoxLayout(topWidget);
    vBox = new QVBoxLayout(this);
    adminButton = new QPushButton(tr("ADMIN"), topWidget);
    clientButton = new QPushButton(tr("CLIENT"), topWidget);

    setWindowTitle("LinQedIn");

    connect(adminButton, SIGNAL(clicked()), this, SLOT(admin()));
    connect(clientButton, SIGNAL(clicked()), this, SLOT(client()));

    topWidget->setFrameShape(QFrame::Box);

    hBox->addWidget(adminButton);
    hBox->addWidget(clientButton);
    hBox->setAlignment(Qt::AlignVertical_Mask);

    topWidget->setLayout(hBox);
    topWidget->setFixedHeight(50);
    topWidget->setContentsMargins(5, 5, 5, 5);

    vBox->addWidget(topWidget, 0, Qt::AlignTop);

    setLayout(vBox);
    setFixedSize(850, 650);
    setContentsMargins(2, 2, 2, 2);

}

// slot

void MainWindow::admin() {
    adminWidget = new AdminWidget(db, this);

    adminButton->setEnabled(false);

    adminWidget->setContentsMargins(5, 5, 5, 5);

    if(!noUserWidget && !clientWidget)
        vBox->addWidget(adminWidget, 0, Qt::AlignVertical_Mask);
    if(noUserWidget) {
        vBox->replaceWidget(noUserWidget, adminWidget);
        vBox->setAlignment(adminWidget, Qt::AlignVertical_Mask);

        delete noUserWidget;
        noUserWidget = 0;

        clientButton->setEnabled(true);
    }
    if(clientWidget) {
        vBox->replaceWidget(clientWidget, adminWidget);
        vBox->setAlignment(adminWidget, Qt::AlignVertical_Mask);

        delete clientWidget;
        clientWidget = 0;

        clientButton->setText(tr("CLIENT"));
        utente = 0;
    }
}

void MainWindow::client() {
    if(noUserWidget) {
        if(!utente)
            qDebug() << "errore, ho bisogno di un utente per loggare";
        else {
            clientWidget = new ClientWidget(*utente, db, this);

            clientButton->setEnabled(true);
            clientButton->setText(tr("LOGOUT"));

            vBox->replaceWidget(noUserWidget, clientWidget);
            vBox->setAlignment(clientWidget, Qt::AlignCenter);

            delete noUserWidget;
            noUserWidget = 0;
        }
    }
    else {
        noUserWidget = new NoUserWidget(db, this);

        connect(noUserWidget, SIGNAL(logged(PointerUtente*)), this, SLOT(load(PointerUtente*)));

        clientButton->setEnabled(false);

        if(!adminWidget && !clientWidget)
            vBox->addWidget(noUserWidget, 0, Qt::AlignCenter);

        if(clientWidget) {
            clientButton->setText(tr("CLIENT"));

            vBox->replaceWidget(clientWidget, noUserWidget);
            vBox->setAlignment(noUserWidget, Qt::AlignCenter);

            delete clientWidget;
            clientWidget = 0;
        }
        if(adminWidget) {
            adminButton->setEnabled(true);

            vBox->replaceWidget(adminWidget, noUserWidget);
            vBox->setAlignment(noUserWidget, Qt::AlignCenter);

            delete adminWidget;
            adminWidget = 0;
        }
    }
}


void MainWindow::load(PointerUtente *ut) {
    utente = ut;
    client();
}
