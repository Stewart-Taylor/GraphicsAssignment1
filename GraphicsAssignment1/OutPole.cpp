#include "OutPole.h"
#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>


OutPole::OutPole()
{

}


OutPole::OutPole(float x , float y , float z , float radiusT , float lengthT  ,int slicesT)
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
	slices =slicesT;
	texName = TextureLoader::loadTexture("C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\steel.bmp");
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
//	glTranslated(xPosition ,yPosition ,zPosition);
	//glRotatef(xAngle, 1.0, 0.0, 0.0);
//	glRotatef(yAngle, 0.0, 1.0, 0.0);
	//glRotatef(zAngle, 0.0, 0.0, 1.0);
	//glTranslated(0,0 ,0);
	glTranslated(0,0 ,0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);

	glTranslated(xPosition ,yPosition ,length/2);
	glScaled(scale ,scale ,scale);
			   

	GLfloat hl = length * 0.5f;
	GLfloat a = 0.0f;
	GLfloat step = 6.28318 / (GLfloat)slices;

	GLfloat Nx ; //= X ; //= radius *cos(Theta)
	GLfloat Ny ; //= Y ; //= 0
	GLfloat Nz ; //= Z ; // = R*SIN(Theta)
	GLfloat angle ;
 
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat x = cos(a) * radius;
		GLfloat y = sin(a) * radius;

		glNormal3f(x, y, 0);
		glTexCoord2f(x,0); glVertex3f(x,y, hl);
		glTexCoord2f(x,4);    glVertex3f(x,y,-hl);
    
		a += step;
	}
	glEnd();



	glBegin(GL_TRIANGLE_STRIP);  //ENDS
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat theta = 2.0f * 3.14159265359 * GLfloat(i) / GLfloat(slices);//get the current angle 

		GLfloat xT = radius * cosf(theta);//calculate the x component 
		GLfloat yT = radius * sinf(theta);//calculate the y component 

		glNormal3f(xT, yT, 0);
		glTexCoord2f(0,0);		glVertex3f(0 , 0 , hl);
		glTexCoord2f(xT,yT);	glVertex3f(xT , yT, hl );//output vertex 
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat theta = 2.0f * 3.14159265359 * GLfloat(i) / GLfloat(slices);//get the current angle 

		GLfloat xT = radius * cosf(theta);//calculate the x component 
		GLfloat yT = radius * sinf(theta);//calculate the y component 

		glNormal3f(xT, yT, 0);
		glTexCoord2f(0,0);		glVertex3f(0 , 0 , -hl);
		glTexCoord2f(xT,yT);	glVertex3f(xT , yT, -hl );//output vertex 
	}
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}



void OutPole::displayShadow(void)
{
	glPushMatrix(); 

	glMatrixMode(GL_MODELVIEW);
	glTranslated(0,0 ,0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);

	glTranslated(xPosition ,yPosition ,length/2);
	glScaled(scale ,scale ,scale);
		glColor4f(0.2,0.2,0.2,0.1);	   

	GLfloat hl = length * 0.5f;
	GLfloat a = 0.0f;
	GLfloat step = 6.28318 / (GLfloat)slices;


	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < slices + 1; ++i)
	{
		GLfloat x = cos(a) * radius;
		GLfloat y = sin(a) * radius;

		glNormal3f(x, y, 0);
		glTexCoord2f(x,0); glVertex3f(x,y, hl);
		glTexCoord2f(x,4);    glVertex3f(x,y,-hl);
    
		a += step;
	}
	glEnd();


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


void OutPole::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void OutPole::setPosition(float xPositionT , float yPositionT , float zPositionT)
{
	xPosition = xPositionT;
	yPosition = yPositionT;
	zPosition = zPositionT;
}

void OutPole::spin()
{
	zAngle -= 1.0f;
}
