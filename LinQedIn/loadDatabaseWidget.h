#ifndef LOADDATABASEWIDGET_H
#define LOADDATABASEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "admin.h"

class LoadDatabaseWidget : public QWidget
{
    Q_OBJECT
private:
    Admin &admin;
    QLabel *errorLabel;
    QPushButton *caricaButton;
    QVBoxLayout *lay;

public:
    explicit LoadDatabaseWidget(Admin &, QWidget * =0);

signals:

private slots:
    void caricaDatabase();
    void setLabel(const QString &);

public slots:

};

#endif // LOADDATABASEWIDGET_H
