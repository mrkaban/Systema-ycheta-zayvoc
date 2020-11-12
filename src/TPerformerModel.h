#ifndef TPERFORMERMODEL_H
#define TPERFORMERMODEL_H

#include <QSqlTableModel>

class TPerformerModel : public QSqlTableModel
 {
 Q_OBJECT
 public:
  TPerformerModel(QObject *parent=0,QSqlDatabase dataBase=QSqlDatabase());

 protected:

 };

#endif // TPERFORMERMODEL_H
