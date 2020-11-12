/********************************************************************************
** Form generated from reading UI file 'TRequestDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREQUESTDLG_H
#define UI_TREQUESTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TRequestDlg
{
public:
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QGroupBox *requestGroup;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_6;
    QFrame *line;
    QLineEdit *numberEdit;
    QComboBox *importanceCombo;
    QComboBox *typeCombo;
    QComboBox *statusCombo;
    QComboBox *clientCombo;
    QDateEdit *requestDateEdit;
    QPlainTextEdit *requestNoteEdit;
    QLabel *label_7;
    QLineEdit *addressEdit;
    QLineEdit *contactEdit;
    QLabel *label_12;
    QGroupBox *realizeGroup;
    QPlainTextEdit *realizeNoteEdit;
    QDateEdit *realizeDateEdit;
    QLabel *label_5;
    QComboBox *performerCombo;
    QLabel *performerLbl;
    QLabel *label_11;
    QFrame *line_3;
    QPlainTextEdit *workersEdit;
    QPushButton *addBtn;

    void setupUi(QDialog *TRequestDlg)
    {
        if (TRequestDlg->objectName().isEmpty())
            TRequestDlg->setObjectName(QStringLiteral("TRequestDlg"));
        TRequestDlg->resize(560, 304);
        TRequestDlg->setMinimumSize(QSize(560, 304));
        TRequestDlg->setMaximumSize(QSize(560, 304));
        okBtn = new QPushButton(TRequestDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(436, 8, 120, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/ok"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);
        cancelBtn = new QPushButton(TRequestDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(436, 32, 120, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);
        requestGroup = new QGroupBox(TRequestDlg);
        requestGroup->setObjectName(QStringLiteral("requestGroup"));
        requestGroup->setGeometry(QRect(4, 4, 212, 296));
        label_2 = new QLabel(requestGroup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(4, 16, 80, 14));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(requestGroup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(4, 38, 80, 14));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(requestGroup);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(4, 62, 80, 14));
        label_9->setFrameShape(QFrame::NoFrame);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(requestGroup);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(4, 86, 80, 14));
        label_8->setFrameShape(QFrame::NoFrame);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(requestGroup);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(4, 110, 80, 14));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(requestGroup);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(4, 208, 204, 16));
        label_10->setFrameShape(QFrame::NoFrame);
        label_10->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(requestGroup);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(4, 134, 80, 16));
        label_6->setFrameShape(QFrame::NoFrame);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(requestGroup);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(4, 204, 204, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        numberEdit = new QLineEdit(requestGroup);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));
        numberEdit->setGeometry(QRect(88, 12, 120, 22));
        numberEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        importanceCombo = new QComboBox(requestGroup);
        importanceCombo->setObjectName(QStringLiteral("importanceCombo"));
        importanceCombo->setGeometry(QRect(88, 36, 120, 22));
        typeCombo = new QComboBox(requestGroup);
        typeCombo->setObjectName(QStringLiteral("typeCombo"));
        typeCombo->setGeometry(QRect(88, 60, 120, 22));
        statusCombo = new QComboBox(requestGroup);
        statusCombo->setObjectName(QStringLiteral("statusCombo"));
        statusCombo->setGeometry(QRect(88, 84, 120, 22));
        clientCombo = new QComboBox(requestGroup);
        clientCombo->setObjectName(QStringLiteral("clientCombo"));
        clientCombo->setGeometry(QRect(88, 132, 120, 22));
        requestDateEdit = new QDateEdit(requestGroup);
        requestDateEdit->setObjectName(QStringLiteral("requestDateEdit"));
        requestDateEdit->setGeometry(QRect(88, 108, 120, 22));
        requestDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        requestDateEdit->setCalendarPopup(true);
        requestNoteEdit = new QPlainTextEdit(requestGroup);
        requestNoteEdit->setObjectName(QStringLiteral("requestNoteEdit"));
        requestNoteEdit->setGeometry(QRect(4, 228, 204, 64));
        label_7 = new QLabel(requestGroup);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(4, 158, 80, 14));
        label_7->setFrameShape(QFrame::NoFrame);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        addressEdit = new QLineEdit(requestGroup);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        addressEdit->setGeometry(QRect(88, 156, 120, 22));
        addressEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        contactEdit = new QLineEdit(requestGroup);
        contactEdit->setObjectName(QStringLiteral("contactEdit"));
        contactEdit->setGeometry(QRect(88, 180, 120, 22));
        contactEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_12 = new QLabel(requestGroup);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(4, 182, 80, 14));
        label_12->setFrameShape(QFrame::NoFrame);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        realizeGroup = new QGroupBox(TRequestDlg);
        realizeGroup->setObjectName(QStringLiteral("realizeGroup"));
        realizeGroup->setGeometry(QRect(220, 4, 212, 296));
        realizeNoteEdit = new QPlainTextEdit(realizeGroup);
        realizeNoteEdit->setObjectName(QStringLiteral("realizeNoteEdit"));
        realizeNoteEdit->setGeometry(QRect(4, 228, 204, 64));
        realizeDateEdit = new QDateEdit(realizeGroup);
        realizeDateEdit->setObjectName(QStringLiteral("realizeDateEdit"));
        realizeDateEdit->setGeometry(QRect(88, 12, 120, 22));
        realizeDateEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        realizeDateEdit->setCalendarPopup(true);
        label_5 = new QLabel(realizeGroup);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(4, 14, 80, 14));
        label_5->setFrameShape(QFrame::NoFrame);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        performerCombo = new QComboBox(realizeGroup);
        performerCombo->setObjectName(QStringLiteral("performerCombo"));
        performerCombo->setGeometry(QRect(88, 36, 120, 22));
        performerLbl = new QLabel(realizeGroup);
        performerLbl->setObjectName(QStringLiteral("performerLbl"));
        performerLbl->setGeometry(QRect(4, 38, 80, 14));
        performerLbl->setFrameShape(QFrame::NoFrame);
        performerLbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(realizeGroup);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(4, 208, 204, 16));
        label_11->setFrameShape(QFrame::NoFrame);
        label_11->setAlignment(Qt::AlignCenter);
        line_3 = new QFrame(realizeGroup);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(4, 204, 204, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        workersEdit = new QPlainTextEdit(realizeGroup);
        workersEdit->setObjectName(QStringLiteral("workersEdit"));
        workersEdit->setGeometry(QRect(4, 92, 204, 109));
        addBtn = new QPushButton(realizeGroup);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(132, 64, 76, 23));
        QWidget::setTabOrder(numberEdit, importanceCombo);
        QWidget::setTabOrder(importanceCombo, typeCombo);
        QWidget::setTabOrder(typeCombo, statusCombo);
        QWidget::setTabOrder(statusCombo, requestDateEdit);
        QWidget::setTabOrder(requestDateEdit, clientCombo);
        QWidget::setTabOrder(clientCombo, addressEdit);
        QWidget::setTabOrder(addressEdit, contactEdit);
        QWidget::setTabOrder(contactEdit, requestNoteEdit);
        QWidget::setTabOrder(requestNoteEdit, realizeDateEdit);
        QWidget::setTabOrder(realizeDateEdit, performerCombo);
        QWidget::setTabOrder(performerCombo, addBtn);
        QWidget::setTabOrder(addBtn, workersEdit);
        QWidget::setTabOrder(workersEdit, realizeNoteEdit);
        QWidget::setTabOrder(realizeNoteEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(TRequestDlg);

        okBtn->setDefault(true);


        QMetaObject::connectSlotsByName(TRequestDlg);
    } // setupUi

    void retranslateUi(QDialog *TRequestDlg)
    {
        TRequestDlg->setWindowTitle(QApplication::translate("TRequestDlg", "Request", 0));
        okBtn->setText(QApplication::translate("TRequestDlg", "Ok", 0));
        cancelBtn->setText(QApplication::translate("TRequestDlg", "Cancel", 0));
        requestGroup->setTitle(QApplication::translate("TRequestDlg", "Request", 0));
        label_2->setText(QApplication::translate("TRequestDlg", "Number", 0));
        label_3->setText(QApplication::translate("TRequestDlg", "Importance", 0));
        label_9->setText(QApplication::translate("TRequestDlg", "Type", 0));
        label_8->setText(QApplication::translate("TRequestDlg", "Status", 0));
        label_4->setText(QApplication::translate("TRequestDlg", "Request date", 0));
        label_10->setText(QApplication::translate("TRequestDlg", "Note", 0));
        label_6->setText(QApplication::translate("TRequestDlg", "Client", 0));
        label_7->setText(QApplication::translate("TRequestDlg", "Address", 0));
        label_12->setText(QApplication::translate("TRequestDlg", "Contact", 0));
        realizeGroup->setTitle(QApplication::translate("TRequestDlg", "Realize", 0));
        label_5->setText(QApplication::translate("TRequestDlg", "Ralize date", 0));
        performerLbl->setText(QApplication::translate("TRequestDlg", "Performer", 0));
        label_11->setText(QApplication::translate("TRequestDlg", "Note", 0));
        addBtn->setText(QApplication::translate("TRequestDlg", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class TRequestDlg: public Ui_TRequestDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREQUESTDLG_H
