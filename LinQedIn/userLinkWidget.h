#ifndef USERLINKWIDGET_H
#define USERLINKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

#include "pointerUtente.h"

class UserLinkWidget : public QWidget
{
    Q_OBJECT
private:
    PointerUtente &utente;
    QPushButton *openButton;
    QLabel *userLabel;
    QVBoxLayout *vBox;

public:
    explicit UserLinkWidget(PointerUtente &, QWidget * =0);

signals:
    void Open(PointerUtente &);

private slots:
    void pressed();


public slots:

};

#endif // USERLINKWIDGET_H
