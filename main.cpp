#include <QApplication>
#include <QSurfaceFormat>
#include "MainWindow.hpp"

#include "QVTKOpenGLWidget.h"


int
main(int argc, char *argv[])
{
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

  QApplication app(argc, argv);
  MainWindow w(argc, argv);
  w.show();
   
  return app.exec();
}
