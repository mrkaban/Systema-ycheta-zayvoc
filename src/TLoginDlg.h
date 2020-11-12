#ifndef TLOGINDLG_H
#define TLOGINDLG_H

#include "ui_TLoginDlg.h"

class TLoginDlg : public QDialog, private Ui::TLoginDlg
 {
 Q_OBJECT

 public:
  explicit TLoginDlg(QWidget *parent = 0);
  QStringList loginInfo();

 public slots:
  void okBtnClicked();
  void cancelBtnClicked();

 private:
  QString m_user;
  QString m_password;
 };

#endif // TLOGINDLG_H
