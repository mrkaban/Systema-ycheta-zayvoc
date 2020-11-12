#include "TCommon.h"
//#include <botan/botan.h>
#include <QDebug>
#include <QSettings>
#include <QApplication>

#define KEY "27071975"

TCommon::TCommon()
 {
 qRegisterMetaType <TCommon::ItemType>();
 }
//
/*QByteArray TCommon::encrypt(QByteArray bytes,QString password)
 {
 //if (bytes.size()<16 && isBinary)
 // return bytes;
 bytes.append("0000000000000000");

 if (password.isEmpty())
  password=QString(KEY);

 Botan::AES_256 crypt;

 while (password.length()<crypt.minimum_keylength())
  password+=" ";

 crypt.set_key((uchar*)(password.toLatin1().data()),crypt.minimum_keylength());
 crypt.encrypt((uchar*)bytes.data());
 return bytes;
 }
//
QByteArray TCommon::decrypt(QByteArray bytes,QString password)
 {
 //if (bytes.size()<16 && isBinary)
 // return bytes;

 if (password.isEmpty())
  password=QString(KEY);

 Botan::AES_256 crypt;

 while (password.length()<crypt.minimum_keylength())
  password+=" ";

 crypt.set_key((uchar*)(password.toLatin1().data()),crypt.minimum_keylength());
 crypt.decrypt((uchar*)bytes.data());
 return bytes.left(bytes.length()-16);
 }*/
//
void TCommon::putSetting(QString iniFile,QString group,QString key,QVariant value)
 {
 QSettings settings(/*QSettings::IniFormat,QSettings::UserScope,"Janus Worldwide","TtxUiTool");//*/iniFile,QSettings::IniFormat);
 settings.beginGroup(group);
  settings.setValue(key,value);
 settings.endGroup();
 return;
 }
//
QVariant TCommon::getSetting(QString iniFile,QString group,QString key,QVariant defaultValue)
 {
 QSettings settings(/*QSettings::IniFormat,QSettings::UserScope,"Janus Worldwide","TtxUiTool");//*/iniFile,QSettings::IniFormat);
 settings.beginGroup(group);
  QVariant value=settings.value(key,defaultValue);
 settings.endGroup();
 return value;
 }
//
QStringList TCommon::getKeys(QString iniFile,QString group)
 {
 QStringList keys;
 QSettings settings(iniFile,QSettings::IniFormat);
 settings.beginGroup(group);
  keys=settings.childKeys();
 settings.endGroup();
 //qDebug()<<keys;
 return keys;
 }
