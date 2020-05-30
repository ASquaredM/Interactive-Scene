# Interactive-Scene

A CG project were I am building a full interactive scene with OpenGL.  

## To Run the code

The code uses a header file that contains the functions used for drawing.  

So, the following command can be used to run the code

``` terminal
g++ -o Exec main.cpp imageloader.cpp glm.cpp DrawingFuncs.cpp MathHelpers.cpp MainIO.cpp CameraFns.cpp -lGL -lGLU -lglut -lm
```

Or alternatively, the provided `Exec` file can be run like so.

``` terminal
./Exec
```

## Code Functions:

### Functions used for drwaing (contained in `DrawingFuncs.h`)

`Cube()` is used to create a cube and initialize its dimensions.  
`Sphere()` is used to create a sphere and initialize its dimensions.  
`Cylinder()`will be used later to give better shapes to the limbs.  
`Rot()` is used to move and rotate objects.  
`Arm()` is used to creat an arm with the given parameters (Angles,Cooridinates).  
`Arm()` is used to creat an arm with the given parameters (Angles,Cooridinates).  

### Functions used for camera movement

`Right()` - `Left()` is used for camera rotation arround the vertical window screen axis.  
`Up()` - `Down()` is used camera rotation arround the horizontal window screen axis.  
`moveForward()` - `moveBack()` is used for Forward/Backward Navigation

## Controls

### Camera Controls

Arrows: Control the camera in their respective direction.  
`'k'` - `','`: Navigate the body Forward/Backward respectively.  
__The mouse can also be used to rotate the body.__  

### Body Control

`a` - `A`: Right Shoulder (Lateral)  
`s` - `S`: Left Shoulder (Lateral)  
`t` - `T`: Right Shoulder  
`y` - `Y`: Left Shoulder  
`f` - `F`: Grip  
`g` - `G`: Finger Tips  
`z` - `Z`: Right Hip  
`x` - `X`: Left Hip  
`c` - `C`: Right Hip (Lateral)  
`v` - `V`: Left Hip (Lateral)  
`b` - `B`: Right Knee  
`n` - `N`: Left Knee  
