#include "TRequestDlg.h"
#include "TRequestModel.h"
#include "TTypeModel.h"
#include "TClientModel.h"
#include "TPerformerModel.h"

#include <QSqlRecord>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlField>

TRequestDlg::TRequestDlg(QWidget *parent, TRequestModel *requestModel, TTypeModel *typeModel, TClientModel *clientModel,
                         TPerformerModel *performerModel,int id) : QDialog(parent), m_requestModel(requestModel), m_id(id)
 {
 setupUi(this);

 connect(okBtn,SIGNAL(clicked()),this,SLOT(okBtnClicked()));
 connect(cancelBtn,SIGNAL(clicked()),this,SLOT(cancelBtnClicked()));

 connect(addBtn,SIGNAL(clicked()),this,SLOT(addBtnClicked()));

 importanceCombo->addItem(tr("Ordinary"),(int)TRequestModel::Ordinary);
 importanceCombo->addItem(tr("Important"),(int)TRequestModel::Important);
 importanceCombo->setCurrentIndex(-1);

 statusCombo->addItem(tr("In work"),TRequestModel::InWork);
 statusCombo->addItem(tr("Canceled"),TRequestModel::Canceled);
 statusCombo->addItem(tr("Realized"),TRequestModel::Realized);
 statusCombo->setCurrentIndex(-1);

 //typeCombo->addItem(QString(),-1);
 for (int i=0;i<typeModel->rowCount();i++)
  typeCombo->addItem(typeModel->data(typeModel->index(i,typeModel->fieldIndex("type"))).toString(),
                     typeModel->data(typeModel->index(i,typeModel->fieldIndex("id"))).toInt());

 for (int i=0;i<clientModel->rowCount();i++)
  clientCombo->addItem(clientModel->data(clientModel->index(i,clientModel->fieldIndex("client"))).toString(),
                       clientModel->data(clientModel->index(i,clientModel->fieldIndex("id"))).toInt());

 for (int i=0;i<performerModel->rowCount();i++)
  performerCombo->addItem(performerModel->data(performerModel->index(i,performerModel->fieldIndex("performer"))).toString(),
                          performerModel->data(performerModel->index(i,performerModel->fieldIndex("id"))).toInt());

 if (m_id!=-1)
  {
  int row=0;
  int column=m_requestModel->fieldIndex("id");

  QModelIndexList items=m_requestModel->match(m_requestModel->index(row,column),Qt::DisplayRole,m_id,1,Qt::MatchExactly);
  if (items.size())
   {
   row=items.first().row();
   numberEdit->setText(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("number"))).toString());
   importanceCombo->setCurrentIndex(importanceCombo->findData(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("importance")),Qt::UserRole).toInt()));
   statusCombo->setCurrentIndex(statusCombo->findData(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("status")),Qt::UserRole).toInt()));
   typeCombo->setCurrentIndex(typeCombo->findData(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("type_id")),Qt::UserRole).toInt()));
   clientCombo->setCurrentIndex(clientCombo->findData(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("client_id")),Qt::UserRole).toInt()));
   performerCombo->setCurrentIndex(performerCombo->findData(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("performer_id")),Qt::UserRole).toInt()));
   addressEdit->setText(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("address")),Qt::UserRole).toString());
   contactEdit->setText(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("contact")),Qt::UserRole).toString());
   requestDateEdit->setDate(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("request_date")),Qt::UserRole).toDate());
   realizeDateEdit->setDate(m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("realize_date")),Qt::UserRole).toDate());
   workersEdit->setPlainText(m_requestModel->data(m_requestModel->index(row,requestModel->fieldIndex("workers"))).toString());
   requestNoteEdit->setPlainText(m_requestModel->data(m_requestModel->index(row,requestModel->fieldIndex("request_note"))).toString());
   realizeNoteEdit->setPlainText(m_requestModel->data(m_requestModel->index(row,requestModel->fieldIndex("realize_note"))).toString());
   }
  }
 else
  {
  numberEdit->setEnabled(false);
  requestDateEdit->setDate(QDate::currentDate());
  realizeDateEdit->setDate(QDate::currentDate().addDays(3));
  }
 }
//
void TRequestDlg::okBtnClicked()
 {
 QSqlRecord record;
 int row=0;
 int column;
 QModelIndexList items;

 if (m_id==-1)
  {
  column=m_requestModel->fieldIndex("number");
  items=m_requestModel->match(m_requestModel->index(row,column),Qt::DisplayRole,numberEdit->text(),1,Qt::MatchExactly);

  if (!items.size())
   {
   record.append(QSqlField("number",QVariant::String));
   record.append(QSqlField("type_id",QVariant::Int));
   record.append(QSqlField("importance",QVariant::Int));
   record.append(QSqlField("status",QVariant::Int));
   record.append(QSqlField("request_date",QVariant::Date));
   record.append(QSqlField("client_id",QVariant::Int));
   record.append(QSqlField("address",QVariant::String));
   record.append(QSqlField("contact",QVariant::String));
   record.append(QSqlField("request_note",QVariant::String));
   record.append(QSqlField("realize_date",QVariant::Date));
   record.append(QSqlField("performer_id",QVariant::Int));
   record.append(QSqlField("workers",QVariant::String));
   record.append(QSqlField("realize_note",QVariant::String));

   record.setValue("number",numberEdit->text());
   record.setValue("request_date",requestDateEdit->date());
   record.setValue("realize_date",realizeDateEdit->date());
   record.setValue("importance",(importanceCombo->currentIndex()==-1) ? -1 : importanceCombo->currentData().toInt());
   record.setValue("status",(statusCombo->currentIndex()==-1) ? -1 : statusCombo->currentData().toInt());
   record.setValue("type_id",typeCombo->currentData().toInt());
   record.setValue("client_id",clientCombo->currentData().toInt());
   record.setValue("address",addressEdit->text());
   record.setValue("contact",contactEdit->text());
   record.setValue("performer_id",performerCombo->currentData().toInt());
   record.setValue("request_note",requestNoteEdit->toPlainText());
   record.setValue("realize_note",realizeNoteEdit->toPlainText());
   record.setValue("workers",workersEdit->toPlainText());

   m_requestModel->insertRecord(-1,record);//qDebug()<<m_requestModel->database().lastError();
   }
  }
 else
  {
  column=m_requestModel->fieldIndex("id");

  QModelIndexList items=m_requestModel->match(m_requestModel->index(row,column),Qt::DisplayRole,m_id,1,Qt::MatchExactly);
  if (items.size())
   {
   row=items.first().row();

   record=m_requestModel->record(row);
   record.setValue("number",numberEdit->text());
   record.setValue("request_date",requestDateEdit->date());
   record.setValue("realize_date",realizeDateEdit->date());
   record.setValue("importance",importanceCombo->currentData().toInt());
   record.setValue("status",statusCombo->currentData().toInt());
   record.setValue("type_id",typeCombo->currentData().toInt());
   record.setValue("client_id",clientCombo->currentData().toInt());
   record.setValue("address",addressEdit->text());
   record.setValue("contact",contactEdit->text());
   record.setValue("performer_id",performerCombo->currentData().toInt());
   record.setValue("request_note",requestNoteEdit->toPlainText());
   record.setValue("realize_note",realizeNoteEdit->toPlainText());
   record.setValue("workers",workersEdit->toPlainText());

   m_requestModel->setRecord(row,record);
   }
  }
 m_requestModel->refresh();

 accept();
 return;
 }
//
void TRequestDlg::cancelBtnClicked()
 {
 reject();
 return;
 }
//
QString TRequestDlg::number()
 {
 return numberEdit->text();
 }
//
void TRequestDlg::addBtnClicked()
 {
 QString worker=performerCombo->currentText();
 if (!workersEdit->toPlainText().contains(worker))
  workersEdit->appendPlainText(worker);
 return;
 }
