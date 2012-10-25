/*		Sun Class
 *	AUTHOR: STEWART TAYLOR
 *------------------------------------
 * This class is used to generate the sun
 * It has a slight glow to it
 *
 * Last Updated: 23/10/2012
*/

#define _USE_MATH_DEFINES // Allows me to use PI constant 

#include "Sun.h"
#include "TextureLoader.h"

#include <stdio.h>	
#include <math.h>


typedef struct 
{
  double x;
  double y;
  double z;
} Vertex;

Sun::Sun()
{

}

Sun::Sun(GLfloat x , GLfloat y , GLfloat z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = -90;
	yAngle = 0;
	zAngle = 0;
	scale = 3;
	texName = TextureLoader::loadTexture("Textures\\sun.bmp");
}


Sun::~Sun(void)
{
}

void Sun::display(void)
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

	GLfloat emissionColor[] = {0.1, 0.1, 0.1};
	GLfloat blank[] = {0.0, 0.0, 0.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emissionColor);
			   

	GLfloat radius = 1.0;
	GLuint slices = 70;

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
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, blank);
}

void Sun::displayShadow(void)
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




void Sun::update()
{
	xAngle += 0.01f;
	yAngle  += 0.01f;
	//zAngle  += 0.005f;
}
