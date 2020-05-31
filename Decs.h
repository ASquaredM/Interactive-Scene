#ifndef DECS_H_
#define DECS_H_

#include <GL/glut.h>

extern int R_Shoulder, L_Shoulder, R_Shoulder_Lat, L_Shoulder__Lat,
    R_Elbow, L_Elbow, FingerBase, FingerTip, R_Hip, L_Hip,
    R_Hip_Lat, L_Hip_Lat, R_Knee, L_Knee ;
extern float Z_ball ;
extern int moving, startx, starty;

extern GLfloat angle;  /* in degrees */
extern GLfloat angle2; /* in degrees */

extern double eye[];
extern double center[];
extern double up[];
extern double Cross_Product_Vect[];
void timerLeg(int value) ;
void timerBall(int value) ;
void timerHip(int value) ;




#endif