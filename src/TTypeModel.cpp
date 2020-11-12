#include "TTypeModel.h"

TTypeModel::TTypeModel(QObject *parent, QSqlDatabase dataBase) : QSqlTableModel(parent,dataBase)
 {
 setTable("typies");
 setSort(fieldIndex("type"),Qt::AscendingOrder);
 setHeaderData(fieldIndex("type"),Qt::Horizontal,tr("Type"));

 select();
 }
//
