#include "TRequestDelegate.h"
#include "TRequestModel.h"
#include <QPainter>
#include <QDebug>

TRequestDelegate::TRequestDelegate(QObject *parent) : QStyledItemDelegate(parent)
 {

 }
//
void TRequestDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
 const TRequestModel *requestModel=qobject_cast <const TRequestModel*>(index.model());
 TRequestModel::Status status=(TRequestModel::Status)requestModel->data(requestModel->index(index.row(),requestModel->fieldIndex("status")),Qt::UserRole).toInt();
 QColor color;

 if (index.row()%2)
  color=option.palette.color(QPalette::Base);
 else
  color=option.palette.color(QPalette::AlternateBase);

 switch (status)
  {
  case TRequestModel::InWork:
   {
   color=QColor::fromRgb(197, 217, 241);
   break;
   }
  case TRequestModel::Canceled:
   {
   color=QColor::fromRgb(255, 146, 146);
   break;
   }
  case TRequestModel::Realized:
   {
   color=QColor::fromRgb(146, 208, 80);
   break;
   }
  default:
   break;
  }

 painter->save();
 painter->fillRect(option.rect,color);
 painter->restore();

 QStyledItemDelegate::paint(painter,option,index);
 }
