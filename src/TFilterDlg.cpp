#include "TFilterDlg.h"

#include "TRequestModel.h"
#include "TTypeModel.h"
#include "TClientModel.h"
#include "TPerformerModel.h"

#include <QDebug>

TFilterDlg::TFilterDlg(QWidget *parent, TRequestModel *requestModel, TTypeModel *typeModel, TClientModel *clientModel, TPerformerModel *performerModel) :
            QDialog(parent), m_requestModel(requestModel)
 {
 setupUi(this);

 connect(okBtn,SIGNAL(clicked()),this,SLOT(okBtnClicked()));
 connect(cancelBtn,SIGNAL(clicked()),this,SLOT(cancelBtnClicked()));

 importanceCombo->addItem(tr("Ordinary"),(int)TRequestModel::Ordinary);
 importanceCombo->addItem(tr("Important"),(int)TRequestModel::Important);
 importanceCombo->setCurrentIndex(-1);

 statusCombo->addItem(tr("In work"),TRequestModel::InWork);
 statusCombo->addItem(tr("Canceled"),TRequestModel::Canceled);
 statusCombo->addItem(tr("Realized"),TRequestModel::Realized);
 importanceCombo->setCurrentIndex(-1);


 for (int i=0;i<clientModel->rowCount();i++)
  typeCombo->addItem(typeModel->data(typeModel->index(i,typeModel->fieldIndex("type"))).toString(),
                     typeModel->data(typeModel->index(i,typeModel->fieldIndex("id"))).toInt());

 for (int i=0;i<clientModel->rowCount();i++)
  clientCombo->addItem(clientModel->data(clientModel->index(i,clientModel->fieldIndex("client"))).toString(),
                       clientModel->data(clientModel->index(i,clientModel->fieldIndex("id"))).toInt());

 for (int i=0;i<performerModel->rowCount();i++)
  performerCombo->addItem(performerModel->data(performerModel->index(i,performerModel->fieldIndex("performer"))).toString(),
                          performerModel->data(performerModel->index(i,performerModel->fieldIndex("id"))).toInt());

 requestFromDateEdit->setDate(QDate::fromString("01.01.2001","dd.MM.yyyy"));
 realizeFromDateEdit->setDate(QDate::fromString("01.01.2001","dd.MM.yyyy"));

 requestToDateEdit->setDate(QDate::fromString("01.01.2021","dd.MM.yyyy"));
 realizeToDateEdit->setDate(QDate::fromString("01.01.2021","dd.MM.yyyy"));

 m_filter.clear();
 }
//
void TFilterDlg::okBtnClicked()
 { //
 if (numberCheck->isChecked())
  m_filter.append("number like '%"+numberEdit->text()+"%' and ");
 if (clientCheck->isChecked())
  m_filter.append("client_id="+clientCombo->currentData().toString()+" and ");
 if (addressCheck->isChecked())
  m_filter.append("address like '%"+addressEdit->text()+"%' and ");
 if (performerCheck->isChecked())
  m_filter.append("performert_id="+performerCombo->currentData().toString()+" and ");
 if (importanceCheck->isChecked())
  m_filter.append("importance="+importanceCombo->currentData().toString()+" and ");
 if (statusCheck->isChecked())
  m_filter.append("status="+statusCombo->currentData().toString()+" and ");
 if (typeCheck->isChecked())
  m_filter.append("type_id="+typeCombo->currentData().toString()+" and ");
 if (importanceCheck->isChecked())
  m_filter.append("importance="+importanceCombo->currentData().toString()+" and ");
 if (requestCheck->isChecked())
  m_filter.append("request_date between '"+requestFromDateEdit->date().toString("yyyy-MM-dd")+"' and '"
                  +requestToDateEdit->date().toString("yyyy-MM-dd")+"' and ");
 if (realizeCheck->isChecked())
  m_filter.append("realize_date between '"+realizeFromDateEdit->date().toString("yyyy-MM-dd")+"' and '"
                  +realizeToDateEdit->date().toString("yyyy-MM-dd")+"' and ");

 m_filter.remove(m_filter.size()-5,5);

 accept();
 return;
 }
//
void TFilterDlg::cancelBtnClicked()
 {
 m_filter.clear();
 reject();
 return;
 }
//
QString TFilterDlg::filter()
 {
 return m_filter;
 }
