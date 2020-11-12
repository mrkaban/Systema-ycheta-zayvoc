/********************************************************************************
** Form generated from reading UI file 'TLoginDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TLOGINDLG_H
#define UI_TLOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TLoginDlg
{
public:
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QFrame *frame;
    QLabel *label_11;
    QLineEdit *userEdit;
    QLabel *label;
    QLineEdit *passwordEdit;

    void setupUi(QDialog *TLoginDlg)
    {
        if (TLoginDlg->objectName().isEmpty())
            TLoginDlg->setObjectName(QStringLiteral("TLoginDlg"));
        TLoginDlg->resize(256, 100);
        TLoginDlg->setMinimumSize(QSize(256, 100));
        TLoginDlg->setMaximumSize(QSize(256, 100));
        cancelBtn = new QPushButton(TLoginDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(136, 36, 120, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon);
        okBtn = new QPushButton(TLoginDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(136, 12, 120, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ok"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon1);
        frame = new QFrame(TLoginDlg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(4, 8, 128, 88));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(4, 4, 120, 16));
        label_11->setFrameShape(QFrame::NoFrame);
        label_11->setAlignment(Qt::AlignCenter);
        userEdit = new QLineEdit(frame);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setGeometry(QRect(4, 24, 120, 20));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(4, 44, 120, 16));
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);
        passwordEdit = new QLineEdit(frame);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(4, 64, 120, 20));
        passwordEdit->setEchoMode(QLineEdit::Password);
        label_11->raise();
        label_11->raise();
        userEdit->raise();
        label->raise();
        passwordEdit->raise();
        QWidget::setTabOrder(userEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(TLoginDlg);

        okBtn->setDefault(true);


        QMetaObject::connectSlotsByName(TLoginDlg);
    } // setupUi

    void retranslateUi(QDialog *TLoginDlg)
    {
        TLoginDlg->setWindowTitle(QApplication::translate("TLoginDlg", "Login", 0));
        cancelBtn->setText(QApplication::translate("TLoginDlg", "Cancel", 0));
        okBtn->setText(QApplication::translate("TLoginDlg", "Ok", 0));
        label_11->setText(QApplication::translate("TLoginDlg", "User", 0));
        label->setText(QApplication::translate("TLoginDlg", "Password", 0));
    } // retranslateUi

};

namespace Ui {
    class TLoginDlg: public Ui_TLoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TLOGINDLG_H
