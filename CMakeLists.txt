cmake_minimum_required(VERSION 3.10.2)
project (ItkVtkGlue)

find_package(ITK REQUIRED HINTS $ENV{HOME}/tools/InsightToolkit-5.0.1/build/)
include(${ITK_USE_FILE})
find_package(VTK REQUIRED HINTS $ENV{HOME}/tools/VTK-8.2.0/build)
include(${VTK_USE_FILE})

if("${VTK_QT_VERSION}" STREQUAL "")
  message(FATAL_ERROR "VTK was not built with Qt")
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED QUIET)

set(CMAKE_CXX_STANDARD 11) 

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(simpleItkVtkQtTest main.cpp MainWindow.cpp)
target_link_libraries(simpleItkVtkQtTest  ${ITK_LIBRARIES} ${VTK_LIBRARIES} Qt5::Core Qt5::Gui Qt5::Widgets)


