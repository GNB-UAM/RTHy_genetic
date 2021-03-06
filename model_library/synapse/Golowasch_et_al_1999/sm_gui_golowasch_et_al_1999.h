#ifndef SM_GUI_GOLOWASCH_ET_AL_1999_H
#define SM_GUI_GOLOWASCH_ET_AL_1999_H

#include <QDialog>
#include <QSettings>
#include "sm_golowasch_et_al_1999.h"

namespace Ui {
class SM_GUI_Golowasch_et_al_1999;
}

class SM_GUI_Golowasch_et_al_1999 : public QDialog
{
    Q_OBJECT

public:
    explicit SM_GUI_Golowasch_et_al_1999(void ** args = NULL, unsigned int direction = 2, QWidget *parent = 0);
    ~SM_GUI_Golowasch_et_al_1999();

private slots:
    void on_pushButton_accept_clicked();

private:
    Ui::SM_GUI_Golowasch_et_al_1999 *ui;
    void ** args;
    QSettings * settings;

    void saveSettings();
    void loadSettings();
};

#endif // SM_GUI_GOLOWASCH_ET_AL_1999_H
