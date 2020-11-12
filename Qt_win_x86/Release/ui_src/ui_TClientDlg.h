/********************************************************************************
** Form generated from reading UI file 'TClientDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCLIENTDLG_H
#define UI_TCLIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TClientDlg
{
public:
    QPushButton *cancelBtn;
    QGroupBox *clientGroup;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_6;
    QFrame *line;
    QLineEdit *clientEdit;
    QPlainTextEdit *contactEdit;
    QLineEdit *streetEdit;
    QLineEdit *houseEdit;
    QLineEdit *apartmentEdit;
    QLineEdit *personEdit;
    QPushButton *okBtn;

    void setupUi(QDialog *TClientDlg)
    {
        if (TClientDlg->objectName().isEmpty())
            TClientDlg->setObjectName(QStringLiteral("TClientDlg"));
        TClientDlg->resize(340, 232);
        TClientDlg->setMinimumSize(QSize(340, 232));
        TClientDlg->setMaximumSize(QSize(340, 232));
        cancelBtn = new QPushButton(TClientDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(220, 36, 120, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon);
        clientGroup = new QGroupBox(TClientDlg);
        clientGroup->setObjectName(QStringLiteral("clientGroup"));
        clientGroup->setGeometry(QRect(4, 4, 212, 228));
        label_2 = new QLabel(clientGroup);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(4, 16, 80, 14));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(clientGroup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(4, 38, 80, 14));
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(clientGroup);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(4, 62, 80, 14));
        label_9->setFrameShape(QFrame::NoFrame);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(clientGroup);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(4, 86, 80, 14));
        label_8->setFrameShape(QFrame::NoFrame);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(clientGroup);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(4, 140, 204, 16));
        label_10->setFrameShape(QFrame::NoFrame);
        label_10->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(clientGroup);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(4, 110, 80, 16));
        label_6->setFrameShape(QFrame::NoFrame);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(clientGroup);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(4, 136, 204, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        clientEdit = new QLineEdit(clientGroup);
        clientEdit->setObjectName(QStringLiteral("clientEdit"));
        clientEdit->setGeometry(QRect(88, 12, 120, 22));
        contactEdit = new QPlainTextEdit(clientGroup);
        contactEdit->setObjectName(QStringLiteral("contactEdit"));
        contactEdit->setGeometry(QRect(4, 160, 204, 64));
        streetEdit = new QLineEdit(clientGroup);
        streetEdit->setObjectName(QStringLiteral("streetEdit"));
        streetEdit->setGeometry(QRect(88, 36, 120, 22));
        houseEdit = new QLineEdit(clientGroup);
        houseEdit->setObjectName(QStringLiteral("houseEdit"));
        houseEdit->setGeometry(QRect(88, 60, 120, 22));
        houseEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        apartmentEdit = new QLineEdit(clientGroup);
        apartmentEdit->setObjectName(QStringLiteral("apartmentEdit"));
        apartmentEdit->setGeometry(QRect(88, 84, 120, 22));
        apartmentEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        personEdit = new QLineEdit(clientGroup);
        personEdit->setObjectName(QStringLiteral("personEdit"));
        personEdit->setGeometry(QRect(88, 108, 120, 22));
        okBtn = new QPushButton(TClientDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(220, 12, 120, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ok"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon1);
        QWidget::setTabOrder(clientEdit, streetEdit);
        QWidget::setTabOrder(streetEdit, houseEdit);
        QWidget::setTabOrder(houseEdit, apartmentEdit);
        QWidget::setTabOrder(apartmentEdit, personEdit);
        QWidget::setTabOrder(personEdit, contactEdit);
        QWidget::setTabOrder(contactEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(TClientDlg);

        okBtn->setDefault(true);


        QMetaObject::connectSlotsByName(TClientDlg);
    } // setupUi

    void retranslateUi(QDialog *TClientDlg)
    {
        TClientDlg->setWindowTitle(QApplication::translate("TClientDlg", "Client", 0));
        cancelBtn->setText(QApplication::translate("TClientDlg", "Cancel", 0));
        clientGroup->setTitle(QApplication::translate("TClientDlg", "Client", 0));
        label_2->setText(QApplication::translate("TClientDlg", "Client", 0));
        label_3->setText(QApplication::translate("TClientDlg", "Street", 0));
        label_9->setText(QApplication::translate("TClientDlg", "House", 0));
        label_8->setText(QApplication::translate("TClientDlg", "Apartment", 0));
        label_10->setText(QApplication::translate("TClientDlg", "Contacts", 0));
        label_6->setText(QApplication::translate("TClientDlg", "Person", 0));
        okBtn->setText(QApplication::translate("TClientDlg", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class TClientDlg: public Ui_TClientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCLIENTDLG_H
