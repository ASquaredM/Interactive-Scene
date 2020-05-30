#include <GL/glut.h>
#include <math.h>
#include "glm.h"
#include "Decs.h"
#include "DrawingFuncs.h"
#include "imageloader.h"
#include "CameraFns.h"
#include "MainIO.h"
#include "MainDecs.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	init();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	//glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glutMainLoop();
	return 0;
}

void init(void)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Interactive Scene");
	initRendering();

	glMatrixMode(GL_PROJECTION);
	gluPerspective(65.0, aspect, 1.0, 60.0);
}

//Initializes 3D rendering
void initRendering()
{
	Image *image = loadBMP("floor.bmp");
	_textureId = loadTexture(image);
	delete image;

	// Setting light source properties and enabling it
	// Turn on the power
	glEnable(GL_LIGHTING);
	// Flip light switch
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	// assign light parameters
	// Light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);
	// Light 1
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

	// Material Properties
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	glEnable(GL_NORMALIZE);
	//Enable smooth shading
	glShadeModel(GL_SMOOTH);
	// Enable Depth buffer
	glEnable(GL_DEPTH_TEST);

	// startList = glGenLists(4);
	// glNewList(startList, GL_COMPILE);
	// glRotatef(90, 0, 1, 0);
	// 	glScalef(1, 1.2, 1);
	// 	glTranslatef(1.7, -0.05, -.3);
	// pmodel1 = pmodel4;
	// drawmodel();
	// glEndList();

	// glNewList(startList + 1, GL_COMPILE);
	// 	glRotatef(270, 0, 1, 0);
	// 	glScalef(1, 1.2, 1);
	// 	glTranslatef(-1.7, -0.05, -.3);
	// pmodel1 = pmodel4;
	// drawmodel();
	// glEndList();

	// glNewList(startList + 2, GL_COMPILE);
	// glTranslatef(0.3, -.1, 0.075);
	// pmodel1 = pmodel2;
	// drawmodel();
	// glEndList();

	// glNewList(startList + 3, GL_COMPILE);
	// glTranslatef(-0.6, 0, 0.0);
	// pmodel1 = pmodel2;
	// drawmodel();
	// glEndList();
}

void display(void)
{
	// Clear Depth and Color buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
	glPushMatrix();

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

	glPopMatrix();
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

	// materials properties
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
	//floor
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);

	glNormal3f(0.0, -1.0, 0.0);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-21, -8.1, 21);

	glTexCoord2f(5.0f, 0.0f);
	glVertex3f(21, -8.1, 21);

	glTexCoord2f(5.0f, 20.0f);
	glVertex3f(21, -8.1, -21);

	glTexCoord2f(0.0f, 20.0f);
	glVertex3f(-21, -8.1, -21);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv//
	glPushMatrix();

	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);

	// glTranslatef(tx, 0, tz);
	CreateFullBody();

	glPopMatrix();
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//

	// To Represent Light Sources and measure distances (I am too lazy to figure those on my own)
	Sphere(0.1, 0.0, 15.1, 0);
	Sphere(0.1, 0.0, 1.1, -21);

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

//////////////////

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image *image)
{
	GLuint textureId;
	glGenTextures(1, &textureId);			 //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,				  //Always GL_TEXTURE_2D
				 0,							  //0 for now
				 GL_RGB,					  //Format OpenGL uses for image
				 image->width, image->height, //Width and height
				 0,							  //The border of the image
				 GL_RGB,					  //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE,			  //GL_UNSIGNED_BYTE, because pixels are stored
											  //as unsigned numbers
				 image->pixels);			  //The actual pixel data
	return textureId;						  //Returns the id of the texture
}

void drawmodel(void)
{
	glmUnitize(pmodel1);
	glmFacetNormals(pmodel1);
	glmVertexNormals(pmodel1, 90.0);
	glmScale(pmodel1, .15);
	glmDraw(pmodel1, GLM_SMOOTH | GLM_MATERIAL);
}