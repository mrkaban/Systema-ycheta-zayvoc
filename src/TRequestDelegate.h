#ifndef TREQUESTDELEGATE_H
#define TREQUESTDELEGATE_H

#include <QStyledItemDelegate>

class TRequestDelegate : public QStyledItemDelegate
 {
 Q_OBJECT
 public:
  void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  TRequestDelegate(QObject *parent=0);
 };

#endif // TREQUESTDELEGATE_H
