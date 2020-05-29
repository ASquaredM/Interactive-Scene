#ifndef MAINDECS_H_
#define MAINDECS_H_

// White light source
float light_ambient[] = {1.0, 1.0, 1.0, 1.0};
float light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
float light_specular[] = {1.0, 1.0, 1.0, 1.0};

// Light position
float light_position[] = {0.0, 11.0, 4.0, 1.0};

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

#endif