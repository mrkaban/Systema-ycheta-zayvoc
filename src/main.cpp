#include <QApplication>
#include "TMainWnd.h"
#include "TLoginDlg.h"
#include <QTranslator>

int main(int argc, char *argv[])
 {
 QApplication App(argc, argv);

 QTranslator translator;
 if (translator.load(qApp->applicationDirPath()+"/lng/request_ru.qm"))
  App.installTranslator(&translator);

 QStringList login;
 TLoginDlg loginDlg;
 loginDlg.setModal(true);
 if (loginDlg.exec()==QDialog::Accepted)
  {
  login=loginDlg.loginInfo();
  if (login.at(0)=="ee11cbb19052e40b07aac0ca060c23ee" && login.at(1)=="25d55ad283aa400af464c76d713c07ad")
   {
   TMainWnd MainWnd;
   MainWnd.show();
   return App.exec();
   }
  }

 return 0;
 }
