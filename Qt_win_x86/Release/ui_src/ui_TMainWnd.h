/********************************************************************************
** Form generated from reading UI file 'TMainWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TMAINWND_H
#define UI_TMAINWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TMainWnd
{
public:
    QAction *exitActn;
    QAction *clientActn;
    QAction *performerActn;
    QAction *typeActn;
    QAction *aboutQtActn;
    QAction *loginActn;
    QAction *aboutActn;
    QWidget *centralWdgt;
    QGridLayout *gridLayout;
    QSplitter *mainSplitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QTableView *requestTable;
    QSplitter *dictionarySplitter;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *clientTable;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableView *performerTable;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTableView *typeTable;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TMainWnd)
    {
        if (TMainWnd->objectName().isEmpty())
            TMainWnd->setObjectName(QStringLiteral("TMainWnd"));
        TMainWnd->resize(803, 600);
        exitActn = new QAction(TMainWnd);
        exitActn->setObjectName(QStringLiteral("exitActn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/exit"), QSize(), QIcon::Normal, QIcon::Off);
        exitActn->setIcon(icon);
        clientActn = new QAction(TMainWnd);
        clientActn->setObjectName(QStringLiteral("clientActn"));
        performerActn = new QAction(TMainWnd);
        performerActn->setObjectName(QStringLiteral("performerActn"));
        typeActn = new QAction(TMainWnd);
        typeActn->setObjectName(QStringLiteral("typeActn"));
        aboutQtActn = new QAction(TMainWnd);
        aboutQtActn->setObjectName(QStringLiteral("aboutQtActn"));
        loginActn = new QAction(TMainWnd);
        loginActn->setObjectName(QStringLiteral("loginActn"));
        aboutActn = new QAction(TMainWnd);
        aboutActn->setObjectName(QStringLiteral("aboutActn"));
        centralWdgt = new QWidget(TMainWnd);
        centralWdgt->setObjectName(QStringLiteral("centralWdgt"));
        gridLayout = new QGridLayout(centralWdgt);
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mainSplitter = new QSplitter(centralWdgt);
        mainSplitter->setObjectName(QStringLiteral("mainSplitter"));
        mainSplitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(mainSplitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 4, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        requestTable = new QTableView(widget);
        requestTable->setObjectName(QStringLiteral("requestTable"));
        requestTable->setContextMenuPolicy(Qt::CustomContextMenu);
        requestTable->setFrameShadow(QFrame::Sunken);
        requestTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        requestTable->setAlternatingRowColors(true);
        requestTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        requestTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        requestTable->setSortingEnabled(true);
        requestTable->verticalHeader()->setDefaultSectionSize(20);
        requestTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_4->addWidget(requestTable);

        mainSplitter->addWidget(widget);
        dictionarySplitter = new QSplitter(mainSplitter);
        dictionarySplitter->setObjectName(QStringLiteral("dictionarySplitter"));
        dictionarySplitter->setOrientation(Qt::Vertical);
        widget1 = new QWidget(dictionarySplitter);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 4, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        clientTable = new QTableView(widget1);
        clientTable->setObjectName(QStringLiteral("clientTable"));
        clientTable->setContextMenuPolicy(Qt::CustomContextMenu);
        clientTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        clientTable->setAlternatingRowColors(true);
        clientTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        clientTable->verticalHeader()->setDefaultSectionSize(20);
        clientTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout->addWidget(clientTable);

        dictionarySplitter->addWidget(widget1);
        widget2 = new QWidget(dictionarySplitter);
        widget2->setObjectName(QStringLiteral("widget2"));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 4, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        performerTable = new QTableView(widget2);
        performerTable->setObjectName(QStringLiteral("performerTable"));
        performerTable->setContextMenuPolicy(Qt::CustomContextMenu);
        performerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        performerTable->setAlternatingRowColors(true);
        performerTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        performerTable->verticalHeader()->setDefaultSectionSize(20);
        performerTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_2->addWidget(performerTable);

        dictionarySplitter->addWidget(widget2);
        widget3 = new QWidget(dictionarySplitter);
        widget3->setObjectName(QStringLiteral("widget3"));
        verticalLayout_3 = new QVBoxLayout(widget3);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 4, 0, 0);
        label_3 = new QLabel(widget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        typeTable = new QTableView(widget3);
        typeTable->setObjectName(QStringLiteral("typeTable"));
        typeTable->setContextMenuPolicy(Qt::CustomContextMenu);
        typeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        typeTable->setAlternatingRowColors(true);
        typeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        typeTable->verticalHeader()->setDefaultSectionSize(20);
        typeTable->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_3->addWidget(typeTable);

        dictionarySplitter->addWidget(widget3);
        mainSplitter->addWidget(dictionarySplitter);

        gridLayout->addWidget(mainSplitter, 0, 0, 1, 1);

        TMainWnd->setCentralWidget(centralWdgt);
        menubar = new QMenuBar(TMainWnd);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 803, 18));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        helpMenu = new QMenu(menubar);
        helpMenu->setObjectName(QStringLiteral("helpMenu"));
        TMainWnd->setMenuBar(menubar);
        statusbar = new QStatusBar(TMainWnd);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TMainWnd->setStatusBar(statusbar);
        toolBar = new QToolBar(TMainWnd);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        TMainWnd->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(requestTable, clientTable);
        QWidget::setTabOrder(clientTable, performerTable);
        QWidget::setTabOrder(performerTable, typeTable);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(helpMenu->menuAction());
        fileMenu->addAction(exitActn);
        fileMenu->addSeparator();
        helpMenu->addAction(aboutQtActn);
        helpMenu->addAction(aboutActn);

        retranslateUi(TMainWnd);

        QMetaObject::connectSlotsByName(TMainWnd);
    } // setupUi

    void retranslateUi(QMainWindow *TMainWnd)
    {
        TMainWnd->setWindowTitle(QApplication::translate("TMainWnd", "Requests", 0));
        exitActn->setText(QApplication::translate("TMainWnd", "Exit program", 0));
        clientActn->setText(QApplication::translate("TMainWnd", "Clients", 0));
        performerActn->setText(QApplication::translate("TMainWnd", "Performers", 0));
        typeActn->setText(QApplication::translate("TMainWnd", "Types", 0));
        aboutQtActn->setText(QApplication::translate("TMainWnd", "About QT", 0));
        loginActn->setText(QApplication::translate("TMainWnd", "Change login info", 0));
        aboutActn->setText(QApplication::translate("TMainWnd", "About", 0));
        label_4->setText(QApplication::translate("TMainWnd", "Requests", 0));
        label->setText(QApplication::translate("TMainWnd", "Clients", 0));
        label_2->setText(QApplication::translate("TMainWnd", "Performers", 0));
        label_3->setText(QApplication::translate("TMainWnd", "Types", 0));
        fileMenu->setTitle(QApplication::translate("TMainWnd", "File", 0));
        helpMenu->setTitle(QApplication::translate("TMainWnd", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("TMainWnd", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class TMainWnd: public Ui_TMainWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TMAINWND_H
