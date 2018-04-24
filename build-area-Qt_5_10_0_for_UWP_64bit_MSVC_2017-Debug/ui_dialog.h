/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushBtn;
    QLabel *radiusLabel;
    QLabel *areaLabel_1;
    QLabel *areaLabel_2;
    QLineEdit *radiusLineEdit;
    QRadioButton *radioButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(941, 434);
        pushBtn = new QPushButton(Dialog);
        pushBtn->setObjectName(QStringLiteral("pushBtn"));
        pushBtn->setGeometry(QRect(650, 220, 93, 28));
        radiusLabel = new QLabel(Dialog);
        radiusLabel->setObjectName(QStringLiteral("radiusLabel"));
        radiusLabel->setGeometry(QRect(190, 140, 72, 15));
        areaLabel_1 = new QLabel(Dialog);
        areaLabel_1->setObjectName(QStringLiteral("areaLabel_1"));
        areaLabel_1->setGeometry(QRect(460, 140, 72, 15));
        areaLabel_2 = new QLabel(Dialog);
        areaLabel_2->setObjectName(QStringLiteral("areaLabel_2"));
        areaLabel_2->setGeometry(QRect(510, 140, 72, 15));
        areaLabel_2->setFrameShape(QFrame::Panel);
        areaLabel_2->setFrameShadow(QFrame::Sunken);
        radiusLineEdit = new QLineEdit(Dialog);
        radiusLineEdit->setObjectName(QStringLiteral("radiusLineEdit"));
        radiusLineEdit->setGeometry(QRect(240, 140, 113, 21));
        radioButton = new QRadioButton(Dialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(190, 260, 115, 19));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushBtn->setText(QApplication::translate("Dialog", "\350\256\241\347\256\227", nullptr));
        radiusLabel->setText(QApplication::translate("Dialog", "\345\215\212\345\276\204\357\274\232", nullptr));
        areaLabel_1->setText(QApplication::translate("Dialog", "\351\235\242\347\247\257\357\274\232", nullptr));
        areaLabel_2->setText(QString());
        radioButton->setText(QApplication::translate("Dialog", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
