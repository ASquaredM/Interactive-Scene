#include <GL/glut.h>
#include <math.h>
#include "glm.h"
#include "Decs.h"
#include "DrawingFuncs.h"
#include "imageloader.h"
#include "MathHelpers.h"
#include "MainIO.h"
#include "MainDecs.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Interactive Scene");

	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glutMainLoop();
	return 0;
}

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);
}

void display(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);

	// Setting light source properties and enabling it
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glPushMatrix();

	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);

	CreateFullBody();

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 60.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void motion(int x, int y)
{
	if (moving)
	{
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}
}

void Right()
{
	// implement camera rotation arround vertical window screen axis to the right
	// used by mouse and right arrow
	rotatePoint(up, 0.5, eye);
}

void Left()
{
	// used by mouse and left arrow
	rotatePoint(up, -0.5, eye);
}

void Up()
{
	// implement camera rotation arround horizontal window screen axis +ve
	// used by up arrow
	crossProduct(eye, up, Cross_Product_Vect);
	normalize(Cross_Product_Vect);
	rotatePoint(Cross_Product_Vect, 0.5, eye);
	rotatePoint(Cross_Product_Vect, 0.5, up);
}

void Down()
{
	// implement camera rotation arround horizontal window screen axis
	// used by down arrow
	crossProduct(eye, up, Cross_Product_Vect);
	normalize(Cross_Product_Vect);
	rotatePoint(Cross_Product_Vect, -0.5, eye);
	rotatePoint(Cross_Product_Vect, -0.5, up);
}

void moveForward()
{
	double direction[3] = {0, 0, 0};
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];

	eye[0] += direction[0] * 0.1;
	eye[1] += direction[1] * 0.1;
	eye[2] += direction[2] * 0.1;
}

void moveBack()
{
	double direction[3] = {0, 0, 0};
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];

	eye[0] -= direction[0] * 0.1;
	eye[1] -= direction[1] * 0.1;
	eye[2] -= direction[2] * 0.1;
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