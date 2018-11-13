#ifndef CHANGEUSERWIDGET_H
#define CHANGEUSERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QFormLayout>

#include <admin.h>

class ChangeUserWidget : public QWidget
{
    Q_OBJECT
private:
    Admin &admin;
    QLabel *tipoLabel, *errorLabel;
    QLineEdit *emailEdit;
    QRadioButton *basicUserButton, *businessUserButton, *executiveUserButton;
    QButtonGroup *tipoGroup;
    QPushButton *findButton, *changeButton;
    QFormLayout *form;

public:
    explicit ChangeUserWidget(Admin &, QWidget * =0);

signals:

private slots:
    void setLabel(const QString &);
    void loadUser();
    void changeUser();

public slots:

};

#endif // CHANGEUSERWIDGET_H
