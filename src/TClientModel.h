#ifndef TCLIENTMODEL_H
#define TCLIENTMODEL_H

#include <QSqlTableModel>

class TClientModel : public QSqlTableModel
 {
 Q_OBJECT
 public:
  TClientModel(QObject *parent=0,QSqlDatabase dataBase=QSqlDatabase());

 protected:

 };

#endif // TCLIENTMODEL_H
