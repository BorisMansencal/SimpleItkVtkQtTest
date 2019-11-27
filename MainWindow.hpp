#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "itkImage.h"
#include "itkImageToVTKImageFilter.h"
#include "vtkSmartPointer.h"

class vtkResliceImageViewer;
class QVTKOpenGLNativeWidget;


class MainWindow : public QMainWindow
{   
public:
  MainWindow(int argc, char *argv[], QWidget *parent = 0);
  
private:
  void openImage(const QString &fileName);
  void displayImage();

private:
  using Image3DType = itk::Image<float, 3>;
  Image3DType::Pointer m_image3D = nullptr;
  using ConnectorType = itk::ImageToVTKImageFilter<Image3DType>;
  ConnectorType::Pointer m_connector = nullptr;

  vtkSmartPointer<vtkResliceImageViewer> m_riw;


  QVTKOpenGLNativeWidget *m_view;
};

#endif // MAINWINDOW_HPP
