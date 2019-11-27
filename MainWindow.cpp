#include "MainWindow.hpp"

#include<iostream>

//ITK
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageSeriesReader.h"
#include "itkImageToVTKImageFilter.h"
//VTK
#include "vtkResliceImageViewer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "QVTKOpenGLNativeWidget.h"


MainWindow::MainWindow(int argc, char *argv[],
		       QWidget *parent) :
    QMainWindow(parent)
{
  m_view=new QVTKOpenGLNativeWidget(this);
  this->setCentralWidget(m_view);
  
  m_riw = vtkSmartPointer<vtkResliceImageViewer>::New();
  vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
  m_riw->SetRenderWindow(renderWindow);

  m_view->SetRenderWindow(m_riw->GetRenderWindow());
  m_riw->SetupInteractor(m_view->GetRenderWindow()->GetInteractor());

  if (argc > 1) {
    openImage(argv[1]);
  }
  
}

void
MainWindow::openImage(const QString &fileName)
{
  if (! fileName.isEmpty()) {

    using ReaderType = itk::ImageFileReader<Image3DType>;
    ReaderType::Pointer reader = ReaderType::New();

    bool loaded = false;
    try {
      reader->SetFileName(fileName.toStdString());
      reader->Update();
      m_image3D = reader->GetOutput();
      loaded = true;
    }
    catch (itk::ExceptionObject &e) {
      std::cerr<<"ERROR*:" << e <<std::endl;
      throw std::exception();
    }
    displayImage();
  }
}
  
void MainWindow::displayImage()
{
  if (m_image3D == nullptr)
    return;

  m_connector = ConnectorType::New();
  m_connector->SetInput(m_image3D);
  try {
    m_connector->Update();
  }
  catch (itk::ExceptionObject &e) {
    std::cerr <<"ERROR*:" << e << std::endl;
    throw std::exception();
  }

  m_riw->SetInputData(m_connector->GetOutput());
  m_riw->SetSliceOrientation(0);
  m_riw->SetResliceModeToAxisAligned();
  m_riw->SetSlice(m_riw->GetSliceMax()/2);
}

