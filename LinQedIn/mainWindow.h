#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>

#include "adminWidget.h"
#include "noUserWidget.h"
#include "clientWidget.h"
#include "database.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    PointerUtente *utente;
    AdminWidget *adminWidget;
    ClientWidget *clientWidget;
    NoUserWidget *noUserWidget;
    Database db;
    QPushButton *adminButton, *clientButton;
    QVBoxLayout *vBox;
    QHBoxLayout *hBox;
    QFrame *topWidget;

public:
    explicit MainWindow(QWidget * =0);

private slots:
    void admin();
    void client();
    void load(PointerUtente *);
};

#endif // MAINWINDOW_H
