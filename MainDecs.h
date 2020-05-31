#ifndef MAINDECS_H_
#define MAINDECS_H_

#include <math.h>
#include "MathHelpers.h"

int windowWidth = 1024;
int windowHeight = 768;
GLfloat aspect = GLfloat(windowWidth) / GLfloat(windowHeight);

float DRot = 90;
float Zmax, Zmin;
float VRot = 0.0;

Image *floorTex;

GLMmodel *pmodel;
GLMmodel *pmodel1;
GLMmodel *pmodel2;
GLMmodel *pmodel3;

// Material Properties
GLfloat mat_amb_diff[] = {0.643, 0.753, 0.934, 1.0};
GLfloat mat_specular[] = {0.0, 0.0, 0.0, 1.0};
GLfloat shininess[] = {100.0};
//left teapot specular
GLfloat teapotl_diff[] = {0.0, 0.0, 1.0, 1.0};
GLfloat teapotl_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat teapotl_shininess[] = {10.0};
//middle teapot diffuse
GLfloat teapotm_diff[] = {1.0, 0, 0.0, 1.0};
GLfloat teapotm_specular[] = {0.0, 0.0, 0.0, 0.0};
GLfloat teapotm_shininess[] = {1.0};
//right teapot glosy
GLfloat teapotr_diff[] = {1.0, .0, 0.0, 1.0};
GLfloat teapotr_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat teapotr_shininess[] = {1000.0};
//cube
GLfloat cube_diff[] = {1.0, 0.0, 0.0, 1.0};
GLfloat cube_specular[] = {0.5, 0.5, 0.5, 1.0};
GLfloat cube_shininess[] = {10.0};

// White light source
GLfloat light_ambient[] = {0.3, 0.3, 0.3, 0.5};
GLfloat light_diffuse0[] = {0, -1, 0, 1.0};
GLfloat light_diffuse1[] = {0, 0.401, 0.916, 1.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

// Light Position
GLfloat lightPosition0[] = {0.0, 7.1, 0.0, 1.0};
GLfloat lightPosition1[] = {0.0, 1.1, -21.0, 1.0};

// Light Color
GLfloat lightColor1[] = {0.8314f, 0.9216f, 1.0f, 1.0f};

int R_Shoulder = -85, L_Shoulder = -85, R_Shoulder_Lat = 0, L_Shoulder__Lat = 0, R_Elbow = 0, L_Elbow = 0, FingerBase = 10, FingerTip = -20, R_Hip = 0,
    L_Hip = 0, R_Hip_Lat = 0, L_Hip_Lat = 0,
    R_Knee = 0, L_Knee = 0,eagle_angle=180;
float Z_ball = -2.5;

int moving = 0, startx = 0, starty = 0;

GLfloat angle = 0.0;  /* in degrees */
GLfloat angle2 = 0.0; /* in degrees */

double eye[] = {0, 0, -31};
double center[] = {0, 0, 0};
double up[] = {0, 1, 0};
double Cross_Product_Vect[] = {0, 0, 0};

GLuint startList;

GLuint _textureId = 0;
GLuint _textureId1 = 0;
GLuint _textureId2 = 0;
GLuint _textureId3 = 0;
GLuint _textureId4 = 0;
GLuint _textureId5 = 0;

void init(void);
void display(void);
void reshape(int w, int h);

GLuint loadTexture(Image *image, GLuint tex);

void drawmodel(void);
void drawBall(void);
void drawFireHydrant(void);
void drawEagle(void);

void initRendering();

void screen_menu(int value);

#endif