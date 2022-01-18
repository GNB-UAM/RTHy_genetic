/********************************************************************************
** Form generated from reading UI file 'nm_gui_izhikevich_2003.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NM_GUI_IZHIKEVICH_2003_H
#define UI_NM_GUI_IZHIKEVICH_2003_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NM_GUI_Izhikevich_2003
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_a;
    QDoubleSpinBox *doubleSpinBox_b;
    QDoubleSpinBox *doubleSpinBox_c;
    QDoubleSpinBox *doubleSpinBox_d;
    QDoubleSpinBox *doubleSpinBox_v;
    QDoubleSpinBox *doubleSpinBox_u;
    QComboBox *comboBoxIntegrationMethod;
    QPushButton *pushButton_accept;
    QDoubleSpinBox *doubleSpinBox_i;
    QLabel *label_10;

    void setupUi(QWidget *NM_GUI_Izhikevich_2003)
    {
        if (NM_GUI_Izhikevich_2003->objectName().isEmpty())
            NM_GUI_Izhikevich_2003->setObjectName(QStringLiteral("NM_GUI_Izhikevich_2003"));
        NM_GUI_Izhikevich_2003->setWindowModality(Qt::ApplicationModal);
        NM_GUI_Izhikevich_2003->resize(699, 211);
        label = new QLabel(NM_GUI_Izhikevich_2003);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 81, 16));
        label_2 = new QLabel(NM_GUI_Izhikevich_2003);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 20, 91, 16));
        label_3 = new QLabel(NM_GUI_Izhikevich_2003);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(500, 20, 141, 16));
        label_4 = new QLabel(NM_GUI_Izhikevich_2003);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 60, 61, 15));
        label_5 = new QLabel(NM_GUI_Izhikevich_2003);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 90, 61, 15));
        label_6 = new QLabel(NM_GUI_Izhikevich_2003);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 120, 61, 15));
        label_7 = new QLabel(NM_GUI_Izhikevich_2003);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 150, 61, 15));
        label_8 = new QLabel(NM_GUI_Izhikevich_2003);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(240, 60, 61, 15));
        label_9 = new QLabel(NM_GUI_Izhikevich_2003);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 100, 61, 15));
        doubleSpinBox_a = new QDoubleSpinBox(NM_GUI_Izhikevich_2003);
        doubleSpinBox_a->setObjectName(QStringLiteral("doubleSpinBox_a"));
        doubleSpinBox_a->setGeometry(QRect(50, 50, 101, 24));
        doubleSpinBox_a->setDecimals(5);
        doubleSpinBox_a->setMinimum(-99);
        doubleSpinBox_a->setSingleStep(0.01);
        doubleSpinBox_a->setValue(0.02);
        doubleSpinBox_b = new QDoubleSpinBox(NM_GUI_Izhikevich_2003);
        doubleSpinBox_b->setObjectName(QStringLiteral("doubleSpinBox_b"));
        doubleSpinBox_b->setGeometry(QRect(50, 80, 101, 24));
        doubleSpinBox_b->setDecimals(5);
        doubleSpinBox_b->setMinimum(-99);
        doubleSpinBox_b->setSingleStep(0.01);
        doubleSpinBox_b->setValue(0.2);
        doubleSpinBox_c = new QDoubleSpinBox(NM_GUI_Izhikevich_2003);
        doubleSpinBox_c->setObjectName(QStringLiteral("doubleSpinBox_c"));
        doubleSpinBox_c->setGeometry(QRect(50, 110, 101, 24));
        doubleSpinBox_c->setDecimals(5);
        doubleSpinBox_c->setMinimum(-99);
        doubleSpinBox_c->setSingleStep(0.01);
        doubleSpinBox_c->setValue(-50);
        doubleSpinBox_d = new QDoubleSpinBox(NM_GUI_Izhikevich_2003);
        doubleSpinBox_d->setObjectName(QStringLiteral("doubleSpinBox_d"));
        doubleSpinBox_d->setGeometry(QRect(50, 140, 101, 24));
        doubleSpinBox_d->setDecimals(5);
        doubleSpinBox_d->setMinimum(-99);
        doubleSpinBox_d->setSingleStep(0.01);
        doubleSpinBox_d->setValue(2);
        doubleSpinBox_v = new QDoubleSpinBox(NM_GUI_Izhikevich_2003);
        doubleSpinBox_v->setObjectName(QStringLiteral("doubleSpinBox_v"));
        doubleSpinBox_v->setGeometry(QRect(270, 50, 101, 24));
        doubleSpinBox_v->setDecimals(5);
        doubleSpinBox_v->setMinimum(-99);
        doubleSpinBox_v->setSingleStep(0.01);
        doubleSpinBox_v->setValue(30.2403);
        doubleSpinBox_u = new QDoubleSpinBox(NM_GUI_Izhikevich_2003);
        doubleSpinBox_u->setObjectName(QStringLiteral("doubleSpinBox_u"));
        doubleSpinBox_u->setGeometry(QRect(270, 100, 101, 24));
        doubleSpinBox_u->setDecimals(5);
        doubleSpinBox_u->setMinimum(-99);
        doubleSpinBox_u->setSingleStep(0.01);
        doubleSpinBox_u->setValue(-5.54459);
        comboBoxIntegrationMethod = new QComboBox(NM_GUI_Izhikevich_2003);
        comboBoxIntegrationMethod->setObjectName(QStringLiteral("comboBoxIntegrationMethod"));
        comboBoxIntegrationMethod->setEnabled(true);
        comboBoxIntegrationMethod->setGeometry(QRect(490, 50, 141, 23));
        pushButton_accept = new QPushButton(NM_GUI_Izhikevich_2003);
        pushButton_accept->setObjectName(QStringLiteral("pushButton_accept"));
        pushButton_accept->setGeometry(QRect(520, 140, 82, 23));
        doubleSpinBox_i = new QDoubleSpinBox(NM_GUI_Izhikevich_2003);
        doubleSpinBox_i->setObjectName(QStringLiteral("doubleSpinBox_i"));
        doubleSpinBox_i->setGeometry(QRect(50, 170, 101, 24));
        doubleSpinBox_i->setDecimals(5);
        doubleSpinBox_i->setMinimum(-99);
        doubleSpinBox_i->setSingleStep(0.01);
        doubleSpinBox_i->setValue(10);
        label_10 = new QLabel(NM_GUI_Izhikevich_2003);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(33, 178, 61, 15));

        retranslateUi(NM_GUI_Izhikevich_2003);

        comboBoxIntegrationMethod->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(NM_GUI_Izhikevich_2003);
    } // setupUi

    void retranslateUi(QWidget *NM_GUI_Izhikevich_2003)
    {
        NM_GUI_Izhikevich_2003->setWindowTitle(QApplication::translate("NM_GUI_Izhikevich_2003", "Izhikevich (2003) neuron model", Q_NULLPTR));
        label->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "Parameters", Q_NULLPTR));
        label_2->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "Initial values", Q_NULLPTR));
        label_3->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "Integration method", Q_NULLPTR));
        label_4->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "A", Q_NULLPTR));
        label_5->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "B", Q_NULLPTR));
        label_6->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "C", Q_NULLPTR));
        label_7->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "D", Q_NULLPTR));
        label_8->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "V", Q_NULLPTR));
        label_9->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "U", Q_NULLPTR));
        comboBoxIntegrationMethod->clear();
        comboBoxIntegrationMethod->insertItems(0, QStringList()
         << QApplication::translate("NM_GUI_Izhikevich_2003", "Euler", Q_NULLPTR)
         << QApplication::translate("NM_GUI_Izhikevich_2003", "Heun", Q_NULLPTR)
         << QApplication::translate("NM_GUI_Izhikevich_2003", "Runge-Kutta 4", Q_NULLPTR)
         << QApplication::translate("NM_GUI_Izhikevich_2003", "Runge-Kutta (6)5", Q_NULLPTR)
        );
        pushButton_accept->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "Accept", Q_NULLPTR));
        label_10->setText(QApplication::translate("NM_GUI_Izhikevich_2003", "I", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NM_GUI_Izhikevich_2003: public Ui_NM_GUI_Izhikevich_2003 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NM_GUI_IZHIKEVICH_2003_H
