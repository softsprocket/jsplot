#include "tabbedjseditor.h"

#include <QTabBar>
#include <QStackedWidget>
#include <QString>
#include <QVBoxLayout>

#include "jstextedit.h"

TabbedJSEditor::TabbedJSEditor (QWidget *parent) : QWidget (parent) {
    m_tabBar = new QTabBar;
    m_stackedWidget = new QStackedWidget;

    QVBoxLayout* layout = new QVBoxLayout (this);
    setLayout (layout);

    layout->addWidget (m_tabBar);
    layout->addWidget (m_stackedWidget);

    m_stackedWidget->addWidget (new JSTextEdit (this));
    m_tabBar->addTab ("0");
    m_tabBar->setTabText (0, "*new");


}

void TabbedJSEditor::clear () {
    JSTextEdit* edit = dynamic_cast<JSTextEdit*> (m_stackedWidget->currentWidget ());

    edit->clear ();
}

QString TabbedJSEditor::toPlainText () {
    JSTextEdit* edit = dynamic_cast<JSTextEdit*> (m_stackedWidget->currentWidget ());

    return edit->toPlainText ();
}

