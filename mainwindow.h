#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QJSEngine>

#include "graphdisplaywidget.h"
#include "debugoutputdialog.h"
#include "tabbedjseditor.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();

protected:
    GraphDisplayWidget* m_graphDisplay;
    TabbedJSEditor* m_textEdit;

    void createActions ();
    void createMenu ();

    QAction* m_new;
    QAction* m_open;
    QAction* m_save;

    QAction* m_clear;
    QAction* m_exec;
    QAction* m_debug;

    DebugOutputDialog* m_debugDialog;
    QJSEngine jsEngine;

private slots:

    void newScript();
    void openScript();
    void saveScript();
    void clearScript();
    void executeScript();
    void debugScript();
};

#endif // MAINWINDOW_H
