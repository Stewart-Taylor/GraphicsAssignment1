#include "SpaceWall.h"
#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>


SpaceWall::SpaceWall()
{

}

SpaceWall::SpaceWall(float x , float y , float z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 0;
	yAngle = 0;
	zAngle = 0;
	xAngleTexture = 0;
	yAngleTexture = 0;
	zAngleTexture = 0;
	scale = 40;
	texName = TextureLoader::loadTexture("C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\space2.bmp");
}


SpaceWall::~SpaceWall(void)
{
}


void SpaceWall::display(void)
{
	glPushMatrix(); 
	
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texName);

	glMatrixMode(GL_TEXTURE);
	glRotatef(xAngleTexture, 0.0, 0, 1.0);
    
	glMatrixMode(GL_MODELVIEW);
			   
	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,scale);

	glColor3f( 1.0, 1.0, 0.0 );
	glBegin(GL_POLYGON);
 
	glTexCoord2f(-0.5, -0.5);	glVertex3f( -0.5, -0.5, -0.5);       
	glTexCoord2f(-0.5,  0.5);	glVertex3f( -0.5,  0.5, -0.5);      
	glTexCoord2f(0.5,  0.5);	glVertex3f(  0.5,  0.5, -0.5);       
	glTexCoord2f(0.5, -0.5);	glVertex3f(  0.5, -0.5, -0.5);       
 
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void SpaceWall::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void SpaceWall::update()
{
	xAngleTexture += 0.0000001f; // Use time dependent update instead!
}
