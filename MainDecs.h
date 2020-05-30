#ifndef MAINDECS_H_
#define MAINDECS_H_

int windowWidth = 1024;
int windowHeight = 768;
GLfloat aspect = GLfloat(windowWidth) / GLfloat(windowHeight);

float DRot = 90;
float Zmax, Zmin;
GLMmodel *pmodel;
float VRot = 0.0;

GLMmodel *pmodel1;

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
GLfloat light_ambient[] = {0.0, 0.0, 0.0, 0.0};
GLfloat light_diffuse[] = {0.5, 0.5, 0.5, 1.0};
GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

// Light Position
GLfloat lightPosition0[] = {0.5, 5.0, 0.0, 1.0};
GLfloat lightPosition1[] = {-0.5, -5.0, -2.0, 1.0};

// Light Color
GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f};

int R_Shoulder = 0, L_Shoulder = 0, R_Shoulder_Lat = 0, L_Shoulder__Lat = 0, R_Elbow = 0, L_Elbow = 0, FingerBase = 10, FingerTip = -20, R_Hip = 0,
    L_Hip = 0, R_Hip_Lat = 0, L_Hip_Lat = 0,
    R_Knee = 0, L_Knee = 0;

int moving = 0, startx = 0, starty = 0;

GLfloat angle = 0.0;  /* in degrees */
GLfloat angle2 = 0.0; /* in degrees */

double eye[] = {0, 0, -20};
double center[] = {0, 0, 1};
double up[] = {0, 1, 0};
double Cross_Product_Vect[] = {0, 0, 0};

GLuint _textureId;  //The id of the texture
GLuint _textureId1; //The id of the texture

GLuint startList;

GLuint loadTexture(Image *image);

void drawmodel(void);

void initRendering();

#endif