TEMPLATE = app
TARGET = Request

QT += core \
      gui \
      widgets \
      sql \
      printsupport
    
FORMS += \ 
    ui/TMainWnd.ui \
    ui/TRequestDlg.ui \
    ui/TFilterDlg.ui \
    ui/TLoginDlg.ui
HEADERS += \ 
    src/TMainWnd.h \
    src/TRequestModel.h \
    src/TRequestDelegate.h \
    src/TCommon.h \
    src/TRequestDlg.h \
    src/TClientModel.h \
    src/TPerformerModel.h \
    src/TTypeModel.h \
    src/TFilterDlg.h \
    src/TLoginDlg.h
SOURCES += src/main.cpp \
    src/TMainWnd.cpp \
    src/TRequestModel.cpp \
    src/TRequestDelegate.cpp \
    src/TCommon.cpp \
    src/TRequestDlg.cpp \
    src/TClientModel.cpp \
    src/TPerformerModel.cpp \
    src/TTypeModel.cpp \
    src/TFilterDlg.cpp \
    src/TLoginDlg.cpp

UI_DIR = ui_src
DESTDIR = bin
MOC_DIR = moc
OBJECTS_DIR = obj

TRANSLATIONS = lng/request_ru.ts

RESOURCES += \ 
    res/request.qrc
OTHER_FILES += 

RC_ICONS = res/request.ico


