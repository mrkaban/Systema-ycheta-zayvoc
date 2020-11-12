#include "TRequestModel.h"
#include <QDebug>
#include <QSqlRecord>
#include <QSqlField>
#include <QDate>
#include <QTableView>

TRequestModel::TRequestModel(QObject *parent, QSqlDatabase dataBase, QTableView *table) : QSqlTableModel(parent,dataBase), m_table(table)
 {
 qRegisterMetaType <TRequestModel::Importance>();
 qRegisterMetaType <TRequestModel::Status>();

 initCore();
 initIface();
 }
//
void TRequestModel::initCore()
 {
 setTable("requests");
 select();
 return;
 }

void TRequestModel::initIface()
 {
 setHeaderData(fieldIndex("id"),Qt::Horizontal,tr("ID"));
 setHeaderData(fieldIndex("number"),Qt::Horizontal,tr("Number"));
 setHeaderData(fieldIndex("importance"),Qt::Horizontal,tr("Importance"));
 setHeaderData(fieldIndex("type"),Qt::Horizontal,tr("Type"));
 setHeaderData(fieldIndex("status"),Qt::Horizontal,tr("Status"));
 setHeaderData(fieldIndex("request_date"),Qt::Horizontal,tr("Request date"));
 setHeaderData(fieldIndex("client"),Qt::Horizontal,tr("Client"));
 setHeaderData(fieldIndex("address"),Qt::Horizontal,tr("Address"));
 setHeaderData(fieldIndex("contact"),Qt::Horizontal,tr("Contact"));
 setHeaderData(fieldIndex("realize_date"),Qt::Horizontal,tr("Realize date"));
 setHeaderData(fieldIndex("performer"),Qt::Horizontal,tr("Performer"));
 setHeaderData(fieldIndex("workers"),Qt::Horizontal,tr("Workers"));

 return;
 }
// переопределяем SQL запрос для вытаскивания в основную таблицу данных, которые хотим там видеть
QString TRequestModel::selectStatement() const
 {
 QString statement="select requests.id, requests.number, requests.type_id, typies.type, "
                   "requests.importance, requests.status, requests.request_date, "
                   "requests.client_id, clients.client, requests.address, requests.contact, "
                   "requests.request_note, requests.realize_date, requests.realize_note, "
                   "requests.performer_id, performers.performer, requests.workers from requests "
                   "left join typies on requests.type_id=typies.id "
                   "left join clients on requests.client_id=clients.id "
                   "left join performers on requests.performer_id=performers.id";

 if (!filter().isEmpty())
  statement.append(" where "+filter());

 statement.append(" order by number");

 return statement;
 }
//
/*void TRequestModel::setFilter(QString filter)
 {
 m_filter=filter;
 return;
 }*/
//
void TRequestModel::refresh()
 {
 int row=(m_table->selectionModel()->currentIndex().isValid()) ? m_table->selectionModel()->currentIndex().row() : 0;
 int column=fieldIndex("id");

 int id=data(index(row,column)).toInt();

 QString m_filter=filter();
 clear();
 initCore();
 initIface();

 select();
 setFilter(m_filter);
 while (canFetchMore())
  fetchMore();

 row=0;
 QModelIndexList items=match(index(0,column),Qt::DisplayRole,id,1,Qt::MatchExactly);
 if (items.size())//&& index(row,column).isValid())
  {
  row=items.first().row();
  m_table->setCurrentIndex(index(row,column));
  m_table->scrollTo(index(row,column),QAbstractItemView::PositionAtCenter);
  }
 else
  {
  if (rowCount())
   {
   //row=0;//items.first().row();
   m_table->setCurrentIndex(index(row,column));
   m_table->scrollTo(index(row,column),QAbstractItemView::PositionAtCenter);
   }
  }
 return;
 }
//
QVariant TRequestModel::data(const QModelIndex &item, int role) const
 {
 switch (role)
  {
  case Qt::TextAlignmentRole:
   {
   if (item.column()==fieldIndex("id") || item.column()==fieldIndex("request_date") || item.column()==fieldIndex("realize_date"))
    return QVariant(Qt::AlignVCenter | Qt::AlignRight);
   else
    return QVariant(Qt::AlignVCenter | Qt::AlignLeft);
   break;
   }
  case Qt::DisplayRole:
   {
   if (item.column()==fieldIndex("request_date") || item.column()==fieldIndex("realize_date"))
    return QSqlTableModel::data(item,role).toDate().toString("dd.MM.yyyy");

   if (item.column()==fieldIndex("importance"))
    {
    switch (QSqlTableModel::data(item,role).toInt())
     {
     case Ordinary:
      {
      return tr("Ordinary");
      break;
      }
     case Important:
      {
      return tr("Important");
      break;
      }
     default:
      {
      return QString();
      break;
      }
     }
    }

   if (item.column()==fieldIndex("status"))
    {
    switch (QSqlTableModel::data(item,role).toInt())
     {
     case InWork:
      {
      return tr("In work");
      break;
      }
     case Canceled:
      {
      return tr("Canceled");
      break;
      }
     case Realized:
      {
      return tr("Realized");
      break;
      }
     default:
      {
      return QString();
      break;
      }
     }
    }
   break;
   }
  case Qt::UserRole:
   {
   return QSqlTableModel::data(item,Qt::EditRole);
   break;
   }
  }

 return QSqlTableModel::data(item,role);
 }
