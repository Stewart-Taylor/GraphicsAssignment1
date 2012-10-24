#include "Camera.h"


#include <math.h>
#include <stdlib.h>
#include <freeglut.h>




//angle of rotation
float xpos = 2.312, ypos = 13.4, zpos = 16.97, xrot = 29, yrot = 0, angle=0.0;

float cRadius = 10.0f; // our radius distance from our character

float lastx, lasty;



Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}





void Camera::update()
{
	glTranslatef(0.0f, 0.0f, -cRadius);
    glRotatef(xrot,1.0,0.0,0.0);
    
    
    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,-ypos,-zpos); //translate the screento the position of our camera

}


void Camera::mouseControl(int x , int y)
{
	   int diffx=x-lastx; //check the difference between the current x and the last x position
    int diffy=y-lasty; //check the difference between the current y and the last y position
    lastx=x; //set lastx to the current x position
    lasty=y; //set lasty to the current y position
    xrot -= (float) diffy; //set the xrot to xrot with the addition of the difference in the y position
    yrot -= (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position


}


void Camera::keyboardControl(unsigned char key, int x, int y) {
    if (key=='q')
    {
    xrot += 1;
    if (xrot >360) xrot -= 360;
    }

    if (key=='z')
    {
    xrot -= 1;
    if (xrot < -360) xrot += 360;
    }

	    if (key=='x')
    {
		ypos -= 0.1f;
		}

			    if (key=='c')
    {
		ypos += 0.1f;
		}

	if (key=='e')
    {
    yrot -= 1;
    if (yrot < -360) yrot += 360;
    }

    if (key=='w')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f); 
    xpos += float(sin(yrotrad));
    zpos -= float(cos(yrotrad));
    ypos -= float(sin(xrotrad));
    }

    if (key=='s')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f); 
    xpos -= float(sin(yrotrad));
    zpos += float(cos(yrotrad));
    ypos += float(sin(xrotrad));
    }

    if (key=='d')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos += float(cos(yrotrad)) * 0.2;
    zpos += float(sin(yrotrad)) * 0.2;
    }

    if (key=='a')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos -= float(cos(yrotrad)) * 0.2;
    zpos -= float(sin(yrotrad)) * 0.2;
    }

    if (key==27)
    {
    exit(0);
    }
}

