#ifndef GRAPHDISPLAYWIDGET_H
#define GRAPHDISPLAYWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class GraphDisplayWidget : public QOpenGLWidget, protected QOpenGLFunctions {
public:
    GraphDisplayWidget ();

protected:
    void initializeGL ();
    void paintGL ();
    void resizeGL (int w, int h);
};

#endif // GRAPHDISPLAYWIDGET_H
