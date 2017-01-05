#include "graphdisplaywidget.h"

#include<QOpenGLWidget>


GraphDisplayWidget::GraphDisplayWidget () {

}

void GraphDisplayWidget::initializeGL () {
    initializeOpenGLFunctions ();
    glClearColor (1.0f, 1.0f, 1.0f, 1.0f);
}

void GraphDisplayWidget::paintGL () {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GraphDisplayWidget::resizeGL (int w, int h) {

}
