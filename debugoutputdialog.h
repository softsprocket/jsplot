#ifndef DEBUGOUTPUTDIALOG_H
#define DEBUGOUTPUTDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPlainTextEdit>
#include <QString>

class DebugOutputTextEdit : public QPlainTextEdit {
public:
    void contextMenuEvent (QContextMenuEvent *event);
};

class DebugOutputDialog : public QDialog {
public:
    DebugOutputDialog (QWidget* parent);

    void appendText (QString txt);

    void clearText ();
protected:
    DebugOutputTextEdit* m_textEdit;

private slots:
    void clear ();
};

#endif // DEBUGOUTPUTDIALOG_H
