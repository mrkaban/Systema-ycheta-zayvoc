#include "TPerformerModel.h"

TPerformerModel::TPerformerModel(QObject *parent, QSqlDatabase dataBase) : QSqlTableModel(parent,dataBase)
 {
 setTable("performers");
 setSort(fieldIndex("performer"),Qt::AscendingOrder);
 setHeaderData(fieldIndex("performer"),Qt::Horizontal,tr("Performer"));

 select();
 }
//

