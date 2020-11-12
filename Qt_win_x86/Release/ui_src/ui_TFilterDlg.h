/********************************************************************************
** Form generated from reading UI file 'TFilterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TFILTERDLG_H
#define UI_TFILTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TFilterDlg
{
public:
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QGroupBox *filterGroup;
    QComboBox *clientCombo;
    QComboBox *importanceCombo;
    QDateEdit *requestFromDateEdit;
    QComboBox *typeCombo;
    QComboBox *statusCombo;
    QDateEdit *realizeFromDateEdit;
    QComboBox *performerCombo;
    QDateEdit *requestToDateEdit;
    QDateEdit *realizeToDateEdit;
    QLineEdit *addressEdit;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_10;
    QLabel *label_11;
    QCheckBox *clientCheck;
    QCheckBox *addressCheck;
    QCheckBox *performerCheck;
    QCheckBox *importanceCheck;
    QCheckBox *typeCheck;
    QCheckBox *statusCheck;
    QCheckBox *requestCheck;
    QCheckBox *realizeCheck;
    QCheckBox *numberCheck;
    QLineEdit *numberEdit;

    void setupUi(QDialog *TFilterDlg)
    {
        if (TFilterDlg->objectName().isEmpty())
            TFilterDlg->setObjectName(QStringLiteral("TFilterDlg"));
        TFilterDlg->resize(576, 180);
        TFilterDlg->setMinimumSize(QSize(576, 180));
        TFilterDlg->setMaximumSize(QSize(576, 180));
        cancelBtn = new QPushButton(TFilterDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(452, 36, 120, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon);
        okBtn = new QPushButton(TFilterDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(452, 12, 120, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ok"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon1);
        filterGroup = new QGroupBox(TFilterDlg);
        filterGroup->setObjectName(QStringLiteral("filterGroup"));
        filterGroup->setGeometry(QRect(4, 4, 444, 176));
        clientCombo = new QComboBox(filterGroup);
        clientCombo->setObjectName(QStringLiteral("clientCombo"));
        clientCombo->setGeometry(QRect(100, 36, 120, 22));
        importanceCombo = new QComboBox(filterGroup);
        importanceCombo->setObjectName(QStringLiteral("importanceCombo"));
        importanceCombo->setGeometry(QRect(320, 36, 120, 22));
        requestFromDateEdit = new QDateEdit(filterGroup);
        requestFromDateEdit->setObjectName(QStringLiteral("requestFromDateEdit"));
        requestFromDateEdit->setGeometry(QRect(100, 116, 120, 22));
        requestFromDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        requestFromDateEdit->setCalendarPopup(true);
        typeCombo = new QComboBox(filterGroup);
        typeCombo->setObjectName(QStringLiteral("typeCombo"));
        typeCombo->setGeometry(QRect(320, 60, 120, 22));
        statusCombo = new QComboBox(filterGroup);
        statusCombo->setObjectName(QStringLiteral("statusCombo"));
        statusCombo->setGeometry(QRect(320, 84, 120, 22));
        realizeFromDateEdit = new QDateEdit(filterGroup);
        realizeFromDateEdit->setObjectName(QStringLiteral("realizeFromDateEdit"));
        realizeFromDateEdit->setGeometry(QRect(100, 148, 120, 22));
        realizeFromDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        realizeFromDateEdit->setCalendarPopup(true);
        performerCombo = new QComboBox(filterGroup);
        performerCombo->setObjectName(QStringLiteral("performerCombo"));
        performerCombo->setGeometry(QRect(100, 84, 120, 22));
        requestToDateEdit = new QDateEdit(filterGroup);
        requestToDateEdit->setObjectName(QStringLiteral("requestToDateEdit"));
        requestToDateEdit->setGeometry(QRect(320, 116, 120, 22));
        requestToDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        requestToDateEdit->setCalendarPopup(true);
        realizeToDateEdit = new QDateEdit(filterGroup);
        realizeToDateEdit->setObjectName(QStringLiteral("realizeToDateEdit"));
        realizeToDateEdit->setGeometry(QRect(320, 148, 120, 22));
        realizeToDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        realizeToDateEdit->setCalendarPopup(true);
        addressEdit = new QLineEdit(filterGroup);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        addressEdit->setGeometry(QRect(100, 60, 120, 22));
        line = new QFrame(filterGroup);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(4, 110, 412, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(filterGroup);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(4, 142, 412, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(filterGroup);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(224, 120, 92, 14));
        label_10->setFrameShape(QFrame::NoFrame);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(filterGroup);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(224, 152, 92, 14));
        label_11->setFrameShape(QFrame::NoFrame);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        clientCheck = new QCheckBox(filterGroup);
        clientCheck->setObjectName(QStringLiteral("clientCheck"));
        clientCheck->setGeometry(QRect(4, 36, 92, 22));
        addressCheck = new QCheckBox(filterGroup);
        addressCheck->setObjectName(QStringLiteral("addressCheck"));
        addressCheck->setGeometry(QRect(4, 60, 92, 22));
        performerCheck = new QCheckBox(filterGroup);
        performerCheck->setObjectName(QStringLiteral("performerCheck"));
        performerCheck->setGeometry(QRect(4, 84, 92, 22));
        importanceCheck = new QCheckBox(filterGroup);
        importanceCheck->setObjectName(QStringLiteral("importanceCheck"));
        importanceCheck->setGeometry(QRect(224, 36, 92, 22));
        typeCheck = new QCheckBox(filterGroup);
        typeCheck->setObjectName(QStringLiteral("typeCheck"));
        typeCheck->setGeometry(QRect(224, 60, 92, 22));
        statusCheck = new QCheckBox(filterGroup);
        statusCheck->setObjectName(QStringLiteral("statusCheck"));
        statusCheck->setGeometry(QRect(224, 84, 92, 22));
        requestCheck = new QCheckBox(filterGroup);
        requestCheck->setObjectName(QStringLiteral("requestCheck"));
        requestCheck->setGeometry(QRect(4, 116, 92, 22));
        realizeCheck = new QCheckBox(filterGroup);
        realizeCheck->setObjectName(QStringLiteral("realizeCheck"));
        realizeCheck->setGeometry(QRect(4, 148, 92, 22));
        numberCheck = new QCheckBox(filterGroup);
        numberCheck->setObjectName(QStringLiteral("numberCheck"));
        numberCheck->setGeometry(QRect(4, 12, 92, 22));
        numberEdit = new QLineEdit(filterGroup);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));
        numberEdit->setGeometry(QRect(100, 12, 120, 22));
        QWidget::setTabOrder(numberCheck, numberEdit);
        QWidget::setTabOrder(numberEdit, clientCheck);
        QWidget::setTabOrder(clientCheck, clientCombo);
        QWidget::setTabOrder(clientCombo, addressCheck);
        QWidget::setTabOrder(addressCheck, addressEdit);
        QWidget::setTabOrder(addressEdit, performerCheck);
        QWidget::setTabOrder(performerCheck, performerCombo);
        QWidget::setTabOrder(performerCombo, importanceCheck);
        QWidget::setTabOrder(importanceCheck, importanceCombo);
        QWidget::setTabOrder(importanceCombo, typeCheck);
        QWidget::setTabOrder(typeCheck, typeCombo);
        QWidget::setTabOrder(typeCombo, statusCheck);
        QWidget::setTabOrder(statusCheck, statusCombo);
        QWidget::setTabOrder(statusCombo, requestCheck);
        QWidget::setTabOrder(requestCheck, requestFromDateEdit);
        QWidget::setTabOrder(requestFromDateEdit, requestToDateEdit);
        QWidget::setTabOrder(requestToDateEdit, realizeCheck);
        QWidget::setTabOrder(realizeCheck, realizeFromDateEdit);
        QWidget::setTabOrder(realizeFromDateEdit, realizeToDateEdit);
        QWidget::setTabOrder(realizeToDateEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(TFilterDlg);

        okBtn->setDefault(true);


        QMetaObject::connectSlotsByName(TFilterDlg);
    } // setupUi

    void retranslateUi(QDialog *TFilterDlg)
    {
        TFilterDlg->setWindowTitle(QApplication::translate("TFilterDlg", "Filter", 0));
        cancelBtn->setText(QApplication::translate("TFilterDlg", "Cancel", 0));
        okBtn->setText(QApplication::translate("TFilterDlg", "Ok", 0));
        filterGroup->setTitle(QApplication::translate("TFilterDlg", "Filter", 0));
        label_10->setText(QApplication::translate("TFilterDlg", "to", 0));
        label_11->setText(QApplication::translate("TFilterDlg", "to", 0));
        clientCheck->setText(QApplication::translate("TFilterDlg", "Client", 0));
        addressCheck->setText(QApplication::translate("TFilterDlg", "Address", 0));
        performerCheck->setText(QApplication::translate("TFilterDlg", "Performer", 0));
        importanceCheck->setText(QApplication::translate("TFilterDlg", "Importance", 0));
        typeCheck->setText(QApplication::translate("TFilterDlg", "Type", 0));
        statusCheck->setText(QApplication::translate("TFilterDlg", "Status", 0));
        requestCheck->setText(QApplication::translate("TFilterDlg", "Request from", 0));
        realizeCheck->setText(QApplication::translate("TFilterDlg", "Realiaze from", 0));
        numberCheck->setText(QApplication::translate("TFilterDlg", "Number", 0));
    } // retranslateUi

};

namespace Ui {
    class TFilterDlg: public Ui_TFilterDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TFILTERDLG_H
