#ifndef DRWAINGFUNCS_H_
#define DRWAINGFUNCS_H_

#include <GL/glut.h>

//Functions used for Drawing
void Rot(GLfloat ang, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat tbx,
         GLfloat tby, GLfloat tbz, GLfloat fx, GLfloat fy, GLfloat fz);
void Cube(GLfloat x, GLfloat y, GLfloat z);
void Sphere(GLfloat r, GLfloat tx, GLfloat ty, GLfloat tz);
void Cylinder(GLUquadric *quad, GLfloat r, GLfloat orintaion);
void Arm(GLfloat Shoulder, GLfloat Shoulder_Lat, GLfloat Elbow, GLfloat FingerBase, GLfloat FingerTip,
         GLfloat tx, GLfloat ty, GLfloat tz, GLfloat orintation);
void Leg(GLfloat Hip, GLfloat Hip_Lat, GLfloat Knee, GLfloat tx, GLfloat ty,
         GLfloat tz, GLfloat orintation);

//Function used for Drawing The Robot Body
void CreateFullBody();

// Function used to draw floow
void DrawWall(GLfloat x, GLfloat y, GLfloat z, GLuint tex);

#endif