#include <GL/glut.h>
#include "Decs.h"
#include "CameraFns.h"

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        moveLeft();
        break;
    case GLUT_KEY_RIGHT:
        moveRight();
        break;
    case GLUT_KEY_UP:
        moveForward();
        break;
    case GLUT_KEY_DOWN:
        moveBack();
        break;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    // List all youe keyboard keys from assignment two her for body movement
    switch (key)
    {
    case 'p':
        moveUp();
        glutPostRedisplay();
        break;

    case ';':
        moveDown();
        glutPostRedisplay();
        break;

    case '\'':
        Right();
        glutPostRedisplay();
        break;

    case 'l':
        Left();
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

void mouse(int button, int state, int x, int y)
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