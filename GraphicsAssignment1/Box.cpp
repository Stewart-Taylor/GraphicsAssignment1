#include "Box.h"

#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>

Box::Box()
{

}


Box::Box(float x , float y , float z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 90;
	yAngle = 0;
	zAngle = 0;
	scale = 10;
	texName = TextureLoader::loadTexture("C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\brass.bmp");
}


Box::~Box(void)
{
}



void Box::display(void)
{
	glPushMatrix(); 

	

	glEnable(GL_TEXTURE_2D);  // move
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texName);

	glMatrixMode(GL_MODELVIEW);

	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,4.0);
			   

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


void Box::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void Box::update()
{
	xAngle += 0.01f;
	yAngle  += 0.01f;
	zAngle  += 0.005f;
}
