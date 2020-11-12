#ifndef TFILTERDLG_H
#define TFILTERDLG_H

#include "ui_TFilterDlg.h"

class TRequestModel;
class TTypeModel;
class TClientModel;
class TPerformerModel;

class TFilterDlg : public QDialog, private Ui::TFilterDlg
 {
 Q_OBJECT

 public:
  explicit TFilterDlg(QWidget *parent = 0,TRequestModel *requestModel=0, TTypeModel *typeModel=0,
                      TClientModel *clientModel=0, TPerformerModel *performerModel=0);
  QString filter();

 public slots:
  void okBtnClicked();
  void cancelBtnClicked();

 private:
  TRequestModel *m_requestModel;
  QString m_filter;
 };

#endif // TFILTERDLG_H
