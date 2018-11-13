#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QString>
#include <QWidget>
#include <QLabel>
#include <QDateEdit>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>

#include "pointerUtente.h"
#include "database.h"
#include "ricercaUtenteBasic.h"
#include "ricercaUtenteBusiness.h"
#include "ricercaUtenteExecutive.h"
#include "searchBarWidget.h"
#include "userLinkWidget.h"



class SearchWidget : public QWidget
{
    Q_OBJECT
private:
    PointerUtente &utente;
    Database &db;
    QWidget *cercaUsernameWidget, *cercaNomeCognomeWidget, *cercaResidenzaWidget, *cercaDataNascitaWidget;
    QWidget *cercaLuogoNascitaWidget, *cercaSessoWidget, *cercaLavoratoWidget, *cercaStudiatoWidget;
    QWidget *cercaNumeroTelefonicoWidget, *cercaConContattoWidget, *risultatiWidget, *ricercaWidget;
    QCheckBox *cercaUsernameBox, *cercaNomeCognomeBox, *cercaResidenzaBox, *cercaDataNascitaBox, *cercaLuogoNascitaBox;
    QCheckBox *cercaSessoBox, *cercaLavoratoBox, *cercaStudiatoBox, *cercaNumeroTelefonicoBox, *cercaConContattoBox;
    QLabel *risultatiLabel, *noRisultatiLabel;
    QLineEdit *emailEdit, *nomeEdit, *cognomeEdit, *residenzaEdit, *LuogoNascitaEdit, *SessoEdit, *LavoratoEdit;
    QLineEdit *StudiatoEdit, *numeroTelefonicoEdit, *contattoEdit;
    QDateEdit *DataNascitaEdit;
    QPushButton *cercaButton;
    QHBoxLayout  *cercaUsernameLayout, *cercaNomeCognomeLayout, *cercaResidenzaLayout, *cercaDataNascitaLayout;
    QHBoxLayout *cercaLuogoNascitaLayout, *cercaSessoLayout, *cercaLavoratoLayout, *cercaStudiatoLayout;
    QHBoxLayout *cercaNumeroTelefonicoLayout, *cercaConContattoLayout;
    QVBoxLayout *lay, *vBox, *ricercaLay;
    QScrollArea *ricercaScroll, *risultatiScroll;
    bool cercaUsernameBool, cercaNomeCognomeBool, cercaResidenzaBool, cercaDataNascitaBool, cercaLuogoNascitaBool;
    bool cercaSessoBool, cercaLavoratoBool, cercaStudiatoBool, cercaNumeroTelefonicoBool, cercaConContattoBool;
    
public:
    explicit SearchWidget(PointerUtente &, Database &, QWidget * =0);

signals:
    void search(QString);
    void open(PointerUtente &);

private slots:
    void cerca();
    void searchFromBar(QString);
    void cercaUsernamePressed(bool);
    void cercaNomeCognomePressed(bool);
    void cercaResidenzaPressed(bool);
    void cercaDataNascitaPressed(bool);
    void cercaLuogoNascitaPressed(bool);
    void cercaSessoPressed(bool);
    void cercaLavoratoPressed(bool);
    void cercaStudiatoPressed(bool);
    void cercaNumeroTelefonicoPressed(bool);
    void cercaConContattoPressed(bool);
};

#endif // SEARCHWIDGET_H
