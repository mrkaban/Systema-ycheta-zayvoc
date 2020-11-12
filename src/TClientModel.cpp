#include "TClientModel.h"

TClientModel::TClientModel(QObject *parent, QSqlDatabase dataBase) : QSqlTableModel(parent,dataBase)
 {
 setTable("clients");

 setHeaderData(fieldIndex("client"),Qt::Horizontal,tr("Client"));

 setSort(fieldIndex("clilent"),Qt::AscendingOrder);
 select();
 }
//


