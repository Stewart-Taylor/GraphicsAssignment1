/*		Planet Class
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * This class is used to generate a planet
 *
 * Last Updated: 25/10/2012
*/

#define _USE_MATH_DEFINES // Allows me to use PI constant 

#include "Planet.h"
#include "TextureLoader.h"

#include <stdio.h>	
#include <freeglut.h>
#include <math.h>


typedef struct 
{
  double x;
  double y;
  double z;
} Vertex;

Planet::Planet()
{
}


Planet::Planet(GLfloat x , GLfloat y , GLfloat z  ,char* path )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = -90; // planets upright
	yAngle = 0;
	zAngle = 0;
	scale = 1;
	time = 0;
	texName = TextureLoader::loadTexture(path);
}

Planet::~Planet(void)
{
}

void Planet::display(void)
{
	glPushMatrix(); 

	Vertex c;
	c.x = 0;
	c.y = 0;
	c.z = 0;


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

	GLfloat radius = 1.0;
	GLuint slices = 30;

	GLuint i,j;
	GLdouble phi1,phi2,theta, s, t;
	Vertex e,p;


	for (j=0;j <= slices; j++) 
	{
		phi1 = j * (2* M_PI) / slices;
		phi2 = (j + 1) * (2* M_PI) / slices;	

		glBegin(GL_QUAD_STRIP);
		for (i=0;i <= slices;i++) 
		{
			theta = i * M_PI / slices;

			e.x = sin ( theta ) * cos ( phi2 );
			e.y = sin ( theta ) * sin ( phi2 );
			e.z = cos ( theta );
			p.x = c.x + radius * e.x;
			p.y = c.y + radius * e.y;
			p.z = c.z + radius * e.z;

			glNormal3f(e.x,e.y,e.z);
			s = phi2 / (2* M_PI);         
			t = 1 - theta/M_PI;       
			glTexCoord2f(s, t);
			glVertex3f(p.x,p.y,p.z);

			e.x = sin ( theta ) * cos ( phi1 );
			e.y = sin ( theta ) * sin ( phi1 );
			e.z = cos ( theta );
			p.x = c.x + radius * e.x;
			p.y = c.y + radius * e.y;
			p.z = c.z + radius * e.z;

			glNormal3f(e.x,e.y,e.z);
			s = phi1/(2* M_PI);       
			t = 1 - theta/M_PI;      
			glTexCoord2f(s, t);
 
			glVertex3f(p.x,p.y,p.z);
      }
      glEnd();
   }

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void Planet::displayShadow(void)
{
	glPushMatrix(); 

	Vertex c;
	c.x = 0;
	c.y = 0;
	c.z = 0;

	glMatrixMode(GL_MODELVIEW);


	glTranslated(xPosition ,yPosition ,zPosition);
	glRotatef(xAngle, 1.0, 0.0, 0.0);
	glRotatef(yAngle, 0.0, 1.0, 0.0);
	glRotatef(zAngle, 0.0, 0.0, 1.0);
	glTranslated(0,0 ,0);
	glScaled(scale ,scale ,scale);
	glColor4f(0.1,0.1,0.1,0.3);	     

	GLfloat r = 1.0;
	GLuint n = 20;

	GLuint i,j;
	GLdouble phi1,phi2,theta, s, t;
	Vertex e,p;


   for (j=0;j <= n; j++) 
   {
      phi1 = j * (2*M_PI) / n;
      phi2 = (j + 1) * (2*M_PI) / n;	

      glBegin(GL_QUAD_STRIP);
      for (i=0;i <= n;i++) {
         theta = i * M_PI / n;

        e.x = sin ( theta ) * cos ( phi2 );
	e.y = sin ( theta ) * sin ( phi2 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        s = phi2 / (2*M_PI);         
        t = 1 - theta/M_PI;        
        glVertex3f(p.x,p.y,p.z);

        e.x = sin ( theta ) * cos ( phi1 );
		e.y = sin ( theta ) * sin ( phi1 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        s = phi1/(2*M_PI);       
        t = 1 - theta/M_PI; 
 
		glVertex3f(p.x,p.y,p.z);
      }
      glEnd();
   }

	glPopMatrix();
}

void Planet::setAngle(GLfloat xAngleT , GLfloat yAngleT , GLfloat zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void Planet::setPosition(GLfloat xPositionT , GLfloat yPositionT , GLfloat zPositionT)
{
	xPosition = xPositionT;
	yPosition = yPositionT;
	zPosition = zPositionT;
}
