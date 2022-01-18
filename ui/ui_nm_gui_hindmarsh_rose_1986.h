/********************************************************************************
** Form generated from reading UI file 'nm_gui_hindmarsh_rose_1986.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NM_GUI_HINDMARSH_ROSE_1986_H
#define UI_NM_GUI_HINDMARSH_ROSE_1986_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NM_GUI_Hindmarsh_Rose_1986
{
public:
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_i;
    QDoubleSpinBox *doubleSpinBox_y;
    QLabel *label_18;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_s;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_v;
    QLabel *label_21;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_z;
    QDoubleSpinBox *doubleSpinBox_r;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QComboBox *comboBoxIntegrationMethod;
    QPushButton *pushButton_accept;
    QLabel *label_3;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_xr;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_a;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_b;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_c;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_d;

    void setupUi(QWidget *NM_GUI_Hindmarsh_Rose_1986)
    {
        if (NM_GUI_Hindmarsh_Rose_1986->objectName().isEmpty())
            NM_GUI_Hindmarsh_Rose_1986->setObjectName(QStringLiteral("NM_GUI_Hindmarsh_Rose_1986"));
        NM_GUI_Hindmarsh_Rose_1986->setWindowModality(Qt::ApplicationModal);
        NM_GUI_Hindmarsh_Rose_1986->resize(359, 312);
        label_9 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(38, 40, 21, 21));
        doubleSpinBox_i = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_i->setObjectName(QStringLiteral("doubleSpinBox_i"));
        doubleSpinBox_i->setGeometry(QRect(60, 100, 101, 24));
        doubleSpinBox_i->setDecimals(2);
        doubleSpinBox_i->setMinimum(-99.99);
        doubleSpinBox_i->setSingleStep(0.1);
        doubleSpinBox_i->setValue(3);
        doubleSpinBox_y = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_y->setObjectName(QStringLiteral("doubleSpinBox_y"));
        doubleSpinBox_y->setGeometry(QRect(222, 80, 101, 24));
        doubleSpinBox_y->setDecimals(6);
        doubleSpinBox_y->setMinimum(-99.99);
        doubleSpinBox_y->setSingleStep(0.1);
        doubleSpinBox_y->setValue(-1.93688);
        label_18 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(38, 70, 21, 21));
        label_17 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(203, 84, 31, 16));
        doubleSpinBox_s = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_s->setObjectName(QStringLiteral("doubleSpinBox_s"));
        doubleSpinBox_s->setGeometry(QRect(60, 70, 101, 24));
        doubleSpinBox_s->setDecimals(2);
        doubleSpinBox_s->setMinimum(-99.99);
        doubleSpinBox_s->setSingleStep(0.1);
        doubleSpinBox_s->setValue(4);
        label_20 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(202, 54, 31, 21));
        doubleSpinBox_v = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_v->setObjectName(QStringLiteral("doubleSpinBox_v"));
        doubleSpinBox_v->setGeometry(QRect(222, 50, 101, 24));
        doubleSpinBox_v->setDecimals(6);
        doubleSpinBox_v->setMinimum(-99.99);
        doubleSpinBox_v->setSingleStep(0.1);
        doubleSpinBox_v->setValue(-0.712841);
        label_21 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(202, 114, 31, 16));
        label_19 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 100, 21, 21));
        doubleSpinBox_z = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_z->setObjectName(QStringLiteral("doubleSpinBox_z"));
        doubleSpinBox_z->setGeometry(QRect(222, 110, 101, 24));
        doubleSpinBox_z->setDecimals(6);
        doubleSpinBox_z->setMinimum(-99.99);
        doubleSpinBox_z->setSingleStep(0.1);
        doubleSpinBox_z->setValue(3.16568);
        doubleSpinBox_r = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_r->setObjectName(QStringLiteral("doubleSpinBox_r"));
        doubleSpinBox_r->setGeometry(QRect(60, 40, 101, 24));
        doubleSpinBox_r->setDecimals(6);
        doubleSpinBox_r->setMinimum(-99.99);
        doubleSpinBox_r->setSingleStep(0.0001);
        doubleSpinBox_r->setValue(0.0021);
        label = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(68, 14, 91, 16));
        label_2 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 24, 101, 16));
        line = new QFrame(NM_GUI_Hindmarsh_Rose_1986);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(170, 34, 20, 251));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        comboBoxIntegrationMethod = new QComboBox(NM_GUI_Hindmarsh_Rose_1986);
        comboBoxIntegrationMethod->setObjectName(QStringLiteral("comboBoxIntegrationMethod"));
        comboBoxIntegrationMethod->setEnabled(true);
        comboBoxIntegrationMethod->setGeometry(QRect(196, 204, 141, 23));
        pushButton_accept = new QPushButton(NM_GUI_Hindmarsh_Rose_1986);
        pushButton_accept->setObjectName(QStringLiteral("pushButton_accept"));
        pushButton_accept->setGeometry(QRect(224, 260, 82, 23));
        label_3 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(205, 174, 141, 16));
        label_10 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(35, 131, 21, 21));
        doubleSpinBox_xr = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_xr->setObjectName(QStringLiteral("doubleSpinBox_xr"));
        doubleSpinBox_xr->setGeometry(QRect(60, 130, 101, 24));
        doubleSpinBox_xr->setDecimals(6);
        doubleSpinBox_xr->setMinimum(-99.99);
        doubleSpinBox_xr->setSingleStep(0.0001);
        doubleSpinBox_xr->setValue(-1.6);
        label_11 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 182, 21, 21));
        doubleSpinBox_a = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_a->setObjectName(QStringLiteral("doubleSpinBox_a"));
        doubleSpinBox_a->setGeometry(QRect(60, 180, 101, 24));
        doubleSpinBox_a->setDecimals(6);
        doubleSpinBox_a->setMinimum(-99.99);
        doubleSpinBox_a->setSingleStep(0.0001);
        doubleSpinBox_a->setValue(1);
        label_12 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 212, 21, 21));
        doubleSpinBox_b = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_b->setObjectName(QStringLiteral("doubleSpinBox_b"));
        doubleSpinBox_b->setGeometry(QRect(60, 210, 101, 24));
        doubleSpinBox_b->setDecimals(6);
        doubleSpinBox_b->setMinimum(-99.99);
        doubleSpinBox_b->setSingleStep(0.0001);
        doubleSpinBox_b->setValue(3);
        label_13 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 242, 21, 21));
        doubleSpinBox_c = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_c->setObjectName(QStringLiteral("doubleSpinBox_c"));
        doubleSpinBox_c->setGeometry(QRect(60, 240, 101, 24));
        doubleSpinBox_c->setDecimals(6);
        doubleSpinBox_c->setMinimum(-99.99);
        doubleSpinBox_c->setSingleStep(0.0001);
        doubleSpinBox_c->setValue(1);
        label_14 = new QLabel(NM_GUI_Hindmarsh_Rose_1986);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 272, 21, 21));
        doubleSpinBox_d = new QDoubleSpinBox(NM_GUI_Hindmarsh_Rose_1986);
        doubleSpinBox_d->setObjectName(QStringLiteral("doubleSpinBox_d"));
        doubleSpinBox_d->setGeometry(QRect(60, 270, 101, 24));
        doubleSpinBox_d->setDecimals(6);
        doubleSpinBox_d->setMinimum(-99.99);
        doubleSpinBox_d->setSingleStep(0.0001);
        doubleSpinBox_d->setValue(5);

        retranslateUi(NM_GUI_Hindmarsh_Rose_1986);

        comboBoxIntegrationMethod->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(NM_GUI_Hindmarsh_Rose_1986);
    } // setupUi

    void retranslateUi(QWidget *NM_GUI_Hindmarsh_Rose_1986)
    {
        NM_GUI_Hindmarsh_Rose_1986->setWindowTitle(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Hindmarsh-Rose (1986) neuron model", Q_NULLPTR));
        label_9->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "R", Q_NULLPTR));
        label_18->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "S", Q_NULLPTR));
        label_17->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Y", Q_NULLPTR));
        label_20->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "X", Q_NULLPTR));
        label_21->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Z", Q_NULLPTR));
        label_19->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "I", Q_NULLPTR));
        label->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Parameters", Q_NULLPTR));
        label_2->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Initial values", Q_NULLPTR));
        comboBoxIntegrationMethod->clear();
        comboBoxIntegrationMethod->insertItems(0, QStringList()
         << QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Euler", Q_NULLPTR)
         << QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Heun", Q_NULLPTR)
         << QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Runge-Kutta 4", Q_NULLPTR)
         << QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Runge-Kutta (6)5", Q_NULLPTR)
        );
        pushButton_accept->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Accept", Q_NULLPTR));
        label_3->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "Integration method", Q_NULLPTR));
        label_10->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "XR", Q_NULLPTR));
        label_11->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "A", Q_NULLPTR));
        label_12->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "B", Q_NULLPTR));
        label_13->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "C", Q_NULLPTR));
        label_14->setText(QApplication::translate("NM_GUI_Hindmarsh_Rose_1986", "D", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NM_GUI_Hindmarsh_Rose_1986: public Ui_NM_GUI_Hindmarsh_Rose_1986 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NM_GUI_HINDMARSH_ROSE_1986_H
