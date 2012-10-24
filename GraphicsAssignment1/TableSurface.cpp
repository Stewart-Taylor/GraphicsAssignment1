#include "TableSurface.h"

#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>

TableSurface::TableSurface()
{

}


TableSurface::TableSurface(float x , float y , float z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = -90;
	yAngle = 0;
	zAngle = 0;
	scale = 120;
	texName = TextureLoader::loadTexture("C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\wood.bmp");
}


TableSurface::~TableSurface(void)
{
}


void TableSurface::display(void)
{
	glPushMatrix(); 

//	glEnable(GL_TEXTURE_2D);  // move
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texName);


	glMatrixMode(GL_MODELVIEW);

	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,scale);
			   
	glBegin(GL_POLYGON);
	glNormal3f(0.0 , 1.0 , 0.0);
	glColor3f( 1.0, 1.0, 1.0 );		glTexCoord2f(2.0, -2.0);   glVertex3f(  0.5, -0.5, 0.0 );      
	glColor3f( 0.5, 0.5, 0.5 );		glTexCoord2f(2.0,  2.0);   glVertex3f(  0.5,  0.5, 0.0 );     
	glColor3f( 0.0, 0.0, 0.0 );		glTexCoord2f(-2.0,  2.0);  glVertex3f( -0.5,  0.5, 0.0 );      
	glColor3f( 0.5, 0.5, 0.5 );		glTexCoord2f(-2.0, -2.0);  glVertex3f( -0.5, -0.5, 0.0 );      
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void TableSurface::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}


