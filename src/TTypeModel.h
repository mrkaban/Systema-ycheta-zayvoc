#ifndef TTYPEMODEL_H
#define TTYPEMODEL_H

#include <QSqlTableModel>

class TTypeModel : public QSqlTableModel
 {
 Q_OBJECT
 public:
  TTypeModel(QObject *parent=0,QSqlDatabase dataBase=QSqlDatabase());

 protected:

 };

#endif // TTYPEMODEL_H
