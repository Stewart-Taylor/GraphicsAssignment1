/*		Cylinder CLASS
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * This class generates a textured cylinder.
 * It also provides a crude shadow method
 * 
 * Last Updated: 24/10/2012
*/

#define _USE_MATH_DEFINES // Allows me to use PI constant 

#include "Cylinder.h"
#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <math.h>



Cylinder::Cylinder()
{

}


Cylinder::Cylinder(GLfloat x , GLfloat y , GLfloat z , GLfloat radiusT , GLfloat lengthT  ,GLuint slicesT)
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 90; // straight up
	yAngle = 0;
	zAngle = 0;
	scale = 1;
	radius = radiusT;
	length = lengthT;
	slices = slicesT;
	texName = TextureLoader::loadTexture("Textures\\steel.bmp");
}


Cylinder::~Cylinder(void)
{
}



void Cylinder::display(void)
{
	glPushMatrix(); 

	glEnable(GL_TEXTURE_2D); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texName);

	glMatrixMode(GL_MODELVIEW);

	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,scale);
			   

	GLfloat halfLength = length * 0.5f;
	GLfloat a = 0.0f;
	GLfloat step = (M_PI*2) / (GLfloat)slices;


	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat x = cos(a) * radius;
		GLfloat y = sin(a) * radius;

		glNormal3f(x, y, 0);
		glTexCoord2f(x,0);	  glVertex3f(x,y, halfLength);
		glTexCoord2f(x,4);    glVertex3f(x,y,-halfLength);
    
		a += step;
	}
	glEnd();



	glBegin(GL_TRIANGLE_STRIP);  //ENDS
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat theta = 2.0f * M_PI * GLfloat(i) / GLfloat(slices);

		GLfloat xT = radius * cosf(theta);
		GLfloat yT = radius * sinf(theta);

		glNormal3f(xT, yT, 0);
		glTexCoord2f(0,0);		glVertex3f(0 , 0 , halfLength);
		glTexCoord2f(xT,yT);	glVertex3f(xT , yT, halfLength );

	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat theta = 2.0f * M_PI * GLfloat(i) / GLfloat(slices);

		GLfloat xT = radius * cosf(theta);
		GLfloat yT = radius * sinf(theta);

		glNormal3f(xT, yT, 0);
		glTexCoord2f(xT,yT);	glVertex3f(xT , yT, -halfLength ); 
		glTexCoord2f(0,0);		glVertex3f(0 , 0 , -halfLength);
	}
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}




void Cylinder::displayShadow(void)
{
	glPushMatrix(); 

	glMatrixMode(GL_MODELVIEW);

	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,scale);

	glColor4f(0.2,0.2,0.2,0.1);
	
	GLfloat halfLength = length * 0.5f;
	GLfloat a = 0.0f;
	GLfloat step = (2* M_PI) / (GLfloat)slices;

	GLfloat Nx ; //= X ; //= radius *cos(Theta)
	GLfloat Ny ; //= Y ; //= 0
	GLfloat Nz ; //= Z ; // = R*SIN(Theta)
	GLfloat angle ;
 
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat x = cos(a) * radius;
		GLfloat y = sin(a) * radius;

		glVertex3f(x,y, halfLength);
	    glVertex3f(x,y,-halfLength);
    
		a += step;
	}
	glEnd();

	glPopMatrix();
}


void Cylinder::setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void Cylinder::setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT)
{
	xPosition = xPositionT;
	yPosition = yPositionT;
	zPosition = zPositionT;
}

void Cylinder::spin(GLfloat speed)
{
	zAngle -= speed;
	
	if(zAngle <= -360.0)
	{
		zAngle += 360.0;
	}
}
