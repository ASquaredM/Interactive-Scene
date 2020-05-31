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

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/ScreenShot_1.png?raw=true)

### Sub-Menu for floor texture

(Accessed by pressing the mouse right-click)

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/ScreenShot_2.png?raw=true)

### There are three different objects in the scene

A fire hydrant

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/ScreenShot_3.png?raw=true)

A soccer ball

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/ScreenShot_4.png?raw=true)

An Eagle (Actually a falcon, but we didn't have time to get an actual eagle and we wanted an eagle to fly over the robot throughout the scene)

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/ScreenShot_5.png?raw=true)

### There are three animations in the scene

The flying eagle (Always ON)

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/GIF_1.gif?raw=true)

A Goal Kick (Press `k`)

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/GIF_2.gif?raw=true)

A Celebratory Jumb (Press `y`)

![Alt Text](https://github.com/ASquaredM/Media/blob/master/Temp/imgs/GIF_3.gif?raw=true)
