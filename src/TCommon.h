#ifndef TCOMMON_H
#define TCOMMON_H

#include <QByteArray>
#include <QString>
#include <QVariant>

class TCommon
 {
 public:
  enum ItemType
   {
   RootItem,
   ParentItem,
   ChildItem
   };

  TCommon();
  //static QByteArray encrypt(QByteArray bytes,QString password=QString(""));
  //static QByteArray decrypt(QByteArray bytes,QString password=QString(""));

  static void putSetting(QString iniFile,QString group,QString key,QVariant value);
  static QVariant getSetting(QString iniFile,QString group,QString key,QVariant defaultValue);
  static QStringList getKeys(QString iniFile,QString group);
 };

Q_DECLARE_METATYPE(TCommon::ItemType)

#endif // TCOMMON_H
