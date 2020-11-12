#include "TLoginDlg.h"
#include <QCryptographicHash>

TLoginDlg::TLoginDlg(QWidget *parent) : QDialog(parent)
 {
 setupUi(this);

 connect(okBtn,SIGNAL(clicked()),this,SLOT(okBtnClicked()));
 connect(cancelBtn,SIGNAL(clicked()),this,SLOT(cancelBtnClicked()));
 }
//
void TLoginDlg::okBtnClicked()
 {
 QCryptographicHash hash(QCryptographicHash::Md5);
 m_user=hash.hash(userEdit->text().toLatin1(),QCryptographicHash::Md5).toHex();
 m_password=hash.hash(passwordEdit->text().toLatin1(),QCryptographicHash::Md5).toHex();
 accept();
 return;
 }
//
void TLoginDlg::cancelBtnClicked()
 {
 m_user=QString();
 m_password=QString();
 reject();
 return;
 }
//
QStringList TLoginDlg::loginInfo()
 {
 QStringList login;
 login<<m_user<<m_password;
 return login;
 }
