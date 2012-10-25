/*		OutPole Class
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * This class is to generate a cylinder
 * It rotates around an origin from an offset out to the planet
 *
 * Last Updated: 23/10/2012
*/

#define _USE_MATH_DEFINES // Allows me to use PI constant 

#include "OutPole.h"
#include "TextureLoader.h"

#include <freeglut.h>
#include <math.h>


OutPole::OutPole()
{

}


OutPole::OutPole(GLfloat x , GLfloat y , GLfloat z , GLfloat radiusT , GLfloat lengthT  ,GLuint slicesT)
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 90; // straight up
	yAngle = 0;
	zAngle = 0;
	scale = 1;
	originPosX = 0;
	originPosY = 0;
	originPosZ = 0;
	radius = radiusT;
	length = lengthT;
	slices =slicesT;
	texName = TextureLoader::loadTexture("Textures\\steel.bmp");
}


OutPole::~OutPole(void)
{
}



void OutPole::display(void)
{
	glPushMatrix(); 

	glEnable(GL_TEXTURE_2D);  // move
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texName);

	glMatrixMode(GL_MODELVIEW);
	glTranslated(originPosX,originPosY,originPosZ);
	glRotatef(yAngle, 0.0, 1.0, 0.0);

	glTranslated(xPosition ,yPosition ,length/2);
	glScaled(scale ,scale ,scale);
			   

	GLfloat halfLength = length * 0.5f;
	GLfloat a = 0.0f;
	GLfloat step = (2 * M_PI) / (GLfloat)slices;

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat x = cos(a) * radius;
		GLfloat y = sin(a) * radius;

		glNormal3f(x, y, 0);
		glTexCoord2f(x,0); glVertex3f(x,y, halfLength);
		glTexCoord2f(x,4);    glVertex3f(x,y,-halfLength);
    
		a += step;
	}
	glEnd();

	//CYLINDER ENDS
	glBegin(GL_TRIANGLE_STRIP);
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
		glTexCoord2f(0,0);		glVertex3f(0 , 0 , -halfLength);
		glTexCoord2f(xT,yT);	glVertex3f(xT , yT, -halfLength );
	}
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}



void OutPole::displayShadow(void)
{
	glPushMatrix(); 

	glMatrixMode(GL_MODELVIEW);
	glTranslated(originPosX,originPosY,originPosZ);
	glRotatef(yAngle, 0.0, 1.0, 0.0);

	glTranslated(xPosition ,yPosition ,length/2);
	glScaled(scale ,scale ,scale);
	glColor4f(0.2,0.2,0.2,0.2);	   

	GLfloat halfLength = length * 0.5f;
	GLfloat a = 0.0f;
	GLfloat step = (2*M_PI) / (GLfloat)slices;


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
	glDisable(GL_TEXTURE_2D);
}


void OutPole::setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void OutPole::setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT)
{
	xPosition = xPositionT;
	yPosition = yPositionT;
	zPosition = zPositionT;
}

void OutPole::setOriginPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT  )
{
	originPosX = xPositionT;
	originPosY = yPositionT;
	originPosZ = zPositionT;
}


