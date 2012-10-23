#include "Cylinder.h"

#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>

Cylinder::Cylinder()
{

}


Cylinder::Cylinder(float x , float y , float z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = 90;
	yAngle = 0;
	zAngle = 0;
	scale = 1;
	texName = TextureLoader::loadTexture("C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\steel.bmp");
}


Cylinder::~Cylinder(void)
{
}



void Cylinder::display(void)
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
	glScaled(scale ,scale ,scale);
			   

	GLfloat M_PI = 3.141;
	
	//glTranslated(xPosition ,yPosition ,zPosition);
//	glRotatef(xAngle, 1.0, 0.0, 0.0);
//	glRotatef(yAngle, 0.0, 1.0, 0.0);
//	glRotatef(zAngle, 0.0, 0.0, 1.0);
	//glRotatef(120, 0.0, 1.0, 0.0);
//	glTranslated(0,0 ,0);

	GLfloat radius = 0.5f;
	GLfloat halfLength = 15.2;
	int slices = 50;

				float hl = halfLength * 0.5f;
float a = 0.0f;
float step = 6.28318 / (float)slices;


GLfloat Nx ; //= X ; //= radius *cos(Theta)
GLfloat Ny ; //= Y ; //= 0
GLfloat Nz ; //= Z ; // = R*SIN(Theta)
GLfloat angle ;
 
glBegin(GL_TRIANGLE_STRIP);
for (int i = 0; i < slices + 1; ++i)
{
    float x = cos(a) * radius;
    float y = sin(a) * radius;

	angle = (i*360)/slices;                      //here theta is (current slice)*360/(number of slices).
	Nx = radius * cos(angle);
	Ny = 0;
	Nz = radius * sin(angle);

	GLfloat nVector[3] = { x, y , 0};
//NormalHelper::normalize(nVector);


	glNormal3f(nVector[0], nVector[1], nVector[2]);
	glTexCoord2f(x,0); glVertex3f(x,y, hl);
	glTexCoord2f(x,4);    glVertex3f(x,y,-hl);
    
		
 
    a += step;
}
glEnd();


//draw ends
glBegin(GL_TRIANGLE_STRIP);
for (int i = 0; i < slices + 1; ++i)
{
		float theta = 2.0f * 3.1415926f * float(i) / float(slices);//get the current angle 

		float xT = radius * cosf(theta);//calculate the x component 
		float yT = radius * sinf(theta);//calculate the y component 

		glNormal3f(xT, yT, 0);
	glTexCoord2f(0,0);	glVertex3f(0 , 0 , hl);
	glTexCoord2f(xT,yT);	glVertex3f(xT , yT, hl );//output vertex 
}
glEnd();

glBegin(GL_TRIANGLE_STRIP);
for (int i = 0; i < slices + 1; ++i)
{
		float theta = 2.0f * 3.1415926f * float(i) / float(slices);//get the current angle 

		float xT = radius * cosf(theta);//calculate the x component 
		float yT = radius * sinf(theta);//calculate the y component 

				glNormal3f(xT, yT, 0);
	glTexCoord2f(0,0);	glVertex3f(0 , 0 , -hl);
	glTexCoord2f(xT,yT);	glVertex3f(xT , yT, -hl );//output vertex 
}
glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void Cylinder::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void Cylinder::update()
{
	xAngle += 0.01f;
	yAngle  += 0.01f;
	zAngle  += 0.005f;
}
