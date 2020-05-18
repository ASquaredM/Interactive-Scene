#include <GL/glut.h>
#include <math.h>

static int R_Shoulder = 0, L_Shoulder = 0, R_Shoulder_Lat = 0, L_Shoulder__Lat = 0, R_Elbow = 0, L_Elbow = 0, FingerBase = 10, FingerTip = -20, R_Hip = 0,
		   L_Hip = 0, R_Hip_Lat = 0, L_Hip_Lat = 0,
		   R_Knee = 0, L_Knee = 0;

int moving, startx, starty;

GLfloat angle = 0.0;  /* in degrees */
GLfloat angle2 = 0.0; /* in degrees */

static double eye[] = {0, 0, -20};
static double center[] = {0, 0, 1};
static double up[] = {0, 1, 0};
static double Cross_Product_Vect[] = {0, 0, 0};

void init(void);
void display(void);
void specialKeys(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);
static void mouse(int button, int state, int x, int y);
static void motion(int x, int y);

//Functions for the Camera movement
void crossProduct(double a[], double b[], double c[]);
void normalize(double a[]);
void rotatePoint(double a[], double theta, double p[]);
void Right();
void Left();
void Up();
void Down();
void moveForward();
void moveBack();

//Function used for Drawing
#include "DrawingFuncs.h"
void CreateFullBody();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutReshapeFunc(reshape);

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glPushMatrix();

	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);

	CreateFullBody();

	glPopMatrix();

	glutSwapBuffers();
	glEnable(GL_DEPTH_TEST);
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

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Left();
		break;
	case GLUT_KEY_RIGHT:
		Right();
		break;
	case GLUT_KEY_UP:
		Up();
		break;
	case GLUT_KEY_DOWN:
		Down();
		break;
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	// List all youe keyboard keys from assignment two her for body movement
	switch (key)
	{
	case 'j':
		moveForward();
		glutPostRedisplay();
		break;

	case 'm':
		moveBack();
		glutPostRedisplay();
		break;

	case 'a':
		if (R_Shoulder <= 85)
		{
			R_Shoulder = (R_Shoulder + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'A':
		if (R_Shoulder >= -85)
		{
			R_Shoulder = (R_Shoulder - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 's':
		if (L_Shoulder <= 85)
		{
			L_Shoulder = (L_Shoulder + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'S':
		if (L_Shoulder >= -85)
		{
			L_Shoulder = (L_Shoulder - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 't':
		if (R_Shoulder_Lat <= 35)
		{
			R_Shoulder_Lat = (R_Shoulder_Lat + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'T':
		if (R_Shoulder_Lat >= -85)
		{
			R_Shoulder_Lat = (R_Shoulder_Lat - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'y':
		if (L_Shoulder__Lat <= 35)
		{
			L_Shoulder__Lat = (L_Shoulder__Lat + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'Y':
		if (L_Shoulder__Lat >= -85)
		{
			L_Shoulder__Lat = (L_Shoulder__Lat - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'w':
		if (R_Elbow <= 135)
		{
			R_Elbow = (R_Elbow + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'W':
		if (R_Elbow >= 0)
		{
			R_Elbow = (R_Elbow - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'e':
		if (L_Elbow <= 135)
		{
			L_Elbow = (L_Elbow + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'E':
		if (L_Elbow >= 0)
		{
			L_Elbow = (L_Elbow - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'f':
		if (FingerBase <= 25)
		{
			FingerBase = (FingerBase + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'F':
		if (FingerBase >= 0)
		{
			FingerBase = (FingerBase - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'g':
		if (FingerTip <= -5)
		{
			FingerTip = (FingerTip + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'G':
		if (FingerTip >= -35)
		{
			FingerTip = (FingerTip - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'z':
		if (R_Hip <= 85)
		{
			R_Hip = (R_Hip + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'Z':
		if (R_Hip >= -85)
		{
			R_Hip = (R_Hip - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'x':
		if (L_Hip <= 85)
		{
			L_Hip = (L_Hip + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'X':
		if (L_Hip >= -85)
		{
			L_Hip = (L_Hip - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'c':
		if (R_Hip_Lat <= 75)
		{
			R_Hip_Lat = (R_Hip_Lat + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'C':
		if (R_Hip_Lat >= 5)
		{
			R_Hip_Lat = (R_Hip_Lat - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'v':
		if (L_Hip_Lat <= 75)
		{
			L_Hip_Lat = (L_Hip_Lat + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'V':
		if (L_Hip_Lat >= 5)
		{
			L_Hip_Lat = (L_Hip_Lat - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'b':
		if (R_Knee <= 135)
		{
			R_Knee = (R_Knee + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'B':
		if (R_Knee >= 0)
		{
			R_Knee = (R_Knee - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'n':
		if (L_Knee <= 135)
		{
			L_Knee = (L_Knee + 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 'N':
		if (L_Knee >= 0)
		{
			L_Knee = (L_Knee - 5) % 360;
			glutPostRedisplay();
		}
		break;

	case 27:
		exit(0);
		break;

	default:
		break;
	}
}

static void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			moving = 1;
			startx = x;
			starty = y;
		}
		if (state == GLUT_UP)
		{
			moving = 0;
		}
	}
}

static void motion(int x, int y)
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

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta)) * (a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta)) * (a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta)) * (a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta) * p[0];
	temp[1] += cos(theta) * p[1];
	temp[2] += cos(theta) * p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];
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