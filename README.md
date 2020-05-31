# Interactive-Scene

A CG project were I am building a full interactive scene with OpenGL.  

## To Run the code

The following command can be used to run the code

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

Arrows(`<-^->`): Control the camera in their respective direction.  

--------`'p'`--------  
`'l'` - `';'` - `'''`: Navigate the scene Upward/Downward or Rotate Right/Left.  
__The mouse can also be used to rotate the body.__  

### Body Control

#### Shoulder

`s` - `S`: Right Shoulder (Lateral)  
`a` - `A`: Left Shoulder (Lateral)  
`w` - `W`: Right Shoulder  
`q` - `Q`: Left Shoulder  

#### Elbow

`r` - `R`: Right Elbow  
`e` - `E`: Left Elbow  

#### Hand

`f` - `F`: Grip  
`g` - `G`: Finger Tips  

#### Leg

`x` - `X`: Right Hip  
`z` - `z`: Left Hip  
`v` - `V`: Right Hip (Lateral)  
`c` - `C`: Left Hip (Lateral)  
`n` - `N`: Right Knee  
`b` - `B`: Left Knee  

## Results

### The final scene

![Alt Text](res/imgs/ScreenShot_1.png)

### Sub-Menu for floor texture

(Accesd by pressing mouse right-click)

![Alt Text](res/imgs/ScreenShot_2.png)

### There are three different objects in the scene

A fire hydrant

![Alt Text](res/imgs/ScreenShot_3.png)

A soceer ball

![Alt Text](res/imgs/ScreenShot_4.png)

An Eagle (Actually a falcon but we didn't have time to get an actual eagle and we wanted an eagle to fly over the robot after the shot)

![Alt Text](res/imgs/ScreenShot_5.png)