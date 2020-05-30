#include "CameraFns.h"
#include "MathHelpers.h"
#include "Decs.h"

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

void moveUp()
{
    eye[1] += 0.7;
    center[1] += 0.7;
}
void moveDown()
{
    eye[1] -= 0.7;
    center[1] -= 0.7;
}