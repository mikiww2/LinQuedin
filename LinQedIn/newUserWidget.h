#ifndef NEWUSERWIDGET_H
#define NEWUSERWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QFormLayout>

#include "email.h"
#include "admin.h"

class NewUserWidget : public QWidget
{
    Q_OBJECT
private:
    Admin &admin;
    QLabel *tipoLabel, *errorLabel;
    QLineEdit *nomeEdit, *cognomeEdit, *emailEdit;
    QRadioButton *basicUserButton, *businessUserButton, *executiveUserButton;
    QButtonGroup *tipoGroup;
    QPushButton *creaButton;
    QFormLayout *form;

public:
    explicit NewUserWidget(Admin &, QWidget * = 0);

signals:

private slots:
    void creaUser();
    void setLabel(const QString &);

public slots:

};

#endif // NEWUSERWIDGET_H
