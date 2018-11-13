#ifndef DELETEUSERWIDGET_H
#define DELETEUSERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

#include "admin.h"

class DeleteUserWidget : public QWidget
{
    Q_OBJECT
private:
    Admin &admin;
    QLabel *errorLabel;
    QLineEdit *emailEdit;
    QPushButton *eliminaButton;
    QFormLayout *form;

public:
    explicit DeleteUserWidget(Admin &, QWidget * =0);

signals:

private slots:
    void eliminaUser();
    void setLabel(const QString &);

public slots:

};

#endif // DELETEUSERWIDGET_H
