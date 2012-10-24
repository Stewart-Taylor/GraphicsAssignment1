#include "Sun.h"

#include "TextureLoader.h"

#include <windows.h>	
#include <stdio.h>	
#include <freeglut.h>
#include <glaux.h>
#include <math.h>

Sun::Sun()
{

}


Sun::Sun(float x , float y , float z )
{
	xPosition = x;
	yPosition = y;
	zPosition = z;
	xAngle = -90;
	yAngle = 0;
	zAngle = 0;
	scale = 3;
	texName = TextureLoader::loadTexture("C:\\Users\\Stewart\\Documents\\Visual Studio 2010\\Projects\\opengl\\TextureExample\\Debug\\sun.bmp");
}


Sun::~Sun(void)
{
}

typedef struct {
  double x;
  double y;
  double z;
} XYZ;


void Sun::display(void)
{
	glPushMatrix(); 

	XYZ c;
	c.x = 0;
	c.y = 0;
	c.z = 0;



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

		GLfloat whiteSpecularMaterial[] = {0.1, 0.1, 0.1};
		GLfloat blank[] = {0.0, 0.0, 0.0};
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, whiteSpecularMaterial);
			   

		GLfloat r = 1.0;
   int i,j;
   double phi1,phi2,theta, s, t;
   XYZ e,p;
   float PI = 3.141;
   float TWOPI = PI * 2;

   int n = 70;

   if (r < 0)
      r = -r;
   if (n < 0)
      n = -n;
   if (n < 4 || r <= 0) {
      glBegin(GL_POINTS);
      glVertex3f(c.x,c.y,c.z);
      glEnd();
      return;
   }

   for (j=0;j <= n; j++) {
      phi1 = j * TWOPI / n;
      phi2 = (j + 1) * TWOPI / n;	//next phi

      glBegin(GL_QUAD_STRIP);
      for (i=0;i <= n;i++) {
         theta = i * PI / n;

        e.x = sin ( theta ) * cos ( phi2 );
	e.y = sin ( theta ) * sin ( phi2 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        glNormal3f(e.x,e.y,e.z);
        s = phi2 / TWOPI;          // column
        t = 1 - theta/PI;          // row
	glTexCoord2f(s, t);
        glVertex3f(p.x,p.y,p.z);

        e.x = sin ( theta ) * cos ( phi1 );
	e.y = sin ( theta ) * sin ( phi1 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        glNormal3f(e.x,e.y,e.z);
        s = phi1/TWOPI;        // column
        t = 1 - theta/PI;      // row
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

	XYZ c;
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
	int i,j;
	double phi1,phi2,theta, s, t;
	XYZ e,p;
	float PI = 3.141;
	float TWOPI = PI * 2;

   int n = 20;

   if (r < 0)
      r = -r;
   if (n < 0)
      n = -n;
   if (n < 4 || r <= 0) {
      glBegin(GL_POINTS);
      glVertex3f(c.x,c.y,c.z);
      glEnd();
      return;
   }

   for (j=0;j <= n; j++) {
      phi1 = j * TWOPI / n;
      phi2 = (j + 1) * TWOPI / n;	//next phi

      glBegin(GL_QUAD_STRIP);
      for (i=0;i <= n;i++) {
         theta = i * PI / n;

        e.x = sin ( theta ) * cos ( phi2 );
	e.y = sin ( theta ) * sin ( phi2 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        s = phi2 / TWOPI;          // column
        t = 1 - theta/PI;          // row
        glVertex3f(p.x,p.y,p.z);

        e.x = sin ( theta ) * cos ( phi1 );
	e.y = sin ( theta ) * sin ( phi1 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        s = phi1/TWOPI;        // column
        t = 1 - theta/PI;      // row
 
	glVertex3f(p.x,p.y,p.z);
      }
      glEnd();
   }

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}


void Sun::setAngle(float xAngleT , float yAngleT , float zAngleT)
{
	xAngle = xAngleT;
	yAngle = yAngleT;
	zAngle = zAngleT;
}

void Sun::update()
{
	xAngle += 0.01f;
	yAngle  += 0.01f;
	//zAngle  += 0.005f;
}
