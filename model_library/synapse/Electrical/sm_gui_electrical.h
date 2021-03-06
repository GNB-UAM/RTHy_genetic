#ifndef SM_GUI_ELECTRICAL_H
#define SM_GUI_ELECTRICAL_H

#include <QDialog>
#include <QSettings>
#include "sm_electrical.h"

namespace Ui {
class SM_GUI_Electrical;
}

class SM_GUI_Electrical : public QDialog
{
    Q_OBJECT

public:
    explicit SM_GUI_Electrical(void ** args = NULL, unsigned int direction = 2, QWidget *parent = 0);
    ~SM_GUI_Electrical();

private slots:
    void on_pushButton_accept_clicked();

private:
    Ui::SM_GUI_Electrical *ui;
    void ** args;
    QSettings * settings;

    void saveSettings();
    void loadSettings();
};

#endif // SM_GUI_ELECTRICAL_H
