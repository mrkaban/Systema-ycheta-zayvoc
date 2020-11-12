#ifndef TREQUESTDLG_H
#define TREQUESTDLG_H

#include "ui_TRequestDlg.h"

class TRequestModel;
class TTypeModel;
class TClientModel;
class TPerformerModel;

class TRequestDlg : public QDialog, private Ui::TRequestDlg
 {
  Q_OBJECT

 public:
  explicit TRequestDlg(QWidget *parent = 0, TRequestModel *requestModel=0, TTypeModel *typeModel=0,
                       TClientModel *clientModel=0, TPerformerModel *performerModel=0, int id=-1);

  QString number();

 private:
  TRequestModel *m_requestModel;
  //TTypeModel m_typeModel;
  int m_id;

 public slots:
  void okBtnClicked();
  void cancelBtnClicked();

  void addBtnClicked();
 };

#endif // TREQUESTDLG_H
