/*		Saturn Ring CLASS
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * This class generates a textured ring of saturn
 * It also provides a crude shadow method
 * 
 * Last Updated: 25/10/2012
*/

#define _USE_MATH_DEFINES // Allows me to use PI constant 

#include "SaturnRing.h"
#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <math.h>



SaturnRing::SaturnRing()
{

}


SaturnRing::SaturnRing(GLfloat x , GLfloat y , GLfloat z , GLfloat radiusT , GLfloat lengthT  ,GLuint slicesT)
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
	texName = TextureLoader::loadTexture("Textures\\saturn.bmp");
}


SaturnRing::~SaturnRing(void)
{
}


void SaturnRing::display(void)
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
			   
	GLfloat width = 0.1;
	GLfloat inner_radius = 2.1;
	GLfloat outer_radius = 3.5;
	GLfloat tooth_depth = 0;
	GLfloat teeth = 30;
	GLint i;
	GLfloat r0, r1, r2;
	GLfloat angle, da;
	GLfloat u, v, len;

	r0 = inner_radius;
	r1 = outer_radius - tooth_depth / 2.0;
	r2 = outer_radius + tooth_depth / 2.0;

	da = 2.0 * M_PI / teeth / 4.0;

	glNormal3f(0.0, 0.0, 1.0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= teeth; i++) 
	{
		angle = i * 2.0 * M_PI / teeth;

		glTexCoord2f(r0 * cos(angle) ,r0 * sin(angle) ); 	glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
		glTexCoord2f(r1 * cos(angle), r1 * sin(angle) );	glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
		glTexCoord2f(r0 * cos(angle), r0 * sin(angle) );	glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
		glTexCoord2f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da) );	glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
	}
	glEnd();



	glNormal3f(0.0, 0.0, -1.0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= teeth; i++) 
	{
		angle = i * 2.0 * M_PI / teeth;
		glNormal3f(0.0, 0.0, -1.0);		glTexCoord2f(r1 * cos(angle), r1 * sin(angle) ); glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
		glNormal3f(0.0, 0.0, -1.0);		glTexCoord2f(r0 * cos(angle), r0 * sin(angle) ); glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
		glNormal3f(0.0, 0.0, -1.0);		glTexCoord2f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da) ); glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glNormal3f(0.0, 0.0, -1.0);		glTexCoord2f(r0 * cos(angle), r0 * sin(angle) ); glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
	}
	glEnd();

	glBegin(GL_QUADS);
	da = 2.0 * M_PI / teeth / 4.0;
	for (i = 0; i < teeth; i++) 
	{
		angle = i * 2.0 * M_PI / teeth;
		glTexCoord2f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da) );  glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glTexCoord2f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da));  glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
		glTexCoord2f(r2 * cos(angle + da), r2 * sin(angle + da) );  glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
		glTexCoord2f(r1 * cos(angle), r1 * sin(angle) );  glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < teeth; i++) 
	{
		angle = i * 2.0 * M_PI / teeth;

		glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
		glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
		u = r2 * cos(angle + da) - r1 * cos(angle);
		v = r2 * sin(angle + da) - r1 * sin(angle);
		len = sqrt(u * u + v * v);
		u /= len;
		v /= len;
		glNormal3f(v, -u, 0.0);
		glTexCoord2f(r2 * cos(angle + da), r2 * sin(angle + da) );   glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), width * 0.5);
		glTexCoord2f(r2 * cos(angle + da), r2 * sin(angle + da) );   glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
		glNormal3f(cos(angle), sin(angle), 0.0);
		glTexCoord2f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da) );   glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), width * 0.5);
		glTexCoord2f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da) );   glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
		u = r1 * cos(angle + 3 * da) - r2 * cos(angle + 2 * da);
		v = r1 * sin(angle + 3 * da) - r2 * sin(angle + 2 * da);
		glNormal3f(v, -u, 0.0);
		glTexCoord2f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da) );  glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
		glTexCoord2f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da));  glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glNormal3f(cos(angle), sin(angle), 0.0);
	}
	glTexCoord2f(r1 * cos((float)0), r1 * sin((float)0));  glVertex3f(r1 * cos((float)0), r1 * sin((float)0), width * 0.5);
	glTexCoord2f(r1 * cos((float)0), r1 * sin((float)0) );  glVertex3f(r1 * cos((float)0), r1 * sin((float)0), -width * 0.5);

	glEnd();
	
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= teeth; i++) 
	{
		angle = i * 2.0 * M_PI / teeth;
		glNormal3f(-cos(angle), -sin(angle), 0.0);
		glTexCoord2f(r0 * cos(angle), r0 * sin(angle) );   glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
		glTexCoord2f(r0 * cos(angle), r0 * sin(angle) );  glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
	}
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


void SaturnRing::displayShadow(void)
{
	glPushMatrix(); 

	glMatrixMode(GL_MODELVIEW);

	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,scale);

	glColor4f(0.2f,0.2f,0.2f,0.1f);
	
	GLfloat width = 0.1;
	GLfloat inner_radius = 2.1;
	GLfloat outer_radius = 3.5;
	GLfloat tooth_depth = 0;
	GLfloat teeth = 30;
	GLint i;
	GLfloat r0, r1, r2;
	GLfloat angle, da;
	GLfloat u, v, len;

	r0 = inner_radius;
	r1 = outer_radius - tooth_depth / 2.0;
	r2 = outer_radius + tooth_depth / 2.0;

	da = 2.0 * M_PI / teeth / 4.0;

	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= teeth; i++) 
	{
		angle = i * 2.0 * M_PI / teeth;
		glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
		glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
	}
	glEnd();

	glBegin(GL_QUADS);
	da = 2.0 * M_PI / teeth / 4.0;
	for (i = 0; i < teeth; i++) 
	{
		angle = i * 2.0 * M_PI / teeth;
		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
		glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
		glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
	}
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


void SaturnRing::setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void SaturnRing::setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT)
{
	xPosition = xPositionT;
	yPosition = yPositionT;
	zPosition = zPositionT;
}

