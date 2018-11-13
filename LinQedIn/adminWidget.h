#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "admin.h"
#include "layoutWidget.h"
#include "listaUserWidget.h"
#include "loadDatabaseWidget.h"
#include "saveDatabaseWidget.h"
#include "newUserWidget.h"
#include "changeUserWidget.h"
#include "deleteUserWidget.h"

class AdminWidget : public LayoutWidget
{
    Q_OBJECT
private:
    Admin adm;
    QPushButton *listaUserButton, *loadDatabaseButton, *saveDatabaseButton, *newUserButton, *changeUserButton, *deleteUserButton;
    QVBoxLayout *vBoxleft;
    void enableButtons();

public:
    explicit AdminWidget(Database &, QWidget * =0);

private slots:
    void listaUser();
    void loadDatabase();
    void saveDatabase();
    void newUser();
    void changeUser();
    void deleteUser();
};

#endif // ADMINWIDGET_H
