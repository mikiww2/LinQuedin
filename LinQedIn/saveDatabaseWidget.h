#ifndef SAVEDATABASEWIDGET_H
#define SAVEDATABASEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "admin.h"

class SaveDatabaseWidget : public QWidget
{
    Q_OBJECT
private:
    Admin &admin;
    QLabel *errorLabel;
    QPushButton *salvaButton;
    QVBoxLayout *lay;

public:
    explicit SaveDatabaseWidget(Admin &, QWidget * =0);

signals:

private slots:
    void salvaDatabase();
    void setLabel(const QString &);

public slots:

};

#endif // SAVEDATABASEWIDGET_H
