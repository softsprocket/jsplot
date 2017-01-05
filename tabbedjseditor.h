#ifndef TABBEDJSEDITOR_H
#define TABBEDJSEDITOR_H

#include <QWidget>
#include <QTabBar>
#include <QStackedWidget>
#include <QString>

class TabbedJSEditor : public QWidget {
    Q_OBJECT
public:
    explicit TabbedJSEditor (QWidget *parent = 0);

    void clear ();
    QString toPlainText ();
signals:

public slots:

private:
    QTabBar* m_tabBar;
    QStackedWidget* m_stackedWidget;
};

#endif // TABBEDJSEDITOR_H
