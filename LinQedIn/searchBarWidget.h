#ifndef SEARCHBARWIDGET_H
#define SEARCHBARWIDGET_H

#include <QFrame>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFont>

class SearchBarWidget : public QFrame
{
    Q_OBJECT
private:
    QLineEdit *testoEdit;
    QLabel *aiutoLabel;
    QPushButton *cercaButton, *altroButton;
    QGridLayout *lay;

public:
    explicit SearchBarWidget(QWidget * =0);

signals:
    void cerca(QString);
    void altro();

private slots:
    void searchUser();
    void changeButton(QString);

public slots:

};

#endif // SEARCHBARWIDGET_H
