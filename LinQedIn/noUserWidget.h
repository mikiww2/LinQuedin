#ifndef NOUSERWIDGET_H
#define NOUSERWIDGET_H

#include <QString>
#include <QFrame>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCloseEvent>

#include "email.h"
#include "pointerUtente.h"
#include "database.h"

class NoUserWidget : public QFrame
{
    Q_OBJECT
private:
    PointerUtente *ut;
    Database &db;
    QLabel *userLabel, *errorLabel;
    QLineEdit *userEdit;
    QPushButton *userButton;

public:
    explicit NoUserWidget(Database &, QWidget * =0);

signals:
    void error();
    void logged(PointerUtente *);

private slots:
    void loadUser();
    void mostraErrore();
    void enableButton(QString);
};

#endif // NOUSERWIDGET_H
