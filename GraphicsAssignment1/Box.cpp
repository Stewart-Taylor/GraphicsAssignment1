/*		CUBE CLASS
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * This class generates a textured cube.
 * It also provides a crude shadow method
 * 
 * Last Updated: 24/10/2012
*/

#include "Box.h"
#include "TextureLoader.h"
#include "NormalHelper.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>


Box::Box()
{

}


Box::Box(GLfloat x , GLfloat y , GLfloat z, GLfloat boxWidth , GLfloat boxHeight , GLfloat boxLength )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 90; 
	yAngle = 0;
	zAngle = 0;
	width = boxWidth;
	height = boxHeight;
	length = boxLength;
	texName = TextureLoader::loadTexture("Textures\\brass.bmp"); 

	calculateNormals();
}

void Box::calculateNormals(void)
{
	GLfloat pointb1[3]= {-0.5,0.5,0.5};
	GLfloat pointc1[3]= {-0.5,-0.5,0.5};
	GLfloat pointd1[3]= {0.5,-0.5,0.5};
	NormalHelper::getSurfaceNormal(normal1, pointd1, pointc1, pointb1);

	GLfloat pointa2[3] = {0.5,0.5,0.5};
	GLfloat pointb2[3]= {0.5,-0.5,0.5};
	GLfloat pointc2[3]= {0.5,-0.5,-0.5};
	GLfloat pointd2[3]= {0.5,0.5,-0.5};
	NormalHelper::getSurfaceNormal(normal2, pointd2, pointc2, pointb2);

	GLfloat pointa3[3] = {0.5,0.5,-0.5};
	GLfloat pointb3[3]= {0.5,-0.5,-0.5};
	GLfloat pointc3[3]= {-0.5,-0.5,-0.5};
	GLfloat pointd3[3]= {-0.5,0.5,-0.5};
    NormalHelper::getSurfaceNormal(normal3, pointc3, pointb3, pointa3);

	GLfloat pointa4[3] ={-0.5,0.5,0.5};
	GLfloat pointb4[3]= {-0.5,0.5,-0.5};
	GLfloat pointc4[3]= {-0.5,-0.5,-0.5};
	GLfloat pointd4[3]={-0.5,-0.5,0.5};
    NormalHelper::getSurfaceNormal(normal4, pointc4, pointb4, pointa4);

	GLfloat pointa5[3] ={0.5,0.5,0.5};
	GLfloat pointb5[3]= {0.5,0.5,-0.5};
	GLfloat pointc5[3]= {-0.5,0.5,-0.5};
	GLfloat pointd5[3]={-0.5,0.5,0.5};
    NormalHelper::getSurfaceNormal(normal5, pointc5, pointb5, pointa5);

	GLfloat pointa6[3] = {0.5,-0.5,0.5};
	GLfloat pointb6[3]= {-0.5,-0.5,0.5};
	GLfloat pointc6[3]= {-0.5,-0.5,-0.5};
	GLfloat pointd6[3]= {0.5,-0.5,-0.5};
    NormalHelper::getSurfaceNormal(normal6, pointc6, pointb6, pointa6);
}


Box::~Box(void)
{
}


void Box::display(void)
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
	glScaled(width ,height ,length);
			   
	glColor3f(0.4,0.4,0.4);
	
	glBegin(GL_POLYGON);
	glNormal3f(normal1[0], normal1[1], normal1[2]);
	glTexCoord2f(1.0, -1.0);  glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1.0,  1.0);   glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(-1.0,  1.0);  glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(-1.0, -1.0);    glVertex3f(0.5,-0.5,0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(normal2[0], normal2[1], normal2[2]);
	glTexCoord2f(1.0, -1.0);   glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1.0,  1.0);   glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(-1.0,  1.0);  glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(-1.0, -1.0);  glVertex3f(0.5,0.5,-0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(normal3[0], normal3[1], normal3[2]);
	glTexCoord2f(1.0, -1.0);	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(1.0,  1.0);	glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(-1.0,  1.0);   glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(-1.0, -1.0);   glVertex3f(-0.5,0.5,-0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(normal4[0], normal4[1], normal4[2]);
	glTexCoord2f(1.0, -1.0);	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(1.0,  1.0);    glVertex3f(-0.5,0.5,-0.5);
	glTexCoord2f(-1.0,  1.0);   glVertex3f(-0.5,-0.5,-0.5);
    glTexCoord2f(-1.0, -1.0);   glVertex3f(-0.5,-0.5,0.5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glNormal3f(normal5[0], normal5[1], normal5[2]);
	glTexCoord2f(1.0, -1.0);	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1.0,  1.0);    glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(-1.0,  1.0);   glVertex3f(-0.5,0.5,-0.5);
    glTexCoord2f(-1.0, -1.0);   glVertex3f(-0.5,0.5,0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(normal6[0], normal6[1], normal6[2]);
	glTexCoord2f(1.0, -1.0);    glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(1.0,  1.0);    glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(-1.0,  1.0);    glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(-1.0, -1.0);   glVertex3f(0.5,-0.5,-0.5);
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


void Box::displayShadow(void)
{
	glPushMatrix(); 

	glMatrixMode(GL_MODELVIEW);

	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(width ,height ,length);
			   
	glColor4f(0.1,0.1,0.1,0.3);	    
	
	glBegin(GL_POLYGON);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(-0.5,0.5,0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glVertex3f(0.5,0.5,-0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.5,0.5,-0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.5,0.5,0.5);
	glVertex3f(-0.5,0.5,-0.5);
	glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.5,0.5,0.5);
	glVertex3f(0.5,0.5,-0.5);
	glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void Box::setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}


