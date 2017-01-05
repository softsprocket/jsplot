#include "mainwindow.h"

#include <QHBoxLayout>
#include <QWidget>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include<QAction>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QJSEngine>
#include <QJSValue>

#include "graphdisplaywidget.h"

MainWindow::MainWindow (QWidget *parent)
    : QMainWindow (parent) {


    m_textEdit = new TabbedJSEditor;
    //QWidget* widget = new QWidget;
    //this->setCentralWidget (widget);
    this->setCentralWidget (m_textEdit);

//    QHBoxLayout* layout = new QHBoxLayout (widget);
//
//    m_graphDisplay = new GraphDisplayWidget;
//    layout->addWidget (m_graphDisplay, 1);
//
//    QWidget* textAreaWidget = new QWidget;
//    QVBoxLayout* textAreaLayout = new QVBoxLayout (textAreaWidget);
//
//    m_textEdit = new TabbedJSEditor;
//    textAreaLayout->addWidget (m_textEdit);
//
//    QWidget* buttonWidget = new QWidget;
//    QHBoxLayout* buttonLayout = new QHBoxLayout (buttonWidget);
//
//    QPushButton* executeButton = new QPushButton ("Execute");
//    connect (executeButton, SIGNAL (clicked ()), this, SLOT (executeScript ()));
//
//    QPushButton* clearButton = new QPushButton ("Clear");
//    connect (clearButton, SIGNAL (clicked ()), this, SLOT (clearScript ()));
//
//    QPushButton* debugButton = new QPushButton ("Debug");
//    connect (debugButton, SIGNAL (clicked ()), this, SLOT (debugScript ()));
//
//
//    buttonLayout->addWidget (debugButton);
//    buttonLayout->addWidget (clearButton);
//    buttonLayout->addWidget (executeButton);
//
//    textAreaLayout->addWidget (buttonWidget);
//
//    layout->addWidget (textAreaWidget, 1);

    createActions ();

    QMenu* file = new QMenu (tr ("&File"));
    file->addAction (m_new);
    file->addAction (m_open);
    file->addAction (m_save);

    menuBar ()->addMenu (file);

    QMenu* script = new QMenu (tr ("&Script"));
    script->addAction (m_clear);
    script->addAction (m_exec);
    script->addAction (m_debug);

    menuBar ()->addMenu (script);

    m_debugDialog = new DebugOutputDialog (this);

    resize (800, 400);

    statusBar ()->showMessage (tr ("Ready"));
}

MainWindow::~MainWindow () {

}

void MainWindow::createActions () {

    m_new = new QAction (tr ("&New"), this);
    m_new->setShortcut (QKeySequence::New);
    m_new->setStatusTip (tr ("Clear script and plot"));
    connect (m_new, SIGNAL (triggered ()), this, SLOT (newScript ()));

    m_open = new QAction (tr ("&Open"), this);
    m_open->setShortcut (QKeySequence::Open);
    m_open->setStatusTip (tr ("Open saved script"));
    connect (m_open, SIGNAL (triggered ()), this, SLOT (openScript ()));

    m_save = new QAction (tr ("&Save"), this);
    m_save->setShortcut (QKeySequence::Save);
    m_save->setStatusTip (tr ("Save current script"));
    connect (m_save, SIGNAL (triggered ()), this, SLOT (saveScript ()));

    m_clear = new QAction (tr ("Clea&r"), this);
    m_clear->setShortcut (QKeySequence::fromString ("Ctrl+R"));
    m_clear->setStatusTip (tr ("Clear script"));
    connect (m_clear, SIGNAL (triggered ()), this, SLOT (clearScript ()));

    m_exec = new QAction (tr ("&Execute"), this);
    m_exec->setShortcut (QKeySequence::fromString ("Ctrl+E"));
    m_exec->setStatusTip (tr ("Execute script"));
    connect (m_exec, SIGNAL (triggered ()), this, SLOT (executeScript ()));

    m_debug = new QAction (tr ("&Debug"), this);
    m_debug->setShortcut (QKeySequence::fromString ("Ctrl+D"));
    m_debug->setStatusTip (tr ("Open debug script window"));
    connect (m_debug, SIGNAL (triggered ()), this, SLOT (debugScript ()));
}

void MainWindow::newScript () {

}

void MainWindow::openScript () {

}

void MainWindow::saveScript () {

}

void MainWindow::clearScript () {
    m_debugDialog->clearText ();
    m_textEdit->clear ();
}

void MainWindow::executeScript () {
    QString txt = m_textEdit->toPlainText ();

    QJSValue result = jsEngine.evaluate (txt);

    if (result.isError ()) {
        m_debugDialog->appendText ("Uncaught exception at line ");
        m_debugDialog->appendText (result.property("lineNumber").toString ());
        m_debugDialog->appendText ("\n");
        m_debugDialog->appendText (result.toString());
        m_debugDialog->appendText ("\n");
    } else {
        m_debugDialog->appendText (result.toString ());
    }
}

void MainWindow::debugScript () {

    m_debugDialog->show ();
}
