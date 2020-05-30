#include <GL/glut.h>
#include "DrawingFuncs.h"
#include "Decs.h"

void Rot(GLfloat ang, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat tbx,
         GLfloat tby, GLfloat tbz, GLfloat fx, GLfloat fy, GLfloat fz)
{
    glTranslatef(tbx, tby, tbz);
    glRotatef(ang, fx, fy, fz);
    glTranslatef(tx, ty, tz);
}

void Cube(GLfloat x, GLfloat y, GLfloat z)
{
    glPushMatrix();
    glScalef(x, y, z);
    glutWireCube(1.0);
    glPopMatrix();
}

void Sphere(GLfloat r, GLfloat tx, GLfloat ty, GLfloat tz)
{
    glPushMatrix();

    glTranslatef(tx, ty, tz);
    glutSolidSphere(r, 51, 51);

    glPopMatrix();
}

void Cylinder(GLUquadric *quad, GLfloat r, GLfloat orintation)
{
    glPushMatrix();

    Rot(orintation * 90, 0, 0, 0, 0, 0, 0, 0, 1, 0);
    gluCylinder(quad, r, r, 1.5, 21, 21);

    glPopMatrix();
}

void Arm(GLfloat Shoulder, GLfloat Shoulder_Lat, GLfloat Elbow, GLfloat FingerBase,
         GLfloat FingerTip, GLfloat tx, GLfloat ty, GLfloat tz, GLfloat orintation)
{
    //GLUquadricObj *quadratic;
    //quadratic = gluNewQuadric();

    glPushMatrix();

    //Shoulder Joint
    Sphere(0.35, tx - (orintation * 0.05), ty, tz);

    //Arm
    Rot(orintation * Shoulder_Lat, -tx, -ty, -tz, tx, ty, tz, 0, 1, 0);
    Rot(orintation * Shoulder, orintation * 1.21, 0, 0, tx, ty, tz, 0, 0, 1);
    //Cylinder(quadratic,0.31,orintation);
    Cube(2, 0.5, 0.5);

    //Shoulder Joint
    Sphere(0.25, orintation * 1, 0, 0);

    //Forearm
    Rot(orintation * Elbow, orintation * 1.1, 0, 0, orintation * 1, 0, 0, 0, 0, 1);
    Cube(2, 0.5, 0.5);

    //#####First Finger#####
    glPushMatrix();
    //Finger Base
    Rot(-orintation * FingerBase, orintation * 0.105, 0, 0, orintation * 1, (1.0 / 24.0), (1.0 / 6.0), 0, 1, 0);
    Cube(0.21, 0.05, 0.05);
    //Finger Tip
    Rot(-orintation * FingerTip, orintation * 0.105, 0, 0, orintation * 0.105, 0, 0, 0, 1, 0);
    Cube(0.21, 0.05, 0.05);
    glPopMatrix();

    //#####Second Finger#####
    glPushMatrix();
    //Finger Base
    Rot(orintation * FingerBase, orintation * 0.105, 0, 0, orintation * 1, (1.0 / 6.0), 0, 0, 0, 1);
    Cube(0.21, 0.05, 0.05);
    //Finger Tip
    Rot(orintation * FingerTip, orintation * 0.105, 0, 0, orintation * 0.105, 0, 0, 0, 0, 1);
    Cube(0.21, 0.05, 0.05);
    glPopMatrix();

    //#####Third Finger#####
    glPushMatrix();
    //Finger Base
    Rot(orintation * FingerBase, orintation * 0.105, 0, 0, orintation * 1, (1.0 / 24.0), -(1.0 / 6.0), 0, 1, 0);
    Cube(0.21, 0.05, 0.05);
    //Finger Tip
    Rot(orintation * FingerTip, orintation * 0.105, 0, 0, orintation * 0.105, 0, 0, 0, 1, 0);
    Cube(0.21, 0.05, 0.05);
    glPopMatrix();

    //#####Fourth Finger#####
    glPushMatrix();
    Rot(-21, 0, 0, 0, 0, 0, -0.05, 1, 0, 0);
    //Finger Base
    Rot(-orintation * FingerBase, orintation * 0.105, 0, 0, orintation * 1, -(1.0 / 8.0), (1.0 / 12.0), 0, 0, 1);
    Cube(0.21, 0.05, 0.05);
    //Finger Tip
    Rot(-orintation * FingerTip, orintation * 0.105, 0, 0, orintation * 0.105, 0, 0, 0, 0, 1);
    Cube(0.21, 0.05, 0.05);
    glPopMatrix();

    //#####Fifth Finger#####
    glPushMatrix();
    Rot(21, 0, 0, 0, 0, 0, 0.05, 1, 0, 0);
    //Finger Base
    Rot(-orintation * FingerBase, orintation * 0.105, 0, 0, orintation * 1, -(1.0 / 8.0), -(1.0 / 12.0), 0, 0, 1);
    Cube(0.21, 0.05, 0.05);
    //Finger Tip
    Rot(-orintation * FingerTip, orintation * 0.105, 0, 0, orintation * 0.105, 0, 0, 0, 0, 1);
    Cube(0.21, 0.05, 0.05);
    glPopMatrix();

    glPopMatrix();
}

void Leg(GLfloat Hip, GLfloat Hip_Lat, GLfloat Knee, GLfloat tx, GLfloat ty,
         GLfloat tz, GLfloat orintation)
{
    //GLUquadricObj *quadratic;
    //quadratic = gluNewQuadric();

    glPushMatrix();

    //Hip Joint
    Sphere(0.41, tx, ty - 0.1, tz);

    //Thigh
    Rot(orintation * Hip_Lat, -tx, -ty, -tz, tx, ty, tz, 0, 0, 1);
    Rot(Hip, 0, -2, 0, tx, ty, tz, 1, 0, 0);
    //Cylinder(quadratic,0.31,orintation);
    Cube(0.35, 3, 0.35);

    //Knee Joint
    Sphere(0.35, 0, -1.41, 0);

    //Knee
    Rot(Knee, 0, -1.45, 0, 0, -1.45, 0, 1, 0, 0);
    Cube(0.4, 3, 0.4);

    //Foot
    Rot(0, 0, -1.45, -0.35, 0, 0, 0, 0, 0, 0);
    Cube(0.5, 0.21, 1);

    glPopMatrix();
}

void CreateFullBody()
{
    Sphere(0.5, 0, 2, 0);

    Cube(2, 3, 1);

    Arm(R_Shoulder, R_Shoulder_Lat, R_Elbow, FingerBase, FingerTip, -1.35, 1.3, 0, -1);
    Arm(L_Shoulder, L_Shoulder__Lat, L_Elbow, FingerBase, FingerTip, 1.35, 1.3, 0, 1);

    Leg(R_Hip, R_Hip_Lat, R_Knee, -0.5, -1.7, 0, -1);
    Leg(L_Hip, L_Hip_Lat, L_Knee, 0.5, -1.7, 0, 1);
}

void DrawWall(GLfloat x, GLfloat y, GLfloat z, GLuint tex)
{
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);

    GLfloat Sam = 3.0f;

    glNormal3f(0.0, 1.0, 0.0);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-x, y, z);

    glTexCoord2f(Sam, 0.0f);
    glVertex3f(x, y, z);

    glTexCoord2f(Sam, Sam);
    glVertex3f(x, y, -z);

    glTexCoord2f(0.0f, Sam);
    glVertex3f(-x, y, -z);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

/*
    glNormal3f(0.0, -1.0, 0.0);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-21, -8.1, 21);

	glTexCoord2f(5.0f, 0.0f);
	glVertex3f(21, -8.1, 21);

	glTexCoord2f(5.0f, 20.0f);
	glVertex3f(21, -8.1, -21);

	glTexCoord2f(0.0f, 20.0f);
	glVertex3f(-21, -8.1, -21);
*/