#include "TMainWnd.h"
#include "TCommon.h"
#include "TRequestModel.h"
#include "TRequestDelegate.h"
#include "TClientModel.h"
#include "TPerformerModel.h"
#include "TTypeModel.h"

#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QPushButton>
#include <QInputDialog>

#include <QSqlRecord>

#include "TRequestDlg.h"
#include "TFilterDlg.h"

#include <QFileDialog>
#include <QProgressDialog>

#include <QPrintDialog>
#include <QPrinter>
#include <QPrintPreviewDialog>

#include <QTextDocument>
#include <QCloseEvent>

//#include "TLoginDlg.h"

TMainWnd::TMainWnd(QWidget *parent) : QMainWindow(parent)
 {
 setupUi(this);

 initDBase();
 initCore();
 initIface();
 }
//
void TMainWnd::initDBase()
 {
 // Инициализируем SQL БД
 m_requestBase=QSqlDatabase::addDatabase("QSQLITE","requestBase");
 m_requestBase.setDatabaseName(qApp->applicationDirPath()+"/dbase/request.db");

 if (!QFile::exists(m_requestBase.databaseName()) || !m_requestBase.open())
  {
  QMessageBox::critical(this,tr("Error"),tr("Can't open database file.\n%1\nProgram now exit.").arg(m_requestBase.databaseName()));
  exit(0);
  }
 return;
 }
//
void TMainWnd::initCore()
 {
 connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(aboutToQuit()));

 // модель представления таблицы заказов
 m_requestModel=new TRequestModel(this,m_requestBase,requestTable);
 requestTable->setModel(m_requestModel);

 // это экземпляр класса для делегирования представления, тут переопределяются всякие интерфейсные штучки
 // например цвет строк и т.п.
 m_requestDelegate=new TRequestDelegate(this);
 // для таблицы в интерфейсе говорим, что будет отображать такую-то модель, а рисовать согласно такому-то делегату

 requestTable->setItemDelegate(m_requestDelegate);

 // модель представления таблицы клиентов
 m_clientModel=new TClientModel(this,m_requestBase);
 clientTable->setModel(m_clientModel);
 // модель представления списка исполнителей
 m_performerModel=new TPerformerModel(this,m_requestBase);
 performerTable->setModel(m_performerModel);
 // модель представления списка типов работ
 m_typeModel=new TTypeModel(this,m_requestBase);
 typeTable->setModel(m_typeModel);

 connect(requestTable,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(requestTableContextMenu(QPoint)));
 connect(requestTable->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(requestTableRowChanged(QModelIndex,QModelIndex)));
 connect(clientTable,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(clientTableContextMenu(QPoint)));
 connect(performerTable,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(performerListContextMenu(QPoint)));
 connect(typeTable,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(typeListContextMenu(QPoint)));

 connect(requestTable,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(requestDoubleClicked(QModelIndex)));
 connect(clientTable,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(clientDoubleClicked(QModelIndex)));
 connect(typeTable,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(typeDoubleClicked(QModelIndex)));
 connect(performerTable,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(performerDoubleClicked(QModelIndex)));

 appendRequestActn=new QAction(QIcon(":images/append"),tr("Append request"),this);
 appendRequestActn->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_I));
 connect(appendRequestActn,SIGNAL(triggered()),this,SLOT(appendRequest()));
 editRequestActn=new QAction(QIcon(":images/edit"),tr("Edit request"),this);
 appendRequestActn->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_E));
 connect(editRequestActn,SIGNAL(triggered()),this,SLOT(editRequest()));
 removeRequestActn=new QAction(QIcon(":images/remove"),tr("Remove request"),this);
 appendRequestActn->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_D));
 connect(removeRequestActn,SIGNAL(triggered()),this,SLOT(removeRequest()));

 filterRequestActn=new QAction(QIcon(":images/filter"),tr("Filter requests"),this);
 filterRequestActn->setCheckable(true);
 connect(filterRequestActn,SIGNAL(triggered(bool)),this,SLOT(filterRequest(bool)));
 reportRequestActn=new QAction(QIcon(":images/report"),tr("Requests report"),this);
 connect(reportRequestActn,SIGNAL(triggered()),this,SLOT(reportRequest()));

 previewRequestActn=new QAction(QIcon(":images/preview"),tr("Preview request"),this);
 connect(previewRequestActn,SIGNAL(triggered()),this,SLOT(previewRequest()));

 printRequestActn=new QAction(QIcon(":images/print"),tr("Print request"),this);
 connect(printRequestActn,SIGNAL(triggered()),this,SLOT(printRequest()));

 appendClientActn=new QAction(QIcon(":images/append"),tr("Append client"),this);
 connect(appendClientActn,SIGNAL(triggered()),this,SLOT(appendClient()));
 editClientActn=new QAction(QIcon(":images/edit"),tr("Edit client"),this);
 connect(editClientActn,SIGNAL(triggered()),this,SLOT(editClient()));
 removeClientActn=new QAction(QIcon(":images/remove"),tr("Remove client"),this);
 connect(removeClientActn,SIGNAL(triggered()),this,SLOT(removeClient()));

 appendPerformerActn=new QAction(QIcon(":images/append"),tr("Append performer"),this);
 connect(appendPerformerActn,SIGNAL(triggered()),this,SLOT(appendPerformer()));
 editPerformerActn=new QAction(QIcon(":images/edit"),tr("Edit performer"),this);
 connect(editPerformerActn,SIGNAL(triggered()),this,SLOT(editPerformer()));
 removePerformerActn=new QAction(QIcon(":images/remove"),tr("Remove performer"),this);
 connect(removePerformerActn,SIGNAL(triggered()),this,SLOT(removePerformer()));

 appendTypeActn=new QAction(QIcon(":images/append"),tr("Append type"),this);
 connect(appendTypeActn,SIGNAL(triggered()),this,SLOT(appendType()));
 editTypeActn=new QAction(QIcon(":images/edit"),tr("Edit type"),this);
 connect(editTypeActn,SIGNAL(triggered()),this,SLOT(editType()));
 removeTypeActn=new QAction(QIcon(":images/remove"),tr("Remove type"),this);
 connect(removeTypeActn,SIGNAL(triggered()),this,SLOT(removeType()));

 toolBar->addAction(appendRequestActn);
 toolBar->addSeparator();
 toolBar->addAction(editRequestActn);
 toolBar->addSeparator();
 toolBar->addAction(removeRequestActn);
 toolBar->addSeparator();
 toolBar->addAction(filterRequestActn);
 toolBar->addSeparator();
 toolBar->addAction(reportRequestActn);
 toolBar->addSeparator();
 toolBar->addAction(previewRequestActn);
 toolBar->addSeparator();
 toolBar->addAction(printRequestActn);
 toolBar->addSeparator();
 toolBar->addAction(exitActn);

 connect(exitActn,SIGNAL(triggered()),this,SLOT(close()));
 connect(aboutQtActn,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
 connect(aboutActn,SIGNAL(triggered()),this,SLOT(about()));

 return;
 }
//
void TMainWnd::initIface()
 {
 // скрываем ненужные для отображения колонки
 requestTable->setColumnHidden(m_requestModel->fieldIndex("type_id"),true);
 requestTable->setColumnHidden(m_requestModel->fieldIndex("client_id"),true);
 requestTable->setColumnHidden(m_requestModel->fieldIndex("request_note"),true);
 requestTable->setColumnHidden(m_requestModel->fieldIndex("performer_id"),true);
 requestTable->setColumnHidden(m_requestModel->fieldIndex("realize_note"),true);
 requestTable->setColumnHidden(m_requestModel->fieldIndex("workers"),true);

 clientTable->setColumnHidden(m_clientModel->fieldIndex("id"),true);

 performerTable->setColumnHidden(m_performerModel->fieldIndex("id"),true);
 typeTable->setColumnHidden(m_typeModel->fieldIndex("id"),true);

 requestTable->horizontalHeader()->setSectionsMovable(true);
 clientTable->horizontalHeader()->setSectionsMovable(true);
 // читаем настройки из ini файла
 readSettings();
 return;
 }
//
void TMainWnd::closeEvent(QCloseEvent *event)
 {
 if (QMessageBox::question(this,tr("Confirmation"),tr("Exit program?"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes)
  event->accept();
 else
  event->ignore();
 return;
 }
//
void TMainWnd::writeSettings()
 {
 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","dictionary_splitter",dictionarySplitter->saveState());
 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","main_splitter",mainSplitter->saveState());

 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","state",saveState());
 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","geometry",saveGeometry());

 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","request_table",requestTable->horizontalHeader()->saveState());
 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","client_table",clientTable->horizontalHeader()->saveState());
 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","performer_table",performerTable->horizontalHeader()->saveState());
 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","type_table",typeTable->horizontalHeader()->saveState());
 TCommon::putSetting(qApp->applicationDirPath()+"/request.ini","interface","tool_bar",toolBar->saveGeometry());
 return;
 }
//
void TMainWnd::readSettings()
 {
 restoreState(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","state",0).toByteArray());
 restoreGeometry(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","geometry",0).toByteArray());

 mainSplitter->restoreState(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","main_splitter",0).toByteArray());
 dictionarySplitter->restoreState(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","dictionary_splitter",0).toByteArray());

 requestTable->horizontalHeader()->restoreState(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","request_table",0).toByteArray());
 clientTable->horizontalHeader()->restoreState(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","client_table",0).toByteArray());
 performerTable->horizontalHeader()->restoreState(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","performer_table",0).toByteArray());
 typeTable->horizontalHeader()->restoreState(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","type_table",0).toByteArray());

 toolBar->restoreGeometry(TCommon::getSetting(qApp->applicationDirPath()+"/request.ini","interface","tool_bar",0).toByteArray());
 return;
 }
//
void TMainWnd::aboutToQuit()
 {
 if (m_requestBase.isOpen() && m_requestBase.isValid())
  m_requestBase.close();
 // сохраняем настройки интерфейса в ini файл
 writeSettings();
 return;
 }
//
void TMainWnd::requestTableContextMenu(QPoint point)
 {
 QMenu contextMenu;

 contextMenu.addAction(appendRequestActn);
 contextMenu.addAction(editRequestActn);
 contextMenu.addAction(removeRequestActn);
 contextMenu.addSeparator();
 contextMenu.addAction(printRequestActn);

 if (requestTable->indexAt(point).isValid())
  {
  editRequestActn->setEnabled(true);
  removeRequestActn->setEnabled(true);
  }
 else
  {
  editRequestActn->setEnabled(false);
  removeRequestActn->setEnabled(false);
  }

 contextMenu.exec(QCursor::pos());
 return;
 }
//
void TMainWnd::clientTableContextMenu(QPoint point)
 {
 QMenu contextMenu;

 contextMenu.addAction(appendClientActn);
 contextMenu.addAction(editClientActn);
 contextMenu.addAction(removeClientActn);

 if (clientTable->indexAt(point).isValid())
  {
  editClientActn->setEnabled(true);
  removeClientActn->setEnabled(true);
  }
 else
  {
  editClientActn->setEnabled(false);
  removeClientActn->setEnabled(false);
  }

 contextMenu.exec(QCursor::pos());
 return;
 }
//
void TMainWnd::performerListContextMenu(QPoint point)
 {
 QMenu contextMenu;

 contextMenu.addAction(appendPerformerActn);
 contextMenu.addAction(editPerformerActn);
 contextMenu.addAction(removePerformerActn);

 if (performerTable->indexAt(point).isValid())
  {
  editPerformerActn->setEnabled(true);
  removePerformerActn->setEnabled(true);
  }
 else
  {
  editPerformerActn->setEnabled(false);
  removePerformerActn->setEnabled(false);
  }

 contextMenu.exec(QCursor::pos());
 return;
 }
//
void TMainWnd::typeListContextMenu(QPoint point)
 {
 QMenu contextMenu;

 contextMenu.addAction(appendTypeActn);
 contextMenu.addAction(editTypeActn);
 contextMenu.addAction(removeTypeActn);

 if (typeTable->indexAt(point).isValid())
  {
  editTypeActn->setEnabled(true);
  removeTypeActn->setEnabled(true);
  }
 else
  {
  editTypeActn->setEnabled(false);
  removeTypeActn->setEnabled(false);
  }

 contextMenu.exec(QCursor::pos());
 return;
 }
//
void TMainWnd::requestDoubleClicked(QModelIndex index)
 {
 if (index.isValid())
  editRequest();
 return;
 }
//
void TMainWnd::clientDoubleClicked(QModelIndex index)
 {
 if (index.isValid())
  editClient();
 return;
 }
//
void TMainWnd::typeDoubleClicked(QModelIndex index)
 {
 if (index.isValid())
  editType();
 return;
 }
//
void TMainWnd::performerDoubleClicked(QModelIndex index)
 {
 if (index.isValid())
  editPerformer();
 return;
 }
//
void TMainWnd::appendRequest()
 {
 TRequestDlg *requestDlg=new TRequestDlg(this,m_requestModel,m_typeModel,m_clientModel,m_performerModel,-1);
 requestDlg->setModal(true);
 if (requestDlg->exec()==QDialog::Accepted)
  {
  QString number=requestDlg->number();
  int row=0;
  int column=m_requestModel->fieldIndex("number");

  QModelIndexList items=m_requestModel->match(m_requestModel->index(row,column),Qt::DisplayRole,number,1,Qt::MatchExactly);
  if (items.size())
   {
   row=items.first().row();
   int id=m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("id"))).toInt();
   m_requestModel->setData(m_requestModel->index(row,m_requestModel->fieldIndex("number")),QDate::currentDate().toString("dd_MM_yyyy")+"-"+QString::number(id));
   requestTable->setCurrentIndex(m_requestModel->index(row,column));
   requestTable->scrollTo(m_requestModel->index(row,column),QAbstractItemView::PositionAtCenter);
   }
  }

 delete requestDlg;
 return;
 }
//
void TMainWnd::editRequest()
 {
 int row=requestTable->selectionModel()->currentIndex().row();
 int column=m_requestModel->fieldIndex("id");

 int id=m_requestModel->data(m_requestModel->index(row,column)).toInt();

 TRequestDlg *requestDlg=new TRequestDlg(this,m_requestModel,m_typeModel,m_clientModel,m_performerModel,id);
 requestDlg->setModal(true);
 if (requestDlg->exec()==QDialog::Accepted)
  {
  row=0;
  QModelIndexList items=m_requestModel->match(m_requestModel->index(row,column),Qt::DisplayRole,id,1,Qt::MatchExactly);
  if (items.size())
   {
   row=items.first().row();
   requestTable->setCurrentIndex(m_requestModel->index(row,column));
   requestTable->scrollTo(m_requestModel->index(row,column),QAbstractItemView::PositionAtCenter);
   }
  }

 delete requestDlg;
 return;
 }
//
void TMainWnd::removeRequest()
 {
 if (QMessageBox::question(this,tr("Confirm removing"),tr("Remove current record?"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::No)
  return;

 int row=requestTable->selectionModel()->currentIndex().row();
 m_requestModel->removeRow(row);
 m_requestModel->refresh();

 if (m_requestModel->rowCount())
  {
  int row=0;
  int column=m_requestModel->fieldIndex("number");
  requestTable->setCurrentIndex(m_requestModel->index(row,column));
  requestTable->scrollTo(m_requestModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 return;

 }
//
void TMainWnd::filterRequest(bool checked)
 {
 QString filter;
 if (checked)
  {
  TFilterDlg *filterDlg=new TFilterDlg(this,m_requestModel,m_typeModel,m_clientModel,m_performerModel);
  filterDlg->setModal(true);
  if (filterDlg->exec()==QDialog::Accepted)
   filter=filterDlg->filter();
  else
   filter.clear();
  delete filterDlg;
  }
 else
  filter.clear();

 m_requestModel->setFilter(filter);
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::reportRequest()
 {
 QString csvName=QFileDialog::getSaveFileName(this,tr("Save error log"),qApp->applicationDirPath(),tr("CSV files (*.csv)"));
 if (csvName.isEmpty())
  return;

 QFile csvFile(csvName);

 if (!csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
  {
  QMessageBox::critical(this,tr("Error"),tr("Can't open destination CSV file \n%1.").arg(csvName));
  return;
  }

 QTextStream csvStream(&csvFile);
 csvStream.setCodec("UTF-8");
 csvStream.setGenerateByteOrderMark(true);

 QProgressDialog progressDlg;
 progressDlg.setModal(true);
 progressDlg.setWindowFlags(progressDlg.windowFlags() & ~Qt::WindowCloseButtonHint);
 progressDlg.setWindowTitle(tr("Request"));
 progressDlg.setCancelButton(NULL);
 progressDlg.setLabelText(tr("Saving report.\nPlease wait a little time."));
 progressDlg.setMinimum(0);
 progressDlg.setMaximum(100);
 progressDlg.setValue(0);
 progressDlg.show();
 qApp->processEvents();

 csvStream<<tr("\"Number\";\"Type\";\"Importance\";\"Status\";\"Request Date\";\"Client\";\"Address\";\"Contact\";\"Realize Date\";\"Performer\";\n");

 progressDlg.setValue(progressDlg.value()+1);
 qApp->processEvents();

 for (int i=0;i<m_requestModel->rowCount();i++)
  {
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("number"))).toString()<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("type"))).toString()<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("importance"))).toString()<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("status"))).toString()<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("request_date"))).toDate().toString("dd.MM.yyyy")<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("client"))).toString()<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("address"))).toString()<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("contact"))).toString()<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("realize_date"))).toDate().toString("dd.MM.yyyy")<<"\";";
  csvStream<<"\""<<m_requestModel->data(m_requestModel->index(i,m_requestModel->fieldIndex("performer"))).toString()<<"\";\n";

  progressDlg.setValue(progressDlg.value()+1);
  qApp->processEvents();
  }

 csvStream.flush();
 csvFile.close();

 progressDlg.close();
 return;
 }
//
void TMainWnd::appendClient()
 {
 QString client=QInputDialog::getText(this,tr("New client"),tr("Client:"),QLineEdit::Normal,QString());
 //if (client.isEmpty())
 // return;

 QSqlRecord record=m_clientModel->record();
 int row=0;
 int column=m_clientModel->fieldIndex("client");
 QModelIndexList items=m_performerModel->match(m_clientModel->index(row,column),Qt::DisplayRole,client,1,Qt::MatchExactly);
 if (!items.size())
  {
  record.setValue("client",client);
  m_clientModel->insertRecord(-1,record);
  m_clientModel->select();

  items=m_clientModel->match(m_clientModel->index(row,column),Qt::DisplayRole,client,1,Qt::MatchExactly);
  }

 if (items.size())
  {
  row=items.first().row();
  clientTable->setCurrentIndex(m_clientModel->index(row,column));
  clientTable->scrollTo(m_clientModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }

 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::editClient()
 {
 int row=clientTable->selectionModel()->currentIndex().row();
 int column=m_clientModel->fieldIndex("client");

 QSqlRecord record=m_clientModel->record(row);
 QString client=m_clientModel->data(m_clientModel->index(row,m_clientModel->fieldIndex("client"))).toString();
 client=QInputDialog::getText(this,tr("Edit client"),tr("Performer:"),QLineEdit::Normal,client);
 //if (performer.isEmpty())
 // return;

 record.setValue("client",client);
 m_clientModel->setRecord(row,record);
 m_clientModel->select();

 row=0;
 QModelIndexList items=m_clientModel->match(m_clientModel->index(row,column),Qt::DisplayRole,client,1,Qt::MatchExactly);

 if (items.size())
  {
  row=items.first().row();
  clientTable->setCurrentIndex(m_clientModel->index(row,column));
  clientTable->scrollTo(m_clientModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::removeClient()
 {
 if (QMessageBox::question(this,tr("Confirm removing"),tr("Remove current record?"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::No)
  return;

 int row=clientTable->selectionModel()->currentIndex().row();
 m_clientModel->removeRow(row);
 m_clientModel->select();

 if (m_clientModel->rowCount())
  {
  int row=0;
  int column=m_clientModel->fieldIndex("client");
  clientTable->setCurrentIndex(m_clientModel->index(row,column));
  clientTable->scrollTo(m_clientModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::appendPerformer()
 {
 QString performer=QInputDialog::getText(this,tr("New performer"),tr("Performer:"),QLineEdit::Normal,QString());
 //if (performer.isEmpty())
 // return;

 QSqlRecord record=m_performerModel->record();
 int row=0;
 int column=m_performerModel->fieldIndex("performer");
 QModelIndexList items=m_performerModel->match(m_performerModel->index(row,column),Qt::DisplayRole,performer,1,Qt::MatchExactly);
 if (!items.size())
  {
  record.setValue("performer",performer);
  m_performerModel->insertRecord(-1,record);
  m_performerModel->select();

  items=m_performerModel->match(m_performerModel->index(row,column),Qt::DisplayRole,performer,1,Qt::MatchExactly);
  }

 if (items.size())
  {
  row=items.first().row();
  performerTable->setCurrentIndex(m_performerModel->index(row,column));
  performerTable->scrollTo(m_performerModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }

 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::editPerformer()
 {
 int row=performerTable->selectionModel()->currentIndex().row();
 int column=m_performerModel->fieldIndex("performer");

 QSqlRecord record=m_performerModel->record(row);
 QString performer=m_performerModel->data(m_performerModel->index(row,m_performerModel->fieldIndex("performer"))).toString();
 performer=QInputDialog::getText(this,tr("Edit performer"),tr("Performer:"),QLineEdit::Normal,performer);
 //if (performer.isEmpty())
 // return;

 record.setValue("performer",performer);
 m_performerModel->setRecord(row,record);
 m_performerModel->select();

 row=0;
 QModelIndexList items=m_performerModel->match(m_performerModel->index(row,column),Qt::DisplayRole,performer,1,Qt::MatchExactly);

 if (items.size())
  {
  row=items.first().row();
  performerTable->setCurrentIndex(m_performerModel->index(row,column));
  performerTable->scrollTo(m_performerModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::removePerformer()
 {
 if (QMessageBox::question(this,tr("Confirm removing"),tr("Remove current record?"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::No)
  return;

 int row=performerTable->selectionModel()->currentIndex().row();
 m_performerModel->removeRow(row);
 m_performerModel->select();

 if (m_performerModel->rowCount())
  {
  int row=0;
  int column=m_performerModel->fieldIndex("performer");
  performerTable->setCurrentIndex(m_performerModel->index(row,column));
  performerTable->scrollTo(m_performerModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::appendType()
 {
 QString type=QInputDialog::getText(this,tr("New request type"),tr("Type:"),QLineEdit::Normal,tr("Enter type here"));
 //if (type.isEmpty())
 // return;

 QSqlRecord record=m_typeModel->record();
 int row=0;
 int column=m_typeModel->fieldIndex("type");
 QModelIndexList items=m_typeModel->match(m_typeModel->index(row,column),Qt::DisplayRole,type,1,Qt::MatchExactly);

 if (!items.size())
  {
  record.setValue("type",type);
  m_typeModel->insertRecord(-1,record);
  m_typeModel->select();

  items=m_typeModel->match(m_typeModel->index(row,column),Qt::DisplayRole,type,1,Qt::MatchExactly);
  }

 if (items.size())
  {
  row=items.first().row();
  typeTable->setCurrentIndex(m_typeModel->index(row,column));
  typeTable->scrollTo(m_typeModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::editType()
 {
 int row=typeTable->selectionModel()->currentIndex().row();
 int column=m_typeModel->fieldIndex("type");

 QSqlRecord record=m_typeModel->record(row);
 QString type=m_typeModel->data(m_typeModel->index(row,m_typeModel->fieldIndex("type"))).toString();
 type=QInputDialog::getText(this,tr("Edit request type"),tr("Type:"),QLineEdit::Normal,type);
 //if (type.isEmpty())
 // return;

 record.setValue("type",type);
 m_typeModel->setRecord(row,record);
 m_typeModel->select();

 row=0;
 QModelIndexList items=m_typeModel->match(m_typeModel->index(row,column),Qt::DisplayRole,type,1,Qt::MatchExactly);

 if (items.size())
  {
  row=items.first().row();
  typeTable->setCurrentIndex(m_typeModel->index(row,column));
  typeTable->scrollTo(m_typeModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::removeType()
 {
 if (QMessageBox::question(this,tr("Confirm removing"),tr("Remove current record?"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::No)
  return;

 int row=typeTable->selectionModel()->currentIndex().row();
 m_typeModel->removeRow(row);
 m_typeModel->select();

 if (m_typeModel->rowCount())
  {
  int row=0;
  int column=m_typeModel->fieldIndex("type");
  typeTable->setCurrentIndex(m_typeModel->index(row,column));
  typeTable->scrollTo(m_typeModel->index(row,column),QAbstractItemView::PositionAtCenter);
  }
 m_requestModel->refresh();
 return;
 }
//
void TMainWnd::previewRequest()
 {
 QPrinter *printer=new QPrinter();
 QPrintPreviewDialog *preview=new QPrintPreviewDialog(printer,this);
 connect(preview,SIGNAL(paintRequested(QPrinter*)),SLOT(printPreview(QPrinter*)));
 //float ratio=(float)preview->height()/preview->width();qDebug()<<ratio;
 preview->resize(1000,803);//printer->pageRect().width(),printer->pageRect().height());
 preview->exec();

 delete printer;
 delete preview;
 return;
 }
//
void TMainWnd::printPreview(QPrinter *printer)
 {
 QTextDocument *document=createDocument(printer);
 printer->setDocName(document->metaInformation(QTextDocument::DocumentTitle));

 document->print(printer);
 delete document;

 return;
 }
//
void TMainWnd::printRequest()
 {
 QPrintDialog printDialog(this);
 QPrinter *printer;
 if (printDialog.exec()==QDialog::Accepted)
  {
  printer=printDialog.printer();
  if (!printer->isValid())
   {
   QMessageBox::critical(this,tr("Error"),tr("No printer selected"),QMessageBox::Ok);
   return;
   }
  }
 else
  return;

 QTextDocument *document=createDocument(printer);
 printer->setDocName(document->metaInformation(QTextDocument::DocumentTitle));

 document->print(printer);
 delete document;

 return;
 }
//
QTextDocument * TMainWnd::createDocument(QPrinter *printer)
 {
 //if (!items.size())
 // return NULL;
 QTextDocument *document=new QTextDocument();
 document->setMetaInformation(QTextDocument::DocumentTitle,tr("Requests"));
 //document->setd

 QString number;
 QString client;
 QString address;
 QString contact;
 QString performer;
// QString date;
 QString type;
 QString note;

 int row;

 if (printer)
  printer->setPageMargins(5,5,5,5,QPrinter::Point);

 QTextCursor cursor(document);
 QTextBlockFormat blockFormat;
 QTextCharFormat charFormat;
 //QFontMetrics metrics(charFormat.font());

 charFormat.setFontWeight(50);
 charFormat.setFontPointSize(12);
 charFormat.setFontFamily("Arial Cyr");

 blockFormat.setAlignment(Qt::AlignLeft);

 cursor.movePosition(QTextCursor::End);
 cursor.insertBlock();
 cursor.setBlockFormat(blockFormat);
 cursor.setCharFormat(charFormat);
  //cursor.insertText(tr("Requests"));   //Название отчета
 cursor.insertText("\n ");
 cursor.insertText(tr("----------------------------------"));
 cursor.insertText("\n ");
 QModelIndexList items=requestTable->selectionModel()->selectedRows();
 if (items.size()==0)
  requestTable->selectAll();
 items=requestTable->selectionModel()->selectedRows();
 for (int i=0;i<items.size();i++)
  {
  row=items.at(i).row();//qDebug()<<row;
  number=tr("Request: ")+m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("number"))).toString()+" ("+
                         m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("importance"))).toString()+") from "+
                         m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("request_date"))).toString();
  type=tr("Type: ")+m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("type"))).toString();
  client=tr("Client: ")+m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("client"))).toString();
  address=tr("Address: ")+m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("address"))).toString();
  contact=tr("Contact: ")+m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("contact"))).toString();
  performer=tr("Performer: ")+m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("performer"))).toString();
  note="Note: \n"+m_requestModel->data(m_requestModel->index(row,m_requestModel->fieldIndex("request_note"))).toString();

  cursor.insertText(number,charFormat);
  cursor.insertText("\n ");
  //cursor.insertText(date,charFormat);
  //cursor.insertText("\n ");
  cursor.insertText(type,charFormat);
  cursor.insertText("\n ");
  cursor.insertText(client,charFormat);
  cursor.insertText("\n ");
  cursor.insertText(address,charFormat);
  cursor.insertText("\n ");
  cursor.insertText(contact,charFormat);
  cursor.insertText("\n ");
  cursor.insertText(note,charFormat);
  cursor.insertText("\n ");
  cursor.insertText(performer,charFormat);
  cursor.insertText("\n ");
  cursor.insertText(tr("----------------------------------"));
  cursor.insertText("\n ");
  }
 return document;
 }
//
void TMainWnd::about()
 {
 QMessageBox::information(this,tr("About"),tr("'Orion-telecom' Krasnoyarsk billing system.\nCopyrigh (c) Yaroslav Matveev,\nMikhail F. Reshetnev SibSAU, 2015"),QMessageBox::Ok);
 return;
 }
//
void TMainWnd::requestTableRowChanged(const QModelIndex & current, const QModelIndex & previous)
 {
 if (current.isValid())
  {
  editRequestActn->setEnabled(true);
  removeRequestActn->setEnabled(true);
  }
 else
  {
  editRequestActn->setEnabled(false);
  removeRequestActn->setEnabled(false);
  }
 return;
 }
