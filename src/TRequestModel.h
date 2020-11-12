#ifndef TREQUESTMODEL_H
#define TREQUESTMODEL_H

#include <QSqlTableModel>

class QTableView;
class TRequestModel : public QSqlTableModel
 {
 Q_OBJECT
 public:
 // перечисления, просто чтобы дальше не с абстрактными числами работать, а с понятными обозначениями
  // Значимость
  enum Importance
   {
   Ordinary=0,
   Important
   };
  //Статус
  enum Status
   {
   InWork=0,
   Canceled,
   Realized
   };

  TRequestModel(QObject *parent=0, QSqlDatabase dataBase=QSqlDatabase(), QTableView *table=0);
  QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;
  void refresh();
  //void setFilter(QString);

 protected:
  void initCore();
  void initIface();
  QString selectStatement() const;


 private:
  QTableView *m_table;
  //QString m_filter;
 };

#endif // TREQUESTMODEL_H

Q_DECLARE_METATYPE(TRequestModel::Importance)
Q_DECLARE_METATYPE(TRequestModel::Status)
