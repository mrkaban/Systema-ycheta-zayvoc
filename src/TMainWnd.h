#ifndef TMAINWND_H
#define TMAINWND_H

#include "ui_TMainWnd.h"

#include <QSqlDatabase>

class TRequestModel;
class TRequestDelegate;
class QPushButton;
class QMenu;
class QAction;
class TClientModel;
class TPerformerModel;
class TTypeModel;
class QTextDocument;
class QPrinter;

class TMainWnd : public QMainWindow, private Ui::TMainWnd
 {
 Q_OBJECT
 public:
  TMainWnd(QWidget *parent = 0);

 protected:
  void initDBase();
  void initCore();
  void initIface();

  void writeSettings();
  void readSettings();

  void closeEvent(QCloseEvent *event);

  QTextDocument *createDocument(QPrinter *printer=NULL);

 private:
  QSqlDatabase m_requestBase;

  TRequestModel *m_requestModel;
  TRequestDelegate *m_requestDelegate;

  TClientModel *m_clientModel;
  TPerformerModel *m_performerModel;
  TTypeModel *m_typeModel;

  QAction *appendRequestActn;
  QAction *editRequestActn;
  QAction *removeRequestActn;

  QAction *previewRequestActn;
  QAction *printRequestActn;

  QAction *filterRequestActn;
  QAction *reportRequestActn;

  QAction *appendClientActn;
  QAction *editClientActn;
  QAction *removeClientActn;

  QAction *appendPerformerActn;
  QAction *editPerformerActn;
  QAction *removePerformerActn;

  QAction *appendTypeActn;
  QAction *editTypeActn;
  QAction *removeTypeActn;

 public slots:
  void aboutToQuit();

  void appendRequest();
  void editRequest();
  void removeRequest();

  void filterRequest(bool checked);
  void reportRequest();

  void printRequest();
  void previewRequest();
  void printPreview(QPrinter *);

  void requestTableContextMenu(QPoint point);
  void clientTableContextMenu(QPoint point);
  void typeListContextMenu(QPoint point);
  void performerListContextMenu(QPoint point);

  void requestDoubleClicked(QModelIndex);
  void clientDoubleClicked(QModelIndex);
  void typeDoubleClicked(QModelIndex);
  void performerDoubleClicked(QModelIndex);

  void appendClient();
  void editClient();
  void removeClient();

  void appendPerformer();
  void editPerformer();
  void removePerformer();

  void appendType();
  void editType();
  void removeType();

  void about();
  void requestTableRowChanged(const QModelIndex & current, const QModelIndex & previous);
 };

#endif // TMAINWND_H
