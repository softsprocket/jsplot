#include "debugoutputdialog.h"

#include <QDialog>
#include <QWidget>
#include <QPlainTextEdit>
#include <QString>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>

void DebugOutputTextEdit::contextMenuEvent (QContextMenuEvent *event) {
    QMenu *menu = createStandardContextMenu ();

    QAction* clearAction = new QAction (tr ("C&lear"), this);
    connect (clearAction, SIGNAL (triggered ()), this, SLOT (clear ()));

    menu->addAction (clearAction);

    menu->exec (event->globalPos ());
    delete menu;
}

DebugOutputDialog::DebugOutputDialog (QWidget* parent) : QDialog (parent) {
    setSizeGripEnabled (true);

    QVBoxLayout* layout = new QVBoxLayout;

    setLayout (layout);

    m_textEdit = new DebugOutputTextEdit;
    m_textEdit->setReadOnly (true);

    layout->addWidget (m_textEdit);

    resize (600, 400);
}

void DebugOutputDialog::appendText (QString txt) {
    m_textEdit->appendPlainText (txt);
}


void DebugOutputDialog::clear () {
   m_textEdit->clear ();
}

void DebugOutputDialog::clearText () {
    clear ();
}
