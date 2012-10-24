#include "SpaceWall.h"
#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>

SpaceWall::SpaceWall()
{

}


SpaceWall::SpaceWall(float x , float y , float z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 0;
	yAngle = 90;
	zAngle = 0;
	xAngleTexture = 0;
	yAngleTexture = 0;
	zAngleTexture = 0;
	scale = 800;
	texName = TextureLoader::loadTexture("Textures\\spaceTile.bmp");
}


SpaceWall::~SpaceWall(void)
{
}


void SpaceWall::display(void)
{
	glPushMatrix(); 

	glEnable(GL_TEXTURE_2D);  // move
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
			   
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);     glVertex3f(  0.5, -0.5, -0.5 );      
	glTexCoord2f(1.0,  1.0);   glVertex3f(  0.5,  0.5, -0.5 );     
	glTexCoord2f(-1.0,  1.0);     glVertex3f( -0.5,  0.5, -0.5 );      
	glTexCoord2f(-1.0, -1.0);  glVertex3f( -0.5, -0.5, -0.5 );      
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0); glVertex3f(  0.5, -0.5, 0.5 );
	glTexCoord2f(1.0,  1.0); glVertex3f(  0.5,  0.5, 0.5 );
	glTexCoord2f(-1.0,  1.0); glVertex3f( -0.5,  0.5, 0.5 );
	glTexCoord2f(-1.0, -1.0); glVertex3f( -0.5, -0.5, 0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f( 0.5, -0.5, -0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f( 0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( 0.5,  0.5,  0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( 0.5, -0.5,  0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f( -0.5, -0.5,  0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f( -0.5,  0.5,  0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( -0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f(  0.5,  0.5,  0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f(  0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( -0.5,  0.5, -0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5,  0.5,  0.5 );
	glEnd();
 
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, -1.0);	glVertex3f(  0.5, -0.5, -0.5 );
	glTexCoord2f(1.0,  1.0);	glVertex3f(  0.5, -0.5,  0.5 );
	glTexCoord2f(-1.0,  1.0);	glVertex3f( -0.5, -0.5,  0.5 );
	glTexCoord2f(-1.0, -1.0);	glVertex3f( -0.5, -0.5, -0.5 );
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
	//xAngleTexture += 0.0000001f; // Use time dependent update instead!
}
