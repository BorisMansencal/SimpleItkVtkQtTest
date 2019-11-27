This program load a 3D image file via ITK and displays it in a VTK/Qt application.


If I execute this program with no argument, I get the following errors:
```
ERROR: In /home/mansenca/tools/VTK-8.2.0/Common/ExecutionModel/vtkDemandDrivenPipeline.cxx, line 709
vtkCompositeDataPipeline (0x5597c17e8ce0): Input port 0 of algorithm vtkImageMapToWindowLevelColors(0x5597c17ec9b0) has 0 connections but is not optional.

ERROR: In /home/mansenca/tools/VTK-8.2.0/Common/ExecutionModel/vtkDemandDrivenPipeline.cxx, line 709
vtkCompositeDataPipeline (0x5597c17e8ce0): Input port 0 of algorithm vtkImageMapToWindowLevelColors(0x5597c17ec9b0) has 0 connections but is not optional.

ERROR: In /home/mansenca/tools/VTK-8.2.0/Common/ExecutionModel/vtkDemandDrivenPipeline.cxx, line 709
vtkCompositeDataPipeline (0x5597c17e8ce0): Input port 0 of algorithm vtkImageMapToWindowLevelColors(0x5597c17ec9b0) has 0 connections but is not optional.
```

If I pass a valid 3D image file as parameter to the executable on the command line, I don't get these errors.

I would like to get rid off these errors to be able to load the image via an "Open File..." menu entry for example.



Tested with:
```
Ubuntu 18.04.3 
gcc 7.4.0
cmake 3.13.4
InsightToolkit 5.0.1
VTK 8.2.0
Qt 5.9.5
```

